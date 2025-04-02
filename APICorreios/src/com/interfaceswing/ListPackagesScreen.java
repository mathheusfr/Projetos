/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.interfaceswing;

import com.apicorreios.dao.PackageDAO;
import com.apicorreios.dao.UserPackageDAO;
import java.util.ArrayList;
import java.awt.Color;
import java.awt.Component;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.HashMap;
import java.util.Map;
import javax.swing.JOptionPane;
import javax.swing.JTable;
import javax.swing.SwingUtilities;
import javax.swing.SwingWorker;
import javax.swing.event.TableModelEvent;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;


/**
 *
 * @author santo
 */
public class ListPackagesScreen extends javax.swing.JFrame {
    
    private final String username;
    private final HashMap<Integer, String> editedDescriptions = new HashMap<>();

    public ListPackagesScreen(String username) {
        this.username = username;

        DefaultTableModel tableModelCustom = new DefaultTableModel() {
            @Override
            public boolean isCellEditable(int row, int column) {
                return column == 1;
            }
        };

        tableModelCustom.addColumn("Código");
        tableModelCustom.addColumn("Descrição");
        tableModelCustom.addColumn("Status");
        tableModelCustom.addColumn("🗑"); 

        UserPackageDAO userPackageDAO = new UserPackageDAO();
        ArrayList<com.apicorreios.Package> packs = userPackageDAO.userListPacks(username);

        for (com.apicorreios.Package pack : packs) {
            tableModelCustom.addRow(new Object[]{pack.getCod(), pack.getDescription(), pack.getStatus(), "🗑"});
        }

        initComponents();
        FrameUtils.centerFrameOnScreen(this, 650, 300);

        jTable.setModel(tableModelCustom);
        jTable.getColumnModel().getColumn(3).setMaxWidth(20);
        jTable.getColumnModel().getColumn(3).setMinWidth(20);
        
        DefaultTableCellRenderer renderer = new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component c = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (!isSelected) {
                    c.setBackground(row % 2 == 0 ? Color.WHITE : Color.LIGHT_GRAY);
                }
                return c;
            }
        };

        for (int i = 0; i < jTable.getColumnCount(); i++) {
            jTable.getColumnModel().getColumn(i).setCellRenderer(renderer);
        }

        jTable.getModel().addTableModelListener((TableModelEvent e) -> {
            int row = e.getFirstRow();
            int col = e.getColumn();

            if (col == 1) {
                String editedDescription = (String) jTable.getValueAt(row, col);
                editedDescriptions.put(row, editedDescription);
            }
        });

        jTable.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int row = jTable.rowAtPoint(e.getPoint());
                int col = jTable.columnAtPoint(e.getPoint());

                if (row >= 0 && col >= 0) {
                    if (col != 1 && col != 3) {
                        String packageCode = (String) jTable.getValueAt(row, 0);
                        openAnotherScreen(packageCode, username);
                    } else if (col == 3) { // Coluna do botão de exclusão
                        String packageCode = (String) jTable.getValueAt(row, 0);

                        int confirmResult = JOptionPane.showConfirmDialog(
                                jTable,
                                "Tem certeza de que deseja excluir o pacote " + packageCode + "?",
                                "Confirmação",
                                JOptionPane.YES_NO_OPTION);

                        if (confirmResult == JOptionPane.YES_OPTION) {
                            // Exibe tela de loading antes de iniciar a exclusão
                            SwingUtilities.invokeLater(() -> {
                                LoadingDialogUtil.showLoadingDialog("Excluindo pacote. Aguarde...");
                            });

                            // Lógica para exclusão
                            SwingWorker<Void, Void> worker = new SwingWorker<>() {
                                @Override
                                protected Void doInBackground() {
                                    UserPackageDAO upDAO = new UserPackageDAO();
                                    int rowCount = upDAO.unlinkUserPack(username, packageCode);

                                    if (rowCount > 0) {
                                        PackageDAO packageDAO = new PackageDAO();
                                        int rowCountPack = packageDAO.delete(packageCode);

                                        if (rowCountPack > 0) {
                                            // Após excluir com sucesso, atualiza o modelo da tabela
                                            updateTableModel();
                                            JOptionPane.showMessageDialog(jTable, "Pacote " + packageCode + " excluído com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
                                        } else {
                                            JOptionPane.showMessageDialog(jTable, "Falha ao excluir o pacote " + packageCode + ". \nContate o suporte.", "Erro", JOptionPane.ERROR_MESSAGE);
                                        }
                                    }

                                    return null;
                                }

                                @Override
                                protected void done() {
                                    // Oculta a tela de loading após a conclusão da exclusão
                                    LoadingDialogUtil.hideLoadingDialog();
                                }
                            };

                            worker.execute();
                        }
}
                }
            }
        });
    }


    // Método para abrir outra tela
    private void openAnotherScreen(String packageCode, String username) {
        // Cria uma nova instância da tela desejada, passando os dados necessários
        UpdateScreen updateScreen = new UpdateScreen(packageCode, username);
        updateScreen.setVisible(true);
        this.dispose();
    }
    
// Método para atualizar o modelo da tabela
private void updateTableModel() {
    DefaultTableModel tableModel = (DefaultTableModel) jTable.getModel();
    
    // Limpa todas as linhas da tabela
    tableModel.setRowCount(0);

    // Recarrega os dados da tabela (sem o pacote excluído)
    UserPackageDAO userPackageDAO = new UserPackageDAO();
    ArrayList<com.apicorreios.Package> packs = userPackageDAO.userListPacks(username);

    for (com.apicorreios.Package pack : packs) {
        tableModel.addRow(new Object[]{pack.getCod(), pack.getDescription(), pack.getStatus(), "🗑"});
    }

    // Notifica que os dados foram alterados
    tableModel.fireTableDataChanged();
}


    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jTable = new javax.swing.JTable();
        jButtonBack = new javax.swing.JButton();
        jButtonSave = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));
        jScrollPane1.setViewportView(jTable);

        jButtonBack.setText("⬅");
        jButtonBack.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonBackActionPerformed(evt);
            }
        });

        jButtonSave.setText("Salvar");
        jButtonSave.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonSaveActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 638, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButtonBack)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
            .addGroup(layout.createSequentialGroup()
                .addGap(286, 286, 286)
                .addComponent(jButtonSave)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jButtonBack)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 170, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButtonSave)
                .addContainerGap(60, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonBackActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonBackActionPerformed
        HomeScreen homeScreen = new HomeScreen(username);
        homeScreen.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_jButtonBackActionPerformed

    private void jButtonSaveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonSaveActionPerformed
        // Verifica se existem alterações antes de tentar salvar
    if (editedDescriptions.isEmpty()) {
        JOptionPane.showMessageDialog(this, "Nenhuma alteração para salvar.", "Aviso", JOptionPane.WARNING_MESSAGE);
        return;
    }

    for (Map.Entry<Integer, String> entry : editedDescriptions.entrySet()) {
        int row = entry.getKey();
        String packageCode = (String) jTable.getValueAt(row, 0);
        String editedDescription = entry.getValue();

        int rowCount = updatePackageDescription(packageCode, editedDescription);

        if (rowCount > 0) {
            JOptionPane.showMessageDialog(this, "Descrição atualizada com sucesso para o pacote: " + packageCode, "Sucesso", JOptionPane.INFORMATION_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(this, "Falha ao atualizar a descrição para o pacote: " + packageCode + ". \nContate o suporte.", "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
    }//GEN-LAST:event_jButtonSaveActionPerformed
    
    private int updatePackageDescription(String packageCode, String editedDescription) {
        PackageDAO packageDAO = new PackageDAO();
        return packageDAO.update(editedDescription, packageCode);
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonBack;
    private javax.swing.JButton jButtonSave;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable jTable;
    // End of variables declaration//GEN-END:variables
}

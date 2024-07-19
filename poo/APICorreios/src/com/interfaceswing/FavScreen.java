/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.interfaceswing;

import com.apicorreios.Package;
import com.apicorreios.dao.PackageDAO;
import com.apicorreios.dao.UserPackageDAO;
import javax.swing.JOptionPane;
import javax.swing.WindowConstants;

public class FavScreen extends javax.swing.JFrame {
    
    private final String code;
    private final String date;
    private final String hour;
    private final String local;
    private final String status;
    private final String username;
    
    public FavScreen(String username, String code, String date, String hour, String local, String status) {
        initComponents();
        FrameUtils.centerFrameOnScreen(this, 300, 135);
        this.setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
        
        this.username = username;
        this.code = code;
        this.date = date;
        this.hour = hour;
        this.local = local;
        this.status = status;
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTextFieldDescription = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jButtonSave = new javax.swing.JButton();
        jButtonBack = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jTextFieldDescription.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextFieldDescriptionActionPerformed(evt);
            }
        });

        jLabel1.setText("Descrição");

        jButtonSave.setText("Salvar");
        jButtonSave.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonSaveActionPerformed(evt);
            }
        });

        jButtonBack.setText("⬅");
        jButtonBack.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonBackActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButtonBack, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonSave, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jTextFieldDescription, javax.swing.GroupLayout.PREFERRED_SIZE, 183, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(32, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldDescription, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonSave)
                    .addComponent(jButtonBack))
                .addContainerGap(51, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonSaveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonSaveActionPerformed
        // Cria um objeto Package com os valores desejados
        String description = jTextFieldDescription.getText();
        
        if(!jTextFieldDescription.getText().isEmpty()){
            Package myPackage = new Package(code, description, date, hour, local, status);
           
            // Cria uma instância de PackageDAO
            PackageDAO packageDAO = new PackageDAO();
            
            // Chama o método insert
            int rowCount = packageDAO.insert(myPackage);

            // Verifica se a inserção foi bem-sucedida
            if (rowCount > 0) {
                
                // Vincula o usuário ao pacote
                UserPackageDAO userPackageDAO = new UserPackageDAO();
                if (userPackageDAO.linkUserPack(username, code)) {
                    // Inserção bem-sucedida, exibe uma mensagem de sucesso
                    JOptionPane.showMessageDialog(null, "Inserção bem-sucedida!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);                      
                    this.dispose();
                } else {
                    JOptionPane.showMessageDialog(null, "Falha ao inserir! Contate o suporte.", "Erro", JOptionPane.ERROR_MESSAGE);
                    this.dispose();
                }
            } else {
                JOptionPane.showMessageDialog(null, "Falha ao inserir! Contate o suporte.", "Erro", JOptionPane.ERROR_MESSAGE);
                this.dispose();
            }
        } else{
            JOptionPane.showMessageDialog(null, "Descrição vazia!", "Erro", JOptionPane.ERROR_MESSAGE);
        }
        // Teste
        System.out.println("Code = " + code + " | Description = " + description + " | Date: " + date + " | Hour: " + hour + " | Local: " + local + " | Status: " + status);
        
        
    }//GEN-LAST:event_jButtonSaveActionPerformed

    private void jTextFieldDescriptionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldDescriptionActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextFieldDescriptionActionPerformed

    private void jButtonBackActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonBackActionPerformed
        this.dispose();
    }//GEN-LAST:event_jButtonBackActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonBack;
    private javax.swing.JButton jButtonSave;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JTextField jTextFieldDescription;
    // End of variables declaration//GEN-END:variables
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.interfaceswing;

import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;
import javax.swing.SwingWorker;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.InputStream;
import javax.imageio.ImageIO;
/**
 *
 * @author santo
 */

public class LoadingDialogUtil {

    private static JDialog loadingDialog;

    public static void showLoadingDialog(String message) {
        SwingUtilities.invokeLater(() -> {
            if (loadingDialog != null && loadingDialog.isVisible()) {
                return;
            }

            JOptionPane optionPane = new JOptionPane(message, JOptionPane.PLAIN_MESSAGE, JOptionPane.DEFAULT_OPTION, getLoadingIcon(), new Object[]{}, null);

            loadingDialog = optionPane.createDialog(null, "Aguarde");
            loadingDialog.setModal(false);

            loadingDialog.setVisible(true);
        });
    }

    public static void hideLoadingDialog() {
        SwingUtilities.invokeLater(() -> {
            if (loadingDialog != null && loadingDialog.isVisible()) {
                loadingDialog.dispose();
            }
        });
    }

    private static ImageIcon getLoadingIcon() {
        try {
            InputStream inputStream = LoadingDialogUtil.class.getResourceAsStream("spinner.gif");
            BufferedImage originalImage = ImageIO.read(inputStream);

            int newWidth = 50;
            int newHeight = 50;

            Image resizedImage = originalImage.getScaledInstance(newWidth, newHeight, Image.SCALE_SMOOTH);

            return new ImageIcon(resizedImage);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }
}
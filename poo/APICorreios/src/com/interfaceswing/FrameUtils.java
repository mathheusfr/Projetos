/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.interfaceswing;

import javax.swing.JFrame;
import java.awt.Dimension;
import java.awt.Toolkit;

public class FrameUtils {

    public static void centerFrameOnScreen(JFrame frame, int width, int height) {
        // Bloqueai o dimensionamento da janela
        frame.setResizable(false);
        
        // Obtém as dimensões da tela
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

        // Calcula as coordenadas para centralizar o frame
        int screenWidth = screenSize.width;
        int screenHeight = screenSize.height;

        int x = (screenWidth - width) / 2;
        int y = (screenHeight - height) / 2;

        // Define as coordenadas para centralizar o frame
        frame.setBounds(x, y, width, height);
    }
}

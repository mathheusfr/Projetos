/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mysql.connection;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author santo
 */
public class MySQLConnection {
    public static java.sql.Connection getMySQLConnection(){
        
        Connection conn = null;
        String server = "db4free.net";
        String db = "apicorreios";
        String url = "jdbc:mysql://" + server + "/" + db;
        String user = "bsantosdarosa";
        String pass = "@G4m3P4ss";
    
        try{
            conn = DriverManager.getConnection(url, user, pass);
        } catch(SQLException e){
            e.printStackTrace();
        }
        return conn;
    }
}

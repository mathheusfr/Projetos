/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.apicorreios.dao;

import com.mysql.connection.MySQLConnection;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import com.apicorreios.Package;

public class PackageDAO {
    
    public int insert(Package p){
        try {
            Connection conn = MySQLConnection.getMySQLConnection();
            
            PreparedStatement ps = conn.prepareStatement("INSERT INTO tbl_packages (cod, pack_description, pack_dt, pack_hr, pack_local, pack_status) VALUES (?,?,?,?,?,?)", Statement.RETURN_GENERATED_KEYS);
            ps.setString(1, p.getCod());
            ps.setString(2, p.getDescription());
            ps.setString(3, p.getDate());
            ps.setString(4, p.getHour());
            ps.setString(5, p.getLocal());
            ps.setString(6, p.getStatus());
            
            int rowCount = ps.executeUpdate();
            
            conn.close();
            
            return rowCount;
        } catch (SQLException ex) {
            Logger.getLogger(PackageDAO.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex);
        }
        return 0;     
    }
    
    public int update(String description, String cod){
        try {
            Connection conn = MySQLConnection.getMySQLConnection();
            
            PreparedStatement ps = conn.prepareStatement("UPDATE tbl_packages SET pack_description = ? WHERE cod = ?", Statement.RETURN_GENERATED_KEYS);
            ps.setString(1, description);
            ps.setString(2, cod);
            
            int rowCount = ps.executeUpdate();
            
            conn.close();
            
            return rowCount;
        } catch (SQLException ex) {
            Logger.getLogger(PackageDAO.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex);
        }
        return 0;     
    }
    
    public int delete(String cod){
        try{
            Connection conn = MySQLConnection.getMySQLConnection();
            PreparedStatement ps = conn.prepareStatement("DELETE FROM tbl_packages WHERE cod = ?");
            ps.setString(1, cod);

            
            ps.executeUpdate();
        } catch(SQLException e){
            Logger.getLogger(PackageDAO.class.getName()).log(Level.SEVERE, null, e);
            System.out.println(e);
        }    
        return 1;
    }
    
}

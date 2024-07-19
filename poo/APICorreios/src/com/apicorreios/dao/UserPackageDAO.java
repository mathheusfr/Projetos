/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.apicorreios.dao;

import com.mysql.connection.MySQLConnection;
import java.sql.*;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import com.apicorreios.Package;

public class UserPackageDAO {
    
    public boolean linkUserPack(String username, String packCod) {
        try {
            Connection connection = MySQLConnection.getMySQLConnection();
            PreparedStatement ps = connection.prepareStatement("INSERT INTO tbl_packtouser VALUES (?,?)");
            ps.setString(1, username);
            ps.setString(2, packCod);

            int rowCount = ps.executeUpdate();
            return rowCount > 0; // Retorna true se pelo menos uma linha foi afetada
        } catch (SQLException e) {
            Logger.getLogger(UserPackageDAO.class.getName()).log(Level.SEVERE, null, e);
            return false; // Retorna false em caso de exceção ou falha na execução
        }
    }
    
    public int unlinkUserPack(String username, String packCod) {
        try {
            Connection connection = MySQLConnection.getMySQLConnection();
            PreparedStatement ps = connection.prepareStatement("DELETE FROM tbl_packtouser WHERE username = ? AND codPack = ?");
            ps.setString(1, username);
            ps.setString(2, packCod);
            
            ps.executeUpdate();
        } catch(SQLException e) {
            Logger.getLogger(UserPackageDAO.class.getName()).log(Level.SEVERE, null, e);
        }
        return 1;
    }
    
public ArrayList<Package> userListPacks(String username) {
    ArrayList<Package> packs = new ArrayList<>();

    try {
        Connection conn = MySQLConnection.getMySQLConnection();
        PreparedStatement ps = conn.prepareStatement("""
                                                     SELECT p.cod, p.pack_description, p.pack_dt, p.pack_hr, p.pack_local, p.pack_status
                                                     FROM tbl_packtouser ptu
                                                     JOIN tbl_packages p
                                                     ON ptu.codPack = p.cod
                                                     WHERE ptu.username = ?""");
        ps.setString(1, username);

        ResultSet rs = ps.executeQuery();

        // Preenche a lista de pacotes com os dados do ResultSet
        while (rs.next()) {
            String cod = rs.getString("cod");
            String description = rs.getString("pack_description");
            String date = rs.getString("pack_dt");
            String hour = rs.getString("pack_hr");
            String local = rs.getString("pack_local");
            String status = rs.getString("pack_status");

            Package pack = new Package(cod, description, date, hour, local, status);
            packs.add(pack);
        }

    } catch (SQLException e) {
        Logger.getLogger(UserPackageDAO.class.getName()).log(Level.SEVERE, null, e);
    }

    // Retorna a lista de pacotes
    return packs;
}


    
}

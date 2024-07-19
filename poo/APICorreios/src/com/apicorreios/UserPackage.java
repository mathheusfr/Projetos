/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.apicorreios;

public class UserPackage {
    private String username;
    private String packCod;

    public UserPackage(String username, String packCod) {
        this.username = username;
        this.packCod = packCod;
    }

    public String getUsername() {
        return username;
    }

    public String getPackCod() {
        return packCod;
    }
    
    public void setUsername(int userID) {
        this.username = username;
    }

    public void setPackCod(String packCod) {
        this.packCod = packCod;
    }
}

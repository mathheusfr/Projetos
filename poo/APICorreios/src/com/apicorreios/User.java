/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.apicorreios;

public class User {
    private int userID;
    private String name;
    private String pass;
    private String email;
    private boolean type;

    public User(int userID, String name, String pass, String email, boolean type) {
        this.userID = userID;
        this.name = name;
        this.pass = pass;
        this.email = email;
        this.type = type;
    }

    public int getUserID() {
        return userID;
    }

    public String getName() {
        return name;
    }

    public String getPass() {
        return pass;
    }

    public String getEmail() {
        return email;
    }

    public boolean isType() {
        return type;
    }

    public void setUserID(int userID) {
        this.userID = userID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPass(String pass) {
        this.pass = pass;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setType(boolean type) {
        this.type = type;
    }
}

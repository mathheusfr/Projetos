/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.apicorreios;

public class Package {
    private String cod;
    private String description;
    private String date;
    private String hour;
    private String local;
    private String status;
    
    public Package(String cod, String description, String date, String hour, String local, String status) {
        this.cod = cod;
        this.description = description;
        this.date = date;
        this.hour = hour;
        this.local = local;
        this.status = status;
    }
    
    public String getCod() {
        return cod;
    }

    public String getDescription() {
        return description;
    }

    public String getDate() {
        return date;
    }

    public String getHour() {
        return hour;
    }

    public String getLocal() {
        return local;
    }

    public String getStatus() {
        return status;
    }

    public void setCod(String cod) {
        this.cod = cod;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setHour(String hour) {
        this.hour = hour;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public void setStatus(String status) {
        this.status = status;
    }

}

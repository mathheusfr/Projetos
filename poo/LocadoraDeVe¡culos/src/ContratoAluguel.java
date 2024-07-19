

import java.time.LocalDate;
import java.util.Objects;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Lucas Henrique
 */
import java.util.Objects;

public class ContratoAluguel {

    private static int PROXIMOID = 1; // Variável estática para controlar o próximo ID disponível
    private int id;
    private String dataInicio;
    private String dataTermino;
    private Cliente cliente;
    private Veiculo veiculo;
    private StatusContrato statusContrato;

    public ContratoAluguel(int id, String dataInicio, String dataTermino, Cliente cliente, Veiculo veiculo, StatusContrato statusContrato) {
        this.id = id;
        this.dataInicio = dataInicio;
        this.dataTermino = dataTermino;
        this.cliente = cliente;
        this.veiculo = veiculo;
        this.statusContrato = statusContrato;
        iniciarAluguel(); // Inicia o aluguel do veículo ao criar o contrato
    }

    public int getId() {
        return id;
    }

    public String getDataInicio() {
        return dataInicio;
    }

    public void String(String dataInicio) {
        this.dataInicio = dataInicio;
    }

    public String getDataTermino() {
        return dataTermino;
    }

    public void setDataTermino(String dataTermino) {
        this.dataTermino = dataTermino;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public void setVeiculo(Veiculo veiculo) {
        this.veiculo = veiculo;
    }

    public StatusContrato getStatusContrato() {
        return statusContrato;
    }

    public void setStatusContrato(StatusContrato statusContrato) {
        this.statusContrato = statusContrato;
    }

    // Método para iniciar o aluguel do veículo
    public void iniciarAluguel() {
        this.veiculo.marcarComoAlugado();
    }

    // Método para finalizar o aluguel do veículo
    public void finalizarAluguel() {
        this.veiculo.marcarComoDisponivel();
    }

    @Override
    public String toString() {
        return "ContratoAluguel{" +
                "id=" + id +
                ", dataInicio=" + dataInicio +
                ", dataTermino=" + dataTermino +
                ", cliente=" + cliente +
                ", veiculo=" + veiculo +
                ", statusContrato=" + statusContrato +
                '}';
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, dataInicio, dataTermino, cliente, veiculo, statusContrato);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        ContratoAluguel that = (ContratoAluguel) obj;
        return id == that.id &&
                Objects.equals(dataInicio, that.dataInicio) &&
                Objects.equals(dataTermino, that.dataTermino) &&
                Objects.equals(cliente, that.cliente) &&
                Objects.equals(veiculo, that.veiculo) &&
                statusContrato == that.statusContrato;
    }
}



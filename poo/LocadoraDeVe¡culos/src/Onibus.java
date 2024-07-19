
import java.util.Objects;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public class Onibus extends Veiculo {

    private String marca;
    private String modelo;
    private String cor;
    private float potenciaMotor;
    private int kmRodados;
    private int qtdAssentos;

    public Onibus(String marca, String modelo, String cor, float potenciaMotor, int kmRodados, int qtdAssentos, String placa, String chassi, int renavam, int ano, TipoTransmissao tipo_transmissao, TipoCombustivel tipo_combustivel, StatusVeiculo status_veiculo) {
        super(placa, chassi, renavam, ano, tipo_transmissao, tipo_combustivel, status_veiculo);
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.potenciaMotor = potenciaMotor;
        this.kmRodados = kmRodados;
        this.qtdAssentos = qtdAssentos;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        validarStringNaoVazia(marca, "marca");
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        validarStringNaoVazia(modelo, "modelo");
        this.modelo = modelo;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        validarStringNaoVazia(cor, "cor");
        this.cor = cor;
    }

    public float getPotenciaMotor() {
        return potenciaMotor;
    }

    public void setPotenciaMotor(float potenciaMotor) {
        if (potenciaMotor < 1.0 || potenciaMotor > 3.0) {
            throw new IllegalArgumentException("Digite uma potência válida, entre 1.0 e 3.0");
        }
        this.potenciaMotor = potenciaMotor;
    }

    public int getKmRodados() {
        return kmRodados;
    }

    public void setKmRodados(int kmRodados) {
        if (kmRodados < 0) {
            throw new IllegalArgumentException("A quilometragem rodada não pode ser negativa.");
        }
        this.kmRodados = kmRodados;
    }

    public int getQtdAssentos() {
        return qtdAssentos;
    }

    public void setQtdAssentos(int qtdAssentos) {
        if (qtdAssentos < 20 || qtdAssentos > 50) {
            throw new IllegalArgumentException("Quantidade de assentos inválida.");
        }
        this.qtdAssentos = qtdAssentos;
    }

    @Override
    protected void validarStringNaoVazia(String valor, String nomeCampo) {
        if (valor == null || valor.trim().isEmpty()) {
            throw new IllegalArgumentException("O campo " + nomeCampo + " não pode ser vazio ou em branco");
        }
    }

    @Override
    public int hashCode() {
        return Objects.hash(marca, modelo, cor, potenciaMotor, kmRodados, qtdAssentos, getPlaca(), getChassi(), getRenavam(), getAno(), getTipo_transmissao(), getTipo_combustivel(), getStatus_veiculo());
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Onibus onibus = (Onibus) obj;
        return Float.compare(onibus.potenciaMotor, potenciaMotor) == 0
                && kmRodados == onibus.kmRodados
                && qtdAssentos == onibus.qtdAssentos
                && Objects.equals(marca, onibus.marca)
                && Objects.equals(modelo, onibus.modelo)
                && Objects.equals(cor, onibus.cor)
                && Objects.equals(getPlaca(), onibus.getPlaca())
                && Objects.equals(getChassi(), onibus.getChassi())
                && getRenavam() == onibus.getRenavam()
                && getAno() == onibus.getAno()
                && getTipo_transmissao() == onibus.getTipo_transmissao()
                && getTipo_combustivel() == onibus.getTipo_combustivel()
                && getStatus_veiculo() == onibus.getStatus_veiculo();
    }

    @Override
    public String toString() {
        return "Onibus{"
                + "marca='" + marca + '\''
                + ", modelo='" + modelo + '\''
                + ", cor='" + cor + '\''
                + ", potenciaMotor=" + potenciaMotor
                + ", kmRodados=" + kmRodados
                + ", qtdAssentos=" + qtdAssentos
                + ", placa='" + getPlaca() + '\''
                + ", chassi='" + getChassi() + '\''
                + ", renavam=" + getRenavam()
                + ", ano=" + getAno()
                + ", tipo_transmissao=" + getTipo_transmissao()
                + ", tipo_combustivel=" + getTipo_combustivel()
                + ", status_veiculo=" + getStatus_veiculo()
                + '}';
    }

}


import java.util.Objects;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public class Moto extends Veiculo {

    private String marca;
    private String modelo;
    private String cor;
    private int kmRodados;
    private int cilindradas;

    public Moto(String marca, String modelo, String cor, int kmRodados, int cilindradas, String placa, String chassi, int renavam, int ano, TipoTransmissao tipo_transmissao, TipoCombustivel tipo_combustivel, StatusVeiculo status_veiculo) {
        super(placa, chassi, renavam, ano, tipo_transmissao, tipo_combustivel, status_veiculo);
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.kmRodados = kmRodados;
        this.cilindradas = cilindradas;
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

    public int getKmRodados() {
        return kmRodados;
    }

    public void setKmRodados(int kmRodados) {
        if (kmRodados < 0) {
            throw new IllegalArgumentException("A quilometragem rodada não pode ser negativa.");
        }
        this.kmRodados = kmRodados;
    }

    public int getCilindradas() {
        return cilindradas;
    }

    public void setCilindradas(int cilindradas) {
        if (cilindradas < 110 || cilindradas > 250) {
            throw new IllegalArgumentException("Cilindrada inválida.");
        }
        this.cilindradas = cilindradas;
    }

    @Override
    protected void validarStringNaoVazia(String valor, String nomeCampo) {
        if (valor == null || valor.trim().isEmpty()) {
            throw new IllegalArgumentException("O campo " + nomeCampo + " não pode ser vazio ou em branco");
        }
    }

    @Override
    public String toString() {
        return "Moto{"
                + "marca='" + marca + '\''
                + ", modelo='" + modelo + '\''
                + ", cor='" + cor + '\''
                + ", kmRodados=" + kmRodados
                + ", cilindradas=" + cilindradas
                + ", placa='" + getPlaca() + '\''
                + ", chassi='" + getChassi() + '\''
                + ", renavam=" + getRenavam()
                + ", ano=" + getAno()
                + ", tipo_transmissao=" + getTipo_transmissao()
                + ", tipo_combustivel=" + getTipo_combustivel()
                + ", status_veiculo=" + getStatus_veiculo()
                + '}';
    }

    @Override
    public int hashCode() {
        return Objects.hash(marca, modelo, cor, kmRodados, cilindradas, getPlaca(), getChassi(), getRenavam(), getAno(), getTipo_transmissao(), getTipo_combustivel(), getStatus_veiculo());
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Moto moto = (Moto) obj;
        return kmRodados == moto.kmRodados
                && cilindradas == moto.cilindradas
                && Objects.equals(marca, moto.marca)
                && Objects.equals(modelo, moto.modelo)
                && Objects.equals(cor, moto.cor)
                && Objects.equals(getPlaca(), moto.getPlaca())
                && Objects.equals(getChassi(), moto.getChassi())
                && getRenavam() == moto.getRenavam()
                && getAno() == moto.getAno()
                && getTipo_transmissao() == moto.getTipo_transmissao()
                && getTipo_combustivel() == moto.getTipo_combustivel()
                && getStatus_veiculo() == moto.getStatus_veiculo();
    }

}

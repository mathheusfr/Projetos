
import java.util.Objects;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public class Carro extends Veiculo {

    private String marca;
    private String modelo;
    private String cor;
    private float potenciaMotor;
    private int kmRodados;
    private CategoriaCarro categoria_carro;

    public Carro(String marca, String modelo, String cor, float potenciaMotor, int kmRodados, CategoriaCarro categoria_carro, String placa, String chassi, int renavam, int ano, TipoTransmissao tipo_transmissao, TipoCombustivel tipo_combustivel, StatusVeiculo status_veiculo) {
        super(placa, chassi, renavam, ano, tipo_transmissao, tipo_combustivel, status_veiculo);
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.potenciaMotor = potenciaMotor;
        this.kmRodados = kmRodados;
        this.categoria_carro = categoria_carro;
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
        } else {
            this.potenciaMotor = potenciaMotor;
        }
    }

    public int getKmRodados() {
        return kmRodados;
    }

    public void setKmRodados(int kmRodados) {
        if (kmRodados < 0) {
            throw new IllegalArgumentException("A quilometragem rodada não pode ser negativa.");
        } else {
            this.kmRodados = kmRodados;
        }
    }

    public CategoriaCarro getCategoria_carro() {
        return categoria_carro;
    }

    public void setCategoria_carro(CategoriaCarro categoria_carro) {
        this.categoria_carro = categoria_carro;
    }

    /**
     *
     * @param valor
     * @param nomeCampo
     */
    @Override
    protected void validarStringNaoVazia(String valor, String nomeCampo) {
        if (valor == null || valor.trim().isEmpty()) {
            throw new IllegalArgumentException("O campo " + nomeCampo + " não pode ser vazio ou em branco");
        }
    }

    @Override
    public String toString() {
        return "Carro{"
                + "placa='" + getPlaca() + '\''
                + ", chassi='" + getChassi() + '\''
                + ", renavam=" + getRenavam()
                + ", ano=" + getAno()
                + ", tipoTransmissao=" + getTipo_transmissao()
                + ", tipoCombustivel=" + getTipo_combustivel()
                + ", marca='" + marca + '\''
                + ", modelo='" + modelo + '\''
                + ", cor='" + cor + '\''
                + ", potenciaMotor=" + potenciaMotor
                + ", kmRodados=" + kmRodados
                + ", categoria_carro=" + categoria_carro
                + '}';
    }

    @Override
    public int hashCode() {
        return Objects.hash(marca, modelo, cor, potenciaMotor, kmRodados, categoria_carro, getPlaca(), getChassi(), getRenavam(), getAno(), getTipo_transmissao(), getTipo_combustivel(), getStatus_veiculo());
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Carro carro = (Carro) obj;
        return Float.compare(carro.potenciaMotor, potenciaMotor) == 0
                && kmRodados == carro.kmRodados
                && Objects.equals(marca, carro.marca)
                && Objects.equals(modelo, carro.modelo)
                && Objects.equals(cor, carro.cor)
                && categoria_carro == carro.categoria_carro
                && Objects.equals(getPlaca(), carro.getPlaca())
                && Objects.equals(getChassi(), carro.getChassi())
                && getRenavam() == carro.getRenavam()
                && getAno() == carro.getAno()
                && getTipo_transmissao() == carro.getTipo_transmissao()
                && getTipo_combustivel() == carro.getTipo_combustivel()
                && getStatus_veiculo() == carro.getStatus_veiculo();
    }

}

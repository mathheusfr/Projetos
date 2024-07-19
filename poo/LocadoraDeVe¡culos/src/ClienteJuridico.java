
import java.util.Objects;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public class ClienteJuridico extends Cliente {

    private String cnpj;
    private Veiculo veiculoLocado;

    public ClienteJuridico(String cnpj, Veiculo veiculoLocado, String nome, String endereco, String telefone, String email) {
        super(nome, endereco, telefone, email); // Chamando construtor da classe pai
        this.cnpj = cnpj;
        this.veiculoLocado = veiculoLocado;
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        validarDocumento(cnpj);
        this.cnpj = cnpj;
    }

    /**
     *
     * @param documento
     */
    @Override
    public void validarDocumento(String documento) {
        if (documento == null || !documento.matches("\\d{14}")) { // CNPJ possui 14 dígitos
            throw new IllegalArgumentException("CNPJ inválido");
        }
    }

    public Veiculo getVeiculoLocado() {
        return veiculoLocado;
    }

    public void setVeiculoLocado(Veiculo veiculoLocado) {
        this.veiculoLocado = veiculoLocado;
    }

    @Override
    public String toString() {
        return "ClienteJuridico{"
                + ", nome='" + nome + '\''
                + ", endereco='" + endereco + '\''
                + ", telefone='" + telefone + '\''
                + ", email='" + email + '\''
                + ", cnpj='" + cnpj + '\''
                + ", veiculoLocado=" + veiculoLocado
                + '}';
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), cnpj, veiculoLocado);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        if (!super.equals(obj)) {
            return false;
        }
        ClienteJuridico that = (ClienteJuridico) obj;
        return Objects.equals(cnpj, that.cnpj)
                && Objects.equals(veiculoLocado, that.veiculoLocado);
    }
}

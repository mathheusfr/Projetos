
import java.util.Objects;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public class ClienteFisico extends Cliente {

    private String cpf;
    private Veiculo veiculoLocado;

    public ClienteFisico(String cpf, Veiculo veiculoLocado, String nome, String endereco, String telefone, String email) {
        super(nome, endereco, telefone, email); // Chamando construtor da classe pai
        this.cpf = cpf;
        this.veiculoLocado = veiculoLocado;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        validarDocumento(cpf);
        this.cpf = cpf;
    }

    /**
     *
     * @param documento
     */
    @Override
    public void validarDocumento(String documento) {
        if (documento == null || !documento.matches("\\d{11}")) {
            throw new IllegalArgumentException("CPF inválido");
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
        return "ClienteFisico{"
                + ", nome='" + nome + '\''
                + ", endereco='" + endereco + '\''
                + ", telefone='" + telefone + '\''
                + ", email='" + email + '\''
                + ", cpf='" + cpf + '\''
                + ", veiculoLocado=" + veiculoLocado
                + '}';
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), cpf, veiculoLocado);
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
        ClienteFisico that = (ClienteFisico) obj;
        return Objects.equals(cpf, that.cpf)
                && Objects.equals(veiculoLocado, that.veiculoLocado);
    }

}


import java.util.Objects;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public abstract class Cliente {

    protected static int PROXIMOID = 1; // Variável estática para controlar o próximo ID disponível
    protected int id;
    protected String nome;
    protected String endereco;
    protected String telefone;
    protected String email;

    public Cliente(int id, String nome, String endereco, String telefone, String email) {

        this.id = PROXIMOID++;
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.email = email;
    }

    // Construtor público sem o ID
    public Cliente(String nome, String endereco, String telefone, String email) {
        this(PROXIMOID++, nome, endereco, telefone, email); // Atribui o próximo ID disponível
    }

    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {

        if (nome == null || nome.trim().isEmpty()) {

            throw new IllegalArgumentException("O campo não pode ser vázio ou em branco");
        } else {
            this.nome = nome;
        }

    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {

        if (endereco == null || endereco.trim().isEmpty()) {

            throw new IllegalArgumentException("O campo não pode ser vázio ou em branco");

        } else {

            this.endereco = endereco;

        }
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {

        if (telefone == null || telefone.trim().isEmpty()) {

            throw new IllegalArgumentException("O campo não pode ser vázio ou em branco");

        } else {

            this.telefone = telefone;

        }
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {

        if (email != null && email.matches("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$")) {

            this.email = email;

        } else {

            throw new IllegalArgumentException("Email inválido");
        }
    }

    // Método abstrato que deve ser implementado pelas subclasses
    public abstract void validarDocumento(String documento);

    @Override
    public String toString() {
        return "Cliente{" + "id=" + id + ", nome=" + nome + ", endereco=" + endereco + ", telefone=" + telefone + ", email=" + email + '}';
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 53 * hash + this.id;
        hash = 53 * hash + Objects.hashCode(this.nome);
        hash = 53 * hash + Objects.hashCode(this.endereco);
        hash = 53 * hash + Objects.hashCode(this.telefone);
        hash = 53 * hash + Objects.hashCode(this.email);
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Cliente other = (Cliente) obj;
        if (this.id != other.id) {
            return false;
        }
        if (!Objects.equals(this.nome, other.nome)) {
            return false;
        }
        if (!Objects.equals(this.endereco, other.endereco)) {
            return false;
        }
        if (!Objects.equals(this.telefone, other.telefone)) {
            return false;
        }
        return Objects.equals(this.email, other.email);
    }

}

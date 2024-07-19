
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
public abstract class Veiculo {

    protected static int PROXIMOID = 1; // Variável estática para controlar o próximo ID disponível
    protected int id;
    protected String placa;
    protected String chassi;
    protected int renavam;
    protected int ano;
    protected TipoTransmissao tipo_transmissao;
    private TipoCombustivel tipo_combustivel;
    private StatusVeiculo status_veiculo;

    public Veiculo(int id, String placa, String chassi, int renavam, int ano, TipoTransmissao tipo_transmissao, TipoCombustivel tipo_combustivel, StatusVeiculo status_veiculo) {
        this.id = id;
        this.placa = placa;
        this.chassi = chassi;
        this.renavam = renavam;
        this.ano = ano;
        this.tipo_transmissao = tipo_transmissao;
        this.tipo_combustivel = tipo_combustivel;
        this.status_veiculo = StatusVeiculo.DISPONIVEL; // Inicia como disponível
        atualizarProximoId(id); // Atualiza o próximo ID baseado no ID atual
    }

    // Construtor público sem o ID explícito
    public Veiculo(String placa, String chassi, int renavam, int ano, TipoTransmissao tipo_transmissao, TipoCombustivel tipo_combustivel, StatusVeiculo status_veiculo) {
        this(PROXIMOID++, placa, chassi, renavam, ano, tipo_transmissao, tipo_combustivel, status_veiculo);
    }

    // Método para atualizar o próximo ID baseado no ID atual
    private void atualizarProximoId(int id) {
        PROXIMOID = Math.max(PROXIMOID, id + 1);
    }

    public int getId() {
        return id;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        if (placa != null && placa.matches("[A-Z]{3}[0-9]{1}[A-Z]{1}[0-9]{2}|[A-Z]{3}[0-9]{4}")) {
            this.placa = placa;
        } else {
            throw new IllegalArgumentException("Placa inválida");
        }
    }

    public String getChassi() {
        return chassi;
    }

    public void setChassi(String chassi) {
        if (chassi != null && chassi.matches("\\d{17}")) {
            this.chassi = chassi;
        } else {
            throw new IllegalArgumentException("Chassi inválido");
        }
    }

    public int getRenavam() {
        return renavam;
    }

    public void setRenavam(int renavam) {
        String renavamStr = Integer.toString(renavam);
        if (renavam != 0 && renavamStr.length() == 11 && renavamStr.matches("\\d{11}")) {
            this.renavam = renavam;
        } else {
            throw new IllegalArgumentException("Renavam inválido. Deve conter exatamente 11 dígitos numéricos.");
        }
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        LocalDate current_date = LocalDate.now();
        int currentYear = current_date.getYear();
        if (ano >= 2000 && ano <= currentYear) { // Incluí o ano atual como válido
            this.ano = ano;
        } else {
            throw new IllegalArgumentException("Ano inválido. Deve estar entre 2000 e o ano atual.");
        }
    }

    public TipoTransmissao getTipo_transmissao() {
        return tipo_transmissao;
    }

    public void setTipo_transmissao(TipoTransmissao tipo_transmissao) {
        this.tipo_transmissao = tipo_transmissao;
    }

    public TipoCombustivel getTipo_combustivel() {
        return tipo_combustivel;
    }

    public void setTipo_combustivel(TipoCombustivel tipo_combustivel) {
        this.tipo_combustivel = tipo_combustivel;
    }

    public StatusVeiculo getStatus_veiculo() {
        return status_veiculo;
    }

    public void setStatus_veiculo(StatusVeiculo status_veiculo) {
        this.status_veiculo = status_veiculo;
    }

    protected void validarStringNaoVazia(String valor, String nomeCampo) {
        if (valor == null || valor.trim().isEmpty()) {
            throw new IllegalArgumentException("O campo " + nomeCampo + " não pode ser vazio ou em branco");
        }
    }

    // Método para marcar o veículo como alugado
    public void marcarComoAlugado() {
        this.status_veiculo = StatusVeiculo.ALUGADO;
    }

    // Método para marcar o veículo como disponível
    public void marcarComoDisponivel() {
        this.status_veiculo = StatusVeiculo.DISPONIVEL;
    }

    @Override
    public String toString() {
        return "Veiculo{"
                + "id='" + id + '\''
                + "placa='" + placa + '\''
                + ", chassi='" + chassi + '\''
                + ", renavam=" + renavam
                + ", ano=" + ano
                + ", tipoTransmissao=" + tipo_transmissao
                + ", tipoCombustivel=" + tipo_combustivel
                + ", statusVeiculo=" + status_veiculo
                + '}';
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, placa, chassi, renavam, ano, tipo_transmissao, tipo_combustivel, status_veiculo);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Veiculo veiculo = (Veiculo) obj;
        return renavam == veiculo.renavam
                && ano == veiculo.ano
                && Objects.equals(placa, veiculo.placa)
                && Objects.equals(chassi, veiculo.chassi)
                && tipo_transmissao == veiculo.tipo_transmissao
                && tipo_combustivel == veiculo.tipo_combustivel
                && status_veiculo == veiculo.status_veiculo;
    }
}

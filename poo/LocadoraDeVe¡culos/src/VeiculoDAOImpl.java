
import java.util.ArrayList;
import java.util.List;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public class VeiculoDAOImpl implements VeiculoDAO {

    private ArrayList<Veiculo> cadastroVeiculo = new ArrayList<>();

    @Override
    public boolean inserir(Veiculo veiculo) {
        // Verifica se já existe um veículo com a mesma placa
        for (Veiculo v : cadastroVeiculo) {
            if (v.getPlaca().equals(veiculo.getPlaca())) {
                return false; // Veículo já existe
            }
        }

        // Verifica o tipo de veículo para adicionar à lista específica
        if (veiculo instanceof Carro) {
            cadastroVeiculo.add((Carro) veiculo);
        } else if (veiculo instanceof Moto) {
            cadastroVeiculo.add((Moto) veiculo);
        } else if (veiculo instanceof Onibus) {
            cadastroVeiculo.add((Onibus) veiculo);
        } else {
            return false; // Tipo de veículo não reconhecido
        }

        return true; // Inserção bem-sucedida
    }

    @Override
    public boolean atualizar(Veiculo veiculo) {
        for (int i = 0; i < cadastroVeiculo.size(); i++) {
            if (cadastroVeiculo.get(i).getId() == veiculo.getId()) {
                cadastroVeiculo.set(i, veiculo);
                return true;
            }
        }
        return false; // Veículo não encontrado para atualização
    }

    @Override
    public boolean excluir(int id) {
        for (Veiculo veiculo : cadastroVeiculo) {
            if (veiculo.getId() == id) {
                cadastroVeiculo.remove(veiculo);
                return true;
            }
        }
        return false; // Veículo não encontrado para exclusão
    }

    @Override
    public Veiculo buscarPorId(int id) {
        for (Veiculo veiculo : cadastroVeiculo) {
            if (veiculo.getId() == id) {
                return veiculo;
            }
        }
        return null; // Veículo não encontrado
    }

    @Override
    public List<Veiculo> buscarTodos() {
        return cadastroVeiculo;
    }

    @Override
    public Veiculo buscarPorPlaca(String placa) {
        for (Veiculo veiculo : cadastroVeiculo) {
            if (veiculo.getPlaca().equals(placa)) {
                return veiculo;
            }
        }
        return null; // Veículo com a placa especificada não encontrado
    }

    @Override
    public List<Veiculo> buscarPorMarca(String marca) {
        List<Veiculo> veiculosPorMarca = new ArrayList<>();
        for (Veiculo veiculo : cadastroVeiculo) {
            if (veiculo instanceof Carro) {
                Carro carro = (Carro) veiculo;
                if (carro.getMarca().equals(marca)) {
                    veiculosPorMarca.add(carro);
                }
            } else if (veiculo instanceof Moto) {
                Moto moto = (Moto) veiculo;
                if (moto.getMarca().equals(marca)) {
                    veiculosPorMarca.add(moto);
                }
            } else if (veiculo instanceof Onibus) {
                Onibus onibus = (Onibus) veiculo;
                if (onibus.getMarca().equals(marca)) {
                    veiculosPorMarca.add(onibus);
                }
            }
        }
        return veiculosPorMarca;
    }

    @Override
    public List<Veiculo> buscarPorCategoria(CategoriaCarro categoria) {
        List<Veiculo> veiculosPorCategoria = new ArrayList<>();
        for (Veiculo veiculo : cadastroVeiculo) {
            if (veiculo instanceof Carro) {
                Carro carro = (Carro) veiculo;
                if (carro.getCategoria_carro() == categoria) {
                    veiculosPorCategoria.add(carro);
                }
            }
        }
        return veiculosPorCategoria;
    }

    @Override
    public List<Veiculo> buscarPorCambio(TipoTransmissao transmissao) {
        List<Veiculo> veiculosPorCambio = new ArrayList<>();
        for (Veiculo veiculo : cadastroVeiculo) {
            if (veiculo.getTipo_transmissao() == transmissao) {
                veiculosPorCambio.add(veiculo);
            }
        }
        return veiculosPorCambio;
    }
}

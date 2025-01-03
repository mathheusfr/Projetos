class Ninja
    # Definindo getter e setter usando attr_accessor
    attr_accessor :name
  
    def mostrar_nome
      puts "O nome do ninja é #{name}"
    end
  
    def jutsu
      puts "Jutsu clone das sombras"
    end
  end
  
  # Criando a instância
  ninja1 = Ninja.new
  
  # Atribuindo o nome para a instância
  ninja1.name = 'Naruto'
  
  # Chamando os métodos
  ninja1.mostrar_nome
  ninja1.jutsu
  
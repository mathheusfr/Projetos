class Ninja
    attr_accessor :nome, :idade
  
    def initialize(nome, idade)
      @nome = nome
      @idade = idade
    end
  end
  
  # Criando uma instância de Ninja
  ninja = Ninja.new("Hanzo", 32)
  
  # Acessando os atributos
  puts ninja.nome  # Output: Hanzo
  puts ninja.idade # Output: 32
  
  # Modificando os atributos
  ninja.nome = "Hattori"
  ninja.idade = 45
  
  puts ninja.nome  # Output: Hattori
  puts ninja.idade # Output: 45
  
class Person
    # Cria automaticamente os métodos getter e setter para o atributo `name`
    attr_accessor :name
    
    # Criando apenas o getter para o atributo `age`
    attr_reader :age
    
    # Criando apenas o setter para o atributo `location`
    attr_writer :location
  
    def initialize(name, age, location)
      @name = name
      @age = age
      @location = location
    end
  end
  
  person = Person.new("John", 30, "USA")
  
  # Usando o getter (acesso)
  puts person.name   # John
  
  # Usando o setter (modificação)
  person.name = "Alice"
  puts person.name   # Alice
  
  # Usando apenas o getter para `age`
  puts person.age    # 30
  
  # Usando apenas o setter para `location`
  person.location = "Canada"
  
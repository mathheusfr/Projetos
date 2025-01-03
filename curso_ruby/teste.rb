class Person
    attr_accessor :name
    
    # Cri
    def initialize(name)
      @name = name
    end
  end
  
  person = Person.new("Matheus")


class Account
  attr_accessor :balance
  
  private def initialize(balance)
    @balance = balance
  end
  
  # Método para adicionar valor ao balance
  def add_to_balance(amount)
    @balance += amount
  end
end

# Criando uma instância da classe Account
account = Account.new(100)

# Exibindo o saldo inicial
puts "Saldo inicial: #{account.balance}"  # Saída: 100

# Adicionando 50 ao saldo
account.add_to_balance(50)

# Exibindo o saldo após adicionar
puts "Saldo após adição: #{account.balance}"  # Saída: 150
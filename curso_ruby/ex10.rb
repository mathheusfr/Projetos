def potencia (firstNumber, secondNumber) 
    firstNumber ** secondNumber
end 


puts "Digite a base:"
firstNumber = gets.chomp.to_f

puts "Digite o expoente:"
secondNumber = gets.chomp.to_f

result = potencia(firstNumber, secondNumber);

print("O resultado e #{result}");




const casual = require('casual');

const generateRandomPerson = () => ({
  Nome: casual.first_name,
  Sobrenome: casual.last_name,
  Rua: casual.street,
  Cidade: casual.city,
  Pais: casual.country,
  CEP: casual.zip(5) // 5 dígitos para o CEP
});

const numberOfPeople = 10;
const randomPeople = Array.from({ length: numberOfPeople }, generateRandomPerson);

randomPeople.forEach((person, index) => {
  console.log(`Pessoa ${index + 1}:`);
  console.log(person);
  console.log('-----------------------');
});

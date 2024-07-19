const express = require('express');
const app = express();
const path = require('path');

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.get('/', (req, res) => {
  res.send("Bem vindo ao meu exercício!");
});

app.get('/nome/:nome', (req, res) => {
  const nome = req.params.nome;
  res.send(`Bem vindo(a) ${nome}!`);
});

app.get('/repetir/:mensagem/:quantidade', (req, res) => {
  const mensagem = req.params.mensagem;
  const quantidade = parseInt(req.params.quantidade);
  const repeticoes = new Array(quantidade).fill(mensagem).join(' ');
  res.send(repeticoes);
});

app.get('/som/:animal', (req, res) => {
  const animal = req.params.animal.toLowerCase();
  const sons = {
    cao: "O cachorro faz 'Auuu Auuu Auuu'.",
    gato: "O gato faz 'Miauuu'.",
    vaca: "A vaca faz 'Mooon'.",
    ovelha: "A ovelha faz 'Meeeee'.",
    cavalo: "O cavalo faz 'Rhiiiii'.",
  };
  const som = sons[animal] || "Animal desconhecido.";
  res.send(som);
});

app.get('/rep', (req, res) => {
  const mensagem = req.query.p;
  const quantidade = parseInt(req.query.q);
  const repeticoes = new Array(quantidade).fill(mensagem).join(' ');
  res.send(repeticoes);
});

app.get('*', (req, res) => {
  res.send("Página não encontrada!");
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});

const express = require('express');
const app = express();
const port = 3000;

app.set('view engine', 'ejs');

app.get('/palindromo', (req, res) => {
    const palavra = req.query.q || '';
    const palindromo = palavra.toLowerCase() === palavra.toLowerCase().split('').reverse().join('');
    res.render('palindromo', { palavra, palindromo });
});

app.listen(port, () => {
    console.log(`Servidor ligado na porta ${port}!`);
});

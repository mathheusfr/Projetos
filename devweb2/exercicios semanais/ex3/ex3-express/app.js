const express = require("express");
const app = express();
const path = require("path");

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

const sons = {
    Cao: "Auuu Auuu Auuu",
    Gato: "Miauuu",
    Vaca: "Moooon",
    Ovelha: "Meeeee",
    Cavalo: "Rhiiiii"
};

const imagens = {
    Cao: "https://t0.gstatic.com/licensed-image?q=tbn:ANd9GcQkrjYxSfSHeCEA7hkPy8e2JphDsfFHZVKqx-3t37E4XKr-AT7DML8IwtwY0TnZsUcQ",
    Gato: "https://i0.statig.com.br/bancodeimagens/0v/10/gk/0v10gkja6fccyqrxefzjaurpl.jpg",
    Vaca: "https://www.otempo.com.br/image/contentid/policy:1.2536791:1630682884/Vaca-louca-jpg.jpg",
    Ovelha: "https://www.marianebrezolin.com.br/wp-content/uploads/2020/08/DSC04353-2-1024x768.jpg",
    Cavalo: "https://cptstatic.s3.amazonaws.com/imagens/enviadas/materias/materia16043/caracteristicas-cavalos-saudaveis-artigos-cursos-cpt.jpg"
};

app.get('/', (req, res) => {
    res.render('home');
});

app.get('/nome/:nome', (req, res) => {
    const nome = req.params.nome;
    res.render('nome', { nome });
});

app.get('/repetir/:palavra/:vezes', (req, res) => {
    const { palavra, vezes } = req.params;
    const texto = Array(Number(vezes)).fill(palavra).join(' ');
    res.render('repetir', { texto });
});

app.get('/rep', (req, res) => {
    const { p, q } = req.query;
    const texto = Array(Number(q)).fill(p).join(' ');
    res.render('repetir', { texto });
});



app.listen(3000, () => {
    console.log("Servidor ligado na porta ");
})
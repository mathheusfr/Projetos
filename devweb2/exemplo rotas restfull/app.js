const express = require('express');
const methodOverride = require('method-override');
const app = express();

app.set('view engine', 'ejs');

app.use(express.urlencoded({extended: true}));
app.use(methodOverride('_method'));

let cursos = [
    {
        sigla: 'ADS',
        nome: 'Tecnologia em Análise e Desenvolvimento de Sistemas'
    },
    {
        sigla: 'TPG',
        nome: 'Tecnologia em Processos Gerenciais'
    },
];

app.get('/cursos', (req, res) => {
    res.render('cursos/index', {cursos});
});

app.get('/cursos/new', (req, res) => {
    res.render('cursos/new');
});

app.get('/cursos/:sigla', (req, res) => {
    const {sigla} = req.params;
    const curso = cursos.find(curso => curso.sigla == sigla);
    res.render('cursos/show', {curso});
});

app.post('/cursos', (req, res) => {
    const {sigla, nome} = req.body;
    cursos.push({sigla, nome});
    res.redirect('/cursos');
});

app.get('/cursos/:sigla/edit', (req, res) => {
    const {sigla} = req.params;
    const curso = cursos.find(curso => curso.sigla == sigla);
    res.render('cursos/edit', {curso});
});

app.patch('/cursos/:sigla', (req, res) => {
    const {sigla} = req.params;
    const novoNome = req.body.nome;
    const curso = cursos.find(curso => curso.sigla == sigla);
    curso.nome = novoNome;
    res.redirect('/cursos/' + sigla);
});

app.delete('/cursos/:sigla', (req, res) => {
    const {sigla} = req.params;
    cursos = cursos.filter(curso => curso.sigla != sigla);
    res.redirect('/cursos');
});


app.listen(3000, () => console.log("Servidor ligado na porta 3000!"));
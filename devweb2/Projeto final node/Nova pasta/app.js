const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();

const Posts = require('./Posts.js');

var session = require('express-session');

mongoose.connect('mongodb://127.0.0.1:27017/DbProjeto')
    .then(function () {
        console.log('Conectado com sucesso');
    }).catch(function (err) {
        console.log(err.message);
    });

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
    extended: true
}));

app.use(session({secret: 'keyboard cat', cookie: { maxAge: 6000}}));

app.engine('html', require('ejs').renderFile);
app.set('view engine', 'ejs');

app.use('/public', express.static(path.join(__dirname, 'public')));
app.set('views', path.join(__dirname, '/pages'));

app.get('/', async (req, res) => {
    try {
        if (req.query.busca == null) {
           // const posts = await Posts.find({}).sort({'_id': -1}).exec();
           //  console.log(posts[0]);
            res.render('home', {});
            

        } else if (req.query.busca === 'gremio') {
            res.render('gremio', {});

        } else if (req.query.busca === 'noticias') {
            res.render('noticias', {});

        } else if (req.query.busca === 'criar-post') {
            res.render('criar-post', {});

        } else if (req.query.busca === 'posts') {
            res.render('posts', {});
            
        } else {
            res.render('erro', {});
        }
    } catch (error) {
        console.error('Erro ao buscar posts:', error);
        res.send('Erro ao buscar posts');
        res.redirect('/');
    }
});

var usuarios = [
    {
        login: 'matheus',
        senha: '12345'
    }
]

app.post('/admin/login', (req, res) => {
    usuarios.map(function(val){
       if(val.login == req.body.login && val.senha == req.body.senha){
            req.session.login = "Matheus";
            
       }
    })
    res.redirect('/admin/login');
})

app.get('/admin/login',(req, res)=>{
    if (req.session.login == null) {
           res.render('admin-login');
    }else{
        res.render('admin-panel');
    }
})

app.listen(3000, () => {
    console.log('Server rodando!');
});

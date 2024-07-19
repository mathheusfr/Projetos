const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const path = require('path');

const expressSession = require('express-session')

const app = express();

const Posts = require('./Posts.js');

const User = require('./User');

var session = require('express-session');

app.use(expressSession({
    secret: 'meu segredo',
    cookie: { maxAge: 60000 },
    resave: false,  //
    saveUninitialized: false  // Defina a opção saveUninitialized como fals
}));

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

app.use(session({secret: 'keyboard cat', cookie: { maxAge: 60000}}));

app.engine('html', require('ejs').renderFile);
app.set('view engine', 'ejs');

app.use('/public', express.static(path.join(__dirname, 'public')));
app.set('views', path.join(__dirname, '/pages'));

app.get('/', async (req, res) => {
    try {
        if (req.query.busca == null) {
            let posts = await Posts.find({}).sort({'_id': -1}).exec();
             // console.log(posts[0]);
            
            res.render('home', {posts:posts});       

        } else if (req.query.busca === 'gremio') {
            res.render('gremio', {});
        
        } else if (req.query.busca == 'inter') {
            res.render('inter', {});

        } else if (req.query.busca === 'noticias') {
            let posts = await Posts.find({}).sort({'_id': -1}).exec();
            res.render('noticias', {posts:posts});             

        } else if (req.query.busca === 'criar-post') {
            res.render('criar-post', {});

        } else if (req.query.busca === 'posts') {
            res.render('posts', {});
       
        } else if (req.query.busca === 'register') {
            res.render('register');
        }else {
            res.render('erro', {});
        }
    } catch (error) {
        console.error('Erro ao buscar posts:', error);
        res.send('Erro ao buscar posts');
        res.redirect('/');
    }
});



app.get('/:slug', (req, res) => {
    Posts.findOneAndUpdate({ slug: req.params.slug }, { new: true })
        .then((resposta) => {
            console.log(resposta);
            res.render('single', { noticia: resposta });
        })
        .catch((err) => {
            console.error(err);
            res.status(500).send('Erro ao obter a notícia');
        });
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


app.get('/admin/login', async (req, res) => {
    if (req.session.login == null) {
      res.render('admin-login');
    } else {
      try {
        let posts = await Posts.find({}).sort({ '_id': -1 }).exec();
  
        posts = posts.map(function (val) {
          return {
            id: val._id,
            titulo: val.titulo,
            conteudo: val.conteudo,
            descricaoCurta: val.conteudo.substr(0, 100),
            imagem: val.imagem,
            slug: val.slug,
            categoria: val.categoria,
          };
        });
  
        res.render('admin-panel', { posts: posts });
      } catch (err) {
        console.error(err);
        res.status(500).send('Erro');
      }
    }
  });


    app.use(expressSession({
        secret: 'meu_segredo...',
        resave: false, 
        saveUninitialized: false
   }));








app.post('/admin/cadastro', (req, res) => {
    // inserir no banco 
    console.log(req.body);
    Posts.create({
        titulo: req.body.titulo_noticia,
        imagem: req.body.url_imagem,
        categoria: "Nenhuma",
        conteudo: req.body.noticia,
        slug: req.body.slug,
    })
    res.send("Cadastrado com sucesso");
})

app.get('/admin/deletar/:id',(req,res)=>{
    Posts.deleteOne({_id:req.params.id}).then(function(){
        res.redirect('/admin/login')
    });
})

app.post("/register", async (req, res) => {
    const { username, password } = req.body;

    try {
        // Verificar se o usuário já existe no banco de dados
        const existingUser = await User.findOne({ username });

        if (existingUser) {
            return res.render("register", { error: "Usuário já cadastrado" });
        }

        // Criar um novo usuário apenas com nome e senha
        const newUser = new User({ username, password });

        // Salvar o novo usuário no banco de dados
        await newUser.save();

        res.redirect("/login"); // Redirecionar para a página de login após o cadastro
    } catch (error) {
        console.error("Erro ao cadastrar usuário:", error);
        res.status(500).send("Erro ao cadastrar usuário");
    }
});



app.get("/secret", (req, res) => {
    res.render("secret");
})


app.listen(3000, () => {
    console.log('Server rodando!');
});

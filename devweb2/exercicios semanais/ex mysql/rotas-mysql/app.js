
app.set('view engine', 'ejs');

app.use(express.urlencoded({ extended: true }));
app.use(methodOverride('_method'));

connection.connect((err) => {
    if (err) {
        console.error('Erro ao conectar ao BD:', err);
    } else {
        console.log('Conectado com o BD!');
    }
});

app.get('/', (req, res) => {
    res.redirect('/curso');
});

app.get('/curso', (req, res) => {
    const sql = 'SELECT * FROM cursos';
    connection.query(sql, (err, cursos) => {
        if (err) {
            console.error('Erro ao executar a query:', err);
        } else {
            res.render('index', { cursos });
        }
    });
});

app.get('/curso/new', (req, res) => {
    res.render('new');
});

app.get('/curso/:id', (req, res) => {
    const { id } = req.params;
    const sql = 'SELECT * FROM cursos WHERE id = ?';
    connection.query(sql, id, (err, result) => {
        if (err) {
            console.error('Erro ao executar a query:', err);
        } else {
            res.render('show', { curso: result[0] });
        }
    });
});

app.post('/curso', (req, res) => {
    const sql = 'INSERT INTO cursos SET ?';
    connection.query(sql, req.body, (err) => {
        if (err) {
            console.error('Erro ao inserir dados:', err);
        } else {
            res.redirect('/curso');
        }
    });
});

app.get('/curso/:id/edit', (req, res) => {
    const { id } = req.params;
    const sql = 'SELECT * FROM cursos WHERE id = ?';
    connection.query(sql, id, (err, result) => {
        if (err) {
            console.error('Erro ao executar a query:', err);
        } else {
            res.render('edit', { curso: result[0] });
        }
    });
});

app.patch('/curso/:id', (req, res) => {
    const { id } = req.params;
    const sql = 'UPDATE cursos SET ? WHERE id = ?';
    connection.query(sql, [req.body, id], (err) => {
        if (err) {
            console.error('Erro ao atualizar dados:', err);
        } else {
            res.redirect(`/curso/${id}`);
        }
    });
});

app.delete('/curso/:id', (req, res) => {
    const { id } = req.params;
    const sql = 'DELETE FROM cursos WHERE id = ?';
    connection.query(sql, id, (err) => {
        if (err) {
            console.error('Erro ao excluir dados:', err);
        } else {
            res.redirect('/curso');
        }
    });
});
app.listen(3000, () => {
    console.log("Servidor ligado na porta 3000!")
})
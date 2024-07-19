const connection = require('./db.js');

connection.connect((err) => {
    if (err) {
        console.error(err);
    } else {
        console.log('Conectado com o BD!');
        createTableCursos();
    }
});

function createTableCursos() {
    let sql = 'CREATE TABLE IF NOT EXISTS cursos (id int AUTO_INCREMENT, sigla VARCHAR(16), nome VARCHAR(256), PRIMARY KEY(id))';
    connection.query(sql, (err) => {
        if (err) {
            console.error('Erro ao criar tabela cursos:', err);
        } else {
            console.log('Tabela cursos criada!');
            insertFirstCurso();
        }
    });
}

function insertFirstCurso() {
    let sigla = 'ADS';
    let nome = 'Tecnologia em Análise e Desenvolvimento de Sistemas';
    let sql = 'INSERT INTO cursos (sigla, nome) VALUES (?, ?)';
    connection.query(sql, [sigla, nome], (err) => {
        if (err) {
            console.error('Erro ao inserir primeiro curso:', err);
        } else {
            console.log('Primeiro curso gravado!');
            insertSecondCurso();
        }
    });
}

function insertSecondCurso() {
    let curso = { sigla: 'TPG', nome: 'Tecnologia em Processos Gerenciais' };
    let sql = 'INSERT INTO cursos SET ?';
    connection.query(sql, curso, (err) => {
        if (err) {
            console.error('Erro ao inserir segundo curso:', err);
        } else {
            console.log('Segundo curso gravado!');
            // Optionally close the database connection here if needed
            // connection.end();
        }
    });
}

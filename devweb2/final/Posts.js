var mongoose = require('mongoose');
var Schema  = mongoose.Schema;

var postSchema = new Schema({
    titulo: String,
    categoria: String,
    conteudo: String,
    imagem: String,
    slug: String
},{collection:'posts'})

var Posts = mongoose.model("Posts",postSchema);

module.exports = Posts;
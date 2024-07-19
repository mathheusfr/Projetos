var mongoose = require('mongoose');
var Schema  = mongoose.Schema;

var postSchema = new Schema({
    titulo: String,
    categoria: String,
    conteudo: String,
    imagem: String,
    slug: String
},{collection:'sec_posts'})

var SecPosts = mongoose.model("SecPosts",postSchema);

module.exports = SecPosts;
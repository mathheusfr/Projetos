const express = require("express")
const app = express();


app.set("view engine", 'ejs');

app.get("/home", (req,res) => {
    res.render("index");
})

app.listen(3000, () => {
    console.log(" Rodando no servidor, na porta 3000");
})

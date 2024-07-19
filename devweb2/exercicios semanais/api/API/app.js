const express = require('express');
const app = express();
const path = require('path');
const axios = require('axios'); // Importe o módulo axios
//const { translate } = require('bing-translate-api');
const { translate } = require('free-translate');

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.static(path.join(__dirname, 'public')));



app.get('/', (req, res) => {
    res.render('form');
});

app.get('/busca', async (req, res) => {
    const { cidade, uf } = req.query;

    try {
        const response = await axios.get(`http://api.openweathermap.org/geo/1.0/direct?q=${cidade},${uf},Brasil&limit=1&appid=768aafb4ec5342436194116852fa1bd4`);
        
        const resposta = response.data;
        
        if (resposta.length > 0) {
            //const id = resposta[0].id;
            const lat = resposta[0].lat;
            const lon = resposta[0].lon;

            console.log(resposta);
          
            console.log(`Longitute: ${resposta[0].lon}, latitude: ${resposta[0].lat}`);

                const responseWather = await axios.get("https://api.openweathermap.org/data/2.5/weather?lat=" + lat + "&lon=" + lon + "&appid=768aafb4ec5342436194116852fa1bd4");

                console.log("LINK: https://api.openweathermap.org/data/2.5/weather?lat=" + lat + "&lon=" + lon + "&appid=768aafb4ec5342436194116852fa1bd4");

                const respostaWather = responseWather.data;
                             
                console.log("JSON: ", respostaWather);
                console.log("Situação: ", respostaWather.weather[0].description);

                const situacao = respostaWather.weather[0].description;

                const nomeCidade = respostaWather.name;

                const tempMax = respostaWather.main.temp_max;
                const tempMin = respostaWather.main.temp_min;
                const windSpeed = respostaWather.wind.speed;


                var temperaturaMax = tempMax - 273.15;
                const temperaturaMaxFixed = temperaturaMax.toFixed(2);

                var temperaturaMin = tempMin - 273.15
                const temperaturaMinFixed = temperaturaMin.toFixed(2);
                var vento = windSpeed * 3.6;

                console.log("cidade: ", nomeCidade);
                console.log("Temperatura maxima: ", temperaturaMax.toFixed(2));
                console.log("Temperatura minima: ", temperaturaMin.toFixed(2))
                console.log("Veloc. vento: ", vento);

                /*translate(`${situacao}`, null, 'pt').then(res => {

                    console.log(res.translation);

                  })*/
                  
                  const { translate } = require('free-translate');

                (async () => {
                const translatedText = await translate(`${situacao}`, { from: 'en', to: 'pt' });

                console.log(translatedText); 

                res.render("resultado", {
                    situacao: translatedText, 
                    nomeCidade, 
                    temperaturaMax: temperaturaMaxFixed, 
                    temperaturaMin: temperaturaMinFixed, 
                    vento
                })

                })();
                


        } else {
            console.log("Cidade não encontrada");
        }

        //res.render('resultadoBusca', { resposta });
    } catch (error) {
        console.log("Erro ao fazer a requisição na API", error);
    }
});

app.listen(3000, () => console.log("Servidor ligado na porta 3000!"));

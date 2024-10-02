$(document).ready(function(){
    $('.sliderR').slick({
        dots: true, /* Mostra os indicadores de navegação */
        infinite: true, /* Loop infinito */
        speed: 500, /* Velocidade da transição */
        slidesToShow: 3, /* Número de slides exibidos por vez */
        slidesToScroll: 1, /* Número de slides rolados por vez */
        centerMode: false, /* Desative o modo centralizado */
        rows: 1 /* Garante que os slides estejam em uma única linha */
    });

    
});


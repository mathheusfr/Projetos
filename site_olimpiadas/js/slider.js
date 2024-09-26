$(function(){
    var curlSlide = 0;
    var maxSlide = $('.banner-single').length - 1;
    var delay = 3; // Tempo de exibição de cada slide em segundos
    var interval;

    // Função para inicializar o slider
    function initSlider(){
        $('.banner-single').hide(); // Esconde todos os slides
        $('.banner-single').eq(0).css('display', 'block'); // Mostra o primeiro slide
        $('.bullets span').eq(0).addClass('active-slider'); // Adiciona a classe ativa ao primeiro bullet
    }

    // Função para iniciar o slider automaticamente
    function startSlider(){
        interval = setInterval(function() {
            nextSlide();
        }, delay * 1000); // Define o intervalo para mudança dos slides
    }

    // Função para ir ao próximo slide
    function nextSlide(){
        $('.banner-single').eq(curlSlide).fadeOut(2000); // Fade out do slide atual
        $('.bullets span').eq(curlSlide).removeClass('active-slider'); // Remove a classe ativa do bullet atual
        curlSlide = (curlSlide + 1) % (maxSlide + 1); // Atualiza o índice do slide
        $('.banner-single').eq(curlSlide).fadeIn(2000); // Fade in do próximo slide
        $('.bullets span').eq(curlSlide).addClass('active-slider'); // Adiciona a classe ativa ao novo bullet
    }

    // Função para clicar nos bullets e mudar de slide
    $('.bullets span').click(function(){
        clearInterval(interval); // Para o slider automático
        var index = $(this).index(); // Pega o índice do bullet clicado
        if(index != curlSlide){
            $('.banner-single').eq(curlSlide).fadeOut(2000); // Fade out do slide atual
            $('.bullets span').eq(curlSlide).removeClass('active-slider'); // Remove a classe ativa do bullet atual
            curlSlide = index; // Atualiza o slide atual
            $('.banner-single').eq(curlSlide).fadeIn(2000); // Fade in do novo slide
            $('.bullets span').eq(curlSlide).addClass('active-slider'); // Adiciona a classe ativa ao novo bullet
        }
        startSlider(); // Reinicia o slider automático
    });

    // Pré-carregamento das imagens e inicialização do slider
    $(window).on('load', function(){
        $('.banner-single').each(function(){
            $(this).css('background-image', $(this).css('background-image'));
        });
        initSlider(); // Inicializa o slider
        startSlider(); // Inicia o slider automático
    });
});

$(function(){

    $('nav.mobile').click(function(){
        var ListaMenu = $('nav.mobile ul');
        if(ListaMenu.is(':hidden') == true) {
            ListaMenu.fadeIn();
        }
        else {
            ListaMenu.fadeOut();
        }
    })

    $(document).ready(function() {
        $('nav a').click(function(e) {
            e.preventDefault(); // Evita o comportamento padrão do link
    
            var href = $(this).attr('href');
            var target = href.split('/').pop(); // Pega a última parte da URL
    
            if (target === 'depoimentos' || target === 'servicos') {
                $('target').attr('target', target); // Define o atributo target com base no link clicado
                
                if ($('target').length > 0) {
                    // O elemento existe, então precisamos dar o scroll
                    var elemento = '#' + $('target').attr('target');
                    var divScroll = $(elemento).offset().top;
    
                    $('html,body').animate({scrollTop: divScroll}, 2000);
                }
            } else {
                window.location.href = href; // Redireciona normalmente se não for depoimentos ou serviços
            }
        });
    });
    
})
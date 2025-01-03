module ImpresaoDecorada
    def self.imprimir(text)
        decoracao = '#' * 100
        puts decoracao
        puts text
        puts decoracao
    end
end


ImpresaoDecorada.imprimir("Matheus")
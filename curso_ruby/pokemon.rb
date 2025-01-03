module ImpresaoDecorada
    def self.imprimir(text)
        decoracao = '#' * 100
        puts decoracao
        puts text
        puts decoracao
    end
end

module Attack
    include ImpresaoDecorada

    def FireAttack
        if self.name == "Charmander"
            ImpresaoDecorada.imprimir("Flame of the Dragon")
        else 
            ImpresaoDecorada.imprimir("The pokemon don't have the power");
        end
    end

    def BallOfFire
        ImpresaoDecorada.imprimir("Ball of the Fire")
    end
end

module CriarPokemon
    class Pokemon
        include Attack  

        attr_accessor :name
        
        def getterName
            @name
        end

        def ShowName
            ImpresaoDecorada.imprimir("The pokemen name is #{@name}")
        end
    end
end

Pokemon1 = CriarPokemon::Pokemon.new
Pokemon1.name = "Pikachu"

Pokemon1.ShowName 
Pokemon1.FireAttack  

Pokemon2 = CriarPokemon::Pokemon.new
Pokemon2.name = "Infernape"

Pokemon2.ShowName
Pokemon2.FireAttack
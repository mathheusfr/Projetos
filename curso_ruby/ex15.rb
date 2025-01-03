class Animal 
   def pular
        print "Toin Toin"
   end 

   def dormir 
        print "zzzzzz"
   end

end


class Cachorro < Animal 
    def latir
        puts "Au Au"
    end
end

cao = Cachorro.new


cao.pular
cao.dormir
cao.latir




module ReverseWorld
    def self.puts(text)
        Kernel::puts text.reverse.to_s
    end
end

ReverseWorld::puts "O resultado é"
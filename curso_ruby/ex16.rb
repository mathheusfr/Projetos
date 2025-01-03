class Animal
    def speak
      'Some generic sound'
    end
  end
  
  class Dog < Animal
    def speak
      'Woof!'
    end
  end
  
  class Cat < Animal
    def speak
      'Meow!'
    end
  end
  
  def animal_sound(animal)
    puts animal.speak
  end
  
  dog = Dog.new
  cat = Cat.new
  animal_sound(dog)  # Saída: Woof!
  animal_sound(cat)  # Saída: Meow!
  
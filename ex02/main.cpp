#include "Dog.hpp"
#include "Cat.hpp"

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // Intentar instanciar Animal directamente (debería fallar en compilación)
    //Animal animal; // Esto no debería compilar, ya que AAnimal es abstracta

    const int ARRAY_SIZE = 4; // Tamaño del arreglo para simplicidad
    Animal* animals[ARRAY_SIZE];

    // Llenar la primera mitad con Dogs
    std::cout << "\nCreando Dogs:\n";
    for (int i = 0; i < ARRAY_SIZE / 2; ++i)
    {
        animals[i] = new Dog();
    }

    // Llenar la segunda mitad con Cats
    std::cout << "\nCreando Cats:\n";
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
    {
        animals[i] = new Cat();
    }

    // Mostrar tipo, sonidos e ideas de los cerebros
    std::cout << "\nMostrando información de los animales:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
        if (animals[i]->getType() == "Dog")
        {
            Dog* dog = dynamic_cast<Dog*>(animals[i]);
            if (dog)
                std::cout << "Idea en el cerebro: " << dog->getBrain()->getIdea(0) << std::endl;
        }
        else if (animals[i]->getType() == "Cat")
        {
            Cat* cat = dynamic_cast<Cat*>(animals[i]);
            if (cat)
                std::cout << "Idea en el cerebro: " << cat->getBrain()->getIdea(0) << std::endl;
        }
    }

    // Probar copia profunda de un Dog y un Cat
    std::cout << "\nProbando copia profunda:\n";
    Dog* dogOriginal = new Dog();
    Dog* dogCopy = new Dog(*dogOriginal);
    std::cout << "Idea del Dog original: " << dogOriginal->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea del Dog copiado: " << dogCopy->getBrain()->getIdea(0) << std::endl;
    dogOriginal->getBrain()->setIdea(0, "I want to chase a ball");
    std::cout << "Modificando idea del Dog original: " << dogOriginal->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea del Dog copiado (sin cambios): " << dogCopy->getBrain()->getIdea(0) << std::endl;

    Cat* catOriginal = new Cat();
    Cat* catCopy = new Cat(*catOriginal);
    std::cout << "Idea del Cat original: " << catOriginal->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea del Cat copiado: " << catCopy->getBrain()->getIdea(0) << std::endl;
    catOriginal->getBrain()->setIdea(0, "I want to sleep");
    std::cout << "Modificando idea del Cat original: " << catOriginal->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea del Cat copiado (sin cambios): " << catCopy->getBrain()->getIdea(0) << std::endl;

    // Eliminar copias
    std::cout << "\nEliminando copias:\n";
    delete dogOriginal;
    delete dogCopy;
    delete catOriginal;
    delete catCopy;

    // Eliminar todos los animales del arreglo
    std::cout << "\nEliminando animales del arreglo:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        delete animals[i];
    }

    return 0;
}
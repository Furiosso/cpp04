#include "Animal.hpp"  // Incluye tus headers: Animal.hpp, Dog.hpp, Cat.hpp, WrongAnimal.hpp, WrongCat.hpp
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Prueba 1: Replicación del main del ejercicio (polimorfismo correcto) ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "Tipo de Dog: " << j->getType() << std::endl;  // Debe imprimir "Dog"
        std::cout << "Tipo de Cat: " << i->getType() << std::endl;  // Debe imprimir "Cat"

        i->makeSound();  // Debe imprimir sonido de Cat (ej. "Miau!")
        j->makeSound();  // Debe imprimir sonido de Dog (ej. "Guau!")
        meta->makeSound();  // Debe imprimir sonido genérico de Animal

        // Liberar memoria y verificar destructores
        delete meta;  // Debe mostrar destructor de Animal
        delete j;     // Debe mostrar destructor de Dog (y Animal si es virtual)
        delete i;     // Debe mostrar destructor de Cat (y Animal si es virtual)
    }

    std::cout << "\n=== Prueba 2: Polimorfismo con referencias (correcto) ===" << std::endl;
    {
        Dog dog;
        Cat cat;
        Animal& refDog = dog;
        Animal& refCat = cat;

        std::cout << "Tipo via referencia Dog: " << refDog.getType() << std::endl;  // "Dog"
        std::cout << "Tipo via referencia Cat: " << refCat.getType() << std::endl;  // "Cat"

        refDog.makeSound();  // Sonido de Dog
        refCat.makeSound();  // Sonido de Cat

        // Los destructores se llaman automáticamente al salir del scope
    }

    std::cout << "\n=== Prueba 3: Fallo del polimorfismo con WrongAnimal y WrongCat ===" << std::endl;
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << "Tipo de WrongCat: " << wrongCat->getType() << std::endl;  // Debe imprimir "WrongCat" (atributo inicializado)

        wrongCat->makeSound();    // Debe imprimir sonido de WrongAnimal (no de WrongCat, por ligadura estática)
        wrongMeta->makeSound();   // Sonido de WrongAnimal

        delete wrongMeta;  // Destructor de WrongAnimal
        delete wrongCat;   // Destructor de WrongCat (y WrongAnimal si es virtual)
    }

    std::cout << "\n=== Prueba 4: Fallo con referencias en WrongAnimal ===" << std::endl;
    {
        WrongCat wrongCatObj;
        WrongAnimal& refWrongCat = wrongCatObj;

        std::cout << "Tipo via referencia WrongCat: " << refWrongCat.getType() << std::endl;  // "WrongCat"

        refWrongCat.makeSound();  // Debe imprimir sonido de WrongAnimal (ligadura estática)
    }

    std::cout << "\n=== Prueba 5: Arreglo de punteros (polimorfismo masivo correcto) ===" << std::endl;
    {
        const int numAnimals = 4;
        Animal* animals[numAnimals] = {
            new Dog(),
            new Cat(),
            new Dog(),
            new Animal()
        };

        for (int k = 0; k < numAnimals; ++k) {
            std::cout << "Tipo " << k << ": " << animals[k]->getType() << std::endl;
            animals[k]->makeSound();  // Debe ejecutar el sonido correcto según el tipo real
        }

        // Liberar arreglo
        for (int k = 0; k < numAnimals; ++k) {
            delete animals[k];  // Verificar destructores virtuales
        }
    }

    std::cout << "\n=== Prueba 6: Arreglo de punteros (fallo en WrongAnimal) ===" << std::endl;
    {
        const int numWrong = 3;
        WrongAnimal* wrongAnimals[numWrong] = {
            new WrongCat(),
            new WrongCat(),
            new WrongAnimal()
        };

        for (int k = 0; k < numWrong; ++k) {
            std::cout << "Tipo Wrong " << k << ": " << wrongAnimals[k]->getType() << std::endl;
            wrongAnimals[k]->makeSound();  // Todos deben ejecutar sonido de WrongAnimal
        }

        // Liberar arreglo
        for (int k = 0; k < numWrong; ++k) {
            delete wrongAnimals[k];
        }
    }

    std::cout << "\n=== Prueba 7: Verificación de slicing (pérdida de polimorfismo) ===" << std::endl;
    {
        Dog dogObj;
        Animal sliced = dogObj;  // Copia por valor: slicing

        std::cout << "Tipo sliced: " << sliced.getType() << std::endl;  // Debe ser "Animal" o vacío (pérdida de "Dog")
        sliced.makeSound();  // Debe ejecutar sonido de Animal (no de Dog)
    }

    std::cout << "\n=== Prueba 8: Objetos locales (sin new/delete) ===" << std::endl;
    {
        Animal localAnimal;
        Dog localDog;
        Cat localCat;

        localAnimal.makeSound();  // Sonido de Animal
        localDog.makeSound();     // Sonido de Dog
        localCat.makeSound();     // Sonido de Cat

        // Destructores automáticos al salir del scope
    }

    std::cout << "\n=== Prueba 9: Verificación de const-correctness ===" << std::endl;
    {
        const Dog constDog;
        const Animal* constPtr = &constDog;

        std::cout << "Tipo const: " << constPtr->getType() << std::endl;  // "Dog"
        constPtr->makeSound();  // Sonido de Dog (método const)
    }

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
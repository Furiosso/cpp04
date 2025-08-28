#include "Dog.hpp"
#include "Cat.hpp"

// Función auxiliar para verificar la copia profunda
void checkDeepCopy(const Dog& original, const Dog& copy, const std::string& testName)
{
    std::cout << testName << " - Original Brain ptr: " << original.getBrain() << std::endl;
    std::cout << testName << " - Copy Brain ptr: " << copy.getBrain() << std::endl;
    if (original.getBrain() != copy.getBrain())
        std::cout << testName << " - Brain pointers are different (good)" << std::endl;
    else
        std::cout << testName << " - ERROR: Brain pointers are the same (shallow copy)" << std::endl;
}

void checkDeepCopy(const Cat& original, const Cat& copy, const std::string& testName)
{
    std::cout << testName << " - Original Brain ptr: " << original.getBrain() << std::endl;
    std::cout << testName << " - Copy Brain ptr: " << copy.getBrain() << std::endl;
    if (original.getBrain() != copy.getBrain())
        std::cout << testName << " - Brain pointers are different (good)" << std::endl;
    else
        std::cout << testName << " - ERROR: Brain pointers are the same (shallow copy)" << std::endl;
}

int main()
{
    // Test 1: Prueba básica de creación y destrucción (como en el enunciado)
    std::cout << "\n=== Test 1: Creación y destrucción básica ===\n";
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << "Dog type: " << j->getType() << std::endl;
        std::cout << "Cat type: " << i->getType() << std::endl;
        j->makeSound(); // Debe imprimir "WOOF-WOOF"
        i->makeSound(); // Debe imprimir "MEOW"
        delete j; // Debe llamar a ~Dog y ~Brain
        delete i; // Debe llamar a ~Cat y ~Brain
    }

    // Test 2: Array de Animal con mitad Dog y mitad Cat
    std::cout << "\n=== Test 2: Crear arreglo de animales como se indica en el enunciado ===\n";
    const int ARRAY_SIZE = 4; // Tamaño pequeño para simplicidad
    Animal* animals[ARRAY_SIZE];

    // Llenar la primera mitad con Dogs
    for (int i = 0; i < ARRAY_SIZE / 2; ++i)
    {
        animals[i] = new Dog();
    }

    // Llenar la segunda mitad con Cats
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
    {
        animals[i] = new Cat();
    }

    // Mostrar las ideas de los cerebros y sonidos de los animales
    std::cout << "\nMostrando ideas y sonidos de los animales:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
        // Acceder al cerebro según el tipo de animal
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

    // Eliminar todos los animales
    std::cout << "\nEliminando animales:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        delete animals[i];
    }

    // Test 3: Prueba de copia profunda para Dog
    std::cout << "\n=== Test 3: Copia profunda de Dog ===\n";
    {
        Dog original;
        Dog copy(original); // Constructor de copia
        checkDeepCopy(original, copy, "Dog Copy Constructor");
    }

    // Test 4: Prueba de copia profunda para Cat
    std::cout << "\n=== Test 4: Copia profunda de Cat ===\n";
    {
        Cat original;
        Cat copy(original); // Constructor de copia
        checkDeepCopy(original, copy, "Cat Copy Constructor");
    }

    // Test 5: Prueba de asignación para Dog
    std::cout << "\n=== Test 5: Asignación de Dog ===\n";
    {
        Dog dog1, dog2;
        dog2 = dog1; // Operador de asignación
        checkDeepCopy(dog1, dog2, "Dog Assignment");
    }

    // Test 6: Prueba de asignación para Cat
    std::cout << "\n=== Test 6: Asignación de Cat ===\n";
    {
        Cat cat1, cat2;
        cat2 = cat1; // Operador de asignación
        checkDeepCopy(cat1, cat2, "Cat Assignment");
    }

    // Test 7: Prueba de autoasignación
    std::cout << "\n=== Test 7: Autoasignación ===\n";
    {
        Dog dog;
        dog = dog; // Autoasignación
        std::cout << "Dog auto-assignment: Type remains " << dog.getType() << std::endl;

        Cat cat;
        cat = cat; // Autoasignación
        std::cout << "Cat auto-assignment: Type remains " << cat.getType() << std::endl;
    }

    // Test 8: Prueba de polimorfismo con array dinámico
    std::cout << "\n=== Test 8: Polimorfismo con array dinámico ===\n";
    {
        Animal* animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
        for (int i = 0; i < 4; ++i)
        {
            animals[i]->makeSound(); // Debe alternar entre "WOOF-WOOF" y "MEOW"
            delete animals[i]; // Debe llamar a los destructores correctos
        }
    }

    // Test 9: Prueba de copia profunda a través de Animal*
    std::cout << "\n=== Test 9: Copia profunda a través de Animal* ===\n";
    {
        Animal* original = new Dog();
        Animal* copy = new Dog(*(Dog*)original);
        Dog* originalDog = dynamic_cast<Dog*>(original);
        Dog* copyDog = dynamic_cast<Dog*>(copy);
        if (originalDog && copyDog)
            checkDeepCopy(*originalDog, *copyDog, "Polymorphic Dog Copy");
        else
            std::cout << "ERROR: Dynamic cast failed" << std::endl;
        delete original;
        delete copy;
    }

    // Test 10: Prueba de copia profunda con ideas (si Brain tiene setIdea/getIdea)
    std::cout << "\n=== Test 10: Copia profunda con ideas ===\n";
    {
        Dog original;
        original.getBrain()->setIdea(0, "Original Dog Idea");
        Dog copy = original;
        copy.getBrain()->setIdea(0, "Copied Dog Idea");

        std::cout << "Original Dog Idea[0]: " << original.getBrain()->getIdea(0) << std::endl; // Debe ser "Original Dog Idea"
        std::cout << "Copy Dog Idea[0]: " << copy.getBrain()->getIdea(0) << std::endl; // Debe ser "Copied Dog Idea"

        Cat originalCat;
        originalCat.getBrain()->setIdea(0, "Original Cat Idea");
        Cat copyCat = originalCat;
        copyCat.getBrain()->setIdea(0, "Copied Cat Idea");

        std::cout << "Original Cat Idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl; // Debe ser "Original Cat Idea"
        std::cout << "Copy Cat Idea[0]: " << copyCat.getBrain()->getIdea(0) << std::endl; // Debe ser "Copied Cat Idea"
    }

    std::cout << "\n=== Fin de las pruebas ===\n";
    return 0;
}
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
    std::cout << "=== Test 1: Creación básica de Materias y comprobación de tipos ===" << std::endl;
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    std::cout << "Tipo de Ice: " << ice->getType() << " (esperado: ice)" << std::endl;
    std::cout << "Tipo de Cure: " << cure->getType() << " (esperado: cure)" << std::endl;

    std::cout << "=== Test 2: Clonación de Materias ===" << std::endl;
    AMateria* iceClone = ice->clone();
    AMateria* cureClone = cure->clone();
    std::cout << "Tipo de Ice clone: " << iceClone->getType() << " (esperado: ice)" << std::endl;
    std::cout << "Tipo de Cure clone: " << cureClone->getType() << " (esperado: cure)" << std::endl;

    std::cout << "=== Test 3: Creación de MateriaSource y aprendizaje de Materias ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(ice->clone());
    src->learnMateria(cure->clone());
    AMateria* extra = new Ice();
    src->learnMateria(extra);

    std::cout << "=== Test 4: Creación de Materias desde MateriaSource ===" << std::endl;
    AMateria* createdIce = src->createMateria("ice");
    AMateria* createdCure = src->createMateria("cure");
    AMateria* unknown = src->createMateria("unknown");
    std::cout << "Creado Ice: " << (createdIce ? createdIce->getType() : "0") << " (esperado: ice)" << std::endl;
    std::cout << "Creado Cure: " << (createdCure ? createdCure->getType() : "0") << " (esperado: cure)" << std::endl;
    std::cout << "Creado unknown: " << (unknown ? unknown->getType() : "0") << " (esperado: 0)" << std::endl;

    std::cout << "=== Test 5: Creación de Characters y equipamiento ===" << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    me->equip(createdIce);
    me->equip(createdCure);
    me->equip(iceClone);
    me->equip(cureClone);
    AMateria* overflow = new Ice();
    me->equip(overflow);
    delete overflow;

    std::cout << "=== Test 6: Uso de Materias ===" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(-1, *bob);

    std::cout << "=== Test 7: Desequipamiento ===" << std::endl;
    AMateria* savedIce = createdIce;
    AMateria* savedCure = createdCure;
    AMateria* savedIceClone = iceClone;
    AMateria* savedCureClone = cureClone;
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->unequip(5);
    me->use(0, *bob);
    me->equip(savedIce);
    me->equip(savedCure);

    std::cout << "=== Test 8: Copia profunda de Character ===" << std::endl;
    Character* copy = new Character(*static_cast<Character*>(me));
    copy->use(0, *bob);
    copy->use(1, *bob);

    std::cout << "=== Test 9: Asignación de Character ===" << std::endl;
    Character* assign = new Character("assign");
    *assign = *copy;
    assign->use(0, *bob);
    assign->use(1, *bob);

    std::cout << "=== Test 10: Gestión de memoria y limpieza ===" << std::endl;
    delete bob;
    delete me;
    delete copy;
    delete assign;
    delete src;
    delete ice;
    delete cure;
    delete savedIceClone;
    delete savedCureClone;

    std::cout << "Tests completados" << std::endl;
    return 0;
}
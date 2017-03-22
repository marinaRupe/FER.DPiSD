#include <malloc.h>
#include "animals.h"

typedef char const* (*PTRFUN)();

typedef struct Animal {
    char const* name;
    PTRFUN* vtable;
} Animal;

PTRFUN DogVTable[2] = {
        (PTRFUN)dogGreet,
        (PTRFUN)dogMenu
};
PTRFUN CatVTable[2] = {
        (PTRFUN)catGreet,
        (PTRFUN)catMenu
};

void testAnimals(void){
    struct Animal* p1=createDog("Hamlet");
    struct Animal* p2=createCat("Ofelija");
    struct Animal* p3=createDog("Polonije");

    animalPrintGreeting(p1);
    animalPrintGreeting(p2);
    animalPrintGreeting(p3);

    animalPrintMenu(p1);
    animalPrintMenu(p2);
    animalPrintMenu(p3);

    free(p1); free(p2); free(p3);
}

struct Animal* createDog(char const* name) {
    struct Animal* dog = malloc(sizeof(struct Animal));
    constructDog(dog, name);
    return dog;
}

struct Animal* createCat(char const* name) {
    struct Animal* cat = malloc(sizeof(struct Animal));
    constructCat(cat, name);
    return cat;
}

void constructDog(struct Animal* dog, char const* name) {
    dog->name = name;
    dog->vtable = DogVTable;
}

void constructCat(struct Animal* cat, char const* name) {
    cat->name = name;
    cat->vtable = CatVTable;
}

char const* dogGreet(void){
    return "vau!";
}
char const* dogMenu(void){
    return "kuhanu govedinu";
}
char const* catGreet(void){
    return "mijau!";
}
char const* catMenu(void){
    return "konzerviranu tunjevinu";
}
void animalPrintGreeting(struct Animal* animal) {
    printf("%s pozdravlja: %s\n", animal->name, animal->vtable[0]());
}
void animalPrintMenu(struct Animal* animal) {
    printf("%s voli %s\n", animal->name, animal->vtable[1]());
}
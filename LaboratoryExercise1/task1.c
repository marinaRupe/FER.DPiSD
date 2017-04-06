#include <malloc.h>

typedef char const* (*PTRFUN)();

typedef struct {
    PTRFUN* vtable;
    char const* name;
} Animal;

typedef struct {
    PTRFUN* vtable;
    char const* name;
} Dog;

typedef struct {
    PTRFUN* vtable;
    char const* name;
} Cat;


//  Class Dog

char const* dogGreet(void) { return "vau!"; }
char const* dogMenu(void) { return "kuhanu govedinu"; }

PTRFUN DogVTable[2] = {
        (PTRFUN)dogGreet,
        (PTRFUN)dogMenu
};

void constructDog(Animal* dog, char const* name) {
    dog->name = name;
    dog->vtable = DogVTable;
}

Animal* createDog(char const* name) {
    Animal* dog = (Animal*) malloc(sizeof(Dog));
    constructDog(dog, name);
    return dog;
}


//  Class Cat

char const* catGreet(void) { return "mijau!"; }
char const* catMenu(void) { return "konzerviranu tunjevinu"; }

PTRFUN CatVTable[2] = {
        (PTRFUN)catGreet,
        (PTRFUN)catMenu
};

void constructCat(Animal* cat, char const* name) {
    cat->name = name;
    cat->vtable = CatVTable;
}

Animal* createCat(char const* name) {
    Animal* cat = (Animal*) malloc(sizeof(Cat));
    constructCat(cat, name);
    return cat;
}

//

void animalPrintGreeting(Animal* animal) {
    printf("%s pozdravlja: %s\n", animal->name, animal->vtable[0]());
}
void animalPrintMenu(Animal* animal) {
    printf("%s voli %s\n", animal->name, animal->vtable[1]());
}

Animal** createDogs(int n) {
    Animal** dogs = (Animal**) malloc (n * sizeof(Dog*));
    static char str[10][10];
    for (int i = 0; i < n; i++) {
        sprintf(str[i], "Peso_%d", i + 1);
        Animal* d = createDog(str[i]);
        dogs[i] = d;
    }
    return dogs;
}

void destroyDogs(Dog** dogs, int n) {
    for (int i = 0; i < n; i++) {
        free(dogs[i]);
    }
    free(dogs);
}

void testAnimals(void){
    Animal* p1 = createDog("Hamlet");
    Animal* p2 = createCat("Ofelija");
    Animal* p3 = createDog("Polonije");

    animalPrintGreeting(p1);
    animalPrintGreeting(p2);
    animalPrintGreeting(p3);

    animalPrintMenu(p1);
    animalPrintMenu(p2);
    animalPrintMenu(p3);

    free(p1); free(p2); free(p3);

    printf("\n");

    Animal p4;
    constructDog(&p4, "Floki");
    animalPrintGreeting(&p4);
    animalPrintMenu(&p4);

    /*
    printf("\n");

    int N = 10;
    Animal** dogs = createDogs(N);
    for (int i = 0; i < N; i++) {
        Animal* dog = dogs[i];
        animalPrintGreeting(dog);
        animalPrintMenu(dog);
    }
    destroyDogs((Dog **)dogs, N);
     */
}

int main1(void) {
    testAnimals();
    return 0;
}
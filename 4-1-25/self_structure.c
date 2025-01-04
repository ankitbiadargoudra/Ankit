#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    struct Person *self;
};

int main() {
    struct Person person;

    person.name = (char *)malloc( sizeof(char));
    strcpy(person.name, "Ankit Biradargoudra");
    person.age = 22;
    person.self = &person;

    printf("Name: %s\n", person.name); /* accesing variable using structre name directly*/
    printf("Age: %d\n", person.age);
    printf("Self Name: %s\n", person.self->name); /* accessing structure using pointer goes with ->*/

    free(person.name);
    return 0;
}

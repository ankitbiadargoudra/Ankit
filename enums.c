#include <stdio.h>

enum Weekday {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {
    enum Weekday today = Wednesday;
    printf("%d\n", today);
    return 0;
}

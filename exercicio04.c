#include <stdio.h>
struct date {
    int day;
    int month;
    int year;
};

int main() {
    struct date today;
    today.day = 1;
    today.month = 1;
    today.year = 2023;

    printf("Date: %02d/%02d/%04d\n", today.day, today.month, today.year);
    return 0;
}

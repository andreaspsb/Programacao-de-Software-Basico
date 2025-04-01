#include <stdio.h>
typedef struct {
    int day;
    int month;
    int year;
} Date;

void dateFormat1(Date data, char str[]) {
    sprintf(str, "%02d/%02d/%04d", data.day, data.month, data.year);
}

void scanDate(Date *data) {
    printf("Digite a data (dd mm aaaa): ");
    scanf("%d %d %d", &data->day, &data->month, &data->year);
}

int main() {
    char msg[80];

    Date date;
    date.day = 1;
    date.month = 1;
    date.year = 2023;
    dateFormat1(date, msg);
    printf("Data formatada: %s\n", msg);
    return 0;
}

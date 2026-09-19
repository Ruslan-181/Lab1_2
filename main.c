#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PAGE_SIZE 8

double f(double x) {

    return pow(x, 4) - 5 * pow(x, 3) - 0.25 * pow(x, 2) + 2;

}

int main() {
    // встановлення кодування консолі windows
    system("chcp 1251 > nul");

    //Оголошення та ініціалізування змінних
    int mode = 0;
    //Оголошення змінних
    double X1, X2, delta;
    unsigned int N;




    // вивід прохання обрати режим
    printf("Режим (1 - N, 2 - delta): ");
    scanf("%d", &mode);

    // перевірка коректності режиму
    while (mode != 1 && mode != 2) {
        printf("Помилка (1 або 2): ");
        scanf("%d", &mode);
    }





    //прохання ввести значення
    printf("X1: ");
    scanf("%lf", &X1);
    printf("X2: ");
    scanf("%lf", &X2);

    // перевірка щоб кінцеве значення було більшим за початкове
    while (X2 <= X1) {
        printf("Помилка (X2 має бути > X1): ");
        scanf("%lf", &X2);
    }






    //перевірка обраного режиму
    if (mode == 1) {
        printf("N (>= 2): ");
        scanf("%u", &N);
        // перевірка щоб кількість точок була не менше двох
        while (N < 2) {
            printf("Помилка (N >= 2): ");
            scanf("%u", &N);
        }
        delta = (X2 - X1) / (N - 1);
    }
    //режим 2
    else {
        printf("delta (> 0): ");
        scanf("%lf", &delta);
        // перевірка щоб крок був додатним
        while (delta <= 0) {
            printf("Помилка (delta > 0): ");
            scanf("%lf", &delta);
        }
        N = (unsigned int)((X2 - X1) / delta) + 1;
    }







    // вивід вхідних параметрів
    printf("\nX1=%.2f,  X2=%.2f,  delta=%.2f\n\n", X1, X2, delta);
    printf("***********************************\n");
    printf("*       N   *       X   *    F(X) *\n");
    printf("***********************************\n");



   int count = 0; // лічильник рядків на поточній сторінці
    // цикл виводу таблиці для всіх точок
    for (unsigned int i = 1; i <= N; i++) {
        double x = X1 + (i - 1) * delta;
        if (x > X2) x = X2;
        double fx = f(x);

        printf("+-----------+-----------+-----------+\n");
        printf("|%11u|%11.2f|%11.2f|\n", i, x, fx);

        count++; // додаємо +1 до лічильника після кожної ітерації

        // якщо заповнили 8 рядків і це ще не остання точка
        if (count == PAGE_SIZE && i < N) {
            printf("+-----------+-----------+-----------+\n");
            printf("Press Any Key to Continue ...");
            system("pause");
            printf("\n");
            count = 0; // скидаємо лічильник для наступної сторінки
        }
    }
    printf("+-----------+-----------+-----------+\n");



    // вивід заголовку блоку аналізу
    printf("\nІнтервали зміни знака:\n");
    // прапорець наявності змін знака
    int found = 0;
    for (unsigned int i = 1; i < N; i++) {
        double x1_curr = X1 + (i - 1) * delta;
        double x2_curr = X1 + i * delta;
        if (x2_curr > X2) x2_curr = X2;

        // перевірка зміни знака функції
        if (f(x1_curr) * f(x2_curr) <= 0) {
            printf("[%.2f; %.2f]\n", x1_curr, x2_curr);
            found = 1;
        }
    }


    // якщо жодного інтервалу не знайдено вивід повідомлення про відсутність змін
    if (!found) {
        printf("Функція не змінює знак.\n");
    }

    return 0;
}

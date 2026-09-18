#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PAGE_SIZE 8

double f(double x, int variant) {
    switch (variant) {
        case 1:  return pow(x, 4) - 5 * pow(x, 3) - 0.25 * pow(x, 2) + 2;
        case 2:  return 0.25 * pow(x, 5) + 4 * pow(x + 20, 4) - 2 * x;
        case 3:  return -3 * pow(x, 6) - 10 * pow(x - 30, 5) + 12 * pow(x, 4) + 5 * pow(x, 3) - 10;
        case 4:  return pow(x, 3) / 30.0 - 4 * x * x + 50;
        case 5:  return 0.4 * pow(x - 100, 3) + 0.3 * x * x - 0.2 * x + 200;
        case 6:  return x * x / 1000.0 - 0.5 * x - 1000;
        case 7:  return -0.5 * pow(x - 64, 3) - 3 * x * x + 10;
        case 8:  return -4 * pow(x, 3) - 3 * x * x + 2 * x * x - 5 * x - 25;
        case 9:  return 4 * pow(x / 10.0 - 2, 3) - 15 * x + 12;
        case 10: return 0.25 * pow(x - 25, 2) + pow(x + 25, 3) / 100.0 + 1;
        case 11: return 0.5 * pow(x + 250, 3) - pow(x - 125, 2) + 500;
        case 12: return pow(x / 100.0 - 5, 5) - pow(x / 50.0 + 10, 4) - pow(x / 25.0 - 15, 3) - x * x - 10;
        case 13: return pow(x - 10, 3) * sin((x + 10) / 100.0) - 10 * x + 12;
        case 14: return pow(x + 50, 5) * sin((x - 5) / 60.0) - pow(x - 15, 3) - 3 * x * x - 20;
        case 15: return 2 * pow(x - 1000, 3) - 3 * pow(x + 500, 2) + 4 * x - 5;
        case 16: return (x - 50) * cos(x / 10.0) - 3 * x + 500;
        case 17: return pow(x + 125, 3) - 45 * x - 18;
        case 18: return pow(x, 3) / 20.0 - 5 * x * x + 1000;
        case 19: return (x + 100) * sin(x / 5.0) - 5 * (x - 10) - 2100;
        case 20: return pow(x - 200, 5) - pow(x - 100, 3) - 50 * x - 25;
        case 21: return 8 * pow(x / 16.0 - 4, 3) - 4 * x - 12;
        case 22: return (x + 1000) * pow(sin(x / 50.0), 2) - 8 * x + 1800;
        case 23: return 9 * pow(x, 3) + 1000;
        case 24: return 2 * x * x - 3 * pow(x, 3) + 1500 * x - 12000;
        case 25: return -pow(x, 3) / 25.0 + 10 * x * x - 15000;
        default: return 0;
    }
}

int main() {
    system("chcp 1251 > nul");


    int variant = 0, mode = 0;
    double X1, X2, delta;
    unsigned int N;

    printf("Варіант (1-25): ");
    scanf("%d", &variant);


    printf("Режим (1 - N, 2 - delta): ");
    scanf("%d", &mode);

    printf("X1: ");
    scanf("%lf", &X1);
    printf("X2: ");
    scanf("%lf", &X2);


    if (mode == 1) {
        printf("N (>= 2): ");
        scanf("%u", &N);

        delta = (X2 - X1) / (N - 1);
    } else {
        printf("delta (> 0): ");
        scanf("%lf", &delta);

        N = (unsigned int)((X2 - X1) / delta) + 1;
    }

    printf("\nX1=%.2f,  X2=%.2f,  delta=%.2f\n\n", X1, X2, delta);
    printf("***********************************\n");
    printf("*       N   *       X   *    F(X) *\n");
    printf("***********************************\n");

    for (unsigned int i = 1; i <= N; i++) {
        double x = X1 + (i - 1) * delta;
        if (x > X2) x = X2;
        double fx = f(x, variant);

        printf("+-----------+-----------+-----------+\n");
        printf("|%11u|%11.2f|%11.2f|\n", i, x, fx);

        if (i % PAGE_SIZE == 0 && i < N) {
            printf("+-----------+-----------+-----------+\n");
            printf("Press Any Key to Continue ...");
            system("pause > nul");
            printf("\n");
        }
    }
    printf("+-----------+-----------+-----------+\n");

    printf("\nІнтервали зміни знака:\n");
    int found = 0;
    for (unsigned int i = 1; i < N; i++) {
        double x1_curr = X1 + (i - 1) * delta;
        double x2_curr = X1 + i * delta;
        if (x2_curr > X2)
        {
            x2_curr = X2
        };

        if (f(x1_curr, variant) * f(x2_curr, variant) <= 0) {
            printf("[%.2f; %.2f]\n", x1_curr, x2_curr);
            found = 1;
        }
    }

    if (!found) {
        printf("Функція не змінює знак.\n");
    }

    return 0;
}

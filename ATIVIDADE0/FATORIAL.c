#include <stdio.h>

int main() {
    int num, i, fatorial = 1;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        fatorial *= i;
    }

    printf("Fatorial de %d = %d\n", num, fatorial);

    return 0;
}


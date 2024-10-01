#include <stdio.h>

int main() {
    int numeros[5], soma = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    printf("A soma dos números: %d\n", soma);

    return 0;
}


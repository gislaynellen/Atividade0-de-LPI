#include <stdio.h>

int main() {
    int num, i, primo = 1;

    printf("Digite um n�mero inteiro: ");
    scanf("%d", &num);

    if (num < 2) {
        primo = 0;
    } else {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo)
        printf("%d � primo.\n", num);
    else
        printf("%d n�o � primo.\n", num);

    return 0;
}


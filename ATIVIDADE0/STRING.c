#include <stdio.h>

int main() {
    char str[100];
    int count = 0, i = 0;

    printf("Digite uma string: ");
    scanf("%s", str);

    while (str[i] != '\0') {
        count++;
        i++;
    }

    printf("A string tem %d caracteres.\n", count);

    return 0;
}


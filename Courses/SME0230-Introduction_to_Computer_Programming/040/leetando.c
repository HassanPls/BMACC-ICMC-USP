#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 100

int main() {
    char *v;

    v = malloc(TAM*sizeof(char));

    scanf("%s", &*v);

    for (int i = 0; v[i] != '\0'; i++) {
        switch (tolower(v[i])) {
            case 'a':
                v[i] = '4';
                break;

            case 'e':
                v[i] = '3';
                break;

            case 'i':
                v[i] = '1';
                break;

            case 'o':
                v[i] = '0';
                break;

            default:
                v[i] = v[i];
                break;
        }
    }

    printf("%s", v);

    return 0;
}
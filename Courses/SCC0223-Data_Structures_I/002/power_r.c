#include <stdio.h>

long long power(long long a, long long b) {

    if (b == 0) return 1;

    long long metade = power(a, b / 2);

    if (b % 2 == 0) {
        return metade * metade;
    } else {
        return a * metade * metade;
    }
}

int main() {

    int a, b;

    printf("%lld", power(a, b));

    return 0;
}
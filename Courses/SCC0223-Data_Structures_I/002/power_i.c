#include <stdio.h>

long long power(long long a, long long b) {
    long long res = 1;

    for (long long i = 0; i < b; i++)
    {
        res *= a;
    }

    return res;
}

int main() {

    int a, b;

    printf("%lld", power(a, b));

    return 0;
}
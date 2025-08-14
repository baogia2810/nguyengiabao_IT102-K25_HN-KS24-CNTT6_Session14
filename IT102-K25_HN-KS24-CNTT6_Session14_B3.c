#include <stdio.h>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &number);
    printf("Giai thua la: %d", factorial(number));
    return 0;
}

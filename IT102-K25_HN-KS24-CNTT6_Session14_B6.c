#include <stdio.h>
#include <stdbool.h>

bool isPerfectNumber(int n) {
    if (n <= 0) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

int main() {
    int num1, num2;
    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);
    printf("Nhap so thu hai: ");
    scanf("%d", &num2);

    if (isPerfectNumber(num1)) {
        printf("%d la so hoan hao\n", num1);
    } else {
        printf("%d khong phai so hoan hao\n", num1);
    }

    if (isPerfectNumber(num2)) {
        printf("%d la so hoan hao\n", num2);
    } else {
        printf("%d khong phai so hoan hao\n", num2);
    }
    return 0;
}

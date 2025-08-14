#include <stdio.h>

int sumTwoNumbers(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int firstNumber, secondNumber;
    printf("Nhap so thu nhat: ");
    scanf("%d", &firstNumber);
    printf("Nhap so thu hai: ");
    scanf("%d", &secondNumber);
    int total = sumTwoNumbers(firstNumber, secondNumber);
    printf("Tong la: %d\n", total);
    return 0;
}

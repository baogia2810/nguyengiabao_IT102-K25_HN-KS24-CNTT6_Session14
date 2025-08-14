#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int array[] = {5, 8, 2, 9, 4};
    int size = sizeof(array) / sizeof(array[0]);
    printf("So lon nhat la: %d", findMax(array, size));
    return 0;
}

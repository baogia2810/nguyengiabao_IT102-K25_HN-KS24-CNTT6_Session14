#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void inputArray(int arr[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n, int pos, int value) {
    if (*n >= MAX || pos < 0 || pos > *n) return;
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void editElement(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) return;
    arr[pos] = value;
}

void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) return;
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void sortArrayAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortArrayDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) return mid;
        else if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[MAX], n = 0, choice, pos, value, subchoice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("Nhap vi tri chen: ");
                scanf("%d", &pos);
                printf("Nhap gia tri chen: ");
                scanf("%d", &value);
                insertElement(arr, &n, pos, value);
                break;
            case 4:
                printf("Nhap vi tri sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                editElement(arr, n, pos, value);
                break;
            case 5:
                printf("Nhap vi tri xoa: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 6:
                printf("1. Giam dan\n2. Tang dan\nNhap lua chon: ");
                scanf("%d", &subchoice);
                if (subchoice == 1) sortArrayDesc(arr, n);
                else if (subchoice == 2) sortArrayAsc(arr, n);
                break;
            case 7:
                printf("1. Tim kiem tuyen tinh\n2. Tim kiem nhi phan\nNhap lua chon: ");
                scanf("%d", &subchoice);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (subchoice == 1) {
                    int idx = linearSearch(arr, n, value);
                    if (idx != -1) printf("Tim thay tai vi tri %d\n", idx);
                    else printf("Khong tim thay\n");
                } else if (subchoice == 2) {
                    int idx = binarySearch(arr, n, value);
                    if (idx != -1) printf("Tim thay tai vi tri %d\n", idx);
                    else printf("Khong tim thay\n");
                }
                break;
        }
    } while (choice != 8);
    return 0;
}

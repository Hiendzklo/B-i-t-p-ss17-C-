#include <stdio.h>
#include <stdbool.h>

// Ham kiem tra so nguyen to
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
// In cqc so chan trong mang
void printEvenNumbers(int *arr, int size) {
    printf("Cac so chan trong mang la:\n");
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}
// In cac so nguyen to trong mang
void printPrimeNumbers(int *arr, int size) {
    printf("Cac so nguyen to trong mang la:\n");
    for (int i = 0; i < size; i++) {
        if (isPrime(*(arr + i))) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}
// Ðao nguoc mang
void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }
}
// Sap xep mang tang dan
void sortAscending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
// Sap xep mang giam dan
void sortDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) < *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
// Tim kiem phan tu trong mang
void searchElement(int *arr, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == element) {
            printf("Tim thay phan tu %d tai vi tri %d\n", element, i);
            return;
        }
    }
    printf("Khong tim thay phan tu %d trong mang.\n", element);
}

void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhatp vao so phan tu va tung phan tu\n");
    printf("2. In ra cac phan tu la so chan\n");
    printf("3. In ra cac phan tu la so nguyen to\n");
    printf("4. Dao nguoc mang\n");
    printf("5. Sap xep mang\n");
    printf("   1. Tang dan\n");
    printf("   2. Giam dan\n");
    printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

int main() {
    int arr[100], size, choice, sortChoice, element;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nhap so phan tu va cac phan tu
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                printf("Nhap mang:\n");
                for (int i = 0; i < size; i++) {
                    printf("arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2: // In cac so chan
                printEvenNumbers(arr, size);
                break;
            case 3: // In cac so nguyen to
                printPrimeNumbers(arr, size);
                break;
            case 4: // Ðao nguoc mang
                reverseArray(arr, size);
                printf("Mang sau khi dao nguoc la:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 5: // Sap xep mang
                printf("\nMENU Sap xep\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &sortChoice);
                if (sortChoice == 1) {
                    sortAscending(arr, size);
                    printf("Mang sau khi sap xep tang dan la:\n");
                } else if (sortChoice == 2) {
                    sortDescending(arr, size);
                    printf("Mang sau khi sap xep giam dan la:\n");
                }
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 6: // Tim kiem phan tu
                printf("Nhap phan tu can tim kiem: ");
                scanf("%d", &element);
                searchElement(arr, size, element);
                break;
            case 7: // Thoat chuong trinh
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}


#include <stdio.h>
#include <stdlib.h>

// Ham hien thi menu va lay lua chon cua nguoi dung
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. Hien thi cac phan tu trong mang\n");
    printf("3. Tinh do dai mang\n");
    printf("4. Tinh tong cac phan tu trong mang\n");
    printf("5. Hien thi phan tu lon nhat\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}
// Ham hien thi cac phan tu trong mang
void displayArray(int *arr, int size) {
    printf("Mang hien tai: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
// Ham tinh tong cac phan tu trong mang
int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}
// Ham tim phan tu lon nhot trong mang
int findMax(int *arr, int size) {
    int max = *arr; // Gan phan tu dau tien lam gia tri toi da ban dau
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int *array = NULL; // Con tro toi mang dong
    int choice, numElements;

    while (1) { 
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nhap so phan tu va tung phan tu
                printf("Nhap so phan tu: ");
                scanf("%d", &numElements);
                // Cap phat bo nho dong cho mang
                if (array) free(array); // Giai phong bo nho truoc do neu co
                array = (int *)malloc(numElements * sizeof(int));
                if (!array) {
                    printf("Khong du bo nho!\n");
                    exit(1);
                }

                printf("Nhap tung phan tu:\n");
                for (int i = 0; i < numElements; i++) {
                    printf("Phan tu arr[%d]: ", i);
                    scanf("%d", (array + i));
                }
                break;
            case 2: // Hien thi cac phan tu trong mang
                if (array) {
                    displayArray(array, numElements);
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 3: // Tinh do dai mang
                if (array) {
                    printf("So phan tu trong mang la: %d\n", numElements);
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 4: // Tinh tong cac phan tu trong mang
                if (array) {
                    printf("Tong cua mang la: %d\n", sumArray(array, numElements));
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 5: // Hien thi phan tu lon nhat trong mang
                if (array) {
                    printf("Phan tu lon nhat la: %d\n", findMax(array, numElements));
                } else {
                    printf("Ban chua nhap mang.\n");
                }
                break;
            case 6: // Thoat chuong trinh
                if (array) free(array);
                printf("Thoat chuong trinh.\n");
                exit(0);
            default: // Lua chon khong hop le
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}


#include <stdio.h>
#include <string.h>

// Ham hien thi menu và lay lua chon cua nguoi dung
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In ra chuoi\n");
    printf("3. Dem so luong chu cai trong chuoi\n");
    printf("4. Dem so luong chu so trong chuoi\n");
    printf("5. Dem so luong ky tu dac biet trong chuoi\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}
// Ham in chuoi
void printString(char *str) {
    printf("Chuoi hien tai: %s\n", str);
}
// Ham dem so luong chu cai trong chuoi
int countLetters(char *str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            count++;
        }
        str++;
    }
    return count;
}
// Ham dem so luong chu so trong chuoi
int countDigits(char *str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}
// Ham dem so luong ky tu dac biet trong chuoi
int countSpecialCharacters(char *str) {
    int count = 0;
    while (*str) {
        if (!((*str >= 'A' && *str <= 'Z') || 
             (*str >= 'a' && *str <= 'z') || 
             (*str >= '0' && *str <= '9') || 
             (*str == ' '))) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char inputString[100];
    int choice;

    while (1) { 
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nhap chuoi
                printf("Nhap chuoi: ");
                getchar(); // Loai bo ky tu '\n' con lai trong bo dem
                fgets(inputString, 100, stdin);
                inputString[strcspn(inputString, "\n")] = '\0'; // Xoa ky tu newline o cuoi
                break;
            case 2: // In chuoi
                printf("Chuoi hien tai: %s\n", inputString);
                break;
            case 3: // Ğem so luong chu cai
                printf("So chu cai trong chuoi la: %d\n", countLetters(inputString));
                break;
            case 4: // Ğem so luong chu so
                printf("So chu so trong chuoi la: %d\n", countDigits(inputString));
                break;
            case 5: // Ğem so luong ky tu dac biet
                printf("So ky tu dac biet trong chuoi la: %d\n", countSpecialCharacters(inputString));
                break;
            case 6: // Thoat chuong trinh
                printf("Thoat chuong trinh.\n");
                return 0;
            default: // Lua chon khong hop le
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}


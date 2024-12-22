#include <stdio.h>
#include <string.h>

// Hien thi menu cho nguoi dung
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhatp vao chuoi\n");
    printf("2. In ra chuoi dao nguoc\n");
    printf("3. Dem so luong tu trong chuoi\n");
    printf("4. Nhatp chuoi khac va so sanh do dai voi chuoi ban dau\n");
    printf("5. In hoa tat ca chu cai trong chuoi\n");
    printf("6. Nhatp chuoi khac va them vao chuoi ban dau\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}
// In chuoi dao nguoc
void reverseString(char *str, char *reversedStr) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        reversedStr[i] = str[len - 1 - i];
    }
    reversedStr[len] = '\0';
}
// Ðem so tu trong chuoi
int countWords(char *str) {
    int count = 0;
    int inWord = 0;
    while (*str) {
        if (*str != ' ' && *str != '\t') {
            if (!inWord) {
                inWord = 1;
                count++;
            }
        } else {
            inWord = 0;
        }
        str++;
    }
    return count;
}
// In hoa tat ca cac chu cai trong chuoi
void toUpperCase(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 'a' + 'A';
        }
        str++;
    }
}
// Them chuoi vao cuoi chuoi ban dau
void appendString(char *dest, char *src) {
    strcat(dest, src);
}

int main() {
    char inputString[200] = "";
    char reversedString[200];
    char compareString[200];
    int choice;

    while (1) { 
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Loai bo ký t? '\n' 	

        switch (choice) {
            case 1: // Nhap chuoi
                printf("Nhap chuoi: ");
                fgets(inputString, 200, stdin);
                inputString[strcspn(inputString, "\n")] = '\0'; // Xoa ky tu newline o cuoi
                break;
            case 2: // In chuoi dao nguoc
                reverseString(inputString, reversedString);
                printf("Chuoi dao nguoc: %s\n", reversedString);
                break;
            case 3: // Ðem so luong tu trong chuoi
                printf("So tu trong chuoi la: %d\n", countWords(inputString));
                break;
            case 4: // Nhap chuoi khac va so sanh do dai
                printf("Nhap chuoi khac de so sanh: ");
                fgets(compareString, 200, stdin);
                compareString[strcspn(compareString, "\n")] = '\0';
                if (strlen(compareString) < strlen(inputString)) {
                    printf("Chuoi khac ngan hon chuoi ban dau.\n");
                } else if (strlen(compareString) > strlen(inputString)) {
                    printf("Chuoi khac dai hon chuoi ban dau.\n");
                } else {
                    printf("Chuoi khac co do dai bang chuoi ban dau.\n");
                }
                break;
            case 5: // Chuyen tat ca chu cai thanh in hoa
                toUpperCase(inputString);
                printf("Chuoi sau khi chuyen sang in hoa: %s\n", inputString);
                break;
            case 6: // Them chuoi khac vao chuoi ban dau
                printf("Nhap chuoi khac de them: ");
                fgets(compareString, 200, stdin);
                compareString[strcspn(compareString, "\n")] = '\0';
                appendString(inputString, compareString);
                printf("Chuoi sau khi them: %s\n", inputString);
                break;
            case 7: // Thoat
                printf("Thoat chuong trinh.\n");
                return 0;
            default: // Lua chon khong hop le
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}


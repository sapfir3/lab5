#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#define MAX_N 8
#define MAX_M 10

int arr[MAX_N][MAX_M] = {
    {10, 11, 12, 13},
    {20, 21, 9, 23},
    {30, 31, 32, 33},
};
int n = 3;
int m = 4;

void print() {
    printf("!!!!print()!!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

void fillx10() {
    printf("!!!!fillx10()!!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
}

void fillZero() {
    printf("!!!!fillZero()!!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
        }
    }
}

int randFill0_9() {
    printf("!!!!randFill0_9!!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    return 0;
}

void oddsX10() {
    printf("!!!!oddsX10()!!!!");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 == 1) {
                arr[i][j] = arr[i][j] * 10;
            }
        }
    }
}

void save() {
    FILE* fout = fopen("c:\\Temp\\arr1.txt", "wt");
    if (fout == NULL) {
        printf("Файл не может быть открыт\n");
        return;
    }
    fprintf(fout, "%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%d ", arr[i][j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}

void load() {
    FILE* fin = fopen("c:\\Temp\\arr1.txt", "rt");
    if (fin == NULL) {
        printf("Файл не может быть открыт\n");
        return;
    }
    if (fscanf(fin, "%d %d", &n, &m) != 2 || n > MAX_N || m > MAX_M) {
        printf("Ошибка загрузки, неверный размер массива\n");
        fclose(fin);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fscanf(fin, "%d", &arr[i][j]) != 1) {
                printf("Ошибка загрузки данных\n");
                fclose(fin);
                return;
            }
        }
    }
    fclose(fin);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int item;
    do {
        printf("\n");
        print();
        printf("Выберите нужную вам операцию:\n");
        printf("1: Заполнить значениями\n");
        printf("2: Заполнить нулями\n");
        printf("3: Заполнить случайным значением\n");
        printf("4: Все нечетные умножить на 10\n");
        printf("5: Сохранить массив\n");
        printf("6: Загрузить массив\n");
        printf("0: Выход\n");

        scanf_s("%d", &item);

        switch (item) {
        case 1:
            fillx10();
            break;
        case 2:
            fillZero();
            break;
        case 3:
            randFill0_9();
            print();
            break;
        case 4:
            oddsX10();
            break;
        case 5:
            save();
            print();
            break;
        case 6:
            load();
            print();
            break;
        }
    } while (item != 0);
    return 0;
}
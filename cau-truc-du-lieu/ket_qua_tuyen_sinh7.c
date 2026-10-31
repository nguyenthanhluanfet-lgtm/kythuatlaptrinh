#include <stdio.h>
#include <string.h>

struct ket_qua_tuyen_sinh {
    int tt;
    char ten[20];
    float toan;
    float ly;
    float hoa;
    float tong;
    char xep_lop[20];
    char xep_loai[20];
};

int main() {
    struct ket_qua_tuyen_sinh s[] =
    {
        {1, "Nguyen Van A", 6, 5, 8},
        {2, "Tran Thi B", 7, 8, 9},
        {3, "Le Van C", 6, 4, 7},
        {4, "Hoang Thi D", 3, 5, 7},
        {5, "Vu Van E", 6, 5, 6},
        {6, "Ngo Thi D", 9, 3, 4},
        {7, "Lo Van A", 9, 8, 9}
    };

    for (int i = 0; i < 7; i++) {
        s[i].tong = s[i].toan*2 + s[i].ly + s[i].hoa;
    }


    for (int i = 0; i < 7; i++) {
        if (s[i].tong >= 35)
            strcpy(s[i].xep_lop, "Lop A");
        else if (s[i].tong >= 30)
            strcpy(s[i].xep_lop, "Lop B");
        else
            strcpy(s[i].xep_lop, "Lop C");

        if (s[i].tong >= 31)
            strcpy(s[i].xep_loai, "DUOC KHEN");
    }

    printf("%65s", "KET QUA TUYEN SINH\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-16s | %-5s | %-5s | %-5s | %-10s | %-16s | %-18s |\n",
           "TT",  "Ho ten", "Toan", "Ly", "Hoa", "Tong diem", "Xep lop", "Xep loai");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("| %-2d | %-16s | %-5.2f | %-5.2f | %-5.2f | %-10.2f | %-16s | %-18s |\n",
               s[i].tt, s[i].ten, s[i].toan, s[i].ly, s[i].hoa, s[i].tong, s[i].xep_lop, s[i].xep_loai);
    }
    printf("------------------------------------------------------------------------------------------------------\n");

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < 7; i++) {
        if (strcmp(s[i].xep_lop, "Lop A") == 0)
            a += 1;
        if (!strcmp(s[i].xep_lop, "Lop B"))
            b += 1;
        if (!strcmp(s[i].xep_lop, "Lop C"))
            c += 1;
    }

    printf("Lop A: %d\n", a);
    printf("Lop B: %d\n", b);
    printf("Lop C: %d\n", c);
}


/*
Note:
    if (strcmp(s[i].xep_lop, "Lop A") == 0) tương tự if (!strcmp(s[i].xep_lop, "Lop A"))
*/

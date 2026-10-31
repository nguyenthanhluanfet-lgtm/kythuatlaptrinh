#include <stdio.h>
#include <string.h>

struct ket_qua_tuyen_sinh {
    int tt;
    char ten[20];
    float toan;
    float ly;
    float hoa;
    float tong;
    float xet_tuyen;
    char xep_loai[20];
};

int main() {
    struct ket_qua_tuyen_sinh s[] =
    {
        {1, "Nguyen Van A", 5.5, 6.5, 7.5},
        {2, "Tran Thi B", 6, 8, 5.5},
        {3, "Le Van C", 4.5, 7, 5},
        {4, "Hoang Thi D", 7, 4, 9},
        {5, "Vu Van E", 8.5, 4, 8},
        {6, "Ngo Thi D", 3.5, 6, 3},
        {7, "Lo Van A", 4.5, 2.5, 5.5}
    };

    float tong = 0;
    float xet_tuyen = 0;

    for (int i = 0; i < 7; i++) {
        s[i].tong = (s[i].toan*2 + s[i].ly + s[i].hoa) / 4;
        tong += s[i].tong;
    }

    xet_tuyen = tong / 7;

    for (int i = 0; i < 7; i++) {
        s[i].xet_tuyen = xet_tuyen;
        if (s[i].tong > xet_tuyen)
            strcpy(s[i].xep_loai, "Trung Tuyen");
        else
            strcpy(s[i].xep_loai, "Khong Trung Tuyen");
    }

    printf("%65s", "KET QUA TUYEN SINH\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-16s | %-5s | %-5s | %-5s | %-10s | %-16s | %-18s |\n",
           "TT",  "Ho ten", "Toan", "Ly", "Hoa", "Tong diem", "Diem xet tuyen", "Xep loai");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("| %-2d | %-16s | %-5.2f | %-5.2f | %-5.2f | %-10.2f | %-16.2f | %-18s |\n",
               s[i].tt, s[i].ten, s[i].toan, s[i].ly, s[i].hoa, s[i].tong, s[i].xet_tuyen, s[i].xep_loai);
    }
    printf("------------------------------------------------------------------------------------------------------\n");

    int max_toan = 0, max_ly = 0, max_hoa = 0;

    for (int i = 0; i < 7; i++) {
        if (s[i].toan > s[max_toan].toan)
            max_toan = i;
        if (s[i].ly > s[max_ly].ly)
            max_ly = i;
        if (s[i].hoa > s[max_hoa].hoa)
            max_hoa = i;
    }

    printf("Thi sinh co diem toan cao nhat: %s\n", s[max_toan].ten);
    printf("Thi sinh co diem ly cao nhat: %s\n", s[max_ly].ten);
    printf("Thi sinh co diem hoa cao nhat: %s\n", s[max_hoa].ten);
}

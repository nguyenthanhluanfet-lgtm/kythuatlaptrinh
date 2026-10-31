#include <stdio.h>
#include <string.h>

struct quy_mo_kinh_doanh {
    int tt;
    char ten_hang[20];
    int so_luong;
    int gia_nhap;
    int gia_xuat;
    int loi_nhuan;
    char kho_hang[10];
    char xep_loai[10];
};

int main() {
    struct quy_mo_kinh_doanh s[] = {
        {1, "Banh", 120, 58000, 65000, 0, "Kho A"},
        {2, "Keo", 190, 38500, 48000, 0, "Kho C"},
        {3, "Nuoc Ngot", 90, 89200, 99000, 0, "Kho C"},
        {4, "Duong", 35, 29000, 40000, 0, "Kho B"},
        {5, "Sua", 60, 24000, 36000, 0, "Kho B"},
        {6, "Bia", 150, 30000, 40000, 0, "Kho C"},
        {7, "Ruou", 100, 68000, 98000, 0, "Kho A"},
    };

    for (int i = 0; i < 7; i++) {
        s[i].loi_nhuan = (s[i].gia_xuat - s[i].gia_nhap) * s[i].so_luong;
        if (s[i].loi_nhuan > 1500000)
            strcpy(s[i].xep_loai, "Loai III");
        if (s[i].loi_nhuan > 800000)
            strcpy(s[i].xep_loai, "Loai II");
        else
            strcpy(s[i].xep_loai, "Loai I");
    }

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n",
           "TT", "Ten hang", "So luong", "Gia nhap", "Gia Xuat", "Loi nhuan", "Kho hang", "Xep loai");
    printf("-------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("| %-2d | %-10s | %-10d | %-10d | %-10d | %-10d | %-10s | %-10s |\n",
               s[i].tt,
               s[i].ten_hang,
               s[i].so_luong,
               s[i].gia_nhap,
               s[i].gia_xuat,
               s[i].loi_nhuan,
               s[i].kho_hang,
               s[i].xep_loai);
    }
    printf("-------------------------------------------------------------------------------------------------\n");

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < 7; i++) {
        if (strcmp(s[i].kho_hang, "Kho A") == 0)
            a += s[i].so_luong;
        if (strcmp(s[i].kho_hang, "Kho B") == 0)
            b += s[i].so_luong;
        if (strcmp(s[i].kho_hang, "Kho C") == 0)
            c += s[i].so_luong;
    }

    printf("Kho A: %d sp\n", a);
    printf("Kho B: %d sp\n", b);
    printf("Kho C: %d sp\n", c);

    return 0;
}

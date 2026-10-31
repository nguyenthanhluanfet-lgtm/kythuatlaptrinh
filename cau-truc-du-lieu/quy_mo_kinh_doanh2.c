#include <stdio.h>
#include <string.h>

struct quy_mo_kinh_doanh {
    int tt;
    char ten_hang[20];
    int sl_nhap, gia_nhap, sl_xuat, gia_xuat, ton_kho;
    char xep_loai[10];
};

int main() {
    struct quy_mo_kinh_doanh s[] = {
        {1, "Banh", 120, 58000, 100, 65000},
        {2, "Keo", 190, 38500, 100, 48000},
        {3, "Nuoc Ngot", 90, 89200, 80, 99000},
        {4, "Duong", 35, 29000, 30, 40000},
        {5, "Sua", 60, 24000, 45, 36000},
        {6, "Bia", 150, 30000, 120, 40000},
        {7, "Ruou", 100, 68000, 60, 98000},
    };

    for (int i = 0; i < 7; i++) {
        s[i].ton_kho = s[i].sl_nhap - s[i].sl_xuat;
        (s[i].gia_xuat * s[i].sl_xuat - s[i].gia_nhap * s[i].sl_nhap > 0) ? strcpy(s[i].xep_loai, "Co lai"): strcpy(s[i].xep_loai, "Lo von");
    }

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n",
           "TT", "Ten hang", "SL nhap", "Gia nhap", "SL xuat", "Gia xuat", "Ton kho", "Xep loai");
    printf("-------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("| %-2d | %-10s | %-10d | %-10d | %-10d | %-10d | %-10d | %-10s |\n",
               s[i].tt,
               s[i].ten_hang,
               s[i]. sl_nhap,
               s[i].gia_nhap,
               s[i].sl_xuat,
               s[i].gia_xuat,
               s[i].ton_kho,
               s[i].xep_loai);
    }
    printf("-------------------------------------------------------------------------------------------------\n");

    int m1 = 0, m2 = 0, m3 = 0;

    for (int i = 0; i < 7; i++) {
        if (s[i].sl_nhap > s[m1].sl_nhap)
            m1 = i;
        if (s[i].sl_xuat > s[m1].sl_xuat)
            m2 = i;
        if (s[i].ton_kho > s[m1].ton_kho)
            m3 = i;
    }

    printf("Nhap nhieu nhat: %d\n", s[m1].sl_nhap);
    printf("Xuat nhieu nhat: %d\n", s[m2].sl_xuat);
    printf("Ton kho nhieu nhat: %d\n", s[m3].ton_kho);

    return 0;
}

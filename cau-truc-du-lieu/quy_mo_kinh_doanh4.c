#include <stdio.h>
#include <string.h>

struct quy_mo_kinh_doanh {
    int tt;
    char ten_thuoc[20];
    int so_luong;
    int gia_mua;
    int gia_ban;
    int loi_nhuan;
    char kho_hang[10];
    char xep_loai[10];
};

int main() {
    struct quy_mo_kinh_doanh s[] = {
        {1, "Amoxilin", 150, 90000, 97000, 0, "Kho A"},
        {2, "Cefalexin", 350, 55000, 60000, 0, "Kho B"},
        {3, "Zeltaxilin", 350, 55000, 60000, 0, "Kho A"},
        {4, "Sulfamide", 250, 29000, 31000, 0, "Kho C"},
        {5, "Penicilin", 300, 50000, 55000, 0, "Kho B"},
        {6, "Bentalzol", 200, 65500, 75900, 0, "Kho C"},
        {7, "Efferagal", 500, 21000, 25000, 0, "Kho A"},
    };

    for (int i = 0; i < 7; i++) {
        s[i].loi_nhuan = (s[i].gia_ban - s[i].gia_mua) * s[i].so_luong;
        if (s[i].loi_nhuan >= 500000)
            strcpy(s[i].xep_loai, "Loai A");
        else if (s[i].loi_nhuan >= 200000)
            strcpy(s[i].xep_loai, "Loai B");
        else
            strcpy(s[i].xep_loai, "Loai C");
    }

    printf("%60s\n", "THONG TIN THONG KE");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-14s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n",
           "TT", "Ten thuoc", "So luong", "Gia mua", "Gia ban", "Loi nhuan", "Kho hang", "Xep loai");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("| %-2d | %-14s | %-10d | %-10d | %-10d | %-10d | %-10s | %-10s |\n",
               s[i].tt, s[i].ten_thuoc, s[i].so_luong, s[i].gia_mua, s[i].gia_ban, s[i].loi_nhuan, s[i].kho_hang, s[i].xep_loai);
    }

    printf("-----------------------------------------------------------------------------------------------------\n");

    int max = 0, min = 0, kho_A = 0;

    for (int i = 0; i < 7; i++) {
        if (s[i].loi_nhuan > s[max].loi_nhuan)
            max = i;
        if (s[i].loi_nhuan > s[max].loi_nhuan)
            min = i;
        if (strcmp(s[i].kho_hang, "Kho A") == 0)
            kho_A++;
    }

    printf("Mat hang loi nhuan cao nhat: %s\n", s[max].ten_thuoc);
    printf("Mat hang loi nhuan thap nhat: %s\n", s[min].ten_thuoc);
    printf("Mat hang co trong kho A: %d\n", kho_A);
}

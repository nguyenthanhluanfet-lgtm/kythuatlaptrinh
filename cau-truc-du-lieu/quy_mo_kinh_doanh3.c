#include <stdio.h>
#include <string.h>

struct sach
{
    int tt;
    char ten[30];
    int sl_mua;
    float mua;
    int sl_ban;
    float ban;
    int ton_kho;
    char xep[30];
};


int main()
{
    struct sach s[] =
    {
        {1, "Lap trinh C", 120, 55000, 110, 60000},
        {2, "Co so du lieu", 100, 45000, 90, 55000},
        {3, "Lap trinh Python", 150, 60000, 120, 75000},
        {4, "Tin hoc van phong", 200, 50000, 180, 55000},
        {5, "Khoa hoc may tinh", 100, 90000, 90, 95000},
        {6, "Du lieu giai thuat", 110, 77000, 105, 79000},
        {7, "Word-Excel", 120, 60000, 110, 65000},
    };

    for (int i = 0; i < 7; i++)
    {
        s[i].ton_kho = s[i].sl_mua - s[i].sl_ban;
        if ((s[i].ban * s[i].sl_ban - s[i].mua * s[i].sl_mua) > 0)
            strcpy(s[i].xep, "Co lai");
        else
            strcpy(s[i].xep, "Lo von");
    }

    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-20s | %-14s | %-10s | %-14s | %-10s | %-10s | %-10s |\n",
    "TT", "Ten sach", "So luong mua", "Gia mua", "So luong ban", "Gia ban", "Ton kho", "xep loai");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++)
    {
        printf("| %-2d | %-20s | %-14d | %-10.2f | %-14d | %-10.2f | %-10d | %-10s |\n",
        i+1, s[i].ten, s[i].sl_mua, s[i].mua, s[i].sl_ban, s[i].ban, s[i].ton_kho, s[i].xep);
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    int imax_mua = 0, imax_ban = 0, imax_ton = 0;
    for (int i = 1; i < 7; i++)
    {
        if (s[i].sl_mua > s[imax_mua].sl_mua)
            imax_mua = i;
        if (s[i].sl_ban > s[imax_ban].sl_ban)
            imax_ban = i;
        if (s[i].ton_kho > s[imax_ton].ton_kho)
            imax_ton = i;
    }

    printf("Sach nhap nhieu nhat: %s (%d quyen)\n", s[imax_mua].ten, s[imax_mua].sl_mua);
    printf("Sach ban nhieu nhat: %s (%d quyen)\n", s[imax_ban].ten, s[imax_ban].sl_ban);
    printf("Sach ton kho nhieu nhat: %s (%d quyen)\n", s[imax_ton].ten, s[imax_ton].ton_kho);
}

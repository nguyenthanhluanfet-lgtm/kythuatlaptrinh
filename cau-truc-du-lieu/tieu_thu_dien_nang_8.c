#include <stdio.h>
#include <string.h>

struct diennang {
    int tt;
    char ho_tt[20];
    int cu;
    int moi;
    char loai[2];
    int dien_tt;
    int tien_dien;
    float phai_tra;
};

int main() {
    struct diennang s[] = {
        {1, "Ho tieu thu 11", 1872, 1963, "B"},
        {2, "Ho tieu thu 2", 1642, 2178, "A"},
        {3, "Ho tieu thu 3", 1521, 1909, "A"},
        {4, "Ho tieu thu 4", 1102, 1806, "A"},
        {5, "Ho tieu thu 10", 972, 1121, "B"},
        {6, "Ho tieu thu 27", 827, 972, "C"},
        {7, "Ho tieu thu 23", 425, 786, "C"}
    };

    float he_so;

    for (int i = 0; i < 7; i++) {
        s[i].dien_tt = s[i].moi - s[i].cu;
        s[i].tien_dien = s[i].dien_tt * 5000;
        if (!strcmp(s[i].loai, "A"))
            he_so = 0.9;
        if (!strcmp(s[i].loai, "B"))
            he_so = 1.1;
        if (!strcmp(s[i].loai, "C"))
            he_so = 1.3;
        s[i].phai_tra = s[i].tien_dien * he_so;
    }

    printf("-----------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-15s | %-6s | %-6s | %-8s | %-13s | %-10s | %-10s |\n",
           "TT", "Ho TT", "CS Cu", "CS Moi", "Loai ho", "Dien tieu thu", "Tien dien", "Phai tra");
    printf("-----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("| %-2d | %-15s | %-6d | %-6d | %-8s | %-13d | %-10d | %-10.2f |\n",
               s[i].tt, s[i].ho_tt, s[i].cu, s[i].moi, s[i].loai, s[i].dien_tt, s[i].tien_dien, s[i].phai_tra);
    }
    printf("-----------------------------------------------------------------------------------------------\n");

    int max = 0;

    for (int i = 0; i < 7; i++) {
        if (s[i].dien_tt > s[max].dien_tt)
            max = i;
    }

    printf("Thong ke ho tieu thu: \n");
    printf("Ho tieu thu nhieu nhat: %d KWh.   Ho tieu thu: %s\n", s[max].dien_tt, s[max].ho_tt);
    printf("Ho phai tra nhieu nhat: %.2f dong", s[max].phai_tra);
}

#include <stdio.h>
#include <string.h>

struct quy_mo_kinh_doanh {
    int tt;
    char cong_ty[20];
    int so_ld;
    float doanh_thu, lai_rong, ti_suat, loi_nhuan;
    char xep_loai[12];
};

int main() {
    struct quy_mo_kinh_doanh s[] =
    {
        {1, "Vinamilk", 10000, 2.5, 350},
        {2, "Vietcombank", 22000, 1.85, 1100},
        {3, "Vingroup", 50000, 5.3, 150},
        {4, "FPT", 42000, 1.8, 260},
        {5, "Hoa Phat", 30000, 5.8, 330},
        {6, "Vietnam Airline", 15000, 3.2, 21},
        {7, "Petrovietnam", 60000, 29.2, 2100}
    };

    for (int i = 0; i < 7; i++)
    {
        s[i].ti_suat = s[i].lai_rong / s[i].doanh_thu / 1000.0 * 100.0;

        s[i].loi_nhuan = s[i].lai_rong /  s[i].so_ld;

        if (s[i].doanh_thu >= 10)
            strcpy(s[i].xep_loai, "Cao");
        else if (s[i].doanh_thu >= 5)
            strcpy(s[i].xep_loai, "Trung Binh");
        else
            strcpy(s[i].xep_loai, "Thap");
    }

    printf("%60s\n","THONG TIN THONG KE");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-18s | %-10s | %-10s | %-10s | %-10s | %-10s | %-12s |\n",
    "TT", "Cong ty", "So nguoi", "Doanh thu", "Lai rong", "Ti suat", "Loi Nhuan", "Xep loai");
    printf("-----------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("| %-2d | %-18s | %-10d | %-10.2f | %-10.0f | %-10.2f | %-10.3f | %-12s |\n",
        s[i].tt, s[i].cong_ty, s[i].so_ld, s[i].doanh_thu, s[i].lai_rong, s[i].ti_suat, s[i].loi_nhuan, s[i].xep_loai);
    }
    printf("-----------------------------------------------------------------------------------------------------------\n");

    int max1 = 0, max2 = 0, max3 = 0;

    for (int i = 0; i < 7; i++) {
        if (s[i].so_ld > s[max1].so_ld) {
            max1 = i;
        }
        if (s[i].doanh_thu > s[max2].doanh_thu) {
            max2 = i;
        }
        if (s[i].ti_suat > s[max3].ti_suat) {
            max3 = i;
        }
    }

    printf("So nhan vien dong nhat: %d nguoi\n", s[max1].so_ld);
    printf("Doanh thu cao nhat: %.f ti USD\n", s[max2].doanh_thu);
    printf("Ti suat cao nhat: %.2f %%\n", s[max3].ti_suat);

    return 0;
}

/*
Note:
    1 Tỷ USD = 1000 Triệu USD
    doanh thu (tỉ USD)
    lãi ròng (Triệu USD)
*/

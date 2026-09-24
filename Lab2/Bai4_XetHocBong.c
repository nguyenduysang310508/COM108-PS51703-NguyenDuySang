#include <stdio.h>

int main() {
    float diemTrungBinh;
    int hanhKiem;
    int dkDiem, dkHanhKiem, ketQua;

    printf("Nhap diem trung binh: ");
    scanf("%f", &diemTrungBinh);
    printf("Nhap hanh kiem (1 = Tot, 0 = Khac): ");
    scanf("%d", &hanhKiem);

    dkDiem = (diemTrungBinh >= 8.0);
    dkHanhKiem = (hanhKiem == 1);
    ketQua = dkDiem && dkHanhKiem;

    printf("Dieu kien diem trung binh >= 8: %d\n", dkDiem);
    printf("Dieu kien hanh kiem tot: %d\n", dkHanhKiem);
    printf("Ket qua xet hoc bong (1: Dat, 0: Khong dat): %d\n", ketQua);

    return 0;
}
#include <stdio.h>
#include <math.h>

void tinhHocLuc() {
    float diem;
    printf("Nhap diem so (0.0 - 10.0): ");
    scanf("%f", &diem);
    if (diem < 0.0 || diem > 10.0) {
        printf("Diem so nhap vao khong hop le!\n");
    } else if (diem >= 9.0) {
        printf("Hoc luc: Xuat sac\n");
    } else if (diem >= 8.0) {
        printf("Hoc luc: Gioi\n");
    } else if (diem >= 6.5) {
        printf("Hoc luc: Kha\n");
    } else if (diem >= 5.0) {
        printf("Hoc luc: Trung binh\n");
    } else if (diem >= 3.5) {
        printf("Hoc luc: Yeu\n");
    } else {
        printf("Hoc luc: Kem\n");
    }
}

void giaiPTBachai() {
    float a, b, c;
    printf("Nhap 3 he so a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Truong trinh co vo so nghiem.\n");
            } else {
                printf("Truong trinh vo nghiem.\n");
            }
        } else {
            printf("Truong trinh co nghiem duy nhat: x = %.4f\n", -c / b);
        }
    } else {
        float delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Truong trinh vo nghiem.\n");
        } else if (delta == 0) {
            printf("Truong trinh co nghiem kep: x = %.4f\n", -b / (2 * a));
        } else {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Truong trinh co 2 nghiem phan biet: x1 = %.4f, x2 = %.4f\n", x1, x2);
        }
    }
}

void tinhTienDien() {
    float kwh;
    printf("Nhap so kWh tieu thu: ");
    scanf("%f", &kwh);
    if (kwh < 0) {
        printf("So kWh phai la so duong!\n");
        return;
    }
    float tien = 0;
    if (kwh <= 50) {
        tien = kwh * 1678;
    } else if (kwh <= 100) {
        tien = 50 * 1678 + (kwh - 50) * 1734;
    } else if (kwh <= 200) {
        tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    } else if (kwh <= 300) {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    } else if (kwh <= 400) {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    } else {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    }
    printf("Tong tien dien phai tra: %.0f dong\n", tien);
}

int main() {
    int choice;
    do {
        printf("\n=================== MENU LAB 3 ===================\n");
        printf("1. Tinh hoc luc (Bai 2)\n");
        printf("2. Giai phuong trinh bac hai (Bai 3)\n");
        printf("3. Tinh tien dien (Bai 4)\n");
        printf("0. Thoat chuong trinh\n");
        printf("==================================================\n");
        printf("Moi ban chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tinhHocLuc();
                break;
            case 2:
                giaiPTBachai();
                break;
            case 3:
                tinhTienDien();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct SinhVien {
    string hoTen;
    double diem;
    string hocLuc;
};

bool sapXepGiamDan(const SinhVien &a, const SinhVien &b) {
    return a.diem > b.diem;
}

int main() {
    int choice;
    do {
        cout << "\n======================== MENU CHUONG TRINH ========================\n";
        cout << "1. Kiem tra so nguyen (Nguyen to, Chinh phuong)\n";
        cout << "2. Tim UCLN va BCNN cua 2 so\n";
        cout << "3. Tinh tien cho quan Karaoke\n";
        cout << "4. Tinh tien dien\n";
        cout << "5. Chuc nang doi tien\n";
        cout << "6. Tinh lai suat vay ngan hang tra gop (12 thang)\n";
        cout << "7. Chuong trinh vay tien mua xe (24 nam)\n";
        cout << "8. Sap xep thong tin sinh vien theo diem giam dan\n";
        cout << "9. Tinh tong, hieu, tich, thuong 2 phan so\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "===================================================================\n";
        cout << "Nhap lua chon cua ban (0-9): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n--- CHUC NANG 1: KIEM TRA SO NGUYEN ---\n";
                double num;
                cout << "Nhap vao 1 so x: ";
                cin >> num;

                if (num == (int)num) {
                    cout << "- So " << num << " LA so nguyen.\n";
                    int x = (int)num;
                    
                    bool isPrime = true;
                    if (x < 2) isPrime = false;
                    else {
                        for (int i = 2; i <= sqrt(x); i++) {
                            if (x % i == 0) {
                                isPrime = false;
                                break;
                            }
                        }
                    }
                    if (isPrime) cout << "- So " << x << " LA so nguyen to.\n";
                    else cout << "- So " << x << " KHONG PHAI la so nguyen to.\n";

                    int s = sqrt(x);
                    if (s * s == x) cout << "- So " << x << " LA so chinh phuong.\n";
                    else cout << "- So " << x << " KHONG PHAI la so chinh phuong.\n";
                } else {
                    cout << "- So " << num << " KHONG PHAI la so nguyen (la so thuc).\n";
                }
                break;
            }
            case 2: {
                cout << "\n--- CHUC NANG 2: UCLN VA BCNN ---\n";
                long long a, b;
                cout << "Nhap vao 2 so nguyen (x, y): ";
                cin >> a >> b;

                if (a == 0 && b == 0) {
                    cout << "Ca hai so deu bang 0, khong xac dinh UCLN va BCNN.\n";
                    break;
                }

                long long tempA = abs(a), tempB = abs(b);
                long long tich = tempA * tempB;
                while (tempB != 0) {
                    long long r = tempA % tempB;
                    tempA = tempB;
                    tempB = r;
                }
                long long ucln = tempA;
                long long bcnn = (ucln != 0) ? (tich / ucln) : 0;

                cout << "- Uoc so chung lon nhat (UCLN): " << ucln << endl;
                cout << "- Boi so chung nho nhat (BCNN): " << bcnn << endl;
                break;
            }
            case 3: {
                cout << "\n--- CHUC NANG 3: TINH TIEN KARAOKE ---\n";
                int gioBD, gioKT;
                cout << "Nhap gio bat dau (12 - 23): ";
                cin >> gioBD;
                cout << "Nhap gio ket thuc (12 - 23): ";
                cin >> gioKT;

                if (gioBD < 12 || gioKT > 23 || gioBD >= gioKT) {
                    cout << "Loi: Quan chi hoat dong tu 12h den 23h va gio ket thuc phai lon hon gio bat dau!\n";
                    break;
                }

                int soGio = gioKT - gioBD;
                double tongTien = 0;

                if (soGio <= 3) {
                    tongTien = soGio * 50000;
                } else {
                    tongTien = 3 * 50000 + (soGio - 3) * 50000 * 0.7;
                }

                if (gioBD >= 14 && gioBD <= 17) {
                    tongTien = tongTien * 0.9;
                }

                cout << "So gio hat: " << soGio << " gio\n";
                cout << "Tong so tien can thanh toan: " << fixed << setprecision(0) << tongTien << " VND\n";
                break;
            }
            case 4: {
                cout << "\n--- CHUC NANG 4: TINH TIEN DIEN ---\n";
                double kwh;
                cout << "Nhap vao so kWh dien su dung: ";
                cin >> kwh;

                double tienDien = 0;
                if (kwh <= 50) {
                    tienDien = kwh * 1678;
                } else if (kwh <= 100) {
                    tienDien = 50 * 1678 + (kwh - 50) * 1734;
                } else if (kwh <= 200) {
                    tienDien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
                } else if (kwh <= 300) {
                    tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
                } else if (kwh <= 400) {
                    tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
                } else {
                    tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
                }

                cout << "So tien dien phai tra: " << fixed << setprecision(0) << tienDien << " VND\n";
                break;
            }
            case 5: {
                cout << "\n--- CHUC NANG 5: DOI TIEN ---\n";
                int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
                int n = sizeof(menhGia) / sizeof(menhGia[0]);
                int soTien;
                cout << "Nhap so tien can doi: ";
                cin >> soTien;

                cout << "Ket qua doi tien:\n";
                for (int i = 0; i < n; i++) {
                    if (soTien >= menhGia[i]) {
                        int soTo = soTien / menhGia[i];
                        soTien %= menhGia[i];
                        cout << "- " << soTo << " to menh gia " << menhGia[i] << endl;
                    }
                }
                break;
            }
            case 6: {
                cout << "\n--- CHUC NANG 6: LAI SUAT VAY NGAN HANG TRA GOP (12 THANG) ---\n";
                double tienVay;
                cout << "Nhap so tien muon vay: ";
                cin >> tienVay;

                double gocHangThang = tienVay / 12;
                double soTienConLai = tienVay;

                cout << setw(8) << "Ky han" << setw(15) << "Lai phai tra" << setw(15) << "Goc phai tra" << setw(15) << "Tong phai tra" << setw(18) << "So tien con lai" << endl;
                for (int i = 1; i <= 12; i++) {
                    double laiPhaiTra = soTienConLai * 0.05;
                    double tongPhaiTra = laiPhaiTra + gocHangThang;
                    soTienConLai -= gocHangThang;
                    if (soTienConLai < 0) soTienConLai = 0;

                    cout << setw(8) << i 
                         << setw(15) << fixed << setprecision(0) << laiPhaiTra 
                         << setw(15) << gocHangThang 
                         << setw(15) << tongPhaiTra 
                         << setw(18) << soTienConLai << endl;
                }
                break;
            }
            case 7: {
                cout << "\n--- CHUC NANG 7: CHUONG TRINH VAY TIEN MUA XE ---\n";
                double tienVay = 500000000;
                int phanTrVay;
                cout << "Nhap so phan tram vay toi da: ";
                cin >> phanTrVay;

                double tienVayThucTe = tienVay * (phanTrVay / 100.0);
                double tienTraTruoc = tienVay - tienVayThucTe;

                int soThang = 24 * 12;
                double laiSuatThang = 0.072 / 12;
                double gocThang = tienVayThucTe / soThang;
                double laiThangDau = tienVayThucTe * laiSuatThang;
                double tongThangDau = gocThang + laiThangDau;

                cout << "----------------------------------------\n";
                cout << "Tien tra truoc lan dau: " << fixed << setprecision(0) << tienTraTruoc << " VND\n";
                cout << "So tien vay ngan hang: " << tienVayThucTe << " VND\n";
                cout << "So tien phai tra thang dau tien (Goc + Lai): " << tongThangDau << " VND/thang\n";
                break;
            }
            case 8: {
                cout << "\n--- CHUC NANG 8: SAP XEP THONG TIN SINH VIEN ---\n";
                int n;
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                cin.ignore();

                SinhVien ds[100];
                for (int i = 0; i < n; i++) {
                    cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
                    cout << "Ho va ten: ";
                    getline(cin, ds[i].hoTen);
                    cout << "Diem: ";
                    cin >> ds[i].diem;
                    cin.ignore();

                    if (ds[i].diem >= 9.0) ds[i].hocLuc = "Xuat sac";
                    else if (ds[i].diem >= 8.0) ds[i].hocLuc = "Gioi";
                    else if (ds[i].diem >= 6.5) ds[i].hocLuc = "Kha";
                    else if (ds[i].diem >= 5.0) ds[i].hocLuc = "Trung binh";
                    else ds[i].hocLuc = "Yeu";
                }

                sort(ds, ds + n, sapXepGiamDan);

                cout << "\n--- DANH SACH SINH VIEN SAP XEP THEO DIEM GIAM DAN ---\n";
                cout << left << setw(25) << "Ho va ten" << setw(10) << "Diem" << setw(15) << "Hoc luc" << endl;
                cout << "--------------------------------------------------\n";
                for (int i = 0; i < n; i++) {
                    cout << left << setw(25) << ds[i].hoTen 
                         << setw(10) << ds[i].diem 
                         << setw(15) << ds[i].hocLuc << endl;
                }
                break;
            }
            case 9: {
                cout << "\n--- CHUC NANG NANG CAP: TINH TOAN 2 PHAN SO ---\n";
                long long tu1, mau1, tu2, mau2;
                cout << "Nhap phan so thu 1 (tu va mau): ";
                cin >> tu1 >> mau1;
                cout << "Nhap phan so thu 2 (tu va mau): ";
                cin >> tu2 >> mau2;

                if (mau1 == 0 || mau2 == 0) {
                    cout << "Loi: Mau so khong duoc bang 0!\n";
                    break;
                }

                long long tongTu = tu1 * mau2 + tu2 * mau1;
                long long tongMau = mau1 * mau2;

                long long hieuTu = tu1 * mau2 - tu2 * mau1;
                long long hieuMau = mau1 * mau2;

                long long tichTu = tu1 * tu2;
                long long tichMau = mau1 * mau2;

                long long thuongTu = tu1 * mau2;
                long long thuongMau = mau1 * tu2;

                cout << "Tong 2 phan so: " << tongTu << "/" << tongMau << endl;
                cout << "Hieu 2 phan so: " << hieuTu << "/" << hieuMau << endl;
                cout << "Tich 2 phan so: " << tichTu << "/" << tichMau << endl;
                if (thuongMau != 0) {
                    cout << "Thuong 2 phan so: " << thuongTu << "/" << thuongMau << endl;
                } else {
                    cout << "Thuong 2 phan so: Khong xac dinh.\n";
                }
                break;
            }
            case 0:
                cout << "\nTam biet!\n";
                break;
            default:
                cout << "\nLua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}
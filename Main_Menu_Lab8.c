#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ĐỊNH NGHĨA KIỂU CẤU TRÚC (STRUCT SINH VIÊN) ---
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

// --- KHAI BÁO CÁC NGUYÊN MẪU HÀM (FUNCTION PROTOTYPE) ---
void bai1_NhapXuatDanhSach(struct SinhVien ds[], int *n);
void bai2_SapXepDiemTangDan(struct SinhVien ds[], int n);
void bai3_TimKiemTheoMSSV(struct SinhVien ds[], int n);
void bai4_XuatHocBongTheoNganh(struct SinhVien ds[], int n);
void inThongTinMotSinhVien(struct SinhVien sv, int index);

// HÀM CHÍNH (MAIN) - DỰNG KHUNG MENU CHƯƠNG TRÌNH
int main() {
    // Khai báo mảng cấu trúc tối đa 50 phần tử và biến đếm số lượng sinh viên hiện có
    struct SinhVien ds[50];
    int n = 0; // Ban đầu danh sách chưa có sinh viên nào
    int chon;

    do {
        printf("\n+------------------------------------------------+\n");
        printf("|            MENU CHUONG TRINH LAB 8             |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Nhap va xuat danh sach sinh vien            |\n");
        printf("| 2. Sap xep sinh vien theo diem tang dan        |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV                |\n");
        printf("| 4. Xuat sinh vien nhan hoc bong theo nganh     |\n");
        printf("| 5. Thoat chuong trinh                          |\n");
        printf("+------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);
        getchar(); // Xóa bộ nhớ đệm để tránh trôi lệnh khi nhập chuỗi phía sau

        // Kiểm tra lưu ý chung: Các chức năng 2, 3, 4 yêu cầu danh sách không được rỗng
        if ((chon == 2 || chon == 3 || chon == 4) && n == 0) {
            printf("\nThong bao: Danh sach hien tai dang rong! Vui long chon chuc nang 1 de nhap du lieu truoc.\n");
            continue; // Quay lại đầu vòng lặp Menu
        }

        switch(chon) {
            case 1:
                printf("\n--- BAN DA CHON CHUC NANG 1 ---\n");
                bai1_NhapXuatDanhSach(ds, &n);
                break;
            case 2:
                printf("\n--- BAN DA CHON CHUC NANG 2 ---\n");
                bai2_SapXepDiemTangDan(ds, n);
                break;
            case 3:
                printf("\n--- BAN DA CHON CHUC NANG 3 ---\n");
                bai3_TimKiemTheoMSSV(ds, n);
                break;
            case 4:
                printf("\n--- BAN DA CHON CHUC NANG 4 ---\n");
                bai4_XuatHocBongTheoNganh(ds, n);
                break;
            case 5:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
printf("\nChuc nang khong hop le! Vui long chon lai tu 1 den 5.\n");
        }
    } while(chon != 5);

    return 0;
}

// HÀM BỔ TRỢ: IN THÔNG TIN MỘT SINH VIÊN THEO ĐÚNG ĐỊNH DẠNG MẪU
void inThongTinMotSinhVien(struct SinhVien sv, int index) {
    printf("Sinh vien thu [%d]:\n", index);
    printf("MSSV: %s\n", sv.mssv);
    printf("Ten SV: %s\n", sv.tenSV);
    printf("Nganh hoc: %s\n", sv.nganhHoc);
    printf("Diem TB: %.2f\n", sv.diemTB); // Làm tròn đúng 2 chữ số thập phân
}


// --- CHI TIẾT CÁC HÀM CHỨC NĂNG ---

// BÀI 1: NHẬP VÀ XUẤT DANH SÁCH SINH VIÊN
void bai1_NhapXuatDanhSach(struct SinhVien ds[], int *n) {
    int soLuong;
    
    // Vòng lặp yêu cầu nhập số lượng sinh viên hợp lệ (từ 1 đến 50)
    do {
        printf("Nhap so luong sinh vien (toi da 50): ");
        scanf("%d", &soLuong);
        getchar(); // Xóa bộ đệm
        if (soLuong <= 0 || soLuong > 50) {
            printf("So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (soLuong <= 0 || soLuong > 50);

    *n = soLuong; // Cập nhật số lượng phần tử vào biến n của hàm main

    // Vòng lặp nhập thông tin cho từng sinh viên
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        
        printf("Mã so sinh vien: ");
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        ds[i].mssv[strcspn(ds[i].mssv, "\n")] = '\0'; // Loại bỏ ký tự '\n'

        printf("Ten sinh vien: ");
        fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
        ds[i].tenSV[strcspn(ds[i].tenSV, "\n")] = '\0';

        printf("Nganh hoc: ");
        fgets(ds[i].nganhHoc, sizeof(ds[i].nganhHoc), stdin);
        ds[i].nganhHoc[strcspn(ds[i].nganhHoc, "\n")] = '\0';

        // Kiểm tra điều kiện điểm trung bình phải từ 0.0 đến 10.0
        do {
            printf("Diem trung binh (0.0 - 10.0): ");
            scanf("%f", &ds[i].diemTB);
            getchar(); // Xóa bộ đệm
            if (ds[i].diemTB < 0.0 || ds[i].diemTB > 10.0) {
                printf("Diem khong hop le! Vui long nhap lai.\n");
            }
        } while (ds[i].diemTB < 0.0 || ds[i].diemTB > 10.0);
    }

    // Xuất toàn bộ danh sách vừa nhập
    printf("\n=== DANH SACH SINH VIEN VUA NHAP ===\n");
    for (int i = 0; i < *n; i++) {
        inThongTinMotSinhVien(ds[i], i);
        printf("\n");
    }
}

// BÀI 2: SẮP XẾP SINH VIÊN THEO ĐIỂM TĂNG DẦN
void bai2_SapXepDiemTangDan(struct SinhVien ds[], int n) {
    struct SinhVien svTemp; // Biến cấu trúc trung gian phục vụ hoán vị hoàn chỉnh

    // Thuật toán Bubble Sort lồng nhau duyệt đầy đủ các cặp phần tử
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
if (ds[i].diemTB > ds[j].diemTB) { // > để sắp xếp tăng dần
                // Hoán đổi cả phần tử cấu trúc
                svTemp = ds[i];
                ds[i] = ds[j];
                ds[j] = svTemp;
            }
        }
    }

    printf("\n=== DANH SACH SINH VIEN SAU KHI SAP XEP DIEM TANG DAN ===\n");
    for (int i = 0; i < n; i++) {
        inThongTinMotSinhVien(ds[i], i);
        printf("\n");
    }
}

// BÀI 3: TÌM KIẾM SINH VIÊN THEO MÃ SỐ (MSSV)
void bai3_TimKiemTheoMSSV(struct SinhVien ds[], int n) {
    char maTim[50];
    int flag = 0; // Biến đánh dấu tìm thấy (0: không thấy, 1: tìm thấy)

    printf("Nhap ma so sinh vien can tim: ");
    fgets(maTim, sizeof(maTim), stdin);
    maTim[strcspn(maTim, "\n")] = '\0'; // Xóa dấu xuống dòng

    // Duyệt mảng và so sánh chuỗi bằng hàm strcmp()
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, maTim) == 0) {
            printf("\nTim thay sinh vien:\n");
            printf("MSSV: %s\n", ds[i].mssv);
            printf("Ten SV: %s\n", ds[i].tenSV);
            printf("Nganh hoc: %s\n", ds[i].nganhHoc);
            printf("Diem TB: %.2f\n", ds[i].diemTB);
            flag = 1; // Đánh dấu tìm thấy thành công
            break;    // Dừng vòng lặp vì MSSV là duy nhất
        }
    }

    // Nếu duyệt hết mảng mà flag vẫn bằng 0 nghĩa là không có sinh viên này
    if (flag == 0) {
        printf("Khong tim thay sinh vien co MSSV: %s\n", maTim);
    }
}

// BÀI 4: XUẤT DANH SÁCH SINH VIÊN NHẬN HỌC BỔNG THEO NGÀNH (DIEMTB >= 8.0)
void bai4_XuatHocBongTheoNganh(struct SinhVien ds[], int n) {
    int coHocBongChung = 0; // Biến kiểm tra xem cả trường có ai được học bổng không

    // Bước bổ sung theo gợi ý thuật toán: Tạo một bản sao mảng để sắp xếp theo ngành trước,
    // tránh làm đảo lộn thứ tự danh sách gốc của người dùng.
    struct SinhVien dsCopy[50];
    for(int i = 0; i < n; i++) {
        dsCopy[i] = ds[i];
    }

    // Sắp xếp mảng bản sao theo tên Ngành học bảng chữ cái ASCII để gom các bạn cùng ngành lại gần nhau
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(dsCopy[i].nganhHoc, dsCopy[j].nganhHoc) > 0) {
                struct SinhVien temp = dsCopy[i];
                dsCopy[i] = dsCopy[j];
                dsCopy[j] = temp;
            }
        }
    }

    // Tiến hành in danh sách gom cụm theo ngành học
    for (int i = 0; i < n; i++) {
        // Kiểm tra xem sinh viên hiện tại có đủ điều kiện học bổng (DiemTB >= 8.0) không
        if (dsCopy[i].diemTB >= 8.0) {
            
            // Kỹ thuật kiểm tra xem Ngành học của bạn này đã được in tiêu đề trước đó chưa
// Bằng cách so sánh ngành của bạn này với các bạn đứng trước (từ chỉ số 0 đến i-1)
            int nganhDaIn = 0;
            for (int k = 0; k < i; k++) {
                if (strcmp(dsCopy[i].nganhHoc, dsCopy[k].nganhHoc) == 0 && dsCopy[k].diemTB >= 8.0) {
                    nganhDaIn = 1; // Ngành này đã có sinh viên trước được in và tiêu đề đã xuất hiện
                    break;
                }
            }

            // Nếu ngành này chưa từng được in tiêu đề, tiến hành in ra tên ngành một lần duy nhất
            if (nganhDaIn == 0) {
                printf("\nNganh: %s\n", dsCopy[i].nganhHoc);
            }

            // In thông tin chi tiết dòng sinh viên nhận học bổng theo đúng định dạng mẫu
            printf(" - [%s] - [%s] - Diem TB: %.2f\n", dsCopy[i].mssv, dsCopy[i].tenSV, dsCopy[i].diemTB);
            coHocBongChung = 1;
        }
    }

    // Trường hợp lướt toàn bộ danh sách không tìm thấy bất kỳ ai có điểm >= 8.0
    if (coHocBongChung == 0) {
        printf("\nKhong co sinh vien nao dat hoc bong.\n");
    }
}

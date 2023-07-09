#include "LopHoc.h"
#define SOTIENMOTCHI 120000
#define KHA 2500000
#define GIOI 3000000
#define XUATSAC 3500000

void NhapLopHoc(LOPHOC &lh)
{
	do{
		printf("\nNhap vao so luong sinh vien trong lop hoc: ");
		scanf("%d", &lh.n);

		if(lh.n < 0)
		{
			printf("\nSo luong khong hop le. Xin kiem tra lai !");
		}
	}while(lh.n < 0);

	// cấp phát bộ nhớ cho con trỏ
	lh.arr = (SINHVIEN *)malloc(lh.n * sizeof(SINHVIEN));
	//lh.arr = new SINHVIEN[lh.n];

	for(int i = 0; i < lh.n; i++)
	{
		printf("\n------- Nhap Sinh Vien Thu %d ------", i + 1);
		int Check; // chưa bị trùng
		do{
			Check = 0; // reset.

			fflush(stdin);
			printf("\nNhap vao ma so: ");
			gets(lh.arr[i].MaSo);

			// Kiểm tra xem mã số của sinh viên sau có bị trùng với mã số của các sinh viên trước đó hay không ?
			for(int j = i - 1; j >= 0; j--)
			{
				if(strcmp(lh.arr[i].MaSo, lh.arr[j].MaSo) == 0)
				{
					Check = 1; // Cap nhat bi trung
					break; // thoat ra luon
				}
			}

			if(Check == 1)
			{
				printf("\nMa so sinh vien nay da bi trung. Xin hay nhap lai ma so moi");
			}
		}while(Check == 1);

		// Nhập tiếp các thông tin còn thiếu.
		NhapSinhVien(lh.arr[i]);
	}
}

void XuatLopHoc(LOPHOC lh)
{
	for(int i = 0; i < lh.n; i++)
	{
		printf("\n------- Sinh Vien Thu %d ------", i + 1);
		XuatSinhVien(lh.arr[i]);
	}
}

void HoanVi(SINHVIEN &a, SINHVIEN &b)
{
	SINHVIEN Temp = a;
	a = b;
	b = Temp;
}

void SapXepLopHoc(LOPHOC &lh, char phanloai)
{
	for(int i = 0; i < lh.n - 1; i++)
	{
		for(int j = i + 1; j < lh.n; j++)
		{
			if(phanloai == 't')
			{
				if(TinhDiemTrungBinh(lh.arr[i]) > TinhDiemTrungBinh(lh.arr[j]))
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
			else if(phanloai == 'g')
			{
				if(TinhDiemTrungBinh(lh.arr[i]) < TinhDiemTrungBinh(lh.arr[j]))
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
			
		}
	}
}

int DemSoLuongHocBong(LOPHOC lh)
{
	int dem = 0;
	for(int i = 0; i < lh.n; i++)
	{
		if(strcmp(XepLoai(lh.arr[i]), "Kha") == 0 || strcmp(XepLoai(lh.arr[i]), "Gioi") == 0)
		{
			dem++;
		}
	}
	return dem;
}

void XuLyHocLai(LOPHOC lh, int &dem, float &tien)
{
	tien = 0; // khởi tạo tiền = 0
	dem = 0;

	// duyệt vào từng sinh viên trong lớp học.
	for(int i = 0; i < lh.n; i++)
	{
		int Check = 0;

		// duyệt vào từng môn học của sinh viên thứ i trong danh sách lớp.
		for(int j = 0; j < lh.arr[i].danhsachmon.n; j++)
		{
			if(lh.arr[i].danhsachmon.arr[j].SoDiem < 5)
			{
				Check = 1;
				

				// cộng dồn tiền học lại của môn đó.
				tien += lh.arr[i].danhsachmon.arr[j].SoChi * SOTIENMOTCHI;
			}
			
		}
		if(Check == 1)
		{
			dem++;
		}
	}
}

SINHVIEN* TimKiemThongTin(LOPHOC lh, char* MaTimKiem)
{
	for(int i = 0; i < lh.n; i++)
	{
		if(strcmp(lh.arr[i].MaSo, MaTimKiem) == 0)
		{
			return &lh.arr[i];
		}
	}
	return NULL;
}

template <typename sondeptrai>
// vừa để gia tăng, vừa giảm bớt ô nhớ.
void REALLOC(sondeptrai *&a, int OldSize, int NewSize)
{
	// Bước 1: Tạo ra 1 mảng mới là bản sao của mảng cũ rồi đổ dữ liệu từ mảng cũ sang.
	sondeptrai *tam = new sondeptrai[OldSize];

	for(int i = 0; i < OldSize; i++)
	{
		tam[i] = a[i];
	}

	// Bước 2: Xóa mảng cũ đi và cấp mới lại.
	delete[] a;
	a = new sondeptrai[NewSize];

	// Bước 3: Đổ dữ liệu từ mảng tạm sang mảng mới.
	int Min = OldSize < NewSize ? OldSize : NewSize;

	for(int i = 0; i < Min; i++)
	{
		a[i] = tam[i];
	}

	// Bước 4: Xóa mảng tạm đi.
	delete[] tam;
}

// Xóa 1 sinh viên.
void XoaSinhVien(LOPHOC &lh, int vitrixoa)
{
	for(int i = vitrixoa + 1; i < lh.n; i++)
	{
		//a[i - 1] = a[i];
		lh.arr[i - 1] = lh.arr[i];
	}
	lh.n--;

	// để cập nhật bộ nhớ.
	REALLOC(lh.arr, lh.n + 1, lh.n);
}

// Xóa sinh viên dựa trên mã số.
void XoaSinhVienDuaTrenMaSo(LOPHOC &lh, char *MaSo)
{
	// duyệt danh sách để tìm ra mã số
	for(int i = 0; i < lh.n; i++)
	{
		if(strcmp(lh.arr[i].MaSo, MaSo) == 0)
		{
			XoaSinhVien(lh, i);
			break; // thoát ra khỏi vòng lặp ngay khi vừa xóa xong 1 thằng bởi vì mã số sinh viên sẽ không có chuyện bị trùng.
		}
	}
}

// Xóa tất cả sinh viên bị rớt môn trong danh sách.
void XoaTatCaSinhVienRotMon(LOPHOC &lh)
{
	// duyệt qua danh sách sinh viên.
	for(int i = 0; i < lh.n; i++)
	{
		// thấy thằng nào bị rớt môn => xóa
		if(KiemTraBiRotMon(lh.arr[i]) == 1)
		{
			XoaSinhVien(lh, i);
			i--;
		}
	}
}

// cập nhật sinh viên dựa trên mã số
void CapNhatDuaTrenMaSo(LOPHOC &lh, char *MaSo)
{
	// duyệt qua danh sách các sinh viên đang có trong lớp.
	for(int i = 0; i < lh.n; i++)
	{
		// tìm thấy sinh viên có mã số cần cập nhật.
		if(strcmp(lh.arr[i].MaSo, MaSo) == 0)
		{
			fflush(stdin);
			printf("\nNhap lai ten: ");
			gets(lh.arr[i].Ten);

			printf("\nNhap lai danh sach mon hoc: ");
			NhapDanhSachMon(lh.arr[i].danhsachmon);

			break; // Bởi vì mã số chỉ có 1 thôi.
		}
	}
}

/*
ý tưởng 1:
B1: Duyệt qua danh sách các sinh viên trong lớp
B2: Xét vào từng sinh viên, tính ra điểm trung bình 
B3: Sau đó dựa vào điểm trung bình để quy ra thuộc loại gì từ đó cộng tiền học bổng.
*/

float TongTienHocBong(LOPHOC lh)
{
	float Tong = 0;

	// B1
	for(int i = 0; i < lh.n; i++)
	{
		// B2
		float Dtb = TinhDiemTrungBinh(lh.arr[i]);

		// B3
		if(Dtb >= 7 && Dtb < 8)
		{
			// khá
			Tong += KHA;
		}
		else if(Dtb >= 8 && Dtb < 9)
		{
			Tong += GIOI;
		}
		else if(Dtb > 9)
		{
			Tong += XUATSAC;
		}
	}
	return Tong;
}

void SapXepTen(LOPHOC &lh, char phanloai)
{
	for(int i = 0; i < lh.n - 1; i++)
	{
		for(int j = i + 1; j < lh.n; j++)
		{
			if(phanloai == 't')
			{
				char Ten1[30], Ten2[30];
				// strcpy(Ten1, LocRaTen(lh.arr[i]));
				// strcpy(Ten2, LocRaTen(lh.arr[j]));

				if(strcmp(Ten1, Ten2) == 1)
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
			else if(phanloai == 'g')
			{
				char Ten1[30], Ten2[30];
				// strcpy(Ten1, LocRaTen(lh.arr[i]));
				// strcpy(Ten2, LocRaTen(lh.arr[j]));

				if(strcmp(Ten1, Ten2) == -1)
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
		}
	}
}
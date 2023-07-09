#include "SinhVien.h"

void NhapSinhVien(SINHVIEN &sv)
{
	fflush(stdin);
	printf("\nNhap vao ho ten: ");
	gets(sv.Ten);

	printf("\nNhap vao danh sach mon hoc: ");
	NhapDanhSachMon(sv.danhsachmon);
}

void XuatSinhVien(SINHVIEN sv)
{
	printf("\nMa so: %s", sv.MaSo);
	printf("\nHo ten: %s", sv.Ten);
	printf("\nDanh sach cac mon hoc: ");
	XuatDanhSachMon(sv.danhsachmon);
	printf("\nDiem trung binh la: %f", TinhDiemTrungBinh(sv));
}

float TinhDiemTrungBinh(SINHVIEN sv)
{
	float TongDiem = 0;
	int TongChi = 0;
	for(int i = 0; i < sv.danhsachmon.n; i++)
	{
		TongDiem += (sv.danhsachmon.arr[i].SoDiem * sv.danhsachmon.arr[i].SoChi);
		TongChi += sv.danhsachmon.arr[i].SoChi;
	}
	return TongDiem / TongChi;
}

char* XepLoai(SINHVIEN sv)
{
	float Dtb = TinhDiemTrungBinh(sv);

	if(Dtb < 2)
	{
		return "Kem";
	}

	if(Dtb < 5)
	{
		return "Yeu";
	}

	if(Dtb < 7)
	{
		return "Trung Binh";
	}

	if(Dtb < 8)
	{
		return "Kha";
	}

	if(Dtb < 9)
	{
		return "Gioi";
	}
	return "Xuat Sac";
}

// Kiểm tra 1 đối tượng sinh viên có bị rớt ít nhất 1 môn hay không ?
// rớt thì trả về 1, không rớt trả về 0
int KiemTraBiRotMon(SINHVIEN sv)
{
	// đi vào danh sách các môn học của sinh viên
	for(int i = 0; i < sv.danhsachmon.n; i++)
	{
		// Kiểm tra từng môn xem nếu điểm thi < 5 => return 1 (rớt môn)
		if(sv.danhsachmon.arr[i].SoDiem < 5)
		{
			return 1;
		}
	}
	return 0;
}
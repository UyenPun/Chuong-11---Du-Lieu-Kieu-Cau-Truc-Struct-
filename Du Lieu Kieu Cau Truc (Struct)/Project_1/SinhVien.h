#pragma once
#include "DanhSachMon.h"

struct SinhVien
{
	char MaSo[10], Ten[50];
	DANHSACHMONHOC danhsachmon;
};
typedef struct SinhVien SINHVIEN;

void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN);
float TinhDiemTrungBinh(SINHVIEN);
char* XepLoai(SINHVIEN);
int KiemTraBiRotMon(SINHVIEN);
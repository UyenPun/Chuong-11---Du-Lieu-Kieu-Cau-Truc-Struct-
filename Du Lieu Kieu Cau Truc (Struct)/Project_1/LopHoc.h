#pragma once
#include "SinhVien.h"
#include <string.h>

struct LopHoc
{
	int n; // số lượng sinh viên
	SINHVIEN *arr; // mảng động sinh viên
};
typedef struct LopHoc LOPHOC;

void NhapLopHoc(LOPHOC &);
void XuatLopHoc(LOPHOC);
void HoanVi(SINHVIEN &, SINHVIEN &);
void SapXepLopHoc(LOPHOC &, char);
int DemSoLuongHocBong(LOPHOC);
void XuLyHocLai(LOPHOC, int &, float &);
SINHVIEN* TimKiemThongTin(LOPHOC, char*);
void XoaSinhVien(LOPHOC &, int);
void XoaSinhVienDuaTrenMaSo(LOPHOC &, char *);
void XoaTatCaSinhVienRotMon(LOPHOC &);
void CapNhatDuaTrenMaSo(LOPHOC &, char *);
float TongTienHocBong(LOPHOC);
void SapXepTen(LOPHOC &, char);



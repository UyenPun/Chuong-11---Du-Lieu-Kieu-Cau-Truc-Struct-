#pragma once
#include "MonHoc.h"
#include <stdlib.h>

struct DanhSachMonHoc
{
	int n;
	MONHOC *arr;
};
typedef struct DanhSachMonHoc DANHSACHMONHOC;

void NhapDanhSachMon(DANHSACHMONHOC &);
void XuatDanhSachMon(DANHSACHMONHOC);
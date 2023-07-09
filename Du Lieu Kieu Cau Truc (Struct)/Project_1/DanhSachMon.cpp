#include "DanhSachMon.h"

void NhapDanhSachMon(DANHSACHMONHOC &ds)
{
	do{
		printf("\nNhap vao so luong mon hoc: ");
		scanf("%d", &ds.n);

		if(ds.n < 0)
		{
			printf("\nSo luong mon hoc phai la so duong. Xin kiem tra lai !");
		}
	}while(ds.n < 0);

	// cấp phát bộ nhớ
	//ds.arr = (MONHOC *)malloc(ds.n * sizeof(MONHOC));
	ds.arr = new MONHOC[ds.n];

	for(int i = 0; i < ds.n; i++)
	{
		printf("\n-------- Nhap vao mon hoc thu %d --------\n", i + 1);
		NhapMonHoc(ds.arr[i]);
	}
}

void XuatDanhSachMon(DANHSACHMONHOC ds)
{
	for(int i = 0; i < ds.n; i++)
	{
		printf("\n-------- Mon hoc thu %d --------\n", i + 1);
		XuatMonHoc(ds.arr[i]);
	}
}
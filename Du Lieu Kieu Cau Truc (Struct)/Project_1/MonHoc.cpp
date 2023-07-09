#include "MonHoc.h"

void NhapMonHoc(MONHOC &mh)
{
	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nNhap vao ten mon hoc: ");
	gets(mh.TenMon);

	// điểm phải nằm trong đoạn 0 --> 10
	do{
		printf("\nNhap vao so diem mon hoc: ");
		scanf("%f", &mh.SoDiem);

		if(mh.SoDiem < 0 || mh.SoDiem > 10)
		{
			printf("\nSo diem phai nam trong doan tu 0 --> 10. Xin kiem tra lai !");
		}
	}while(mh.SoDiem < 0 || mh.SoDiem > 10);

	do{
		printf("\nNhap vao so chi: ");
		scanf("%d", &mh.SoChi);

		if(mh.SoChi < 0)
		{
			printf("\nSo chi khong duoc < 0 ! Xin kiem tra lai !");
		}
	}while(mh.SoChi < 0);
}

void XuatMonHoc(MONHOC mh)
{
	printf("\nTen mon hoc: %s", mh.TenMon);
	printf("\nDiem thi: %f", mh.SoDiem);
	printf("\nSo chi: %d", mh.SoChi);
}
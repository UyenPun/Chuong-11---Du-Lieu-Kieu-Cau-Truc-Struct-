#include "LopHoc.h"

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

int main()
{
	LOPHOC lh;

	NhapLopHoc(lh);
	XuatLopHoc(lh);

	/*printf("\nDanh sach lop sau khi sap xep tang dan la\n");
	SapXepLopHoc(lh, 't');
	XuatLopHoc(lh);

	printf("\nDanh sach lop sau khi sap xep giam dan la\n");
	SapXepLopHoc(lh, 'g');
	XuatLopHoc(lh);*/

	//int SoHocSinhNhanHocBong = DemSoLuongHocBong(lh);
	//printf("\nSo luong nhan hoc bong la: %d", SoHocSinhNhanHocBong);

	//char MaTimKiem[30];
	//fflush(stdin); // xóa bộ nhớ đệm.
	//printf("\nNhap vao ma tim kiem la: ");
	//gets(MaTimKiem);

	//SINHVIEN *sv = TimKiemThongTin(lh, MaTimKiem);

	//if(sv == NULL)
	//{
	//	printf("\nKhong tim thay thong tin sinh vien");
	//}
	//else
	//{
	//	printf("\nTim thay thong tin sinh vien la\n");
	//	XuatSinhVien(*sv);
	//}

	SINHVIEN them; // thêm vào cuối danh sách lớp.

	// Nhập thông tin sinh viên cần thêm

	//fflush(stdin);
	//printf("\nNhap vao ma so: ");
	//gets(them.MaSo);

	//NhapSinhVien(them);

	////CapPhatLai(lh);
	////realloc(lh.arr, (lh.n + 1) * sizeof(SINHVIEN));
	//REALLOC(lh.arr, lh.n, lh.n + 1);

	//// Đưa thông tin sinh viên thêm vào cuối cùng.
	//lh.arr[lh.n] = them;

	//lh.n++; // Tăng số lượng sinh viên lên.

	//printf("\nDanh sach lop hoc sau khi them la\n");
	//XuatLopHoc(lh);

	// test
	/*XoaSinhVien(lh, 0);
	printf("\nDanh sach lop sau khi xoa la\n");
	XuatLopHoc(lh);*/

	//XoaSinhVienDuaTrenMaSo(lh, "1");

	/*XoaTatCaSinhVienRotMon(lh);
	printf("\nDanh sach lop sau khi xoa la\n");
	XuatLopHoc(lh);*/

	CapNhatDuaTrenMaSo(lh, "5");
	printf("\nDanh sach sau khi cap nhat la:\n");
	XuatLopHoc(lh);


	// giải phóng bộ nhớ.
	//free(lh.arr);
	delete []lh.arr;

	
	

	getch();
	return 0;
}
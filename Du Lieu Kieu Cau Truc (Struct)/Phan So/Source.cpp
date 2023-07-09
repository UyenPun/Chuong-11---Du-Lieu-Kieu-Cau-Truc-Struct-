#include <iostream>
using namespace std;

struct PhanSo
{
	int TuSo, MauSo;
};
typedef struct PhanSo PHANSO;

void NhapPhanSo(PHANSO &ps)
{
	cout << "\nNhap vao tu so: ";
	cin >> ps.TuSo;

	do{
		cout << "\nNhap vao mau so: ";
		cin >> ps.MauSo;

		if(ps.MauSo == 0)
		{
			cout << "\nPhan So khong hop le. Xin kiem tra lai !";
		}
	}while(ps.MauSo == 0);
}

void XuatPhanSo(PHANSO ps)
{
	cout << ps.TuSo << "/" << ps.MauSo;
}

PHANSO TinhTong(PHANSO ps1, PHANSO ps2)
{
	// a/b + c/d = (a * d + b * c) / (b * d)
	PHANSO Temp;
	Temp.TuSo = ps1.TuSo * ps2.MauSo + ps2.TuSo * ps1.MauSo;
	Temp.MauSo = ps1.MauSo * ps2.MauSo;

	return Temp;
}

int TimUCLN(int a, int b)
{
	if(a == 0 && b != 0)
		return b;
	if(b == 0 && a != 0)
		return a;

	if(a < 0)
		a *= -1;

	if(b < 0)
		b *= -1;

	while(a != b)
	{
		if(a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a;
}

void RutGonPhanSo(PHANSO &ps)
{
	// tử và mẫu sẽ chia cho UCLN của tụi nó.
	int ucln = TimUCLN(ps.TuSo, ps.MauSo); // tạo biến phụ.

	ps.TuSo /= ucln;
	ps.MauSo /= ucln;
}

// operator nhập
istream& operator >>(istream &is, PHANSO &ps) // is, ps là các biến tự đặt
{
	// chỗ nào là cin thì thay bằng is

	cout << "\nNhap vao tu so: ";
	is >> ps.TuSo;

	do{
		cout << "\nNhap vao mau so: ";
		is >> ps.MauSo;

		if(ps.MauSo == 0)
		{
			cout << "\nPhan So khong hop le. Xin kiem tra lai !";
		}
	}while(ps.MauSo == 0);

	return is;
}

// operator xuất
ostream& operator <<(ostream &os, PHANSO ps) // is, ps là các biến tự đặt
{
	// chỗ nào là cout thì thay bằng os

	os << ps.TuSo << "/" << ps.MauSo;
	return os;
}


// ps1 + ps2
PHANSO operator+(PHANSO ps1, PHANSO ps2)
{
	// a/b + c/d = (a * d + b * c) / (b * d)
	PHANSO Temp;
	Temp.TuSo = ps1.TuSo * ps2.MauSo + ps2.TuSo * ps1.MauSo;
	Temp.MauSo = ps1.MauSo * ps2.MauSo;

	return Temp;
}

// ps1 + songuyen
PHANSO operator+(PHANSO ps1, int songuyen)
{
	PHANSO ps2;
	ps2.TuSo = songuyen;
	ps2.MauSo = 1;

	// gọi lại hàm đã có
	return ps1 + ps2;
}

// songuyen + ps1
PHANSO operator+(int songuyen, PHANSO ps1)
{
	// gọi lại hàm ở trên.
	return ps1 + songuyen;
}


PHANSO operator-(PHANSO ps1, PHANSO ps2)
{
	PHANSO Temp;
	Temp.TuSo = ps1.TuSo * ps2.MauSo - ps2.TuSo * ps1.MauSo;
	Temp.MauSo = ps1.MauSo * ps2.MauSo;

	return Temp;
}

PHANSO operator*(PHANSO ps1, PHANSO ps2)
{
	PHANSO Temp;
	Temp.TuSo = ps1.TuSo * ps2.TuSo;
	Temp.MauSo = ps1.MauSo * ps2.MauSo;

	return Temp;
}

PHANSO operator/(PHANSO ps1, PHANSO ps2)
{
	// ps1/ps2 = ps1 * (ps2 bị đảo lại)

	PHANSO Temp; // phân số đảo của ps2
	Temp.TuSo = ps2.MauSo;
	Temp.MauSo = ps2.TuSo;

	// Lợi dụng lại hàm ở trên.
	return ps1 * Temp;
}



int main()
{
	PHANSO ps1, ps2;
	cin >> ps1;
	cout << ps1;

	//NhapPhanSo(ps1);
	//XuatPhanSo(ps1);

	// int a; cin >> a; cout << a;
	// PhanSo ps1; cin >> ps1; cout << ps1;
	// ps1, ps2, ps3, ps4. NhapPhanSo(ps1); NhapPhanSo(ps2); NhapPhanSo(ps3); NhapPhanSo(ps4);
	// cin >> ps1 >> ps2 >> ps3 >> ps4;

	//NhapPhanSo(ps2);
	//XuatPhanSo(ps2);
	cin >> ps2;
	cout << ps2;

	//PHANSO Tong = TinhTong(ps1, ps2);
	PHANSO Tong = 5 + ps1;
	RutGonPhanSo(Tong);
	cout << "\n5 + ps1 = ";
	XuatPhanSo(Tong);

	PHANSO Hieu = ps1 - ps2;
	RutGonPhanSo(Hieu);
	cout << "\nps1 - ps2 = ";
	XuatPhanSo(Hieu);

	PHANSO Tich = ps1 * ps2;
	RutGonPhanSo(Tich);
	cout << "\nps1 x ps2 = ";
	XuatPhanSo(Tich);

	PHANSO Thuong = ps1 / ps2;
	RutGonPhanSo(Thuong);
	cout << "\nps1 / ps2 = ";
	XuatPhanSo(Thuong);

	/* 
	ps1, ps2, ps3, ps4
	muốn tính tổng của 4 cái thì sao ?
	=> GIẢI PHÁP

	CÁCH 1:
	Tong = TinhTong(ps1, ps2);
	Tong = TinhTong(ps3, Tong);
	Tong = TinhTong(ps4, Tong);

	CÁCH 2:
	Tong = TinhTong(TinhTong(TinhTong(ps1, ps2), ps3), ps4);

	CÁCH 3:
	Tong = ps1 + ps2 + ps3 + ps4;
	*/


	system("pause");
	return 0;
}
// #pragma once
#ifndef _MONHOC_
#define _MONHOC_

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct MonHoc
{
	char TenMon[50];
	float SoDiem;
	int SoChi;
};
typedef struct MonHoc MONHOC;

void NhapMonHoc(MONHOC &);
void XuatMonHoc(MONHOC);

#endif
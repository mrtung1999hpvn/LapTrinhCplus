//Thông tin của nhân viên trong một công ty gồm: Họ tên, Năm sinh, Lương cơ bản (lương một ngày công), Số ngày công.
//a) Anh (chị) hãy xây dựng lớp Nhan_Vien của công ty với các thuộc tính trên. Lớp Nhan_Vien có các phương thức: Khởi tạo, Nhập thông tin, In thông tin, Tính lương tháng của nhân viên (theo công thức: lương tháng = số ngày công * lương cơ bản).
//b) Xây dựng lớp Bang_Luong với các thuộc tính: Số lượng nhân viên, Danh sách nhân viên. Lớp Bang_Luong có các phương thức: Khởi tạo (Khởi tạo một danh sách rỗng), Hủy bỏ (hủy danh sách), Nhập danh sách, In danh sách, Thống kế các nhân viên có lương tháng < 5.000.000.
#include <iostream>


using namespace std;
class CongTy
{
protected:
	char HoTen[50];
	int NamSinh;
	int LuongCb;
	int SoNgayCong;
public:
	CongTy(){}
	void Nhap()
	{
		fflush(stdin);
		cout<<"Ho ten : ";cin.getline(HoTen,50);
		cout<<"Nam sinh : ";cin>>NamSinh;
		cout<<"Luong co ban : "; cin>>LuongCb;
		cout<<"So ngay cong : "; cin>>SoNgayCong;		
	}
	void Xuat()
	{
		cout<<"Ho ten : "<<HoTen<<endl;
		cout<<"Nam sinh : "<<NamSinh;
		cout<<"Luong co ban : "<<LuongCb;
		cout<<"So ngay cong : "<<SoNgayCong;
		cout<<"Luong : "<<LuongNV();
	}
	int LuongNV()
	{
		return SoNgayCong*LuongCb;
	}
};
class Bang_Luong
{
protected:
	int SoLuongNV;
public:
	Bang_Luong(){}
	void Nhap()
	{
		cout<<"Nhap so luong nhan vien :";cin>>SoLuongNV;
		CongTy *nv = new CongTy[SoLuongNV+1];
		//Them 1 gia tri o hom khoi tao
		for (int i=1;i<=SoLuongNV;i++)
		{
			nv[i].Nhap();
		}
	}
	void Xuat()
	{
		CongTy *nv;
		for (int i=1;i<=SoLuongNV;i++)
		{
			nv[i].Xuat();
		}
	}
	void InLuongduoi5tr()
	{
		CongTy *nv;
		for (int i=1;i<=SoLuongNV;i++)
		{
			if(nv[i].LuongNV()<5000000)
			{
				nv[i].Xuat();
			}
		}
	}
	~Bang_Luong(){};
};
int main()
{
	Bang_Luong nv;
	nv.Nhap();
	nv.Xuat();
	nv.InLuongduoi5tr();
}

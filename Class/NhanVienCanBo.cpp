//a) Xây dựng lớp các nhân viên gồm các thuộc tính dữ liệu họ tên, hệ số lương, phụ cấp với các phương thức nhập, xuất và tính lương (lương = hệ số lương * 1310 + phụ cấp). Kế thừa lớp nhân viên xây dựng lớp Cán bộ có thêm 1 thuộc tính hệ số chức vụ với các phương thức như lớp nhân viên biết lương cán bộ = (hệ số lương + hệ số chức vụ) * 1310 + phụ cấp.
//b) Viết hàm main nhập vào một mảng n Nhân viên và Cán bộ sau đó:
//+ In ra danh sách vừa nhập;
//+ In ra danh sách tối đa 10% nhân viên có thu nhập thấp nhất và có hệ số lương nhỏ hơn 3.0 để nhận trợ cấp khó khăn cuối năm.
//CODE:
#include<iostream>

using namespace std;
class NhanVien
{
	protected:
		char Hoten[50];
		float Hesoluong;
		float Phucap;
	public :
		NhanVien(){}
		void Nhap()
		{
			cout<<"Nhap ho ten : ";cin.getline(Hoten,50);
			cout<<"He so luong : ";cin>>Hesoluong;
			cout<<"Phu cap : ";cin>>Phucap;			
		}
		void Xuat()
		{
			cout<<"Ho ten : "<<Hoten;
			cout<<"He so luong : "<<Hesoluong;
			cout<<"Phu cap : "<<Phucap;	
		}
		float LuongNhanVien()
		{
			return Hesoluong*1310 + Phucap;
		}
		float getHesoluong()
		{
			return Hesoluong;
		}
		float getPhucap()
		{
			return Phucap;
		}
};
class CanBo : public NhanVien
{
	protected:
		float HesoChucVu;
	public :
		CanBo(){}
		void Nhap()
		{
			NhanVien::Nhap();
			cout<<"He so chuc vu : ";cin>>HesoChucVu;
		}
		void Xuat()
		{
			NhanVien::Xuat();
			cout<<"He so chuc vu : "<<HesoChucVu;
		}
		float LuongCanBo()
		{
			return (NhanVien::getHesoluong() + HesoChucVu)*1310 + NhanVien::getPhucap();	
		}	
};
int main()
{
	int n,m;
	//
	cout<<"Nhap so luong nhan vien : ";cin>>n;
	NhanVien *nv= new NhanVien[n+1];
	for (int i = 1;i<=n;i++)
	{
		nv[i].Nhap();
	}
	for (int i = 1;i<=n;i++)
	{
		nv[i].Xuat();
	}
	cout<<"Nhap so luong can bo : ";cin>>m;
	CanBo *cb = new CanBo[m+1];
	for (int i = 1;i<=m;i++)
	{
		cb[i].Nhap();
	}
	for (int i = 1;i<=m;i++)
	{
		cb[i].Xuat();
	}
	//
	int i =0;
	while((i/n)<=0.1)
	{
		if(nv[i].getHesoluong()>3.0)
		{
			nv[i].Xuat();
		}
		i++;
	}
	return 0;
}

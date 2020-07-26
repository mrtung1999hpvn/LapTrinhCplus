//Cài đặt lớp học viên gồm các thuộc tính dữ liệu mã học viên, họ tên, ngành học và các phương thức:
//+ Hàm tạo mặc định và hàm tạo có tham số;
//+ Hàm nhập;
//+ Hàm xuất.
//Hãy nhập vào một mảng n học viên và sau đó:
//+ In ra danh sách học viên vừa nhập;
//+ Nhập vào một ngành học và in ra danh sách các học viên học theo ngành đó;
//+ Sắp xếp danh sách học viên tăng dần theo họ tên, cùng họ tên theo ngành học và in kết quả ra màn hình

CODE :
#include <iostream>
#include <string.h>

using namespace std;
class HocVien
{
protected:
	char MaHV[10];
	char TenHV[50];
	char NganhHoc[100];
public:
	SinhVien(){}
	void Nhap()
	{
		fflush(stdin);
		cout<<"Ma SV : ";cin.getline(MaHV,10);
		cout<<"Ten SV  : ";cin.getline(TenHV,50);
		cout<<"Nganh hoc : ";cin.getline(NganhHoc,100);
	}
	void Xuat()
	{
		fflush(stdin);
		cout<<"Ma SV : "<<MaHV;
		cout<<"Ten SV  : "<<TenHV,50;
		cout<<"Nganh hoc : "<<NganhHoc;
	}
	char *getTenHV()
	{
		return TenHV;
	}
	char *getNganhHoc()
	{
		return NganhHoc;
	}
};
int main()
{
		int n;
		cout<<"Nhap so luong hoc vien :";cin>>n;
		HocVien *hv = new HocVien[n+1];
		//Them 1 gia tri o hom khoi tao
		for (int i=1;i<=n;i++)
		{
			hv[i].Nhap();
		}
		for (int i=1;i<=n;i++)
		{
			hv[i].Xuat();
		}
		//Nganh hoc
		char nh[100];
		cout<<"Nhap nganh hoc de xem : ";
		cout<<"Nganh hoc : ";cin.getline(nh,100);
		
		for (int i=1;i<=n;i++)
		{
			if((strcmp(hv[i].getTenHV(),nh)==0))
			{
				hv[i].Xuat();
			}
		}
		
		//SX
		for (int i=1;i<=n;i++)
		{
			for (int j=2;j<=n;j++)
			if((strcmp(hv[i].getTenHV(),hv[j].getTenHV())>0) || 
				(strcmp(hv[i].getTenHV(),hv[j].getTenHV())==0)
				&& (strcmp(hv[i].getNganhHoc(),hv[j].getNganhHoc())>0))
				{
					HocVien temp = hv[i];
					hv[i]  = hv[j];
					hv[j] = temp;
				}
		}
		for (int i=1;i<=n;i++)
		{
			hv[i].Xuat();
		}
}

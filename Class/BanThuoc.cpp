//Một cửa hàng bán thuốc lưu thông tin các loại thuốc gồm: Tên thuốc, mã thuốc, số lượng và giá bán. Theo quan điểm Lập trình HĐT bạn hãy viết chương trình thực hiện:
//a) Nhập và in ra màn hình danh sách các loại thuốc có trong cửa hàng;
//b) Sắp xếp danh sách các loại thuốc theo tên, cùng tên theo mã.
#include <iostream>
#include <string.h>

using namespace std;
class Thuoc
{
protected:
	char MaThuoc[10];
	char TenThuoc[50];
	int Giaban;
	int Soluong;
public:
	HangHoa(){}
	void Nhap()
	{
		fflush(stdin);
		cout<<"Nhap ma thuoc : ";cin.getline(MaThuoc,10);
		cout<<"Ten thuoc : ";cin.getline(TenThuoc,50);
		cout<<"Gia ban : ";cin>>Giaban;
		cout<<"So luong : "; cin>>Soluong;
	}
	void Xuat()
	{
		cout<<"Ma thuoc : "<<MaThuoc<<endl;
		cout<<"Ten thuoc : "<<TenThuoc<<endl;
		cout<<"Gia ban : "<<Giaban<<endl;
		cout<<"So luong : "<<Soluong<<endl;
	}
	char *getTenThuoc()
	{
		return TenThuoc;
	}
	char *getMaThuoc()
	{
		return MaThuoc;
	}
};

int main()
{
	int n ; 
	cout<<"Nhap so luong thuoc : "<<endl;
	cin>>n;
	Thuoc *a = new Thuoc[n+1];
	// n+1 vi co ham khoi tao ban dau
	for (int i=1;i<=n;i++)
	{
		a[i].Nhap();
	}
	for (int i=1;i<=n;i++)
	{
		a[i].Xuat();
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=2;j<=n;j++)
			if((strcmp(a[i].getTenThuoc(),a[j].getTenThuoc())>0) || 
				(strcmp(a[i].getTenThuoc(),a[j].getTenThuoc())==0)
				&& (strcmp(a[i].getMaThuoc(),a[j].getMaThuoc())>0))
				{
					Thuoc temp = a[i];
					a[i]  = a[j];
					a[j] = temp;
				}
	}
		cout<<"************ : "<<endl;
	for (int i=1;i<=n;i++)
	{
		a[i].Xuat();
	}
}

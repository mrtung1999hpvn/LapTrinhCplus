//Xây dựng lớp các hàng hóa gồm các thuộc tính mã hàng hóa (số nguyên), tên hàng hóa, giá nhập, giá bán, số lượng và các phương thức:
//+ Hàm tạo mặc định;
//+ Hàm hủy;
//+ Hàm nhập;
//+ Hàm xuất;
//+ Hàm tính lợi nhuận = (giá bán – giá mua) * số lượng bán.
//b) Viết hàm main sử dụng lớp hàng hóa đã xây dựng nhập vào một mảng các hàng hóa sau đó:
//+ In ra danh sách các hàng hóa vừa nhập;
//+ Tính và in ra tổng lợi nhuận của các hàng hóa;
//+ In ra danh sách tối đa 10% mặt hàng bán lãi nhất có số lượng bán > 5.
//CODE
#include <iostream>
using namespace std;
class HangHoa
{
protected:
	int MaHang;
	char TenHang[50];
	int Gianhap;
	int Giaban;
	int Soluong;
public:
	HangHoa(){}
	void Nhap()
	{
		
		cout<<"Nhap ma hang : ";cin>>MaHang;
		fflush(stdin);
		cout<<"Ten Hang : ";cin.getline(TenHang,50);
		cout<<"Gia nhap : ";cin>>Gianhap;
		cout<<"Gia ban : ";cin>>Giaban;
		cout<<"So luong : "; cin>>Soluong;
	}
	void Xuat()
	{
		cout<<"Ma hang : "<<MaHang<<endl;
		cout<<"Ten Hang : "<<TenHang<<endl;
		cout<<"Gia nhap : "<<Gianhap<<endl;
		cout<<"Gia ban : "<<Giaban<<endl;
		cout<<"So luong : "<<Soluong<<endl;
	}
	~ HangHoa(){}
	int LoiNhuan()
	{
		return (Giaban - Gianhap)*Soluong;
	}
	int Sl()
	{
		return Soluong;
	}
};

int main()
{
	int n ; 
	cout<<"Nhap so luong hang hoa : "<<endl;
	cin>>n;
	HangHoa *a = new HangHoa[n+1];
	// n+1 vi co ham khoi tao ban dau
	for (int i=1;i<=n;i++)
	{
		a[i].Nhap();
	}
	for (int i=1;i<=n;i++)
	{
		a[i].Xuat();
		cout<<"Loi nhuan : "<<a[i].LoiNhuan();
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=2;j<=n;j++)
			if(a[i].LoiNhuan()<a[j].LoiNhuan())
			{
				HangHoa temp = a[i];
				a[i]  = a[j];
				a[j] = temp;
			}
	}
	for (int i=1;i<=n;i++)
	{
		a[i].Xuat();
		cout<<"Loi nhuan : "<<a[i].LoiNhuan();
	}
	int i = 1;
	while ((i/n)<=0.1)
	{
		if(a[i].Sl()>5)
		{
			cout<<"Loi nhuan : "<<a[i].LoiNhuan();
			
		}
		i++;
	}
	
}

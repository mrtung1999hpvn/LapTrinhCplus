//Xây dựng lớp các hình tròn gồm các thuộc tính dữ liệu là tọa độ tâm và bán kính với các phương thức:
//+ Hàm khởi tạo mặc định;
//+ Hàm nhập:
//+ Hàm xuất;
//+ Hàm tính diện tích;
//+ Hàm kiểm tra một điểm có nằm trong đường tròn hay không
//Nhập vào một mảng các hình tròn và 1 điểm sau đó:
//+ In ra mảng các hình tròn vừa nhập;
//+ Sắp xếp các hình tròn theo chiều giảm dần của diện tích;
//+ In ra tối đa 10% các hình tròn có diện tích lớn nhất và không chứa điểm đã nhập.

//CODE:
#include<iostream>
#include<cmath>

using namespace std;

class HinhTron
{
	int x,y,r;
public:
	HinhTron(){}
	void Nhap()
	{
		cout<<"Nhap toa do tam (x,y) "<<endl;
		cout<<"x : ";cin>>x;cout<<endl;
		cout<<"y : ";cin>>y;cout<<endl;
		cout<<"Nhap ban kinh : ";cin>>r;cout<<endl;
	}
	void Xuat()
	{
		cout<<endl<<"Toa Do(x,y)  = "<< "("<<x<<","<<y<<")"<<endl;
		cout<<"Ban kinh = " <<r<< endl;
		cout<<"DienTich = "<<DienTich();
	}
	float DienTich()
	{
		return (float)(3.14159*r*r);
	}
	bool KT(int a,int b)
	{
		float d1;
		d1 = sqrt((a-x)*(a-x)+(b-y)*(b-y));
		if (r==d1)
		{
			return true; // A nam tren duong tron 
		}
		if(r>d1)
		{
			return true; // A nam trong duong tron 
		}
		if(r<d1)
		{
			return false; // A nam ngoai duong tron
		}
	}
};
int main()
{
	int n;
	cout<<"Nhap so luong hinh tron :";cin>>n;cout<<endl;
	HinhTron *ht = new HinhTron[n];
	cout<<"**Nhap hinh tron**"<<endl;
	for (int i = 1 ; i<n ; i++)
	{
		ht[i].Nhap();
	}
	cout<<"**Nhap toa do A(x1,y1)**"<<endl;
	int x1,y1;
	cout<<"x1 = ";cin>>x1;cout<<endl;
	cout<<"y1 = ";cin>>y1;cout<<endl;
	cout<<"**Xuat hinh tron**"<<endl;
	for (int i = 0 ; i<n ; i++)
	{
		ht[i].Xuat();
	}
	cout<<endl<<"**Sap xep hinh tron**"<<endl;
	for (int i = 1 ; i<=n ; i++)
	{
		for (int j = 2 ; j<=n;j++)
			if(ht[i].DienTich()<ht[j].DienTich())
			{
				HinhTron temp = ht[i];
				ht[i] = ht[j];
				ht[j] = temp;
			}	
	}
	cout<<"**Xuat hinh tron**"<<endl;
	for (int i = 0 ; i<n ; i++)
	{
		ht[i].Xuat();
	}
	cout<<"**In ra toi da 10% cac hinh tron**"<<endl;
	int i = 1;
	do{
		if(ht[i].KT(x1,y1)==false) // In ra hinh tron khong chua diem A
		{
			ht[i].Xuat();
		}	
		i++;
		
	}while((i/n)<=0.1);
	return 0;
}

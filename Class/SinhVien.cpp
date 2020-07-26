//Cho thông tin của một sinh viên gồm: Tên sinh viên, mã sinh viên, điểm trung bình. Bạn hãy xây dựng các lớp cần thiết để có thể:
//a) Nhập, in danh sách gồm n sinh viên.
//b) Tìm sinh viên có điểm trung bình lớn nhất. Sắp xếp sinh viên theo tên, cùng tên theo mã sinh viên.
// 
#include <iostream>
#include <string.h>

using namespace std;
class SinhVien
{
protected:
	char MaSV[10];
	char TenSV[50];
	float DiemTB;
public:
	CongTy(){}
	void Nhap()
	{
		fflush(stdin);
		cout<<"Ma SV : ";cin.getline(MaSV,10);
		cout<<"Ten SV  : ";cin.getline(TenSV,50);
		cout<<"Diem trung binh : ";cin>>DiemTB;	
	}
	void Xuat()
	{
		fflush(stdin);
		cout<<"Ma SV : "<<MaSV;
		cout<<"Ten SV  : "<<TenSV;
		cout<<"Diem trung binh : "<<DiemTB;	
	}
	float getDiemTB()
	{
		return DiemTB;
	}
	char *getTenSV()
	{
		return TenSV;
	}
	char *getMaSV()
	{
		return MaSV;
	}
};
int main()
{
		int n;
		cout<<"Nhap so luong sinh vien :";cin>>n;
		SinhVien *sv = new SinhVien[n+1];
		//Them 1 gia tri o hom khoi tao
		for (int i=1;i<=n;i++)
		{
			sv[i].Nhap();
		}
		for (int i=1;i<=n;i++)
		{
			sv[i].Xuat();
		}
		//Max
		float max =0;
		for (int i=1;i<=n;i++)
		{
			if(sv[i].getDiemTB()<sv[i+1].getDiemTB())
			{
				max = sv[i+1].getDiemTB();
			}
		}
		//SX
		for (int i=1;i<=n;i++)
		{
			for (int j=2;j<=n;j++)
			if((strcmp(sv[i].getTenSV(),sv[j].getTenSV())>0) || 
				(strcmp(sv[i].getTenSV(),sv[j].getTenSV())==0)
				&& (strcmp(sv[i].getMaSV(),sv[j].getMaSV())>0))
				{
					SinhVien temp = sv[i];
					sv[i]  = sv[j];
					sv[j] = temp;
				}
		}
}

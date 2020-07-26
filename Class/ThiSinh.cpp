//a) Xây dựng lớp các thí sinh xét tuyển đại học gồm các thành viên dữ liệu họ tên, điểm trung bình, điểm tiếng Anh với các phương thức nhập, xuất dữ liệu, xét tuyển (trả về true nếu thí sinh trúng tuyển: điểm trung bình >= 7.0 và điểm tiếng Anh >= 400). Kế thừa từ lớp thí sinh để xây dựng lớp thí sinh ưu tiên có thêm 1 trường dữ liệu là điểm ưu tiên với các phương thức như lớp thí sinh và tiêu chí trúng tuyển là điểm trung bình + điểm ưu tiên >= 7.0 và điểm tiếng Anh >= 400.
//b)  Viết hàm main nhập vào một mảng các thí sinh (bình thường và ưu tiên) đã xây dựng ở câu a sau đó:
//+ In ra danh sách các thí sinh vừa nhập;
//+ In ra danh sách các thí sinh trúng tuyển không vượt quá 30% tổng số thí sinh.


//CODE :

#include<iostream>

using namespace std;
class XetTuyen
{
	protected:
		char Hoten[50];
		float DiemTrungBinh;
		float DiemTiengAnh;
		bool xt;
	public :
		XetTuyen(){}
		void Nhap()
		{
			fflush(stdin);
			cout<<"Nhap ho ten : ";cin.getline(Hoten,50);
			cout<<"Diem trung binh : ";cin>>DiemTrungBinh;
			cout<<"Diem tieng anh : ";cin>>DiemTiengAnh;
			if(DiemTrungBinh >=7.0 && DiemTiengAnh >= 400)
			{
				xt = true;
			}
			else {
				xt = false;
			}
		}
		void Xuat()
		{
			cout<<"Nhap ho ten : "<<Hoten;
			cout<<"Diem trung binh : "<<DiemTrungBinh;
			cout<<"Diem tieng anh : "<<DiemTiengAnh;
		}
		float getDiemTrungBinh()
		{
			return DiemTrungBinh;
		}
		bool getxt()
		{
			return xt;
		}
};
class UuTien : public XetTuyen
{
	protected:
		float DiemUuTien;
	public :
		UuTien(){}
		void Nhap()
		{
			XetTuyen::Nhap();
			cout<<"Diem uu tien : ";cin>>DiemUuTien;
			if(DiemTT() >=7.0 && DiemTiengAnh >= 400)
			{
				xt = true;
			}
			else {
				xt = false;
			}
		}
		void Xuat()
		{
			XetTuyen::Xuat();
			cout<<"Diem uu tien : "<<DiemUuTien;
		}
		float DiemTT()
		{
			return XetTuyen::getDiemTrungBinh()+DiemUuTien;
		}
};
int main()
{
	int n,m;
	//
	cout<<"Nhap so luong thi sinh binh thuong : ";cin>>n;
	XetTuyen *ts= new XetTuyen[n+1];
	for (int i = 1;i<=n;i++)
	{
		ts[i].Nhap();
	}
	for (int i = 1;i<=n;i++)
	{
		ts[i].Xuat();
	}
	cout<<"Nhap so luong thi sinh uu tien : ";cin>>m;
	UuTien *ut = new UuTien[m+1];
	for (int i = 1;i<=m;i++)
	{
		ut[i].Nhap();
	}
	for (int i = 1;i<=m;i++)
	{
		ut[i].Xuat();
	}
	//
	int i =0;
	while((i/n)<=0.3)
	{
		if(ts[i].getxt())
		{
			ts[i].Xuat();
		}
		i++;
	}
	return 0;
}

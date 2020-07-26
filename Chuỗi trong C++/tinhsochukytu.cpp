#include <iostream> 
#include <sstream> 
using namespace std;

int main() { 
    // Tinh so chu , ki tu , so trong String
    string a=",LDaT9998",kq="";
    // Mảng giá trị có 3 phần từ để lưu giá trị
    int GiaTri[3];
    GiaTri[0] = 0;     // GiaTri[0] lưu số lượng chữ
    GiaTri[1] = 0;    // GiaTri[1] lưu số lượng ký tự
    GiaTri[2] = 0;    // GiaTri[2] lưu số lượng số   
    

    for(int i=0;i<a.length();i++)
    {   
        // () ? '1' : '2' cấu trúc rút gọn của if else
        // đk đúng(?) làm '1' sai(:) làm '2' 
        //              lớn hơn = 0       bé hơn = 9
        //bảng mã ascii 0 1 2 3 4 5 6 7 8 9 (trong khoảng này là số)
        (a[i] >= '0' && a[i] <= '9') ? GiaTri[2]++ :
        // chữ thì trong khoảng a-z và A-Z
        ( (a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') ) ? GiaTri[0]++ :
        // Ngược lại thì là ký tự
        GiaTri[1]++;
    }
    
    cout<<"So luong chu : "<<GiaTri[0]<<endl;
    cout<<"So luong ky tu : "<<GiaTri[1]<<endl;
    cout<<"So luong so : "<<GiaTri[2]<<endl;
    return 0;
}

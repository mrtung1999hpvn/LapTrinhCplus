#include <iostream> 
#include <sstream> 
using namespace std;

int main() { 
    //,LDT0001 -> LDT0002
    string a=",LDT9998",kq=""; 
    for(int i=0;i<a.length();i++)
    {
        (a[i] >= '0' && a[i] <= '9') ? kq += a[i] : kq += "";
    }
    // Chuyen String sang int 
    stringstream chuyen(kq); 
    int so=0;
    chuyen>>so; 
    
    // Chuyen int sang string 
    stringstream ss; 
    ss<<(so+1);
    ss>>kq; 
    //Ketqua 
    string b="LDT";
    for(int i=0 ; i < (4-kq.length()) ; i++) 
    { 
        b +="0"; 
    }
    b += kq; 
    cout<<b; 
    return 0;
}

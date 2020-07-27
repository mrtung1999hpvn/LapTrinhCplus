#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
    string a="500000";
    string kq="d";
    int t=0;
    for(int i=a.length();i>=0;i--) // Sắp xếp nổi bọt 
    {
        t++;
        kq+=a[i];
        if(i==0){break;}
        if(t==4 || t==7 || t==10 &&t!=0){kq+=",";}
    }
    reverse(kq.begin(), kq.end()); 
    cout<<kq;
    return 0;
}

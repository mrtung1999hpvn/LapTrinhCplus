#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
    string a="5000000000";
    string kq="d";
    int t=0;
    for(int i=a.length();i>=0;i--) // Sắp xếp nổi bọt 
    {
        kq+=a[i];
        if(i==0){break;}
        if(t%3==0 && t!=0){kq+=".";}
        t++;
    }
    reverse(kq.begin(), kq.end()); 
    cout<<kq;
    return 0;
}

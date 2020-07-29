#include <iostream>

using namespace std;

// string -> 
// chu so
// so
// ky tu
int main()
{
    int chu=0;
    int so=0;
    int kytu=0;
    string a="abc !@ 123"; 
    cout<<(int)'a'<<endl; // 97->122 a-z
    cout<<(int)'z'<<endl;
    cout<<(int)'A'<<endl; //65-90 A-Z
    cout<<(int)'Z'<<endl;
    for(int i=0;i < a.length() ; i++)
    {
        ( a[i] >= 'a' && a[i] <= 'z' ||  a[i] >= 'A' && a[i] <= 'Z' ) ? chu++ :
        ( a[i] >= '0' && a[i] <='9' ) ? so++ : (a[i] != ' ') ? kytu++ : ' ';
    }
    cout<<"Chu : "<<chu<<endl;
    cout<<"So : "<<so<<endl;
    cout<<"ky tu : "<<kytu<<endl;
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int GCD(int a,int b)
{
    if(b==0) return a;
    return GCD(b,a%b);
}
int main()
{


    cout<<GCD(36,15)<<endl;

    cout<<GCD(1032894,199392)<<endl;

    cout<<GCD(17,63)<<endl;

    cout<<GCD(17,289)<<endl;

    cout<<__gcd(17,289)<<endl; // 2 '_'s then gcd => __gcd(a,b)
    //C++ provides fn for gcd, usage is given above

    return 0;
}
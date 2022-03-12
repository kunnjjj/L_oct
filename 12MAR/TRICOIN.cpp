#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
long long maxHeight(int n)
{
    int e=(-1 + sqrt(1+8*n))/2 + 10;
    int ans=0;
    int s=0;
    while (s<=e)
    {
        /* code */
        long long mid=(s+e)/2;
        if((mid*(mid+1)/2)<=n)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
    

    // return ans;
}
int main()
{

    // cout<<INT_MAX<<endl;
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        cout<<maxHeight(n)<<endl;
    }

    return 0;
}
// 2* 1e9
// 2'147'483'647
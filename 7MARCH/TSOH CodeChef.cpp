#include<bits/stdc++.h>
using namespace std;
void print(vector<long long> A)
{
    cout<<"best is : ";
    for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
    cout<<endl;
}
int main()
{


    int n; cin>>n;

    vector<long long> A(n);

    for(int i=0;i<n;i++) cin>>A[i];


    vector<long long> best(n);
    long long ans=LLONG_MIN;

    best[0]=A[0];
    for(int i=1;i<n;i++)
    {
        best[i]=max(best[i-1] + A[i],A[i]);
    }

    vector<long long> left(n);
    left[0]=best[0];


    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1], best[i]);
    }
    //true
    

    best[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        best[i]=max(best[i+1]+A[i],A[i]);
    }
    vector<long long>right(n);

    right[n-1]=best[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],best[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        ans=max(ans,left[i]+right[i+1]);
    }
    cout<<ans<<endl;


    // for(int i=0;i<n-1;i++) //i<=n-2
    // {
    //     best[0]=A[0];
    //     long long ans1=LLONG_MIN,ans2=LLONG_MIN;
    //     for(int j=1;j<i;j++)
    //     {
    //         best[j]=max(best[j-1] + A[j],A[j]);
    //     }
    //     // 1st half [0...1] kadanes wala best sum ready hogya hai


    //     best[i+1]=A[i+1];

    //     for(int j=i+2;j<n;j++)
    //     {
    //         best[j]=max(best[j-1] + A[j],A[j]);
    //     }
    //     for(int j=0;j<=i;j++)
    //     {
    //         ans1=max(ans1,best[j]);
    //     }
    //     for(int j=i+1;j<n;j++)
    //     {
    //         ans2=max(ans2,best[j]);
    //     }
    //     ans=max(ans,ans1 + ans2);
    //     cout<<"i is: "<<i<<endl;
    //     print(best);
    // }
    // cout<<ans<<endl;




    return 0;
}
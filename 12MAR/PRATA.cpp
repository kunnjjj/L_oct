#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL paranthas(LL time,LL rank)
{
    // return 5;
    LL s=0,e=1e3;
    LL ans=0;
    while(s<=e)
    {
        LL mid=(s+e)/2;
        if(rank * 1LL * mid * 1LL * (mid+1)<= 2 * time)
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
}

void solve()
{
    LL n; cin>>n;
    LL k; cin>>k;
    vector<LL> A(k);
    for(LL i=0;i<k;i++) cin>>A[i];

    LL ans=1e9;
    LL s=0,e=1e9;
    while(s<=e)
    {
        LL time=(s+e)/2;
        LL total=0;
        for(LL i=0;i<k;i++)
        {
            total+=paranthas(time,A[i]);
        }
        if(total >= n)
        {
            ans=time;
            e=time-1;
        }
        else
        {
            s=time+1;
        }
    }
    cout<<ans<<endl;
    // return ans;
}

int main()
{
    int t; cin>>t;
    while (t--)
    {
        solve();
    }
    



    return 0;
}


// mcAloo: {
//     all:15
// }
// mcPuff{
//     8
// }
// fries{
//     8
// }
// coke{
//     2L + 2L
// }


#include <bits/stdc++.h>
using namespace std;
bool possibleToPlace(long long *A, long long dist, long long n, long long c)
{
    // A[0] pehli cow
    long long nextDist = A[0] + dist;
    c--; // ek cow 0th pos par lagadi
    for (long long i = 1; i < n; i++)
    {
        if (A[i] >= nextDist)
        {
            c--;
            if (c == 0)
            {
                return true;
            }
            nextDist = dist + A[i];
        }
        else
        {
        }
    }

    if (c > 0)
        return false;
    return true;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long c;
        cin >> c;
        long long A[n];
        for (long long i = 0; i < n; i++)
            cin >> A[i];
        sort(A, A + n);
        long long ans = 0;
        // for(long long dist=1;dist<=1e9;dist++)
        // long long ans=0;
	// for(long long dist=1;dist<=1e9;dist++)
	// {
	// 	if(possibleToPlace(A,dist,n,c))
	// 	{
	// 		ans=dist;
	// 	}
	// 	else
	// 	{
	// 		break;
	// 	}
	// }
	// cout<<ans<<endl;
    // continue;
        long long s = 0, e = 1e9;
        while (s <= e)
        {
            long long mid = (s + e) / 2;
            if (possibleToPlace(A, mid, n, c))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
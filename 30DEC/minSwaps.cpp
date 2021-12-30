#include <bits/stdc++.h>
using namespace std;
// int lenOfChain(int i, int *A, int *visited) // humei ab ith index par jaana hai
// {

//    
//     if (visited[i] == 1) // ith pos par pehle aagya tha and now chain is complete
//     {
//         return 0;
//     }
//     visited[i] = 1;
//     int janaKaunseIndexParHai = A[i];
//     return 1 + lenOfChain(janaKaunseIndexParHai, A, visited);
// }

int lenOfChain(int i, int *A, int *visited, int *B, int n) // humei ab ith index par jaana hai
{

    // if(i==A[i]) return 0;
    if (visited[i] == 1) // ith pos par pehle aagya tha and now chain is complete
    {
        return 0;
    }
    visited[i] = 1;
    // int janaKaunseIndexParHai=index[A[i]]; // no number iteration
    // n iterations-> n^2 which is bad
    // do this in logN time becomes nlogn

    // int j=-1;
    int ele = A[i];
    // for(int i=0;i<n;i++)
    // {
    //     if(B[i]==ele)
    //     {
    //         j=i;
    //         break;
    //     }
    // }
    int janaKaunseIndexParHai;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (B[mid] == ele)
        {
            janaKaunseIndexParHai = mid;
            break;
        }
        if (B[mid] < ele)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return 1 + lenOfChain(janaKaunseIndexParHai, A, visited, B, n);
}
int main()
{
    int n;
    cin >> n;

    int A[n], B[n]; // 1 based indexing was better
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        B[i] = A[i];
        mx = max(mx, A[i]);
    }
    sort(B, B + n);
    // int index[mx+1];
    // for(int i=0;i<n;i++)
    // {
    //     index[B[i]]=i;
    // }

    int visited[n + 1] = {0};
    // yadi visited[i]==0 , mai is index par ja sakta hu
    // visited[i]=1 , i have already visited this

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int cnt = lenOfChain(i, A, visited, B, n);
            ans += cnt - 1;
        }
    }
    cout << ans << endl;
}

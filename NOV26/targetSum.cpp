#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;  
    int A[n];
    for (int i = 0; i < n; i++)cin >> A[i];
    
    int target; 
    cin >> target;
    sort(A,A+n);
    int i=0,j=n-1;
    while(i<j)
    {
        if(A[i] + A[j]==target)
        {
            cout<<A[i]<<" and "<<A[j]<<endl;
            i++;
            j--;
        }
        else if(A[i] + A[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(A[i] + A[j]==target)
    //         {
    //             cout<<A[i]<<" and "<<A[j]<<endl;
    //         }
    //     }
    // }

    return 0;
}
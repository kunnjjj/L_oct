#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n; cin>>n;

    int A[n],B[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    int khali[n];

    int idx=0;
    sort(A,A+n);
    sort(B,B+n);
    int i=0,j=0;
    while(i<n && j<n)
    {
        if(A[i]==B[j]) // intersection hai
        {
            // khali[idx]=A[i];
            // idx++;
            khali[idx++]=A[i];
            i++;
            j++;
        }
        else if(A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    // khali array ab bhar gya if intersection exits
    // idx now denotes the no. of elements in intersection
    cout<<"[";
    for(int i=0;i<idx-1;i++)
    {
        cout<<khali[i]<<", ";
    }
    if(idx>=1)
    cout<<khali[idx-1];
    cout<<"]";


    return 0;
}
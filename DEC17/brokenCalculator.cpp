#include<iostream>
using namespace std;
void multiply(int *A,int x,int &idx)
{
    int carry=0;
    for(int i=0;i<=idx;i++)
    {
        int val=A[i] * x + carry;
        A[i]=val %10;
        carry=val/10;
    }
    // there might be some residual value of carry
    while(carry>0)
    {
        // idx++;
        A[++idx]=carry%10;
        carry/=10;
    }
}
int main()
{

    int n; cin>>n;
    int A[2000]={0};
    A[0]=1;
    int idx=0;
    for(int x=1;x<=n;x++)
    {
        multiply(A,x,idx);
    }
    for(int i=idx;i>=0;i--)
    {
        cout<<A[i];
    }




    return 0;
}
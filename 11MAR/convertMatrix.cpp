#include<iostream>
using namespace std;
int main()
{
    int n,m; cin>>n>>m;
    int A[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>A[i][j];
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1) // is element ne abhi apni row and apne col walon ko 1 banana hai
            {
                for(int k=0;k<m;k++)
                {
                    if(A[i][k]==0) A[i][k]=2;
                }
                for(int k=0;k<n;k++)
                {
                    if(A[k][j]==0) A[k][j]=2;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==2) A[i][j]=1; 
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}

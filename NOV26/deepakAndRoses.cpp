#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t; cin>>t;
	for(int x=1;x<=t;x++)
	{
		int n;
		cin >> n;
		int A[n];
		for (int i = 0; i < n; i++)
			cin >> A[i];

		int target;
		cin >> target;
		sort(A, A + n);
		int i=0,j=n-1;
		int a,b; 
		while(i<j)
		{
			if(A[i] + A[j]==target)
			{
				a=A[i];
				b=A[j];
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
		cout<<"Deepak should buy roses whose prices are "<<a<<" and "<<b<<"."<<endl;
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
#include<iostream>
using namespace std;
// https://hack.codingblocks.com/app/contests/1236/266/problem
int main() {
	int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++) cin>>A[i];
	int mxSize=1e6+1;
	int freq[mxSize]={0};

	for(int i=0;i<n;i++)
	{
		int ele=A[i];
		freq[ele]++;
	}

	int k=0;
	for(int i=0;i<mxSize;i++)
	{
		int cnt=freq[i];
		int ele=i;

		while(cnt>0)
		{
			A[k]=ele;
			k++;
			cnt--;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}

	return 0;
}
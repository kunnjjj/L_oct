#include<iostream>
// https://hack.codingblocks.com/app/contests/2707/21/problem
using namespace std;
void makeInverse(int idx,int *A,int *inv,int n)
{
	// base case
	if(idx==n)
	{
		return ;
	}
	// idx .... end tak ka kaam is function ko sambhalna hai
	// this means , is index ka kaam khud karo
	// aage ka kaam recursion ko dedo

	// rec case

	// int val_at_this_idx=A[idx];
	// inv[val_at_this_idx]=idx;
	inv[A[idx]]=idx;

	makeInverse(idx+1,A,inv,n);


}
int main() {
	int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++) 
	{
		cin>>A[i];
	}
	int inv[n];

	makeInverse(0,A,inv,n);

	for(int i=0;i<n;i++)
	{
		cout<<inv[i]<<" ";
	}

	return 0;
}
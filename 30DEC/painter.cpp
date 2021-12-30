#include<iostream>
using namespace std;
#define LL long long 
bool kyaPainterKoDesaktehai(LL *A,LL n,LL len,LL k)
{
	LL cur=0;
	for(int i=0;i<n;i++)
	{
		if(cur + A[i] <=len)
		{
			cur+=A[i];
		}
		else
		{
			k--;
			if(k<=0) return false;
			cur=A[i];
		}
	}
	return true;
	// if(k>=0) return true;
	// return false;
}
int main() {
	LL n,k,t; cin>>n>>k>>t;
	LL A[n];
	LL s=0,e=0;
	for(int i=0;i<n;i++) 
	{
		cin>>A[i];
		s=max(s,A[i]);
		e+=A[i];
	}
	int M= 10000003;
	// cout<<kyaPainterKoDesaktehai(A,n,8,k)<<endl;
	// cout<<"k is:"<<k<<endl;
	LL ans=1e12;
	while(s<=e)
	{
		LL mid=(s+e)/2;
		if(kyaPainterKoDesaktehai(A,n,mid,k))
		{
			// store this mid somewhere

			ans=mid;
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	cout<<(ans * t)%M<<endl;
	// cout<<ans*t<<endl;
	return 0;
}
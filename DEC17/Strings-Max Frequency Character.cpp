#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string s; cin>>s;
	// sort(a,a+n);
	sort(s.begin(),s.end());
	// cout<<s<<endl;
	int maxVal=0; char ans;
	int i=0;
	int n=s.size();
	while(i<n)
	{
		char cur=s[i];
		int cnt=0;
		while(i<n && cur==s[i])
		{
			cnt++;
			i++;
		}
		if(cnt > maxVal)
		{
			// cnt=maxVal;
			maxVal=cnt;
			ans=cur;
		}

	}
	cout<<ans<<endl;
	//sort(s.begin(),s.begin()+n);

	// int freq[256]={0};
	// for(int i=0;i<s.size();i++)
	// {
	// 	freq[s[i]]++;
	// }
	// char ans, maxVal=0;
	// for(int i=0;i<256;i++)
	// {
	// 	if(freq[i]>maxVal)
	// 	{
	// 		maxVal=freq[i];
	// 		ans=i;
	// 	}
	// }
	// cout<<ans<<endl;
	return 0;
}
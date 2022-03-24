#include<iostream>
using namespace std;
// vector<char> table={' ','A','B','C','D','E'}
void func(string &s,string &op,int i)
{	
	if(i==s.size()) // base case
	{
		cout<<op<<endl;
		return ;
	}
	int cur=s[i]-'0';
	if(cur>=1 && cur<=26) // we have encountered a character btw 1..26
	{
		char toApp=cur + 'A' -1; // khel ke dekhna
		op.push_back(toApp);
		func(s,op,i+1);
		op.pop_back();
	}
	if(i+1<s.size()) // 2 char wala scene might happen
	{
		cur=(s[i]-'0')*10 + (s[i+1]-'0');// "56"
		if(cur>=1 && cur<=26) // we have encountered a character btw 1..26
		{
			char toApp=cur + 'A' -1; // khel ke dekhna
			op.push_back(toApp);
			func(s,op,i+2);
			op.pop_back();
		}
	}
}
int main() {
	string s,op; cin>>s;
	func(s,op,0);
	return 0;
}
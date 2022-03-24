#include<iostream>
#include<stack>

using namespace std;
int main() {
	int t; cin>>t;
	while(t--)
	{
		string s; cin>>s;
		stack<int> st;
		bool ans=true;
		int n=s.size();
		int left=-1,right=-1; // abhi koi pop nahi hua hai
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(') st.push(i);
			else if(s[i]==')')
			{
				int newLeft=st.top();
				int newRight=i;
				st.pop();
				if(newLeft==left-1 && newRight==1 + right)
				{
					ans=false;
				}
				left=newLeft;
				right=newRight;
			}
		}
		if(ans)
		{
			cout<<"Not Duplicates"<<endl;
		}
		else
		{
			cout<<"Duplicate"<<endl;
		}
	}
	return 0;
}

// f(i)-> f(i+1)
//     -> f(i+2) s[i] and s[i+1] form a character <=26

// 1,2,3,,,,,9

// 72

// 10




// comparator
// a="98",b= "9"



// s1=a  +b //+ is concatenation

// s1="989"

// s2=b+a

// s2="998"

// if(s1 < s2)
// 	return b> a;
// return a > b;
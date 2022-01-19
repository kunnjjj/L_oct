#include <iostream>

using namespace std;
int cnt(int n, int last_dig)
{
	if (n == 1)
	{
		// if(last_dig==0) return 1;
		// else return 1;
		return 1;
	}
	// last_dig=0
	if (last_dig == 0)
	{
		return cnt(n - 1, 0) + cnt(n - 1, 1);
	}
	else
	{
		return cnt(n - 1, 0);
	}
}
int main()
{
	// cout<<power(2,7)<<endl;
	int t;
	cin >> t;
	int max_n = 25;
	int cnt0[max_n + 1], cnt1[max_n + 1];
	cnt0[1] = 1;
	cnt1[1] = 1;

	for (int i = 2; i <= max_n; i++)
	{
		cnt0[i] = cnt0[i - 1] + cnt1[i - 1];
		cnt1[i] = cnt0[i - 1];
	}
	for (int i = 1; i <= t; i++)
	{
		cout << "#" << i << " : ";
		int n;
		cin >> n;
		// int what = cnt(n, 0) + cnt(n, 1); //?
		// cout << what << endl;

		int final_ans = cnt0[n] + cnt1[n];
		cout << final_ans << endl;
	}

	// int cnt0[n+1],cnt1[n+1];
	// cnt0[1]=1;
	// cnt1[1]=1;

	// for(int i=2;i<=n;i++)
	// {
	// 	cnt0[i]=cnt0[i-1] + cnt1[i-1];
	// 	cnt1[i]=cnt0[i-1];
	// }
	// int final_ans=cnt0[n] + cnt1[n];
	// cout<<final_ans<<endl;

	// int fib[n+1];
	// fib[0]=0;
	// fib[1]=1;
	// for(int i=2;i<=n;i++)
	// {
	// 	fib[i]=fib[i-1] + fib[i-2];
	// }
	return 0;
}
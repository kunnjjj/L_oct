#include <iostream>
using namespace std;
int maxSumSubarrayTimeN3Space1(int A[], int n)
{
    int maxAns = -1e9;
    for (int L = 0; L < n; L++)
    {
        // int cur_sum = 0;
        for (int R = L; R < n; R++)
        {
            int cur_sum = 0; // 0 se reinitialise ho kaye sum[L..R]
            for (int i = L; i <= R; i++)cur_sum += A[i];  
            if (cur_sum > maxAns)
            {
                maxAns = cur_sum;
            }
        }
    }

    return maxAns;
}
int maxSumSubarrayTimeN2SpaceN(int *A,int n)
{
    int maxAns = -1e9;
    int prefix[n];
    prefix[0]=A[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1] + A[i]; // prefix[i-1]=sum[0...i-1]
        //prefix[i]=sum[0...i]
        //sum[0....i]=sum[0..(i-1)] + A[i]
        // prefix[i]=prefix[i-1] + A[i]
    }
    for (int L = 0; L < n; L++)
    {
        // int cur_sum = 0;
        for (int R = L; R < n; R++)
        {
            int cur_sum = 0; // 0 se reinitialise ho kaye sum[L..R]
            // for (int i = L; i <= R; i++)cur_sum += A[i]; 
            if(L>0)
            cur_sum=prefix[R]-prefix[L-1]; 
            else
            cur_sum=prefix[R];
            if (cur_sum > maxAns)
            {
                maxAns = cur_sum;
            }
        }
    }

    return maxAns;

}
int main()
{
	int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<maxSumSubarrayTimeN3Space1(A,n)<<endl;
	cout<<maxSumSubarrayTimeN3Space1(A,n)<<endl;
    return 0;
}
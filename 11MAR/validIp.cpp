#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maxAreaOfHistogramN2(vector<int> &A)
{
    int n=A.size();
    int maxArea=0;
    for (int i = 0; i < n; i++)
    {
        int span=1;

        for(int j=i+1;j<n;j++)
        {
            if(A[j]< A[i]) break;
            span++;
        }
        for(int j=i-1;j>=0;j--)
        {
            if(A[j] < A[i]) break;
            span++;
        }
        // if(span * A[i] > maxArea)
        // {
        //     maxArea=span * A[i];
        // }
        maxArea=max(maxArea,span * A[i]);
    }
    return maxArea;
    
}
int maxAreaOfHistogram(vector<int> &A)
{

    A.push_back(0);
    int n=A.size();
    stack<int> s; // s ke andar index dalenge
    // A[s.top()] // humein value mil jayegi
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && A[s.top()] >= A[i]) // A[s.top()] issai A[i] se dikkat hogi
        {
            //issai nikalna padega, nikalne se pehle find area
            int height=A[s.top()];
            s.pop();
            int R=i-1;
            int L=(s.empty()?0:(s.top()+1));
            int span=(R-L+1) ;
            ans=max(ans,span * height);
        }
        s.push(i);
    }
    return ans;


}


int main()
{
    int n; cin>>n;
    vector<int> A(n);

    for (int  i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    

    cout<<maxAreaOfHistogramN2(A)<<endl;
    cout<<maxAreaOfHistogram(A)<<endl;



    return 0;
}
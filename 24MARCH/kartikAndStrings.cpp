#include<iostream>
using namespace std;
int maxLenByConv(string &s,int k) // we can it without reference, but string is a big data structure and takes 
// time to copy in new variable 
{
    int n=s.size();

    int cnta=0,cntb=0;
    int L=0;
    int ans=0;
    for(int R=0;R<n;R++)
    {
        if(s[R]=='a') cnta++;
        else cntb++;

        //jab tak mai conversion nahi kar paaraha tha tab tak move L
        // i accept s[l..r] if min(cnta,cntb)<=k
        while(min(cnta,cntb)>k) // i cant accept , i need to move L ptr
        {
            if(s[L]=='a') cnta--;
            else cntb--;
            L++;
        }
        int len=R-L+1;

        if(len>ans) ans=len;
    }
    return ans;
}
int main()
{

    int k; cin>>k;

    string s; cin>>s;
    cout<<maxLenByConv(s,k)<<endl;


    return 0;
}
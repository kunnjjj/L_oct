#include<iostream>
using namespace std;
int main()
{
    int n; cin>>n;
    int arr[100000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int XOR=0;
    for(int i=0;i<n;i++)
    {
        // XOR=XOR ^ arr[i];
        XOR^=arr[i];
    }
    // khaas baat: non zero
    //ek na ek p that is one
    int p=-1;
    for(int i=0;i<=30;i++)
    {
        if((XOR & (1<<i))>0)
        {
            p=i;
            break;
        }
    }
    if(p==-1)
    {
        cout<<"jai ho jai ho"<<endl;
        return 0;
    }
    // yaha par p ko use karna hai
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        int ele=arr[i];
        if(((ele>>p)&1)==1)
        {
            x^=ele;
        }   
        else
        {
            y^=ele;
        }
    }

    cout<<min(x,y)<<" "<<max(x,y)<<endl;

// https://ide.codingblocks.com/s/644995
    return 0;
}
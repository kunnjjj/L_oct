// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int n=s.size();
            int i=0;
            int dots=0;
            while(i<n)
            {
                int cur_num=0;
                int cnt=0;
                while(i<n && s[i]>='0' && s[i]<='9')
                {
                    cnt++; // kitne digits count kare hai
                    cur_num*=10;
                    cur_num+=(s[i]-'0');
                    i++;
                    if(cur_num > 255) return 0; // invalid
                }
                if(cnt==0) return false;
                int dig=0; // cur_num ke andar kitne digits hai
                if(cur_num==0) dig=1;
                while(cur_num>0)
                {
                    cur_num/=10;
                    dig++;
                }
                if(cnt!=dig) return 0;
                
                if(i<n && s[i]=='.') {
                    i++;
                    dots++;
                }
            }
            return dots==3;
            
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
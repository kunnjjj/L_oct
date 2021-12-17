// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
//https://leetcode.com/problems/first-bad-version
class Solution {
public:
    int firstBadVersion(int n) {
        int L=1,R=n;
        int ans=-1;
        while(L<=R)
        {
            int mid=L+(R-L)/2;
            if(isBadVersion(mid))
            {
                ans=mid;
                R=mid-1;
            }
            else
            {
                L=mid+1;
            }
        }
        return ans;
    }
};
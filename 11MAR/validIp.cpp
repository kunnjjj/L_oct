class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        
        int n=A.size();
        vector<int> ans;
        deque<int> dq; // index
        for(int i=0;i<n;i++)
        {
            int last_valid_idx=i-k+1;
            while(!dq.empty() && dq.front()< last_valid_idx)
            {
                dq.pop_front();
            }
            while(!dq.empty() && A[dq.back()]<=A[i])
            {
                dq.pop_back();
            }          
            dq.push_back(i);
            if(i>=k-1)
            ans.push_back(A[dq.front()]);
        }
        return ans;
        
        
    }
};
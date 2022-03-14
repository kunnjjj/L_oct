/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //data naam nahi hai, val naam
    vector<int> ans;
    void find_in_subtree(TreeNode* root,int d,int k)
    {
        if(root==NULL) return ;
        if(d==k)
        {
            ans.push_back(root->val);
            return ;
        }
        
        if(d>k) return ;// we can ignore this case , because ultimatly above BC is gonna hit
        find_in_subtree(root->left,d+1,k);
        find_in_subtree(root->right,d+1,k);
    }
    int dist_from_node(TreeNode* root,TreeNode* target,int k) // dist from given node
    {
        if(root==NULL)
        {
            return -1;
        }
        if(root==target)
        {
            find_in_subtree(root,0,k);   
            return 0; // this fn returns dist from given node
        }
        int left_se_dist=dist_from_node(root->left,target,k);
        // -1 denotes that target isn't node present 
        // in other words I am not any ancestor of target 
        if(left_se_dist!=-1)
        {
            if(1 + left_se_dist==k)
            {
                ans.push_back(root->val);
            }
            find_in_subtree(root->right,0,k-left_se_dist-2);
            
            return 1 + left_se_dist;
        }
        int right_se_dist=dist_from_node(root->right,target,k);
        if(right_se_dist!=-1)
        {
            if(1 + right_se_dist==k)
            {
                ans.push_back(root->val);
            }
            find_in_subtree(root->left,0,k-right_se_dist-2);
            return 1 + right_se_dist;
        }
        return -1; // target node isnt present in left or right subtree
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dist_from_node(root,target,k);
        return ans;
    }
};
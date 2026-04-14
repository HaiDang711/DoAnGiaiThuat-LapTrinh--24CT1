/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool f=true;
        while(!q.empty())
        {
            int s=q.size();
            vector<int> v;
            for(int i=0;i<s;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                v.push_back(temp->val);
            }
            if(f==true) ans.push_back(v);
            else
            {
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            f=!f;
        }
        return ans;
    }
//please upvote...
};
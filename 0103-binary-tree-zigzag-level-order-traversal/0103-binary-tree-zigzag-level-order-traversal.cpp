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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
       
        vector<vector<int>> ans ;
        if (root == nullptr) return ans;
        q.push(root) ;
        int dir = 1 ;
        while(!q.empty()) {
            
            int size = q.size() ;
            vector<int> temp(size) ;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front() ;
                q.pop() ;
                if(dir==1) {
                    temp[i] = node->val ;
                }
                else {
                    temp[size-i-1] = node->val ;
                }
                if(node->left) q.push(node->left) ;
                if(node->right) q.push(node->right) ;
            }
            dir = dir==1?0:1 ;
            ans.push_back(temp) ;
        }
        return ans ;

    }
};
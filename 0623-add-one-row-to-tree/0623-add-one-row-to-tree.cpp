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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
                if (depth==1){
            TreeNode* ptr=new TreeNode(val);
            ptr->left=root;
            return ptr;
        }
        //BFS 
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while(!q.empty()){
            auto [node, level]=q.front();
            q.pop();
            if (level==depth-1){
                TreeNode* ptr=node->left;
                node->left=new TreeNode(val);
                node->left->left=ptr;

                ptr=node->right;
                node->right=new TreeNode(val);
                node->right->right=ptr;
            }
            else{
                if (node->left) q.emplace(node->left, level+1);
                if (node->right) q.emplace(node->right, level+1);
               
            }
        }
        return root;

        
    }
};
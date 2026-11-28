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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int mid=0;
        for(int i=0; i<inorder.size();i++){
            if(root->val == inorder[i]){
                mid =i;
                break;
            }
        }
        vector<int>lin(inorder.begin(), inorder.begin()+mid);
        vector<int>rin(inorder.begin()+mid+1, inorder.end());
        vector<int>lpre(preorder.begin()+1, preorder.begin()+1+lin.size());
        vector<int>rpre(preorder.begin()+1+lpre.size(), preorder.end());
        root->left= buildTree(lpre,lin);
        root->right= buildTree(rpre,rin);
        return root; 
    }
};

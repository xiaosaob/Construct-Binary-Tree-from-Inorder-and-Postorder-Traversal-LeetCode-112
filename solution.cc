// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return helper(inorder, 0, postorder, 0, inorder.size());
    }
    
    TreeNode *helper(vector<int> &inorder, int inStart, vector<int> &postorder, int postStart, int num) {
        if(num <= 0) return NULL;
        int rootVal = postorder[postStart+num-1];
        int inorderIdx = 0;
        for(int i = 0; i < num; ++i) {
            if(inorder[inStart+i] == rootVal) {
                inorderIdx = inStart+i;
                break;
            }
        }
        TreeNode *left = helper(inorder, inStart, postorder, postStart, inorderIdx-inStart);
        TreeNode *right = helper(inorder, inorderIdx+1, postorder, postStart+(inorderIdx-inStart), num-1-(inorderIdx-inStart));
        TreeNode *root = new TreeNode(rootVal);
        root->left = left;
        root->right = right;
        return root;
    }
};

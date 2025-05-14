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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if ( root == NULL )
            return false ;

        if ( !root->left && !root->right ) {
            return targetSum == root -> val ;
        }
        
        bool rightCheck = hasPathSum( root -> right, targetSum - root -> val) ;
        bool leftCheck = hasPathSum( root -> left, targetSum - root -> val) ;
        return rightCheck || leftCheck ;
    }


    bool cal(TreeNode* root, int targetSum ) {
        if ( root == NULL && 0 == targetSum )
            return true ;
        else if ( root == NULL )
            return false ;
        
        if ( cal( root -> left, targetSum - root -> val ) )
            return true ;
        else if ( cal( root -> right, targetSum- root -> val ) )
            return true ;
        
        
        return false ;
    }
};
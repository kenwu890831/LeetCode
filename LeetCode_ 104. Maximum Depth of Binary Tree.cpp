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
    int depth( TreeNode* root ) {
        if ( root == NULL )
          return 0 ;
        int i = 1 + depth( root -> right ) ;
        int j = 1 + depth( root -> left ) ;

        return i > j ? i : j ;

    }
    int maxDepth(TreeNode* root) {
        return depth( root ) ;
    }
};
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
    void traveral( TreeNode* root, vector<int>& result ) {
      if ( root == NULL ) 
        return ;
      traveral( root -> left , result ) ;
      result.push_back( root -> val ) ;
      traveral( root -> right, result ) ;
    } // traveral

    vector<int> inorderTraversal(TreeNode* root) {
        vector< int > result ;

        traveral( root, result ) ;

        return result ;
    }
};
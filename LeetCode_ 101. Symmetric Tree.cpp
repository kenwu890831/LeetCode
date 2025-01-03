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
    void walk(TreeNode* l, TreeNode* r, bool& result ) {
      if ( result == false )
        return ;
      if ( l == NULL && r == NULL )
        return ;
      if ( l == NULL || r == NULL ) {
        result = false ;
        return ;
      }

      if ( l -> val != r -> val  ) {
        result = false ;
        return ;
      }

      walk( l -> left, r -> right, result ) ;
      walk( l -> right, r -> left, result ) ;

    }
    bool isSymmetric(TreeNode* root) {
        bool result = true ;
        walk( root -> left, root -> right, result ) ;
        return result ;
    }
};
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
    void traversal( TreeNode* root, vector< int >& result ) {
       if ( root == NULL )
         return ;
       traversal( root -> left, result ) ;
       traversal( root -> right, result ) ;
       result.push_back( root -> val ) ;
    } // traversal()

    vector<int> postorderTraversal(TreeNode* root) {
        vector< int > result ;

        traversal( root, result ) ;

        return result ;
    }
};
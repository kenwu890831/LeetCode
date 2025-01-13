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
    int run( int& low, int& high, TreeNode* root, bool& check ) {
        if ( root == NULL ) {
          return 0 ;
        }
          

        int temp1, temp2 ;
        temp1 = run( low, high, root -> left, check ) + 1;
        temp2 = run( low, high, root -> right, check ) + 1;
        if ( abs( temp1 - temp2 ) > 1 )
          check = false ;

        return max( temp1, temp2 ) ;
        
    } // run()

    bool isBalanced(TreeNode* root) {
        int low = 5005, high = 0 ;
        bool check = true ;
        run( low, high, root, check ) ;

        return check ;
    }
};
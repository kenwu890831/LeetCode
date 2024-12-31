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
    void check( TreeNode* p, TreeNode* q, bool& result ) {
        if ( result == false ) {
            return ;
        }
        if ( p == NULL && q == NULL )
          return ;
        if ( p == NULL || q == NULL ) {
            result = false ;
            return ;
        }
        if ( p -> val != q -> val ) {
            result = false ;
            return ;
        }
          


        check( p -> left , q -> left, result ) ;
        check( p -> right , q -> right, result ) ;
    }
   
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = true ;
        check( p, q, result ) ;
        return result ;

    
        
    }
};
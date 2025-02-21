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
class FindElements {
public:
    unordered_map< int, bool > temp ;
    

    FindElements(TreeNode* root) {

        root -> val = 0 ;
        temp[0] = true ;
        trl( root ) ;
    }

    void trl( TreeNode* root ) {
        if ( root -> left != NULL ) {
            root -> left -> val = ( root -> val )*2 + 1 ;
            temp[root -> left -> val] = true ;
            trl( root -> left ) ;
        }

        if ( root -> right != NULL ) {
            root -> right -> val = ( root -> val )*2 + 2 ;
            temp[root -> right -> val] = true ;
            trl( root -> right ) ;
        }
        


    }
    
    bool find(int target) {
        if ( temp[ target ] == true )
          return true ;
        return false ;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
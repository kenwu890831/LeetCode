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
    void walkTree ( TreeNode* root, vector<int>& result,int height ) {
        if ( root == NULL ) 
          return ;
        else {
            cout << root -> val << " " << height << endl ;
           if ( result.size() <= height ) 
             result.push_back( root -> val ) ;
           result[height] = max( root -> val, result[height] ) ;
           walkTree( root -> left, result, height+1 ) ;
           walkTree( root -> right, result, height+1 ) ;
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result ;
        
        

        walkTree( root, result, 0 ) ;

        return result ;
    }
};
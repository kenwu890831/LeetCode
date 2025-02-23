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
    int index = 0, n ;
     TreeNode* construct( vector<int>& pre, vector<int>& pos, int head, int tail ) {
        if ( index >= n || head > tail )
            return NULL ;
        
        TreeNode* newNode = new TreeNode( pre[index] );
        index++ ;

        if ( head == tail )
            return newNode ;

        int temp = head ;
        for ( ; temp <= tail ; temp++ ) {
            if ( pos[temp] == pre[index] )
                break ;
        }


        if ( temp <= tail ) {
            newNode->left = construct( pre, pos, head, temp );
            newNode->right = construct( pre, pos, temp+1, tail-1 );
        }

        return newNode ;



     }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        n = preorder.size() ;
        return construct( preorder, postorder, 0, n - 1 ) ;
    }
};
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
    TreeNode* run( vector<int>& nums, int head, int tail ) {
        if ( head > tail )
          return NULL ;
        int place = ( tail + head ) / 2 ;
        TreeNode* root = new TreeNode(nums[place]);


        root->left = run( nums, head , place-1 ) ; // left
        root->right = run( nums, place + 1 , tail ) ; // right

        return root ;
        

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() ;

        


        return run( nums, 0, n-1 ) ;
    }
};
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
    TreeNode* recoverFromPreorder(string s) {
        vector < pair< int, int > > temp ;
        int level = 0, index = 0, num = 0 ;
        while ( index < s.size() ) {
            if ( s[index] != '-' ) {
                num *=10 ;
                num += s[index] - '0' ;
            }
            else {
                if ( num != 0 ) {
                    temp.push_back( {level, num } ) ;
                    num = 0 ;
                    level = 1 ;
                }
                else 
                  level++ ;
            }

            index++ ;
        }

        temp.push_back( {level, num } ) ;

        TreeNode* result = new TreeNode( temp[0].second ) ;
        unordered_map<int, TreeNode*> m ;
        m[0] = result ;
        for (int i = 1; i < temp.size(); i++) {
            int parent = temp[i].first - 1 ;
            TreeNode* n = new TreeNode( temp[i].second ) ;
            m[temp[i].first] = n ;

            if ( !m[parent] -> left ) {
                m[parent] -> left = n ;
            } else {
                m[parent] -> right = n ;
            }
        }


        return result ;
    }
};
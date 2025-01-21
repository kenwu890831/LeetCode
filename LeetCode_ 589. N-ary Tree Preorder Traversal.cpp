/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void traversal( Node* root, vector< int >& result ) {
      if ( root == NULL )
        return ;

      for ( auto child : root -> children ) {
         result.push_back( child -> val ) ;
         traversal( child, result ) ;
         
      }
    } // traversal()


    vector<int> preorder(Node* root) {
        vector< int > result ;
        
        if ( root == NULL )
          return result ;
        
        result.push_back( root -> val ) ;
        traversal( root, result ) ;
        

        return result ;       
    }
};
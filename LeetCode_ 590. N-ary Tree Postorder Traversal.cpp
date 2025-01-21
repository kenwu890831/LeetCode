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
         traversal( child, result ) ;
         result.push_back( child -> val ) ;
      }
    } // traversal()

    vector<int> postorder(Node* root) {
        vector< int > result ;
        
        if ( root == NULL )
          return result ;
        

        traversal( root, result ) ;
        result.push_back( root -> val ) ;

        return result ;
    }
};
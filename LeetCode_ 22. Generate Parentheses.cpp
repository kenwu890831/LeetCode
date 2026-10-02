class Solution {
public:
    stack<char> s;
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        run( n, 0, "", ans ) ;
        return ans ;
    }

    void run( int left, int right, string temp, vector<string>& ans ) {
        if ( left == 0 && right == 0 ) {
            ans.push_back( temp ) ;
            return  ;
        }
        if ( left > 0 ) {
            temp.push_back( '(' ) ;
            run( left-1, right+1, temp, ans ) ;
            temp.pop_back() ;
        }
        if ( right > 0 ) {
            temp.push_back( ')' ) ;
            run( left, right-1, temp, ans ) ;
            temp.pop_back() ;
        }


    }
};
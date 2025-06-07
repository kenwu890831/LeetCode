class Solution {
public:
    string clearStars(string s) {
        unordered_map< char, vector< int > > m ;
        priority_queue< char, vector<char >, greater<char> > q ;
        int n = s.size() ;
        string result = "" ;
        vector< bool > check( n, true ) ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] == '*' ) {
                char c = q.top() ;
                q.pop() ;
                int index = m[c].back() ;
                m[c].pop_back();
                check[i] = false ;
                check[index] = false ;
            }
            else {
                q.push( s[i] ) ;
                m[s[i]].push_back( i ) ;
            }
        }

        for ( int i = 0 ; i < n ; i++ ) {
            if ( check[i] == true )
                result += s[i] ;
        }




        


        return result ;
    }
};
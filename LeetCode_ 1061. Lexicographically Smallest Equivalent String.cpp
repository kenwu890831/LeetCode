class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map< char, vector< char > > temp ;
        int n = s1.size() ;
        string result = "" ;

        for ( int i = 0 ; i < n ; i++ ) {
            char x = s1[i], y = s2[i] ;
            temp[x].push_back( y ) ;
            temp[y].push_back( x ) ;

        }

        for( int i = 0 ; i < baseStr.size() ; i++ ) {
            vector< bool > check( 26, false ) ;
            int r = dfs( baseStr[i], check, temp ) ;
            result += 'a' + r ;
        }


        return result ;
    }

    int dfs( char input, vector< bool >& check, unordered_map< char, vector< char > >& list ) {
        check[input - 'a' ] = true ;
        int result = input - 'a' ;
        for( int i = 0 ; i < list[input].size(); i++ ) {
            if ( check[list[input][i]-'a'] == false )
              result = min( result, dfs( list[input][i], check, list ) ) ;
        }
        return result ;
    }
};
class Solution {
public:
    string getHappyString(int n, int k) {
        int set = pow( 2, n-1 ), count = 0 ;
        string result = "" ;
        if ( ( 3*set ) < k )
            return "" ;

        
        if ( k <= set ) {
            result.push_back( 'a' ) ;
        } else if ( k <= 2*set ) {
            result.push_back( 'b' ) ;
            k -= set ;
        }
        else {
            result.push_back('c' ) ;
            k -= 2*set   ;
        }

        cout << k << endl ;
        return dfs( n, k, result, count ) ;

    }

    string dfs( int n, int k , string result, int& count ) {
        if ( result.size() == n ) {
            count++ ;
            return result ;
        }

        string s ;
        for ( char temp = 'a' ; temp <= 'c' ; temp++) {
            if ( result.back() == temp )
                continue ;
            s = dfs( n, k, result + temp , count ) ;
            if ( count == k )
              return s ;
        }

        return "" ;
    }
};
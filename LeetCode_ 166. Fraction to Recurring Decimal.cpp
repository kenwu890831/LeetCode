class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "" ;
        unordered_map< long long, int > h ;
        if ( numerator == 0 ) 
            return "0" ;
        if ( ( numerator < 0 ) ^ ( denominator < 0 ) )
            ans += "-" ;

        long long n = abs( ( long long )numerator ) ;
        long long d = abs( ( long long )denominator ) ;
        ans += to_string( n / d ) ;
        long long temp = n % d ;
        if ( temp == 0 )
            return ans ;

        ans += "." ;

        while( temp != 0 ) {
            if ( h.find( temp ) != h.end() ) {
                int index = h[temp] ;
                ans.insert( index, "(" ) ;
                ans += ")" ;
                break ;
            }

            h[temp] = ans.size() ;
            temp *= 10 ;
            int c = temp / d ;
            ans.push_back( '0' + c ) ;
            temp = temp % d ;
        }

        return ans ;
    }
};
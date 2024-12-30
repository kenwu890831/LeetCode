class Solution {
public:
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int m = 1e9+7 ;
        vector <int> dp( high+1, 0 ) ;
        dp[0] = 1 ;
        long long ans = 0 ;
        for ( int i = 1 ; i <= high ; i++ ) {
            ans = 1 ;
            if ( i >= zero )
              ans += dp[ i-zero ] ;
            if ( i >= one )
              ans += dp[ i-one ] ;
            dp[i] = ans % m ;

        }// forward


        return ( dp[ high ] - dp[ low - 1 ] + m ) % m ;
    }
};
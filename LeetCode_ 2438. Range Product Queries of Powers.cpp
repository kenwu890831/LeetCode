class Solution {
public:
    int m = 1e9 + 7 ;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        bitset<32> num = n ;
        vector< int > ans, power ;
        long long temp = 1 ;
        for( int i = 0 ; i < 32 ; i++ ) {
            if ( num[i] == 1 ) {
                power.push_back( temp ) ;
            }
                  
            temp <<= 1 ; 
        }

        for( int i = 0 ; i < queries.size() ; i++ ) {
            long long total = 1 ;
            for ( int j = queries[i][0] ; j <= queries[i][1] ; j++ ) {
                total = ( total * power[j] ) % m ;
            }

            ans.push_back( total ) ;
        }

        
        return ans ;
    }
};
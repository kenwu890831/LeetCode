class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), nq = queries.size(), result = 0, now = 0 ;
        vector< int > temp( n + 1 ) ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( ; now < nums[i]-temp[i] ; result++ ) {
                if ( result >= nq )
                    return -1 ;
                int l = queries[result][0], r = queries[result][1], v = queries[result][2] ;
                if( r < i )
                    continue ;
                temp[max( l, i )] += v ;
                temp[ r + 1 ] -= v ;

            }

            now += temp[i] ;
        }

        return result ;
    }
};
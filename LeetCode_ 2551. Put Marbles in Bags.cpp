class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size() ;
        if ( n == k || k == 1 )
            return 0 ;
        vector < int > temp ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            temp.push_back( weights[i] + weights[i+1] ) ;
        }

        sort( temp.begin(), temp.end() ) ;
        long long min = 0, max = 0 ;
        for ( int i = 0 ; i < k-1 ; i++ ) {
            min += temp[i] ;
            max += temp[n - 2 - i] ;
        }


        return max - min ;
        

    }
};
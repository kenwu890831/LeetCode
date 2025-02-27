class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set< int> m( arr.begin(), arr.end() ) ;
        int n = arr.size(), result = 0, pre, cur ;

        for ( int i = 0 ; i < n - 1 ; i++ ) {
            pre = arr[i] ;
            for ( int j = i + 1 ; j < n ; j++ ) {
                pre = arr[j] ;
                cur = arr[i]+arr[j] ;
                int count = 2 ;

                while ( m.find( cur ) != m.end() ) {
                    int temp = cur ;
                    cur += pre ;
                    pre = temp ;
                    result = max( result, ++count ) ;
                }
                
            }
        }



        return result ;
    }
};
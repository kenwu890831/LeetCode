class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = fruits.size() ;
        vector< bool > h( n, false ) ;

        for( int i : fruits ) {
            for( int j = 0 ; j < n ; j++ ) {
                if ( !h[j] && baskets[j] >= i ) {
                    h[j] = true ;
                    ans-- ;
                    break ;
                }
            }
        }


        return ans ;

    }
};
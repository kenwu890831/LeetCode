class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), result = 0, buy = prices[0] ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( buy > prices[i] ) {
                buy = prices[i] ;
            }
            
            result = max( result, prices[i] - buy ) ;
        }

        return result ;
    }
};
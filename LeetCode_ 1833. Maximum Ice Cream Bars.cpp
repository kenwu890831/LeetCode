class Solution {
public:
    static const int m = 1e5 + 1;
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0, costMax = 0 ;
        int temp[m] = {};
        for ( int i = 0 ; i < costs.size() ; i++ ) {
            temp[ costs[i] ]++ ;
            costMax = max( costMax, costs[i] ) ;
        }

        for ( int i = 1 ; i <= costMax ; i++ ) {
            if ( temp[i] == 0 )
             continue ;
            
            int canBuy = min( coins/i, temp[i] ) ;
            ans += canBuy ;
            coins -= canBuy * i ;
        }
        
        return ans  ;
    }
};
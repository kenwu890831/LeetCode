class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, empty = 0 ;
        while( ( numBottles + empty ) >= numExchange ) {
            if ( empty < numExchange ) {
                empty += numBottles ;
                ans += numBottles ;
                numBottles = 0 ;
            }
            else {
                empty -= numExchange ;
                numBottles++ ;
                numExchange++ ;
            }

        }

        ans += numBottles ;

        return ans ;
    }
};
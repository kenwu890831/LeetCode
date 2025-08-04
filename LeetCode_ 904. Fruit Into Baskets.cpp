class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = -1, second = -1, count = 0, cur = 0, ans = 0 ;

        for ( int i = 0 ; i < fruits.size() ; i++ ) {
            if ( fruits[i] == first || fruits[i] == second ) {
                cur++ ;
            }
            else {
                cur = count + 1 ;
            }

            if ( fruits[i] == first ) {
                count++ ;
            }
            else {
                count = 1 ;
                second = first ;
                first = fruits[i] ;
            }

            ans = max( ans, cur ) ;
        }

        return ans ;
    }
};
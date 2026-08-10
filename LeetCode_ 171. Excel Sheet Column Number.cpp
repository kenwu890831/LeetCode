class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0 ;
        long long mul = 1 ;

        for ( int i = columnTitle.size() - 1 ; i >= 0 ; i-- ) {
            
            ans += ( columnTitle[i] - 'A' + 1) * mul ;
            mul *= 26 ;
        }


        return ans ;
    }
};
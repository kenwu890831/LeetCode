class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map< char, int > h ;
        int ans = 0, temp1 = 0, temp2 = 0 ;
        for ( auto i : s) {
            h[i]++ ;
        }

        for ( auto& i : h ) {
            if ( i.first == 'a' || i.first == 'e' || i.first == 'i' || i.first == 'o' || i.first == 'u' ) {
                temp1 = max( temp1, i.second ) ;
            }
            else {
                temp2 = max( temp2, i.second ) ;
            }
        }

        ans = temp1 + temp2 ;

        return ans ;
    }
};
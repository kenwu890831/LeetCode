class Solution {
public:
    int maxDifference(string s) {
        int odd = -1, even = INT_MAX ;
        unordered_map< char, int > h ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            h[s[i]]++ ;
        }

        for( auto temp : h ) {
            if ( temp.second % 2 == 0 ) 
                even = min( even, temp.second ) ;
            else
                odd = max( odd, temp.second ) ;
        }


        return odd - even ; 
    }
};
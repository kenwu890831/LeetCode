class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), j = 0, result = 0 ;
        unordered_map< char, int > m ;
        for ( int i = 0 ; i < n ; i++ ) { // origin
            m[s[i]]++ ;
            while ( m['a'] > 0 && m['b'] > 0 && m['c'] > 0 ) {
                result += n - i ;
                m[s[j]]-- ;
                j++ ;
            }

        } 

        return result ;
    }
};
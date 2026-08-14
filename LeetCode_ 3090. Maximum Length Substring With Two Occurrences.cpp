class Solution {
public:
    int maximumLengthSubstring(string s) {
        int head = 0, tail = 0, ans = 0 ;
        unordered_map< int, int > m ;
        while ( tail < s.size() ) {
            m[s[tail]]++ ;
            while( m[s[tail]] > 2 ) {
                m[s[head]]-- ;
                head++ ;
            }

            ans = max( ans, tail - head + 1 ) ;
            tail++ ;
            
        }

        return ans ;
    }
};
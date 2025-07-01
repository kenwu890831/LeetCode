class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map< int, int > h ;
        int ans = 1, count = 1 ;
        char cur = ' ' ;
        for ( int i = 0 ; i < word.size() ; i++ ) {
            if ( cur != word[i] ) {
                ans += ( count - 1 ) ;
                count = 1 ;
                cur = word[i] ;
            }
            else
                count++ ;
        }

        ans += count - 1 ;



        return ans ;
    }
};
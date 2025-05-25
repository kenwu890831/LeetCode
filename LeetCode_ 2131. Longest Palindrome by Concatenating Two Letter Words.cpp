class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int result = 0, n = words.size() ;
        unordered_map< string, int > h ;

        for ( int i = 0 ; i < n ; i++ ) {
            string temp = words[i] ;
            reverse( temp.begin() , temp.end() ) ;
            if ( h[temp] > 0 ) {
                result += 4 ;
                h[temp]-- ;
            }
            else
                h[words[i]]++ ;

        } // left right check

        for ( auto temp : h ) { // mid
            if ( temp.first[0] == temp.first[1] && temp.second > 0 ) 
                return result + 2 ;
        }



        return result ;
    }
};
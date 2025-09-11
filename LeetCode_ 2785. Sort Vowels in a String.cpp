class Solution {
public:
    string sortVowels(string s) {
        string ans = "" ;
        vector< char > temp ;

        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' 
                || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ) {
                    temp.push_back( s[i] ) ;
            }
        }

        sort( temp.begin(), temp.end() ) ;

        int index = 0 ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' 
                || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ) {
                    ans += temp[index] ;
                    index++ ;
            }
            else {
                ans += s[i] ;
            }
        }

        return ans ;
    }
};
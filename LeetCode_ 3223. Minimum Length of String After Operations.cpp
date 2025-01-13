class Solution {
public:
    int minimumLength(string s) {
        //int temp[26] = { 0 },
        vector<int> temp(26, 0);
        for ( int i = 0 ; i < s.size() ; i++ ) {
            temp[ s[i] - 'a' ]++ ;
        }

        int result = 0 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
          if ( temp[i] == 0 )
            continue ;
          else if ( temp[i] % 2 == 0 )
            result += 2 ;
          else
            result++ ;
        }

        return result ;
    }
};
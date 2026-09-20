class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, temp = 0 ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            temp =  ( 27 - ( s[i] - 'a' + 1 ) )* ( i + 1 ) ;
            ans += temp ; 
        }

        return ans ;
    }
};
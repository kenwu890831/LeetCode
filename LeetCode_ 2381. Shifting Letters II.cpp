class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       int n = s.size() ;
       vector<int> tempc( n+1, 0 ) ;
       for( int i = 0 ; i < shifts.size() ; i++ ) {
          int start = shifts[i][0], end = shifts[i][1] + 1, d = shifts[i][2] ;
          tempc[start] += (d == 1 ? 1 : -1);
          tempc[end] -= (d == 1 ? 1 : -1);


       } // for i


       int currentShift = 0;
       for ( int i = 0 ; i < n ; i++ ) {
         currentShift += tempc[i] ;
         tempc[i] = currentShift ;
       }
       
       for ( int i = 0 ; i < s.size() ; i++ ) {
          int shiftTemp = ( tempc[i] % 26 + 26 )  ;
          s[i] = 'a' + ( s[i] - 'a' + shiftTemp ) % 26 ;
       }

       return s ;
    }
};
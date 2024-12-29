class Solution {
public:
    int numWays(vector<string>& words, string target) {
      long count[1005][27] = {0} ; // count every index char
      long dp[1005][1005] = {0} ; // dp
      long M = 1e9+7 ;
      int wordSize = words[0].size(), result = 0 ;
      for ( int i = 0 ; i < words.size() ; i++ ) {
        for ( int j = 0 ; j < wordSize ; j++ ) {
            count[j+1][words[i][j]-'a']++ ;
        }
      }

      int targetSize = target.size() ;
      target = "0" + target ;
      for ( int i = 0 ; i <= wordSize ; i++ ) {
        dp[0][i] = 1 ;
      }

      for ( int i = 1 ; i <= targetSize ; i++ ) {
        for ( int j = 1 ; j <= wordSize ; j++ ) {
            dp[i][j] = dp[i][j-1] ;
            if ( count[j][target[i]-'a'] != 0 ){
                dp[i][j] += dp[i-1][j-1] * count[j][target[i]-'a'] % M ;
                dp[i][j]%=M;
            }

        }
      }



      return dp[targetSize][wordSize] ;
    }
};
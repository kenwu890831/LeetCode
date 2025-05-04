class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0, n = dominoes.size() ;
        map< pair<int,int>, int > m ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( dominoes[i][0] <= dominoes[i][1] ) {
                result += m[{dominoes[i][0],dominoes[i][1]}] ;
                m[{dominoes[i][0],dominoes[i][1]}]++ ;
            }
            else {
                result += m[{dominoes[i][1],dominoes[i][0]}] ;
                m[{dominoes[i][1],dominoes[i][0]}]++ ;
            }
                
        }



        return result ;
    }
};
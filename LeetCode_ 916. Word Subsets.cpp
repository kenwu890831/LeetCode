class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result ;
        int n1 = words1.size(), n2 = words2.size() ;
        int subTemp[26] = { 0 } ;
        for ( int i = 0 ; i < n2 ; i++ ) {
            int counter[26] = {0} ;
            for ( int j = 0 ; j < words2[i].size() ; j++ ) {
                counter[words2[i][j]-'a']++ ;
            }

            for ( int j = 0 ; j < 26 ; j++ ) {
                subTemp[j] = max( subTemp[j], counter[j] ) ;
            }
        }


        for ( int i = 0 ; i < n1 ; i++ ) {
            int counter[26] = {0} ;
            for ( int j = 0 ; j < words1[i].size() ; j++ ) {
                counter[words1[i][j]-'a']++ ;
            }

            bool check = true ;

            for ( int j = 0 ; j < 26 ; j++ ) {
                if ( counter[j] < subTemp[j] ) {
                    check = false ;
                    break ;
                }
            }

            if ( check ) 
              result.push_back( words1[i] ) ;
        }





        return result ;
    }
};
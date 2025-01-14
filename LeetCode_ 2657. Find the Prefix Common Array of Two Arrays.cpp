class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int temp[51] = { 0 } ;
        vector< int > result ;
        int count = 0 ;
        for ( int i = 0 ; i < A.size() ; i++ ) {
            if ( ++temp[ A[i] ] == 2 )
              count++ ;
            if ( ++temp[ B[i] ] == 2 )
              count++ ;

            result.push_back( count ) ;
        }

        return result ;
    }
};
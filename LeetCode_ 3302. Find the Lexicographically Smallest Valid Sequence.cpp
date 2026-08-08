class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int w1 = word1.size(), w2 = word2.size() ;
        bool skip = false ;
        vector< int > temp( w2+1, -1 ) ;
        temp[w2] = w1 ;
        for( int i = w2-1, j = w1-1 ; i >= 0 ; i-- ) {
            char w = word2[i] ;
            while (  j >= 0 && w != word1[j] ) 
                j-- ;
            
            if ( j < 0 ) 
                break ;

            temp[i] = j-- ;
        }

        vector< int > ans( w2 ) ;
        int j = 0 ;

        for ( int i = 0 ; i < w1 && j < w2 ; i++ ) {
            bool same = ( word1[i] == word2[j] ) ;
            bool change=( !skip && i < temp[j+1] ) ;
            if ( same | change ) {
                ans[j++] = i ;
                skip |= !same ;
            }
        }

        return ( j == w2 ) ? ans : vector<int>() ;
    }
};
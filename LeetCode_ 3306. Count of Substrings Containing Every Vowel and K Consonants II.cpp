class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int count1 = 0, count2 = 0, n = word.size(), j = 0 ;
        long long result = 0 ;
        unordered_set< char > s ({ 'a', 'e', 'i', 'o', 'u' } );
        unordered_map< char, int > m ;   
        vector< int > c ( n ) ;
        int count = 0 ;
        for ( int i = n-1 ; i >= 0 ; i-- ) {
            if ( s.find( word[i] ) == s.end() )
                count = 0 ;
            else
                count++ ;
            c[i] = count ;
        }


        for ( int i = 0 ; i < n ; i++ ) {
            while ( j < n && ( count1 < 5 || count2 < k ) ) {
                if ( s.find( word[j] ) != s.end() ) {
                    m[word[j]]++ ;
                    if ( m[word[j]] == 1 )
                        count1++ ;
                }
                else
                    count2++ ;
                j++ ;
            }

            if ( count1 == 5 && count2 == k )
                result += 1 + ( j < n ? c[j] : 0 ) ;

            if ( s.find( word[i] ) != s.end() ) {
                m[word[i]]-- ;
                if(  m[word[i]] == 0 )
                    count1-- ;
            }
            else
                count2-- ;
        }



        return result ;

    }
};
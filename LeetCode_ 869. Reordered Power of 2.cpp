class Solution {
public:
    bool reorderedPowerOf2(int n) {

        int num = 1 ;
        string temp = to_string( n ), s = to_string( num ) ;
        vector< int > h ;

        while ( num <= 1000000000 && s.size() <= temp.size() ) {
            if( s.size() == temp.size() ) {
                if ( cal( s, temp ) ) {
                    return true ;
                }

            }

            num *= 2 ;
            s = to_string( num ) ;
        }



        return false ;        
    }


    bool cal( string s, string n ) {
        vector< int > s1( 10, 0 ), s2( 10, 0 ) ;

        for ( int i = 0 ; i < s.size() ; i++ ) {
            s1[s[i]-'0']++ ;
            s2[n[i]-'0']++ ;
        }


        for( int i = 0 ; i < 10 ; i++ ) {
            if ( s1[i] != s2[i] )
                return false ;
        }

        return true ;
    }
};
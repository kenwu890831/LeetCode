class Solution {
public:
    string countAndSay(int n) {
        string result = "1" ;
        if ( n == 1 )
            return result ;
        for ( int i = 0 ; i < n-1 ; i++ ) {
            string temp = "" ;
            char num = result[0] ;
            int count = 1 ;
            for ( int j = 1 ; j < result.size() ; j++ ) {
                if ( result[j] == num ) {
                    count++ ;
                }
                else {
                    temp += to_string( count ) ;
                    temp.append( 1, num ) ;
                    count = 1 ;
                    num = result[j] ;
                }
            }
            temp += to_string( count ) ;
            temp.append( 1, num ) ;
            //result = RLE( result ) ;
            result = temp ;
        }

        return result ;
    }


};
class Solution {
public:

    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> temp(26, 0);
        string result = "" ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            temp[s[i]-'a']++ ;
        }
        
        int current = 25, smaller = 0 ;
        while ( current >= 0 ) {
            if ( temp[current] == 0 ) {
                --current ;
                continue ;
            }

            int times = min( temp[current], repeatLimit ) ;
            for ( int i = 0 ; i < times ; ++i ) {
                result += ( 'a' + current ) ;
                
            }
            temp[current] -= times ;

            if ( temp[current] > 0 ) { // find new char
              smaller = current - 1 ;
              while ( smaller >= 0 && temp[smaller] == 0 ) {
                --smaller ;
              }
               
              if ( smaller < 0 )
                break ;

              result += ( 'a' + smaller ) ;
              --temp[smaller] ;

            } 

        }

        return result ;
    }
};
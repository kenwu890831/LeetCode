class Solution {
public:
    string largestGoodInteger(string num) {
        int cur = num[0], count = 1, n = num.size(), ans = -1 ;

        for ( int i = 1 ; i < n ; i++ ) {
            if ( num[i] == cur ) {
                count++ ;
            }
            else {
                if ( count >= 3 && ans < (cur - '0') )
                    ans = cur -'0' ;
                
                cur = num[i] ;
                count = 1 ;
            }
        }

        if ( count >= 3 && ans < (cur - '0') )
            ans = cur -'0' ;

        string result = "000" ;
        
        result[0] += ans ;
        result[1] += ans ;
        result[2] += ans ;

        return (ans != -1 ) ? result : "" ;
    }
};
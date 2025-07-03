class Solution {
public:
    char kthCharacter(int k) {
        string cur = "a" ;
        while ( true ) {
            string temp = cur ;
            for ( int i = 0 ; i < cur.size() ; i++ ) {
                if ( cur[i] == 'z' )
                    cur[i] = 'a' ;
                else
                  cur[i] += 1 ;
            }

            temp += cur ;

            if ( temp.size() >= k ) {
                return temp[k-1] ;
            }
            
            cur = temp ;

        }


        return ' ' ;
    }
};
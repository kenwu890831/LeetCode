class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map< int, int > temp ;
        int maxSize = 0, result = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            int num = i, count = 0 ;
            while( num != 0 ) {
                count += ( num % 10 ) ;
                num /= 10 ;
            }
            
            temp[count]++ ;
            maxSize = max( maxSize, temp[count] ) ;
        }


        for ( auto& n : temp ) {
            if( n.second == maxSize )
                result++ ;
        }

        return result ;
    }
};
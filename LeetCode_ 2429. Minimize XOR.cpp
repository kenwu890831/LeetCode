class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count1 = __builtin_popcount( num1 );
        int count2 = __builtin_popcount( num2 );
        int result = num1 ;
        for ( int i = 0 ; i < 32 ; i++ ) {
            if ( count1 > count2 && ( 1 << i ) & num1 ) {
                result ^= 1 << i ;
                count1-- ;
                cout << result << endl ;
            } // let forward 1 to 0
            else if ( count1 < count2 && !(( 1 << i ) & num1 ) ) {
                result ^= 1 << i ;
                count1++ ;
            } // 
        }


        return result ;
    }
};
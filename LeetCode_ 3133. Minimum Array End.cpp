class Solution {
public:
    
    long long minEnd(int n, int x) {
        bitset<64> bits(x);
        bitset<64> bits2(n-1);
        vector< int > position ;
        vector< int > position2 ;

        for ( int i = 0 ; i < bits2.size() ; i++ ) {
          if ( bits2.test(i) ) {
            position.push_back( i ) ;
          }
            
        } // for

        for ( int i = 0 ; i < bits.size() ; i++ ) {
          if ( !bits.test(i) ) {
            position2.push_back( i ) ;
          }
            
        } // for

        for ( int i = 0 ; i < position.size() ; i++ ) {
          bits.set( position2[position[i]]) ;
        }



        unsigned long long result = bits.to_ullong();
        return result ;
    }
};
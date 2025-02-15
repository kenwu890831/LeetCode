class Solution {
public:
    bool cal( int num, string temp, int index ) {
      if ( index == temp.length() ) 
          return num == 0 ;
      int sum = 0 ;
      for ( int i = index ; i < temp.size() ; i++ ) {
        sum = sum * 10 + ( temp[i] - '0' ) ;
        if ( sum > num )
          return false ;
        if ( cal( num-sum, temp, i + 1 ) )
          return true ;
      }

      return false ;
    }

    int punishmentNumber(int n) {
        int result = 0 ;
        for( int i = 1 ; i <= n ; i++ ) {
            if ( cal( i, to_string(i*i), 0 ) ) {
                result += ( i*i ) ;
            }
        }

        return result ;
    }
};
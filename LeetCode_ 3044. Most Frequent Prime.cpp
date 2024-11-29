class Solution {
public:

    int xWalk[8] = {0,1,1,1,0,-1,-1,-1} ;
    int yWalk[8] = {1,1,0,-1,-1,-1,0,1} ;
    void cal ( int x, int y , int n, int m, int k , map<int,int>& counter, vector<vector<int>>& mat, int num ) {
      if ( x == n || y == m || x < 0 || y < 0 ) ;
      else {
        num = 10*num + mat[x][y];
        if ( num >= 10 ) {
            counter[num]++ ;
        }
          
        cal( x+xWalk[k], y+yWalk[k], n, m, k, counter, mat, num ) ;
      }
    }


    bool isPrime( int n ) {
        if (n <= 1) 
          return false;
        for (int i = 2; i * i <= n; i++ ){
            if (n % i == 0) 
              return false;
        }

        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        map<int,int>  counter ;
        int n = mat.size(), m = mat[0].size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                for ( int k = 0 ; k < 8 ; k++ ) {
                  cal( i, j, n, m, k, counter, mat, 0 ) ;
                }
                
            }
        }

        
        int result = -1, maxCount = -1 ;
        for ( auto i:  counter) {
            if ( i.second >= maxCount && isPrime( i.first )) {
              result = i.first ;
              maxCount = i.second ;
            }
              
        }

        return result ;
    }
};
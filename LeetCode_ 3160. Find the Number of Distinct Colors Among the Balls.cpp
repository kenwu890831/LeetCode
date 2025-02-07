class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map< int, int > temp, color ;
        vector< int > result ;
        temp[0] = limit+1 ;
        int diff = 0 ;

        for ( int i = 0 ; i < queries.size() ; i++ ) {
          int curColor = color[queries[i][0]], newColor = queries[i][1] ;
          if ( curColor != newColor ) {
            temp[curColor]-- ;
            color[queries[i][0]] = newColor ;
            temp[newColor]++ ;
            if ( temp[newColor] == 1 )
              diff++ ;
            if ( temp[curColor] == 0 && curColor != 0 )
              diff-- ;
          }

          result.push_back( diff ) ;
        }




        return result ;
    }
};
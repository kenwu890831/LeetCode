class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort( items.begin(), items.end()) ;
        vector< int > result ;
        vector< vector<int> > temp = { {0,0}};

        
        int nowPrice = items[0][0], nowBeauty = items[0][1] ;
        for ( int i = 0; i < items.size() ; i++ ) {
          nowPrice = items[i][0] ;
          nowBeauty = items[i][1] ;
          if ( nowBeauty >  temp.back()[1] ) {
            temp.push_back( {nowPrice,nowBeauty} ) ;
          }
        }


        for ( int i = 0 ; i < queries.size() ; i++ ) {
          for ( int j = temp.size() -1 ; j >= 0 ; j-- ) {
            if ( temp[j][0] <= queries[i] ) {
               result.push_back( temp[j][1] ) ;
               break ;
            }
              
          }
        } // for

        return result ;
    }
};
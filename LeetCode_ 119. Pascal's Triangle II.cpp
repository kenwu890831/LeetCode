class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if ( rowIndex == 0 ) 
            return {1} ;
        else if ( rowIndex == 1 ) 
            return { 1, 1 } ;
        vector<int> ans= { 1,1 }, temp ;

        for ( int i = 2 ; i <= rowIndex ; i++ ) {
            temp = ans ;
            ans.clear() ;
            ans.push_back( 1 ) ;
            for ( int j = 0; j < temp.size() - 1 ; j++ ) {
                ans.push_back( temp[j] + temp[j+1] ) ;
            }
            ans.push_back( 1 ) ;
        }


        return ans ;
    }
};
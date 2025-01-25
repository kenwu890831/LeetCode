class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector< int > result ;
        vector< pair< int, int> > temp ; // save index and value
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            temp.push_back( { nums[i], i } ) ;
        }

        sort( temp.begin(), temp.end() ) ;

        vector< vector< pair< int, int > >> group ;

        group.push_back( { temp[0] } ) ;

        for ( int i = 1 ; i < temp.size() ; i++ ) {
            if ( temp[ i ].first - temp[i -1].first <= limit ) {
                group.back().push_back( temp[i] ) ;
            }
            else {
                group.push_back( { temp[i] } ) ;
            }
        }


        for ( int i = 0 ; i < group.size() ; i++ ) {
            vector< int > indexTemp ;
            for ( const auto& [ v, index] : group[i] ) {
                indexTemp.push_back( index) ;
            }

            sort( indexTemp.begin(), indexTemp.end() ) ;

            for ( int j = 0 ; j < indexTemp.size(); j++ ) {
                nums[ indexTemp[j] ] = group[i][j].first ;
            }
        }


        return nums ;
    }
};
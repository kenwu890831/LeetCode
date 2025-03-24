class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int result = 0, walk = 0, pre = 1 ;
        vector< pair< int, int > > temp ;
        for ( auto& n : meetings ) {
            temp.push_back( { n[0], 1 } ) ;
            temp.push_back( { n[1]+1, -1 } ) ;
        }

        sort( temp.begin(), temp.end() ) ;
        for ( int i = 0 ; i < temp.size() ; i++ ) {
            
            if ( walk == 0 ) {
                result += ( temp[i].first - pre ) ;
            }
            
            walk += temp[i].second ;
            pre = temp[i].first ;
        }

        if ( walk == 0 ) {
            result += ( days - pre + 1) ; 
        }

        return result ;
    }
};
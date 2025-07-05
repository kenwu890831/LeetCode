class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map< int, int > count, s ;
        int ans = -1 ;

        for ( int i = 0 ; i < arr.size() ; i++ ) {
            count[arr[i]]++ ;
        }

        for ( auto& temp : count ) {
            if ( temp.first == temp.second )
                ans = max( ans, temp.second ) ;
        }

        return ans == 0 ? -1 : ans ;



    }
};
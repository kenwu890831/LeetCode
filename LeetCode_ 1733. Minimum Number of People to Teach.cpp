class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int ans = INT_MAX, person = languages.size() ;
        vector< bitset<501> > use( person ) ;

        for( int i = 0 ; i < languages.size() ; i++ ) {
            for ( int j = 0 ; j < languages[i].size() ; j++ ) {
                use[i][languages[i][j]] = 1 ;
            }
        }

        bitset<501> need = 0 ;

        // check friend can talk
        for ( int i = 0 ; i < friendships.size() ; i++ ) {
            int p1 = friendships[i][0] - 1, p2 = friendships[i][1] - 1 ;
            if ( ( use[p1] & use[p2] ).any() )
                continue ;

            need[p1] = 1 ;
            need[p2] = 1 ;
        }

        if ( need.count() == 0 ) 
            return 0 ;

        // check person need to learn lang
        for ( int i = 1 ; i <= n ; i++ ) {
            int count = 0 ;
            for ( int j = 0 ; j < person ; j++ ) {
                if ( need[j] & !use[j][i] )
                    count++ ;
            }

            ans = min( ans, count ) ;
        }

        return ans ;

    }
};
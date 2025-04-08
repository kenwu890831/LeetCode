class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0, n = nums.size() ;
        unordered_map< int , int > m ;
        for ( int i = 0 ; i < n ; i++ ) {
            m[nums[i]]++ ;
        }

        for ( int i = 0 ; i < n - 2 ; i+=3 ) {
            
            if ( check( m ) )
                return result ;
            result++ ;
            m[nums[i]]-- ;
            m[nums[i+1]]-- ;
            m[nums[i+2]]-- ;
        }

        if ( check( m ) )
            return result ;
        return result+1 ;
    }


    bool check( unordered_map< int , int >& m ) {
        for ( auto temp : m ) {
            if ( temp.second > 1 )
                return false ;
        }

        return true ;
    }
};
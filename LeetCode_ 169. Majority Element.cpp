class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map< int, int > m ;
        for ( int i = 0 ; i < n ; i++ ) {
            m[nums[i]]++ ;
        }

        for ( auto& [ num, count ] : m ) {
            if ( count > n/2 )
                return num ;
        }


        return -1 ;
    }
};
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map< int, int > temp ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            temp[nums[i]]++ ;
        }

        for ( auto count : temp ) {
            if ( count.second % 2 == 1 )
                return false ;
        }

        return true ;
    }
};
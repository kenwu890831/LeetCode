class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map < int, int > hash ;
        int result = 0, n = nums.size() ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                int mul = nums[i]* nums[j] ;
                result += 8*hash[mul] ;
                hash[mul]++ ;
            }
        }



        return result ;
    }
};
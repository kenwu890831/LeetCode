class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map< int , int > m ;
        int n = nums.size(), count = 0, temp = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            m[nums[i]]++ ;
        }

        for ( auto& [ num, v ] : m ) {
            if ( v*2 > n ) {
                temp = num ;
                count = v ;
                break ;
            }
        }

        int left = 0 ;
        int right = 0 ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            if ( nums[i] == temp )
                left++ ;
            int leftSize = i + 1 ;
            int rightSize = n - leftSize ;
            right = count - left ;



            if ( left > leftSize / 2 && right > rightSize / 2 )
                return i ;            
            
        }


        return -1 ;


    }
};
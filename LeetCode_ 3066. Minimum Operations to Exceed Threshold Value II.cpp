class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue < long,  vector< long >, greater< long > > q ;
        int n = nums.size(), sum = 0, count = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            long temp = nums[i] ;
            q.push( temp ) ;
        }

        while( q.size() >= 2 ) {
            long temp1 = q.top() ;
            if ( temp1 >= k ) {
              return count ;
            }
            q.pop() ;
            
            long temp2 = q.top() ;
            q.pop() ;


            

            q.push( temp1*2 + temp2 ) ;
            

            count++ ;
        }


        return count ;
    }
};
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue< pair< int, int > > q ;
        vector< int > ans, temp ; // temp -> index 
        int n = nums.size() ;

        for ( int i = 0 ; i < n ; i++ ) {
            q.push({ nums[i],i } );
        }

        while( k-- ) {
            pair< int,int > t = q.top() ;
            temp.push_back( t.second ) ;
            q.pop() ;
        }

        sort( temp.begin(), temp.end() ) ;


        for( int i = 0 ; i < temp.size() ; i++ )
            ans.push_back( nums[temp[i]] ) ;


        return ans;
    }
};
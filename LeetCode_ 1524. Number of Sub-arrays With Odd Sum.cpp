class Solution {
public:
    int m = ( int ) 1e9 + 7 ;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), result = 0 ;
        vector< vector< int > > temp ;
        if ( arr[0] % 2 == 1 ) 
            temp.push_back( { 1, 0 }) ;
        else
            temp.push_back( { 0, 1 }) ;
        result = temp[0][0] ;
        for ( int i = 1 ; i < n ; i++ ) {
            if ( arr[i] % 2 == 1 ) {
                temp.push_back( { temp[i-1][1]+1, temp[i-1][0] }) ;
            }
            else {
                temp.push_back( { temp[i-1][0], temp[i-1][1]+1 }) ;
            }

            result = ( result + temp[i][0] ) % m ;
        }



        return result ;
    }
};
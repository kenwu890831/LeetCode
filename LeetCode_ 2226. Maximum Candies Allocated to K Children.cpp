class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size(), result = 0, left = 1, right = *max_element(candies.begin(), candies.end()) ;
        long long total = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            total += candies[i] ;
        }

        if ( total < k )
            return 0 ;
        else if ( total == k )
            return 1 ;
        
        while ( left <= right ) {
            int mid = (right + left) / 2 ;
            if ( cal( candies, k, mid ) ) {
                result = mid ;
                left = mid + 1 ;
            }
            else {
                right = mid - 1 ;
            }

        }

        return result ; 
    }

    bool cal ( vector< int >& list, long long& k, int val ) {
        long long count = 0 ;
        for ( int i = 0 ; i < list.size(); i++ ) {
            count += list[i] / val ;
        }

        return count >= k ;
    }
};
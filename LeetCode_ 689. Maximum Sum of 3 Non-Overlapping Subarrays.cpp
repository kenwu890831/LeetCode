class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sumTemp( n ) ;   
          
        for ( int i = 0 ; i < n ; i++ ) {
            if ( i == 0 ) 
              sumTemp[i] = nums[i] ;
            else
              sumTemp[i] = sumTemp[i-1] + nums[i] ;
        } // record sum    
        
        vector<int> leftMax( n, 0 ) ;
        vector<int> leftIndex( n, 0 ) ;

        int maxSum = 0, maxIndex = 0, sum = 0 ;

        for ( int i = k - 1 ; i < n ; i++ ) {
            if ( i < k )
              sum = sumTemp[i] ;
            else  
              sum = sumTemp[i] - sumTemp[i-k] ;
            if ( sum > maxSum ) {
                maxSum = sum ;
                maxIndex = i - k + 1 ;
            }

            leftMax[i] = maxSum;
            leftIndex[i] = maxIndex;

        }



        vector<int> rightMax( n, 0 ) ;
        vector<int> rightIndex( n, 0 ) ;
        maxSum = 0, maxIndex = 0 ;
        for ( int i = n - k ; i >= 0 ; i-- ) {
            if ( i == 0 )
              sum = sumTemp[ i + k - 1 ] ;
            else  
              sum = sumTemp[ i + k - 1 ] - sumTemp[i-1] ;
            if ( sum >= maxSum ) {
                maxSum = sum ;
                maxIndex = i ;
            }

            rightMax[i] = maxSum;
            rightIndex[i] = maxIndex;
        }


        vector<int> result ;
        maxSum = 0;
        for (int i = k ; i+2*k <= n ; i++ ) {
            if ( i == 0 )
              sum = sumTemp[ i + k - 1 ] ;
            else  
              sum = sumTemp[ i + k - 1 ] - sumTemp[i-1] ;

            if (sum + leftMax[ i - 1 ] + rightMax[ i + k ] > maxSum)
            {
                maxSum = sum + leftMax[ i - 1 ] + rightMax[ i + k ] ;
                result = { leftIndex[ i - 1 ], i, rightIndex[ i + k ]} ;
            }
        }

        return result;
    }
};
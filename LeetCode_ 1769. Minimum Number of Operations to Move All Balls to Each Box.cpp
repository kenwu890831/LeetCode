class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result ;
        int left = 0, right = 0, sum = 0 ;
        for ( int i = 0 ; i < boxes.size() ; i++ ) {
            if ( boxes[i] == '1' ) {
                right++ ;
                sum += i ;

            }
              
        }


        for ( int i = 0 ; i < boxes.size() ; i++ ) {
            result.push_back( sum ) ;
            if ( boxes[i] != '1' ) {
              sum -= right ;
              sum += left ;
            }
              
            else {
                left++ ;
                right-- ;
                sum = sum - right + left ;
            }

        }



        return result ;
    }
};
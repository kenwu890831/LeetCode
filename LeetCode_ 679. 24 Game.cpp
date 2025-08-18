class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector< double > numbers( cards.begin(), cards.end() ) ;
        return search( numbers ) ;
    }

private:
    vector<double> compute( double a, double b ) {
        vector< double > results = { a + b, a - b, b - a, a * b } ;
        if ( fabs(b) > 1e-6 ) 
            results.push_back(a / b);
        if ( fabs(a) > 1e-6 ) 
            results.push_back( b / a ) ;

        return results ;
    }

    bool search( vector< double >& nums ) {

        if ( nums.size() == 1 ) {
            return fabs( nums[0] - 24.0 ) < 1e-6 ;
        }

        int size = nums.size() ;

        for ( int i = 0; i < size ; i++ ) {
            for ( int j = i + 1 ; j < size ; j++ ) {
                vector< double > remaining ;
                for ( int k = 0 ; k < size ; k++ ) {
                    if (k != i && k != j) 
                        remaining.push_back( nums[k] ) ;
                }

                for (double val : compute( nums[i], nums[j] ) ) {
                    remaining.push_back( val ) ;
                    if ( search( remaining ) ) 
                        return true ;
                    remaining.pop_back() ;
                }
            }
        }

        return false ;
    }
};

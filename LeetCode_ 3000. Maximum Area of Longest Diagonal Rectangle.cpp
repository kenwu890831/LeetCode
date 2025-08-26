class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, temp = 0;

        for ( int i = 0; i < dimensions.size(); i++ ) {
            int length = dimensions[i][0] ;
            int width  = dimensions[i][1] ;
            int diagonalSq = length * length + width * width ; 

            if ( diagonalSq > temp || ( diagonalSq == temp && length * width > ans) ) {
                temp = diagonalSq ;
                ans = length * width ;
            }
        }
        return ans ;
    }
};
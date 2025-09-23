class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size(), index1 = 0, index2 = 0, temp1 = 0, temp2 = 0 ;
        while( index1 < n1 || index2 < n2 ) {
            while( index1 < n1 && version1[index1] != '.' ) {
                temp1 = temp1 * 10 + ( version1[index1] - '0' ) ;
                index1++ ;
            }

            while( index2 < n2 && version2[index2] != '.' ) {
                temp2 = temp2 * 10 + ( version2[index2] - '0' ) ;
                index2++ ;
            }

            if ( temp1 < temp2 )
                return -1 ;
            else if ( temp1 > temp2 )
                return 1 ;

            temp1 = 0, temp2 = 0 ;
            index1++, index2++ ;
        }

        return 0 ;
    }
};
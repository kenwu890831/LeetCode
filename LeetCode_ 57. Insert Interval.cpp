class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), new1 = newInterval[0], new2 = newInterval[1], i = 0;
        vector< vector<int> > result ; 
        while( i < n && intervals[i][1] < new1 ) {
          result.push_back( intervals[i] ) ;
          i++ ;
        }


        while( i < n && intervals[i][0] <= new2 ) {
          new1 = min( new1, intervals[i][0] ) ;
          new2 = max( new2, intervals[i][1] ) ;
          i++ ;
        }

        result.push_back({new1, new2});

        while( i < n ) {
            result.push_back( intervals[i] ) ;
            i++ ;
        }

        return result ;

    }
};
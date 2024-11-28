class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int min_num = INT_MAX, max_num = 0, counter = 0, mode_count = 0, mode = 0 ;
        double sum = 0 ;
        for ( int i = 0 ; i < count.size() ; i++ ) {
          if ( count[i] > 0 ) {
            min_num = min( min_num, i ) ;
            max_num = max( max_num, i ) ;
            sum += (i * 1.0) * (count[i]  * 1.0) ;
            counter += count[i] ;
            if ( mode_count < count[i] ) {
                mode_count = count[i] ;
                mode = i ;
            }
          }
        }

        double median = 0 ;
        if ( counter % 2 == 0 ) {
          int place = counter / 2 , walk = 0, pre = 0 ;
          bool check = true ;
          cout << place << endl ;
          for ( int i = 0 ; i < count.size() ; i++ ) {
            if ( count[i] > 0 ) {
                walk += count[i] ;
                
                if ( walk > place && check ) {
                  median = i ;
                  break ;
                } 
                else if ( walk == place ) {
                  check = false ;
                  pre = i ;
                }
                else if ( !check ){
                    median = ( pre + i ) / 2.0 ;
                    break ;
                }
            }

          }

        }
        else {
          int place = counter / 2 + 1, walk = 0 ;
          for ( int i = 0 ; i < count.size() ; i++ ) {
            if ( count[i] > 0 ) {
                walk += count[i] ;
                
                if ( walk >= place ) {
                  median = i ;
                  break ;
                }
            }

          }
        } // else


        double avg = sum/counter ;
        return { min_num*1.0, max_num*1.0, avg, median, mode*1.0 } ;

    }
};
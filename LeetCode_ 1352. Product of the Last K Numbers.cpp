class ProductOfNumbers {
public:
    vector< int > temp ;
    ProductOfNumbers() {
        temp.clear() ;
    }
    
    void add(int num) {
        if ( temp.empty() ) {
            temp.push_back( num ) ;
        }
        else {
            int t ;
            if ( num == 0 ) {
                for ( int i = temp.size() - 1 ; i >= 0 ; i-- ) {
                    temp[i] = 0 ;
                }

            }
            else {
                for ( int i = temp.size() - 1 ; i >= 0 ; i-- ) {
                    if ( temp[i] == 0 )
                      break ;
                    t = num * temp[i] ;
                    temp[i] = t ;
                }
            }
            
            
            temp.push_back( num ) ;
        }
    }
    
    int getProduct(int k) {
        return temp[ temp.size() - k ] ;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
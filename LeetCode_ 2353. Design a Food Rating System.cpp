class FoodRatings {
public:

    struct Food {
        int rate ;
        string name ;

        Food ( int rate, string name ) {
            this -> rate = rate; 
            this -> name = name ;
        }

        bool operator<( const Food& other ) const {
            if ( rate == other.rate ) {
                return name > other.name ; 
            }

            return rate < other.rate ; 
        }
    } ;

    unordered_map< string, int > rating ;
    unordered_map< string, string > type ;
    unordered_map< string, priority_queue< Food > > best ;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size() ;

        for( int i = 0 ; i < n ; i++ ) {
            rating[foods[i]] = ratings[i] ;
            type[foods[i]] = cuisines[i] ;
            best[cuisines[i]].push( Food( ratings[i], foods[i] )) ;
        }
    }
    
    void changeRating(string food, int newRating) {
        rating[food] = newRating ;

        string temp = type[food] ;

        best[temp].push( Food( newRating, food ) ) ;
    }
    
    string highestRated(string cuisine) {
        auto temp = best[cuisine].top() ;

        while( rating[temp.name] != temp.rate ) {
            best[cuisine].pop() ;
            temp = best[cuisine].top() ;
        }



        return temp.name ;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
class Spreadsheet {
public:

    unordered_map<string, int> h ;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        h[cell] = value ;
    }
    
    void resetCell(string cell) {
        h[cell] = 0 ;
    }
    
    int getValue(string formula) {

        formula = formula.substr(1);

        size_t pos = formula.find('+');
        string left = formula.substr(0, pos);
        string right = formula.substr(pos + 1);

        return cal( left ) + cal( right ) ;        
    }

    int cal( string& input ) {
        if ( !input.empty() && isdigit( input[0] ) )
            return stoi(input);
        return h.count( input ) ? h[input] : 0 ;        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
class BrowserHistory {
public:

    vector<string> v;
    int index;

    BrowserHistory(string homepage) {
        v.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        v.erase(v.begin()+index+1, v.end());
        index++;
        v.push_back(url);
    }
    
    string back(int steps) {
        if (steps > index) index = 0;
        else index -= steps;
        return v[index];
    }
    
    string forward(int steps) {
        if (index+steps >= v.size()) index = v.size()-1;
        else index += steps;
        return v[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
class StockPrice {
public:
    map<int,int>mp;
    multiset<int>ms;
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end())
        {
            auto it=ms.find(mp[timestamp]);
            ms.erase(it);
        }
        mp[timestamp]=price;
        ms.insert(price);
    }
    
    int current() {
        auto it=mp.end();
        it--;
        return it->second;
    }
    
    int maximum() {
        auto it=ms.end();
        it--;
        return *it;
    }
    
    int minimum() {
        auto it=ms.begin();
        // it--;
        return *it;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
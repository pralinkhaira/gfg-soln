//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  int capacity;
  list<pair<int,int>> cache;
  unordered_map<int,list<pair<int,int>> ::iterator> map;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capacity = cap;
        
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(map.find(key) == map.end()) return -1;
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key,value});
        map[key] = cache.begin();
        return value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(map.find(key) != map.end()){
            auto it = map[key];
            cache.erase(it);
        }else if(cache.size() == capacity){
            auto lru = cache.back();
            map.erase(lru.first);
            cache.pop_back();
        }
        cache.push_front({key , value});
        map[key] = cache.begin();
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
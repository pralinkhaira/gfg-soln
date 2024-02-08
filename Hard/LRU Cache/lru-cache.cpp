//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

// design the class in the most optimal way
class LRUCache
{
public:
    LRUCache(int cap) : m_cap(cap) { }

    int GET(int key)
    {
        return apply(key,
                     [](int value) { return value; },
                     []() { return -1; });
    }

    void SET(int key, int value)
    {
        apply(key,
              [&value](int& valueRef){ valueRef = value; },
              [&](){
                  m_list.emplace_back(key, value);
                  m_map.emplace(key, std::prev(m_list.end()));

                  if (m_map.size() > m_cap)
                  {
                      m_map.erase(m_list.front().first);
                      m_list.pop_front();
                  }
              });
    }

private:
    template <typename OnFound, typename OnNotFound>
    auto apply(int key, OnFound&& onFound, OnNotFound&& onNotFound) -> decltype(onNotFound())
    {
        auto it = m_map.find(key);
        if (it == m_map.end())
            return onNotFound();

        m_list.splice(m_list.end(), m_list, it->second);
        return onFound(it->second->second);
    }

private:

    int m_cap;
    
    using List = std::list<std::pair<const int, int>>;
    List m_list;
    std::unordered_map<int, List::iterator> m_map;
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
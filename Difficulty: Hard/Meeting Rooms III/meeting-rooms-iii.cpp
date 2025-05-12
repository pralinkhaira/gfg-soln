//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> roomCount(n, 0);
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i)
            available.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!busy.empty() && busy.top().first <= start) {
                int room = busy.top().second;
                busy.pop();
                available.push(room);
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                roomCount[room]++;
                busy.push({end, room});
            } else {
                pair<long long, int> top = busy.top(); busy.pop();
                long long availableTime = top.first;
                int room = top.second;
                long long duration = end - start;
                busy.push({availableTime + duration, room});
                roomCount[room]++;
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};



//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
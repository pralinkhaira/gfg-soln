#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        vector<int> need(128, 0), have(128, 0); // ASCII size
        for (char c : p) need[c]++;

        int required = 0; // total chars to match
        for (int c : need) if (c > 0) required++;

        int formed = 0; 
        int l = 0, r = 0;
        int minLen = INT_MAX, start = -1;

        while (r < s.size()) {
            char c = s[r];
            have[c]++;

            if (need[c] > 0 && have[c] == need[c]) 
                formed++;

            // try to shrink from left
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                have[leftChar]--;
                if (need[leftChar] > 0 && have[leftChar] < need[leftChar]) 
                    formed--;
                l++;
            }

            r++;
        }

        return (start == -1) ? "" : s.substr(start, minLen);
    }
};
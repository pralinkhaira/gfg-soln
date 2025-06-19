#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string caseSort(string &s) {
        vector<char> upper, lower;

        // Separate characters into uppercase and lowercase lists
        for (char ch : s) {
            if (isupper(ch))
                upper.push_back(ch);
            else
                lower.push_back(ch);
        }

        // Sort both character lists
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        // Rebuild the sorted string, maintaining the original case positions
        int i = 0, j = 0;
        string result = s;  // initialize result with same size as s
        for (int k = 0; k < s.length(); k++) {
            if (isupper(s[k]))
                result[k] = upper[i++];
            else
                result[k] = lower[j++];
        }

        return result;
    }
};

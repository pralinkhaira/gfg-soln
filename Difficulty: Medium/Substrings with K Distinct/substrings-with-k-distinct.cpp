class Solution {
public:
  int countSubstr(std::string &s, int k) {
    int result{};
    for (size_t i{}, len(s.length()); i < len; i++) {
      int distinct{}, freq[26]{};
      for (size_t j(i); j < len; j++) {
        if (!freq[s[j] - 'a']++)
          distinct++;
        if (distinct == k)
          result++;
        if (distinct > k)
          break;
      }
    }
    return result;
  }
};
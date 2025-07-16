#define ll long long
class Solution {
  public:
    int countNumbers(int n) {
        vector<int> is_prime(100005, 1);
        is_prime[0] = is_prime[1] = 0;
        vector<int> primes;

        for(int i = 2; i < 100005; i++) {
            if(is_prime[i]) {
                primes.push_back(i);
                for(int j = i * 2; j < 100005; j += i) {
                    is_prime[j] = 0;
                }
            }
        }

        ll ans = 0;
        ll sq = sqrt(n);

        int sz = primes.size();
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                ll prod = 1LL * primes[i] * primes[j];
                if(prod > sq) break;
                ans++;
            }
        }

        // Count perfect 4th powers of primes: p^4 <= n
        vector<int> zz{256, 6561, 390625, 5764801, 214358881, 429981696};
        for(int i = 0; i < zz.size(); i++) {
            if(zz[i] <= n) ans++;
            else break;
        }

        return ans;
    }
};

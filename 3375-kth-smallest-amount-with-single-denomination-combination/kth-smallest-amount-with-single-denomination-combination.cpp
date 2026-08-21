class Solution {
public:
    long long gcd(long long a, long long b) {
        return b ? gcd(b, a % b) : a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(long long x, vector<int>& coins) {
        int n = coins.size();
        long long cnt = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long curLcm = 1;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    curLcm = lcm(curLcm, (long long)coins[i]);

                    if (curLcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            long long add = x / curLcm;

            if (__builtin_popcount(mask) & 1)
                cnt += add;
            else
                cnt -= add;
        }

        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1e18;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countNumbers(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diffs(n);
        long long total = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            total += diffs[i];
            mx = max(mx, diffs[i]);
        }

        // Enough budget to zero out every difference
        if (total <= k) return 0;

        vector<long long> cnt(mx + 1, 0);
        for (int d : diffs) cnt[d]++;

        long long c = 0;  // number of elements flattened down to level v
        for (int v = mx; v >= 1; v--) {
            c += cnt[v];
            if (c == 0) continue;

            if (k >= c) {
                // lower all c elements from v to v-1
                k -= c;
            } else {
                // only k elements drop to v-1, the other (c-k) stay at v
                long long res = (c - k) * v * v + k * (long long)(v - 1) * (v - 1);
                // add elements already below v
                for (int u = 1; u < v; u++) {
                    res += cnt[u] * (long long)u * u;
                }
                return res;
            }
        }
        return 0;
    }
};
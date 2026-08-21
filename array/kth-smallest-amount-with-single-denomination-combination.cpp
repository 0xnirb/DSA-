class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countAmounts(vector<int>& coins, long long x) {

        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            long long multiple = 1;
            int bits = 0;
            bool tooLarge = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    long long g = gcd(multiple, (long long)coins[i]);

                    // Avoid overflow
                    multiple = multiple / g * coins[i];

                    if (multiple > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            long long contribution = x / multiple;

            if (bits % 2 == 1)
                ans += contribution;
            else
                ans -= contribution;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countAmounts(coins, mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
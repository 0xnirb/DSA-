class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {

            if (num[i] == '?') {
                leftQ++;
            }
            else {
                leftSum += num[i] - '0';
            }
        }

        // Second half
        for (int i = n / 2; i < n; i++) {

            if (num[i] == '?') {
                rightQ++;
            }
            else {
                rightSum += num[i] - '0';
            }
        }

        int sumDiff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;

        // Bob can win only if this is exactly balanced
        if (2 * sumDiff + 9 * qDiff == 0) {
            return false;
        }

        return true;
    }
};
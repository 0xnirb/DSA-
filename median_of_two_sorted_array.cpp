//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

//The overall run time complexity should be O(log (m+n)).
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if (l1 <= r2 && l2 <= r1) {

                // Even number of elements
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                // Odd number of elements
                return max(l1, l2);
            }

            // Move towards left
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            // Move towards right
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
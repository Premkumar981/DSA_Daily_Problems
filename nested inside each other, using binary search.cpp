#include <iostream>
#include <algorithm>
#include <climits>

class Solution {
public:
    int binarySearch(int* dp, int size, int val) {
        int lo = 0, hi = size - 1, res = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (dp[mid] < val) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res + 1;
    }

    int maxEnvelopes(int** envelopes, int n) {
        std::sort(envelopes, envelopes + n, [](const int* a, const int* b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int* LIS = new int[n];
        std::fill(LIS, LIS + n, INT_MAX);
        int length = 0;
        for (int i = 0; i < n; i++) {
            int index = binarySearch(LIS, length, envelopes[i][1]);
            LIS[index] = envelopes[i][1];
            if (index == length)
                length++;
        }

        delete[] LIS;
        return length;
    }
};

int main() {
    int n;
    std::cin >> n;
    int** envelopes = new int*[n];

    // Read the values of the envelopes
    for (int i = 0; i < n; i++) {
        envelopes[i] = new int[2];
        std::cin >> envelopes[i][0] >> envelopes[i][1];
    }

    Solution solution;
    int maxEnvelopes = solution.maxEnvelopes(envelopes, n);

    std::cout << maxEnvelopes << std::endl;

    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete[] envelopes[i];
    }
    delete[] envelopes;

    return 0;
}


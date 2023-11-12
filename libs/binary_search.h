#include "pair_int.h"

ii binary_search(int* arr, int n, int t) {
    int l = 0, r = n;
    ii ans = { false, -1 };

    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m] == t) {
            ii ans = { true, m };
            return ans;
        }
        else if (arr[m] < t) l = m + 1;
        else r = m - 1;
    }

    return ans;
}
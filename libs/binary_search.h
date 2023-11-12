int binary_search(int* arr, int n, int t) {
    int l = 0, r = n;

    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m] == t) return m;
        else if (arr[m] < t) l = m + 1;
        else r = m - 1;
    }

    return -1;
}
int lower_bound(int* arr, int n, int t) {
    int l = 0, r = n;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (t <= arr[m]) r = m;
        else l = m + 1;
    }

    return l;
}
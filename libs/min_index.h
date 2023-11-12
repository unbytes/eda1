int min_index(int* arr, int i, int j) {
    if (i == j) return i;

    int k = min_index(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}
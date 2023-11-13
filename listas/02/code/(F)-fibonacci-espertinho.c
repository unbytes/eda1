long int memo[81] = { 0 };
long int fibonacci(int n) {
    if (n <= 2) return 1;
    if (!memo[n]) memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}
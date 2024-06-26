#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>
using namespace std;
using namespace std::chrono;

unordered_map<int, int> memo;
int fibonacciRecursiveMemo(int n) {
    if (n <= 1)
        return n;

    if (memo.find(n) != memo.end())
        return memo[n];

    memo[n] = fibonacciRecursiveMemo(n - 1) + fibonacciRecursiveMemo(n - 2);
    return memo[n];
}

int fibonacciDP(int n) {
    if (n <= 1)
        return n;

    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}

int main() {
    int n_values[] = {10, 25, 30, 40, 50};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    cout << "=== Perbandingan Waktu Eksekusi Fibonacci ===" << endl;
    cout << "n \t| Recur. Time (microseconds) \t| DP Time (microseconds)" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < num_values; ++i) {
        int n = n_values[i];

        auto start_recur = high_resolution_clock::now();
        int fib_recur = fibonacciRecursiveMemo(n);
        auto stop_recur = high_resolution_clock::now();
        auto duration_recur = duration_cast<microseconds>(stop_recur - start_recur);

        auto start_dp = high_resolution_clock::now();
        int fib_dp = fibonacciDP(n);
        auto stop_dp = high_resolution_clock::now();
        auto duration_dp = duration_cast<microseconds>(stop_dp - start_dp);

        cout << n << "\t| " << duration_recur.count() << "\t\t\t| " << duration_dp.count() << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMaxAfterKOperations(std::vector<int>& arr, int k) {
    int n = arr.size();

    // Step 1: Find the maximum value in the original array
    int max_val = *std::max_element(arr.begin(), arr.end());

    // Step 2: Perform the operations
    for (int i = 0; i < n - 1 && k > 0; ++i) {
        int diff = arr[i + 1] - arr[i];
        if (diff > 0) {
            int operations_possible = std::min(k, diff);
            k -= operations_possible;
            arr[i] += operations_possible;
        }
    }

    // Step 3: Calculate the maximum value after all operations
    int max_after_operations = max_val + k * n;

    return max_after_operations;
}

int main() {
    // Example usage:
    int n;cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;cin>>k;
    int result = findMaxAfterKOperations(arr, k);
    std::cout << "Maximum value after " << k << " operations is: " << result << std::endl;

    return 0;
}


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nearestSmallerLeft(int n, vector<int>& arr) {
    vector<int> result(n, 0); // Initialize result array with 0s
    stack<int> s; // Stack to store indices

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop(); // Remove elements greater than or equal to current element
        }
        
        if (!s.empty()) {
            result[i] = s.top() + 1; // Update result with nearest smaller element's index + 1
        }
        
        s.push(i); // Push current index to stack
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nearestSmallerLeft(n, arr);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}

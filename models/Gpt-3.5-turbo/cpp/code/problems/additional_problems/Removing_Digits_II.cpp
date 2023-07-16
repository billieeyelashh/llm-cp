
#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int minSteps(int n) {
    if (n == 0)
        return 0;

    if (memo[n] != -1)
        return memo[n];

    int minStepsRequired = 1e9; // Initialize with a large value

    string num = to_string(n);
    for (char c : num) {
        int digit = c - '0';
        if (digit != 0)
            minStepsRequired = min(minStepsRequired, minSteps(n - digit));
    }

    memo[n] = minStepsRequired + 1;
    return memo[n];
}

int main() {
    int n;
    cin >> n;

    memo.resize(n + 1, -1);

    int minStepsRequired = minSteps(n);
    cout << minStepsRequired << endl;

    return 0;
}

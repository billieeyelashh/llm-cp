
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = (prefixSum[i - 1] + arr[i - 1]) % n;
    }

    vector<long long> modFreq(n, 0);
    for (int i = 0; i <= n; ++i) {
        modFreq[prefixSum[i]]++;
    }

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        count += modFreq[i] * (modFreq[i] - 1) / 2;
    }

    cout << count << endl;

    return 0;
}

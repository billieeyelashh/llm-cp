
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> prefix_sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i+1] = prefix_sum[i] + (s[i] == '1' ? 1 : 0);
    }

    vector<int> counts(n+1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            counts[prefix_sum[j] - prefix_sum[i]]++;
        }
    }

    for (int i = 0; i <= n; i++) {
        cout << counts[i] << " ";
    }

    return 0;
}

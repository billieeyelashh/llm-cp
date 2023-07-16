
#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateSignalProduct(const vector<int>& signal, const vector<int>& mask) {
    int n = signal.size();
    int m = mask.size();
    vector<int> result(n + m - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i + j] += signal[i] * mask[j];
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> signal(n);
    for (int i = 0; i < n; i++) {
        cin >> signal[i];
    }

    vector<int> mask(m);
    for (int i = 0; i < m; i++) {
        cin >> mask[i];
    }

    vector<int> result = calculateSignalProduct(signal, mask);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

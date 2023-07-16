
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    unordered_map<int, int> appleCount, bananaCount;

    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        appleCount[weight]++;
    }

    for (int i = 0; i < m; i++) {
        int weight;
        cin >> weight;
        bananaCount[weight]++;
    }

    for (int w = 2; w <= 2 * k; w++) {
        int ways = 0;
        for (int a = 1; a <= min(w - 1, k); a++) {
            int b = w - a;
            ways += appleCount[a] * bananaCount[b];
        }
        cout << ways << " ";
    }

    return 0;
}

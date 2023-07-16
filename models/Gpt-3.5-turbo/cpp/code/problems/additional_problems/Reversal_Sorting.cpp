
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    vector<pair<int, int>> reversals;
    for (int i = n; i >= 1; i--) {
        if (array[i-1] != i) {
            int j = i;
            while (array[j-1] != i) {
                j--;
            }
            reversals.push_back({j, i});
            reverse(array.begin() + j - 1, array.begin() + i);
        }
    }
    
    cout << reversals.size() << endl;
    for (auto reversal : reversals) {
        cout << reversal.first << " " << reversal.second << endl;
    }
    
    return 0;
}

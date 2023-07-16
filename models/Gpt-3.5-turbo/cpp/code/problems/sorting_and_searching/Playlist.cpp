
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int songs[n];
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }
    
    unordered_set<int> uniqueSongs;
    int left = 0, right = 0;
    int maxLength = 0;
    
    while (right < n) {
        if (uniqueSongs.count(songs[right]) == 0) {
            uniqueSongs.insert(songs[right]);
            maxLength = max(maxLength, right - left + 1);
            ++right;
        } else {
            uniqueSongs.erase(songs[left]);
            ++left;
        }
    }
    
    cout << maxLength << endl;
    
    return 0;
}

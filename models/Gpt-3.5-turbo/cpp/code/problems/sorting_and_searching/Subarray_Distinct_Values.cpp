
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int count = 0, left = 0;
    unordered_map<int, int> freq;
    
    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;
        
        while (freq.size() > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }
            left++;
        }
        
        count += (right - left + 1);
    }
    
    cout << count << endl;
    
    return 0;
}

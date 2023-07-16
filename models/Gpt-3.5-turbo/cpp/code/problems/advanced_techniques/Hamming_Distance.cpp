
#include <iostream>
#include <vector>

using namespace std;

int hammingDistance(string a, string b) {
    int distance = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            distance++;
        }
    }
    return distance;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    int minDistance = k; // Initialize with maximum possible value
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int distance = hammingDistance(strings[i], strings[j]);
            minDistance = min(minDistance, distance);
        }
    }
    
    cout << minDistance << endl;
    
    return 0;
}

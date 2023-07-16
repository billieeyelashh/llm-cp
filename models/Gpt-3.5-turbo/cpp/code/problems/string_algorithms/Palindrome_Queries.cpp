
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    vector<vector<int>> prefix(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1];
        prefix[i][s[i - 1] - 'a']++;
    }
    
    for (int i = 0; i < m; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        
        if (type == 1) {
            s[a - 1] = b;
            
            for (int j = a; j <= n; j++) {
                prefix[j][s[a - 1] - 'a']++;
                prefix[j][s[a - 1] - 'a']--;
            }
        } else {
            bool palindrome = true;
            
            for (int j = 0; j < 26; j++) {
                int count = prefix[b][j] - prefix[a - 1][j];
                
                if (count % 2 != 0) {
                    if (!palindrome) {
                        palindrome = false;
                        break;
                    } else {
                        palindrome = true;
                    }
                }
            }
            
            if (palindrome) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}

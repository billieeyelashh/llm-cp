
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    while (m--) {
        int a, b;
        cin >> a >> b;

        string substring = s.substr(a-1, b-a+1);
        s.erase(a-1, b-a+1);
        s += substring;
    }

    cout << s << endl;

    return 0;
}

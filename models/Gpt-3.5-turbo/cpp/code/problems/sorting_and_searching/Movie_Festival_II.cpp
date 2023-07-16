
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Movie {
    int start;
    int end;
};

bool sortByEnd(const Movie& a, const Movie& b) {
    return a.end < b.end;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }

    sort(movies.begin(), movies.end(), sortByEnd);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (k == 0) break;
        if (movies[i].start >= movies[i].end) continue;
        count++;
        k--;
    }

    cout << count << endl;

    return 0;
}

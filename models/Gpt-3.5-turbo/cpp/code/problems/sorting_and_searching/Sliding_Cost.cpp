
#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> window; // to store the elements of the current window
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        // remove elements from the front of the window if they are outside the current window
        if (!window.empty() && window.front() <= i - k)
            window.pop_front();

        // remove elements from the back of the window if they are greater than the current element
        while (!window.empty() && x < window.back())
            window.pop_back();

        // add the current element to the back of the window
        window.push_back(x);

        // output the minimum cost if the window is of size k
        if (i >= k - 1)
            cout << window.front() << " ";
    }

    return 0;
}

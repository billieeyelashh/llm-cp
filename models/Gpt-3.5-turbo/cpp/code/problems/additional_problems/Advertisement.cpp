
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int height = heights[st.top()];
        st.pop();

        int width = st.empty() ? n : (n - st.top() - 1);
        maxArea = max(maxArea, height * width);
    }

    cout << maxArea << endl;

    return 0;
}

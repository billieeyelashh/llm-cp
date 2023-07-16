
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    stack<int> stack1, stack2;
    int current = 1;

    vector<int> output(n);

    for (int i = 0; i < n; ++i) {
        int num = input[i];

        if (num < current) {
            if (!stack1.empty() && stack1.top() < num) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

            stack1.push(num);
            output[i] = 1;
        } else {
            if (stack1.empty() || stack1.top() != current) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

            stack1.pop();
            output[i] = 2;
            ++current;
        }
    }

    while (!stack2.empty()) {
        if (stack2.top() != current) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        stack2.pop();
        output[n - stack2.size() - 1] = 2;
        ++current;
    }

    for (int i = 0; i < n; ++i) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}

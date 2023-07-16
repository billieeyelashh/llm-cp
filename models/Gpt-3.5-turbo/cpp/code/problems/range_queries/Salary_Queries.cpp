
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    multiset<int> salaries;
    for (int i = 0; i < n; ++i) {
        int salary;
        cin >> salary;
        salaries.insert(salary);
    }

    for (int i = 0; i < q; ++i) {
        char op;
        cin >> op;

        if (op == '!') {
            int k, x;
            cin >> k >> x;

            // Remove the old salary of employee k
            auto it = salaries.find(*(salaries.begin()) + k - 1);
            salaries.erase(it);

            // Insert the new salary of employee k
            salaries.insert(x);
        } else if (op == '?') {
            int a, b;
            cin >> a >> b;

            // Count the number of employees whose salary is between a and b
            cout << salaries.count(b) - salaries.count(a - 1) << endl;
        }
    }

    return 0;
}

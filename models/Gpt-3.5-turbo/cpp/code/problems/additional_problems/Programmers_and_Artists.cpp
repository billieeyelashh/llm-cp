
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Applicant {
    int programming_skill;
    int artistic_skill;
};

bool compare(Applicant a, Applicant b) {
    // Sort in descending order based on sum of skills
    return (a.programming_skill + a.artistic_skill) > (b.programming_skill + b.artistic_skill);
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<Applicant> applicants(n);
    for (int i = 0; i < n; ++i) {
        cin >> applicants[i].programming_skill >> applicants[i].artistic_skill;
    }

    sort(applicants.begin(), applicants.end(), compare);

    long long max_skill_sum = 0;
    for (int i = 0; i < a; ++i) {
        max_skill_sum += applicants[i].programming_skill;
    }
    for (int i = a; i < a + b; ++i) {
        max_skill_sum += applicants[i].artistic_skill;
    }

    cout << max_skill_sum << endl;

    return 0;
}

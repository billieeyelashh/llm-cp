
#include <iostream>
#include <vector>

using namespace std;

vector<int> constructTree(int n, vector<int>& code) {
    vector<int> frequency(n + 1, 0);
    for (int i = 0; i < n - 2; i++) {
        frequency[code[i]]++;
    }

    vector<int> treeEdges;

    int leafNode = 1;
    while (frequency[leafNode] != 0) {
        leafNode++;
    }

    int unusedNode = 1;
    while (frequency[unusedNode] != 0 || unusedNode == leafNode) {
        unusedNode++;
    }

    for (int i = 0; i < n - 2; i++) {
        treeEdges.push_back(leafNode);
        treeEdges.push_back(code[i]);

        frequency[code[i]]--;
        if (frequency[code[i]] == 0 && code[i] < unusedNode) {
            unusedNode = code[i];
        }

        if (frequency[leafNode] == 0) {
            leafNode = unusedNode;
            while (frequency[leafNode] != 0) {
                leafNode++;
            }
        }
    }

    treeEdges.push_back(leafNode);
    treeEdges.push_back(unusedNode);

    return treeEdges;
}

int main() {
    int n;
    cin >> n;

    vector<int> code(n - 2);
    for (int i = 0; i < n - 2; i++) {
        cin >> code[i];
    }

    vector<int> treeEdges = constructTree(n, code);

    for (int i = 0; i < n - 1; i += 2) {
        cout << treeEdges[i] << " " << treeEdges[i + 1] << endl;
    }

    return 0;
}

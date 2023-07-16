
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> postorder;
unordered_map<int, int> inorderIndices;

void buildPostorder(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) {
        return;
    }
    
    int rootValue = preorder[preStart];
    int rootIndex = inorderIndices[rootValue];
    
    buildPostorder(preorder, preStart + 1, preStart + (rootIndex - inStart), inStart, rootIndex - 1);
    buildPostorder(preorder, preStart + (rootIndex - inStart) + 1, preEnd, rootIndex + 1, inEnd);
    
    postorder.push_back(rootValue);
}

vector<int> getPostorder(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    
    // Store the indices of elements in the inorder traversal
    for (int i = 0; i < n; i++) {
        inorderIndices[inorder[i]] = i;
    }
    
    buildPostorder(preorder, 0, n - 1, 0, n - 1);
    
    return postorder;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> preorder(n);
    vector<int> inorder(n);
    
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    
    vector<int> result = getPostorder(preorder, inorder);
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}

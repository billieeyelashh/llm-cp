
bool isIsomorphic(vector<vector<int>>& tree1, int root1, vector<vector<int>>& tree2, int root2) {
    // Base case: if both roots are -1, it means we have reached the end of the tree
    if (root1 == -1 && root2 == -1)
        return true;

    // If one root is -1 and the other is not, they are not isomorphic
    if ((root1 == -1 && root2 != -1) || (root1 != -1 && root2 == -1))
        return false;

    // If the number of children is different, they are not isomorphic
    if (tree1[root1].size() != tree2[root2].size())
        return false;

    // Check if the children of the roots are isomorphic
    for (int i = 0; i < tree1[root1].size(); i++) {
        int child1 = tree1[root1][i];
        int child2 = tree2[root2][i];

        // Recursively check if the children are isomorphic
        if (!isIsomorphic(tree1, child1, tree2, child2))
            return false;
    }

    // If all the checks passed, the trees are isomorphic
    return true;
}


#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    int n = A.size();
    int m = B[0].size();
    int k = A[0].size();

    vector<vector<long long>> C(n, vector<long long>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                C[i][j] += (A[i][x] * B[x][j]) % MOD;
                C[i][j] %= MOD;
            }
        }
    }

    return C;
}

vector<vector<long long>> matrixPower(const vector<vector<long long>>& A, long long k) {
    if (k == 0) {
        int n = A.size();
        vector<vector<long long>> I(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            I[i][i] = 1;
        }
        return I;
    }

    vector<vector<long long>> half = matrixPower(A, k / 2);
    vector<vector<long long>> result = matrixMultiply(half, half);

    if (k % 2 == 1) {
        result = matrixMultiply(result, A);
    }

    return result;
}

long long fibonacci(long long n) {
    if (n == 0 || n == 1) {
        return n;
    }

    vector<vector<long long>> fibMatrix = {{1, 1}, {1, 0}};
    vector<vector<long long>> poweredMatrix = matrixPower(fibMatrix, n - 1);

    return poweredMatrix[0][0];
}

int main() {
    long long n;
    cin >> n;

    long long result = fibonacci(n);
    cout << result << endl;

    return 0;
}

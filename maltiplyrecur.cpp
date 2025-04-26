#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> MatrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C (n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int newSize = n / 2;
        vector<vector<int>> A11(newSize, vector<int>(newSize));
        vector<vector<int>> A12(newSize, vector<int>(newSize));
        vector<vector<int>> A21(newSize, vector<int>(newSize));
        vector<vector<int>> A22(newSize, vector<int>(newSize));

        vector<vector<int>> B11(newSize, vector<int>(newSize));
        vector<vector<int>> B12(newSize, vector<int>(newSize));
        vector<vector<int>> B21(newSize, vector<int>(newSize));
        vector<vector<int>> B22(newSize, vector<int>(newSize));
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }
        vector<vector<int>> C11 = MatrixMultiply(A11, B11);
        vector<vector<int>> C12 = MatrixMultiply(A12, B21);
        vector<vector<int>> C21 = MatrixMultiply(A21, B11);
        vector<vector<int>> C22 = MatrixMultiply(A22, B21);

        vector<vector<int>> D11 = MatrixMultiply(A11, B12);
        vector<vector<int>> D12 = MatrixMultiply(A12, B22);
        vector<vector<int>> D21 = MatrixMultiply(A21, B12);
        vector<vector<int>> D22 = MatrixMultiply(A22, B22);
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C[i][j] = C11[i][j] + C12[i][j];
                C[i][j + newSize] = D11[i][j] + D12[i][j];
                C[i + newSize][j] = C21[i][j] + C22[i][j];
                C[i + newSize][j + newSize] = D21[i][j] + D22[i][j];
            }
        }
    }

    return C;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage
    vector<vector<int>> A = {{1, 0, 1, 0}, {2, 0, 2, 0}, {3, 0, 3, 0}, {4, 0, 0, 0}};
    vector<vector<int>> B = {{-1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}};

    vector<vector<int>> C = MatrixMultiply(A, B);
    printMatrix(C);

    return 0;
}


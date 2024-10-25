#include<bits/stdc++.h>
using namespace std;

void matrix_Inversion() {
    cout << "\nMatrix Inversion selected.\n";

    int n;
    cout << "\nEnter the size of the matrix: ";
    cin >> n;

    vector<vector<double> > A(n, vector<double>(n));
    vector<vector<double> > I(n, vector<double>(n, 0));  // Identity matrix

    cout << "\nEnter the coefficients of the matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (i == j)
                I[i][j] = 1;  // Initializing identity matrix
        }
    }

    // Performing Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Ensuring the pivot element is non-zero
        if (A[i][i] == 0) {
            cout << "\nMatrix is singular, inversion is not possible.\n";
            return;
        }

        double pivot = A[i][i];

        // Now normalizing the pivot row
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }

        // Eliminating other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j < n; j++) {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
    }

    // Output inverse matrix
    cout << "\nThe inverse matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << I[i][j] << "\t";
        }
        cout << endl;
    }
}



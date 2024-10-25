#include<bits/stdc++.h>
using namespace std;

void lu_Factorization() {
    cout << "\nLU Factorization method selected.\n";

    int n;
    cout << "\nNow Enter the number of equations: ";
    cin >> n;

    vector<vector<double> > A(n, vector<double>(n + 1));

    cout << "\nEnter the augmented matrix (A | b):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<double> > L(n, vector<double>(n, 0));
    vector<vector<double> > U(n, vector<double>(n, 0));

    vector<vector<double> > coefficient(n, vector<double>(n));
    vector<double> b(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            coefficient[i][j] = A[i][j];
        }
        b[i] = A[i][n];
    }

    //LU decomposition
    for (int k = 0; k < n; k++) {
        for (int j = k; j < n; j++) {
            double sum = 0;
            for (int s = 0; s < k; s++) {
                sum += L[k][s] * U[s][j];
            }
            U[k][j] = coefficient[k][j] - sum;
        }

        for (int i = k; i < n; i++) {
            if (i == k)
                L[k][k] = 1;
            else {
                double sum = 0;
                for (int s = 0; s < k; s++) {
                    sum += L[i][s] * U[s][k];
                }
                L[i][k] = (coefficient[i][k] - sum) / U[k][k];
            }
        }
    }

    // This is forward substitution to solve Ly = b
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = b[i] - sum;
    }

    // This is backward substitution to solve Ux = y
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    // Output
    cout << "\nSolution vector (x) will be:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << x[i] << "\n";
    }
}

#include<bits/stdc++.h>
using namespace std;

void gauss_Seidel_Iterative_Method() {
    cout << "\nGauss-Seidel Iterative Method selected.\n";

    int n;
    cout << "Now enter the number of variables: ";
    cin >> n;   cout<<"\n";

    double A[n][n], b[n], x[n], tolerance;
    int maxIterations;

    cout << "Enter the coefficients of matrix and the constants in one line for each row:\n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    cout << "\nEnter the initial guess for the variables:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = ";
        cin >> x[i];
    }

    cout << "\nEnter the tolerance for convergence: ";
    cin >> tolerance;
    cout << "\nEnter the maximum number of iterations: ";
    cin >> maxIterations;

    int iterations = 0;
    bool converged = false;

    while (iterations < maxIterations) {
        converged = true;

        for (int i = 0; i < n; i++) {
            double sum = b[i];

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }

            double new_x = sum / A[i][i];

            if (fabs(new_x - x[i]) > tolerance) {
                converged = false;
            }

            x[i] = new_x;
        }

        iterations++;

        if (converged) {
            break;
        }
    }


    if (converged) {
        cout << "\nThe solution converged in " << iterations << " iterations.\n";
    } else {
        cout << "\nThe solution did not converge within the maximum number of iterations.\n";
    }

    cout << "\nThe solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }
}

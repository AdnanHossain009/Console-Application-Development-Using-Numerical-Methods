#include<bits/stdc++.h>
using namespace std;

void jacobi_Iterative_Method() {
    cout << "\nJacobi Iterative Method selected.\n";

    int n;
    cout << "\nEnter the number of variables: ";
    cin >> n;   cout<<"\n";

    double A[n][n], b[n], x[n], new_x[n], tolerance;
    int maxIterations;

    cout << "Enter the coefficients of matrix and the constants in one line for each row:\n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    cout << "\nNow enter the initial guess for the variables:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = ";
        cin >> x[i];
    }

    cout << "Enter the tolerance for convergence: ";
    cin >> tolerance;   cout<<"\n";

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;   cout<<"\n";

    int iterations = 0;

    while (iterations < maxIterations) {
        bool converged = true;

        for (int i = 0; i < n; i++) {
            double sum = b[i];

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }

            new_x[i] = sum / A[i][i];

            if (fabs(new_x[i] - x[i]) > tolerance) {
                converged = false;
            }
        }

        for (int i = 0; i < n; i++) {
            x[i] = new_x[i];
        }

        iterations++;

        if (converged) {
            break;
        }
    }

    if (iterations < maxIterations) {
        cout << "The solution converged in " << iterations << " iterations.\n";
    } else {
        cout << "The solution did not converge within the maximum number of iterations.\n";
    }

    cout << "The solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }
}


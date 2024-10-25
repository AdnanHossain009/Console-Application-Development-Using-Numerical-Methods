#include<bits/stdc++.h>
#include "Jacobi_Iterative_Method.cpp"
#include "Gauss_Seidel_Iterative_Method.cpp"
#include "Gauss_and_Gauss_Jordan_Elimination.cpp"
#include "BiSection_FalsePosition_Secant_NewtonRaphson.cpp"
#include "LU_Factorization.cpp"
#include "RK_method.cpp"
#include "Matrix_Inversion.cpp"

using namespace std;

int main() {
    int choice;

    while (true) {
    cout << "\nSelect a Method:\n";
    cout << left << setw(35) << "1. Solution of Linear Equations" << endl;
    cout << "  " << left << setw(35) << "a. Jacobi Iterative Method" << "(1)\n";
    cout << "  " << left << setw(35) << "b. Gauss-Seidel Iterative Method" << "(2)\n";
    cout << "  " << left << setw(35) << "c. Gauss Elimination" << "(3)\n";
    cout << "  " << left << setw(35) << "d. Gauss-Jordan Elimination" << "(4)\n";
    cout << "  " << left << setw(35) << "e. LU Factorization" << "(5)\n";

    cout << left << setw(35) << "2. Solution of Non-linear Equations" << endl;
    cout << "  " << left << setw(35) << "a. Bisection Method" << "(6)\n";
    cout << "  " << left << setw(35) << "b. False Position Method" << "(7)\n";
    cout << "  " << left << setw(35) << "c. Secant Method" << "(8)\n";
    cout << "  " << left << setw(35) << "d. Newton-Raphson Method" << "(9)\n";

    cout << left << setw(35) << "3. Solution of Differential Equations" << endl;
    cout << "  " << left << setw(35) << "a. Runge-Kutta Method" << "(10)\n";

    cout << left << setw(37) << "4. Matrix Inversion" << "(11)\n";

    cout << "\nEnter your choice (or 0 to exit): ";
        cin >> choice;

        switch (choice) {
            case 0: cout << "Program Terminated...\n"; return 0;

            case 1: jacobi_Iterative_Method(); break;

            case 2: gauss_Seidel_Iterative_Method(); break;

            case 3: gauss_Elimination(); break;

            case 4: gauss_Jordan_Elimination(); break;

            case 5: lu_Factorization(); break;

            case 6: bisection_Method(); break;

            case 7: false_Position_Method(); break;

            case 8: secant_Method(); break;

            case 9: newton_Raphson_Method(); break;

            case 10: runge_Kutta_Method(); break;

            case 11: matrix_Inversion(); break;

            default: cout << "Invalid choice.Please Try again.\n"; break;
        }
    }

    return 0;
}

//Jacobain and Gauss Seidel Sample Test 5 variable
/*
5
10 2 -1 3 4 30
3 12 4 -1 2 20
2 1 11 -2 3 10
1 2 -1 10 1 15
4 -1 3 2 9 25
0
0
0
0
0
0.0001
30
*/

//Rest of the Linear Equation sample test
/*
5
10 2 -1 3 4 30
3 12 4 -1 2 20
2 1 11 -2 3 10
1 2 -1 10 1 15
4 -1 3 2 9 25
*/

//Non linear equation sample Test

//Bisection and False Position Method
/*
0 0 1 -4 -10
5 6
0.0001
*/

//Secant Method
/*
0 0 1 -4 -10
4 2
0.0001
30
*/

//Newton Raphson Method
/*
0 0 1 -3 2
0
0.0001
*/

//matrix inversion
/*
5
10  2  -1  3  4
3  12  4  -1  2
2  1  11  -2  3
1  2  -1  10  1
4  -1  3  2  9

*/


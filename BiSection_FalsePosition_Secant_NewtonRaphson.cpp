#include<bits/stdc++.h>
using namespace std;

//initializing variable a,b,c,d,e globally
double a,b,c,d,e;

void input_coefficients() {
    cout << "\nEnter the coefficients a, b, c, d, e (for ax^4 + bx^3 + cx^2 + dx + e): ";
    cin >> a >> b >> c >> d >> e;
}

// Defining the equation f(x) = ax^4 + bx^3 + cx^2 + dx + e
double f(double x) {
    return a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e;
}

// Defining the derivative f'(x) = 4ax^3 + 3bx^2 + 2cx + d
double f_prime(double x) {
    return 4 * a * pow(x, 3) + 3 * b * pow(x, 2) + 2 * c * x + d;
}


void bisection_Method() {
    cout << "\nBisection Method selected.\n";

    input_coefficients();

    double a, b, epsilon;
    cout << "\nNow enter the initial guesses (a, b) and tolerance (epsilon): ";
    cin >> a >> b >> epsilon;

    while (f(a) * f(b) >= 0) {
        cout << "\nIncorrect initial guesses. Please try again." << endl;
        return;
    }

    double c = a;
    int i = 0;

    cout<<"\n";

    cout << left << setw(10) << "Iter" << setw(15) << "Midpoint c" << setw(20) << "f(c)" << setw(15) << "a" << setw(15) << "b" << endl<<endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout<<"\n";
    while (fabs(a - b) >= epsilon) {
        c = (a + b) / 2.0;

        cout << left << setw(10) << i << setw(15) << c << setw(20) << f(c) << setw(15) << a << setw(15) << b << endl;

        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        i++;
    }

    cout << "\nThe root is: " << c << endl;
}





void false_Position_Method() {
    cout << "\nFalse Position Method selected.\n";

    input_coefficients();

    double a, b, epsilon;
    cout << "\nNow enter the initial guesses (a, b) and tolerance (epsilon): ";
    cin >> a >> b >> epsilon;

    if (f(a) * f(b) >= 0) {
        cout << "\nIncorrect initial values, root may not lie in this interval.\n";
        return;
    }

    double c = a;
    int i = 0;

    cout<<"\n";
    cout << left << setw(10) << "Iter" << setw(20) << "Approximate c" << setw(20) << "f(c)" << endl<<endl;
    cout << "--------------------------------------------" << endl;
    cout<<"\n";
    while (fabs(f(c)) > epsilon) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << left << setw(10) << i << setw(20) << c << setw(20) << f(c) << endl;

        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        i++;
    }

    cout << "\nThe root is: " << c << "\n";
}


void secant_Method() {
    cout << "\nSecant Method selected.\n";

    input_coefficients(); // reads the coefficients for f(x)

    double x0, x1, epsilon;
    int maxIterations;
    cout << "\nNow enter the initial guesses (x0, x1), tolerance (epsilon), and maximum iterations: ";
    cin >> x0 >> x1 >> epsilon >> maxIterations;

    int i = 0;
    double x2;

    cout<<"\n";
    cout << left << setw(10) << "Iter" << setw(15) << "x0" << setw(15) << "x1" << setw(15) << "x2" << setw(20) << "f(x2)" << endl<<endl;
    cout << "-------------------------------------------------------------" << endl;
    cout<<"\n";

    while (fabs(x1 - x0) >= epsilon && i < maxIterations) {
        // Preventing division by zero
        if (fabs(f(x1) - f(x0)) < 1e-7) {
            cout << "Division by zero detected, method failure.\n";
            return;
        }

        // Using secant method formula
        x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - f(x0)));

        i++;

        cout << left << setw(10) << i << setw(15) << x0 << setw(15) << x1 << setw(15) << x2 << setw(20) << f(x2) << endl<<endl;

        x0 = x1;
        x1 = x2;
    }

    // Final output: Check if converged or max iterations reached
    if (fabs(x1 - x0) < epsilon) {
        cout << "\nThe method converged after " << i << " iterations.\n";
        cout << "\nThe root is approximately: " << x2 << " with f(x2) = " << f(x2) << "\n";
    } else {
        cout << "\nThe method did not converge after " << maxIterations << " iterations.\n";
        cout << "\nThe last approximation is x2 = " << x2 << " with f(x2) = " << f(x2) << "\n";
    }
}




void newton_Raphson_Method() {
    cout << "\nNewton-Raphson Method selected.\n";

    input_coefficients();

    double x0, epsilon;
    cout << "\nNow enter the initial guess (x0) and tolerance (epsilon): ";
    cin >> x0 >> epsilon;

    double h = f(x0) / f_prime(x0);
    int i = 0, maxIterations = 1000;

    cout<<"\n";
    cout << left << setw(10) << "Iter" << setw(15) << "x0" << setw(20) << "h" << setw(15) << "|h|" << endl<<endl;
    cout << "---------------------------------------------------" << endl;
    cout<<"\n";

    while (fabs(h) >= epsilon && i < maxIterations) {
        h = f(x0) / f_prime(x0);  // updating the Newton-Raphson formula
        x0 = x0 - h;

        i++;

        cout << i << "\t" << x0 << "\t" << h << "\t" << fabs(h) << endl;
    }

    cout << "\nThe root is: " << x0 << endl;
}


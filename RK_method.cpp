#include<bits/stdc++.h>
using namespace std;

double f1(double x, double y) {
    return x - y;  // dy/dx = x - y
}

double f2(double x, double y) {
    return sin(x);  // dy/dx = sin(x)
}

double f3(double x, double y) {
    return cos(x);  // dy/dx = cos(x)
}

void runge_Kutta_Method() {
    double (*f)(double, double);
    int eq_choice;

    //To solve different equation using RK method
    cout << "\nSelect the equation for dy/dx = f(x, y):\n";
    cout << "1. f(x, y) = x - y\n";
    cout << "2. f(x, y) = sin(x)\n";
    cout << "3. f(x, y) = cos(x)\n";
    cout << "Enter your choice: ";
    cin >> eq_choice;

    switch (eq_choice) {
        case 1: f = f1; break;
        case 2: f = f2; break;
        case 3: f = f3; break;
        default:
            cout << "Invalid choice. Using default f(x, y) = x - y.\n";
            f = f1;
    }

    double x0, y0, start, endi, h;

    // Getting user input for range, initial conditions, and step size
    cout << "\nEnter the initial values for x0 and y0: ";
    cin >> x0 >> y0;
    cout << "Enter the range for x (start and end): ";
    cin >> start >> endi;
    cout << "Enter the step size (h): ";
    cin >> h;

    double y_final = y0;

    cout << "\nStarting the Runge-Kutta method...\n";
    cout << left << setw(10) << "x" << setw(20) << "y (approximation)" << endl;
    cout << "-------------------------------------------\n";
    cout<<"\n";

    for (double i = start; i <= endi; i += h) {

        cout << left << setw(10) << x0 << setw(20) << y_final << endl;

        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h / 2.0, y0 + k1 / 2.0);
        double k3 = h * f(x0 + h / 2.0, y0 + k2 / 2.0);
        double k4 = h * f(x0 + h, y0 + k3);

        y_final = y0 + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        x0 += h;
        y0 = y_final;


    }

    cout << "Final Approximation will be : x = " << endi << ", y = " << setw(10) << y_final << endl;
}


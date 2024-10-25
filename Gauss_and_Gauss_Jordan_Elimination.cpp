#include<bits/stdc++.h>
using namespace std;

void print_Matrix(vector<vector<double> >A)
{
    int n = A.size();
    int m = A[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << setw(10) << A[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;

}

void partial_Pivoting(vector<vector<double> >& A,int n,int col)
{
    int maxRow = col;
    for (int i = col + 1; i < n; i++) {
        if (fabs(A[i][col]) > fabs(A[maxRow][col])) {
            maxRow = i;
        }
    }
    if (maxRow != col) {
        swap(A[maxRow], A[col]);
    }
}

vector<vector<double> > gauss_Elimination() {
    //cout << "Gauss Elimination Method selected.\n";

    int num;
    cout<<"\nEnter the num of variablees in the equation :"<<endl;
    cin>>num;
    vector<vector<double> > A(num,vector<double>(num+1));

    cout<<"\nNow enter the elements row wise"<<endl;

    for(int i=0;i<num;i++){
        for(int j=0;j<num+1;j++){
            cin>>A[i][j];
        }
    }

    int n = A.size();

    for (int i = 0; i < n; i++) {
        // Applying partial pivoting
        partial_Pivoting(A, n, i);

        // Normalizing the pivot row
        double pivot = A[i][i];
        for (int j = 0; j < n + 1; j++) {
            A[i][j] /= pivot;
        }

        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i];
            for (int k = 0; k < n + 1; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }
    cout << "\nMatrix after Gauss Elimination (Upper Triangular Form):" << endl;

    print_Matrix(A);
    return A;

}

void gauss_Jordan_Elimination() {

    cout << "\nGauss Jordan Elimination Method selected.\n";

    vector<vector<double> > A1 = gauss_Elimination();

    int n = A1.size();

    for (int i = n - 1; i >= 0; i--) {

        for (int j = i - 1; j >= 0; j--) {
            double factor = A1[j][i];
            for (int k = 0; k < n + 1; k++) {
                A1[j][k] -= factor * A1[i][k];
            }
        }
    }
    cout << "\nFinal matrix after Jordan Elimination :" << endl;
    print_Matrix(A1);
    cout<<"\n";

}

#include<bits/stdc++.h>
using namespace std;

bool lessThan10ToTheNeg6(double num1, double num2) {
    return abs(num1-num2) <= 0.000001;
}

vector<double> findSequence(double A, double B, int n, int X1, int Xn) {
    vector<double> X(n);

    X[0] = X1;
    X[1] = (X1 + Xn) / 2.0;
    for (int i = 2; i < n; i++) {
        X[i] = A * X[i-1] + B * X[i-2];
    }

    double diff = (Xn - X[n-1]) / ((n-1) * max(1.0, max(abs((double)Xn), abs(X[n-1]))));

    while (!lessThan10ToTheNeg6(X[n-1], Xn)) {
        X[1] += diff;
        for (int i = 2; i < n; i++) {
            X[i] = A * X[i-1] + B * X[i-2];
        }
    }

    return X;
}

int main() {
    double A, B;
    int n, X1, Xn;

    cin >> A >> B;
    cin >> n >> X1 >> Xn;
    vector<double> X = findSequence(A, B, n, X1, Xn);

    cout << fixed << setprecision(10);
    for (double x: X) {
        cout << x << endl;
    }

    return 0;
}

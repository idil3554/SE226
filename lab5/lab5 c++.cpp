#include <iostream>
#include <cmath>

using namespace std;
double calculate_gn_recursive(int n, double r) {
    if (n == 0) {
        return 1.0;
    }
    return pow(r,n) + calculate_gn_recursive(n-1,r);
}

int main() {
    int n;
    double r;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;

    double result = calculate_gn_recursive(n,r);
    cout << "Reuslt is: " << result << endl;
    return 0;
}
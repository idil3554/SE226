#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number between 10 and 100";
    cin >> n;

    while (n < 10 || n > 100) {
        cout << "Invalid input";
        cin >> n;
    }
    int fizz = 0;
    int buzz = 0;
    int fizzBuzz = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0) {
            cout << "(" << i << "is skipped)" << endl;
            continue;
        }
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz" << endl;
            fizzBuzz++;
        }
        else if (i % 3 == 0) {
            cout << "Fizz" << endl;
            fizz++;
        }
        else if (i % 5 == 0) {
            cout << "Buzz" << endl;
            buzz++;
        }
        else {
            cout << i << endl;
        }
    }
    cout <<"--- Summary ---" << endl;
    cout << "Fizz count" << fizz << endl;
    cout << "Buzz count" << buzz << endl;
    cout << "FizzBuzz count" << fizzBuzz << endl;

    return 0;

}
#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Enter a positive integer greater than 9";
   cin >> n;

   int steps = 0;
   cout << n;

   while (n >= 10) {
      int temp = n;
      int digit_sum = 0;
      while (temp > 0) {
         digit_sum += temp % 10;
         temp /= 10;
      }

      n = digit_sum;
      steps++;

      cout << "->" << n;
   }
   cout << "\nFinal Value" <<n<<endl;
   cout << "total steps:" << steps << endl;

   return 0;
}


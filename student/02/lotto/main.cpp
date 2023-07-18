#include <iostream>
using namespace std;


unsigned long long kertoma(int luku) {

    unsigned long long factorial = 1;

   if(luku == 0) {
       return 0;
   }
   for(int i = 1; i <= luku; i++) {
      factorial *= i;
   }
   return factorial;
}

unsigned long long lotto(int n, int p) {

    unsigned long long rivien_maara = kertoma(n) / (kertoma(n-p) * kertoma(p));
    return rivien_maara;
}

int main() {

    int n, p;

    cout << "Enter the total number of lottery balls: ";
    cin >> n;

    cout << "Enter the number of drawn balls: ";
    cin >> p;

    if(n < 0) {
        cout << "The number of balls must be a positive number." << endl;
    }
    else if(p > n) {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
    }
    else if(p == n) {
        cout << "The probability of guessing all " << p << " balls correctly is "
             << "1/" << 1 << endl;
    }
    else {
        cout << "The probability of guessing all " << p << " balls correctly is "
             << "1/" << lotto(n, p) << endl;
    }

}

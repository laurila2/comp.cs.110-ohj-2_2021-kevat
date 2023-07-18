#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main() {

    int number;

    cout << "Enter a positive number: ";
    cin >> number;

    int a = sqrt(number);
    int b = a;

    if(number > 0) {
        while(a * b != number) {
            if((a * b) > number) {
                a -= 1;
            }
            else if((a * b) < number) {
                b += 1;
            }
        }
        cout << number << " = " << a << " * " << b << endl;
    }
    else {
            cout << "Only positive numbers accepted" << endl;
        }

    return 0;
}

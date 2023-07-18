#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int number;

    cout << "Enter a number: ";
    cin >> number;

    int kuutio;

    kuutio = pow(number, 3);

    if(kuutio >= 0) {
        cout << "The cube of " << number << " is " << kuutio << "." << endl;
    }
    else {
        cout << "Error! The cube of " << number << " is not " << kuutio << "." << endl;
    }



    return 0;
}

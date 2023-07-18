#include <iostream>
#include <string>

using namespace std;


int main()
{
    int numbers = 0;
    cout << "How many numbers would you like to have? ";
    cin >> numbers;

    for (int i = 1; i <= numbers; ++i) {
        if ((i % 7) == 0 and (i % 3 == 0)) {
            cout << "zip boing" << endl;
        }
        else if (i % 3 == 0) {
            cout << "zip" << endl;
        }
        else if (i % 7 == 0) {
            cout << "boing" << endl;
        }
        else {
            cout << i << endl;
        }
    }
}

#include <iostream>
#include <string>
#include <cctype>
#include <bitset>

using namespace std;

string encrypt(string teksti, string avain) {

    string salattu_viesti;

    for (char& kirjain : teksti) {
        int ascii_arvo = static_cast< int >(kirjain);
        unsigned int indeksi = ascii_arvo - static_cast<unsigned int>('a');
        char salattu_kirjain = avain.at(indeksi);
        salattu_viesti += salattu_kirjain;
        }
    return salattu_viesti;
}

bool has_alphabet(std::string const &s)
{
    std::bitset<26> alphabet;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z')
            alphabet.set(c - 'A');
        else if (c >= 'a' && c <= 'z')
            alphabet.set(c - 'a');
    }
    return 26 == alphabet.count();
}



int main() {

    string avain;
    string viesti;
    bool isoja = false;

    cout << "Enter the encryption key: ";
    cin >> avain;

    int pituus = avain.length();

    for(int i = 0; i < pituus; i++)
    {
        if(isupper(avain[i])) {
            isoja = true;
        }
    }
    if(isoja == true) {
        cout << "Error! The encryption key must contain "
                "only lower case characters." << endl;
        return EXIT_FAILURE;
    }
    if(avain.length() != 26) {
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return EXIT_FAILURE;
    }
    if(has_alphabet(avain)) {
        cout << "Enter the text to be encrypted: ";
        cin >> viesti;
        cout << "Encrypted text: " << encrypt(viesti, avain) << endl;
    }
    else {
        cout << "Error! The encryption key must contain all alphabets a-z." << endl;
        return EXIT_FAILURE;
    }

}


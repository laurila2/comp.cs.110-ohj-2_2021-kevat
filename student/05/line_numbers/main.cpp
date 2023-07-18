#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    // Ask input filename
    std::string filename;
    std::cout << "Input file: ";
    std::cin >> filename;

    std::string line;

    // Ask output filename
    std::string filename_out;
    std::cout << "Output file: ";
    std::cin >> filename_out;

    //Read input file
    std::ifstream file_in;
    file_in.open(filename);
    if (!file_in.is_open())
    {
        std::cout << "Error! The file " << filename << " cannot be opened."
                  << std::endl;
        return EXIT_FAILURE;
    }

    // Write output file
    std::ofstream outfile;
    outfile.open(filename_out);
    int i = 1;
    while (std::getline(file_in, line))
    {
        outfile << i++ << " " << line << std::endl;
    }

    file_in.close();
    outfile.close();

    return 0;
}

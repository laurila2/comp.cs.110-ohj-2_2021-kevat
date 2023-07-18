#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Stringien käsittely apufunktio
std::vector<std::string> split(const std::string &text,
                               char separator,
                               bool ignore_empty = false)
{
    std::vector<std::string> parts;

    std::string::size_type left = 0;
    std::string::size_type right = text.find(separator, left);

    while (right != std::string::npos)
    {
        std::string part = text.substr(left, right - left);

        if (part != "" || !ignore_empty)
        {
            parts.push_back(part);
        }

        left = right + 1;
        right = text.find(separator, left);
    }
    std::string final_part = text.substr(left, std::string::npos);
    parts.push_back(final_part);

    return parts;
}

int main()
{
    // Ask input filename
    std::string filename;
    std::cout << "Input file: ";
    std::cin >> filename;

    // Read input file
    std::ifstream file_in;
    file_in.open(filename);
    if (!file_in.is_open())
    {
        std::cout << "Error! The file " << filename << " cannot be opened."
                  << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file_in, line))
    {
        lines.push_back(line);
    }

    // Process input.
    std::map<std::string, int> scores_by_name;
    for (size_t row_index = 0; row_index < lines.size(); ++row_index)
    {
        line = lines.at(row_index);
        std::vector<std::string> parts = split(line, ':', true);
        std::string nimi = parts[0];
        int pisteet = stoi(parts[1]);

        if (scores_by_name.find(nimi) != scores_by_name.end())
        {
            // Nimi löytyi mapista, lisää pisteitä.
            scores_by_name.at(nimi) += pisteet;
        }
        else
        {
            // Nimeä ei ole mapissa. Luo nimi mappiin ja anna pisteet.
            scores_by_name[nimi] = pisteet;
        }
    }

    // Lopputuloste
    std::cout << "Final scores:" << std::endl;

    std::map<std::string, int>::iterator iter;
    iter = scores_by_name.begin();
    while (iter != scores_by_name.end())
    {
        std::cout << iter->first << ": " << iter->second << std::endl;
        ++iter;
    }
    return EXIT_SUCCESS;
}

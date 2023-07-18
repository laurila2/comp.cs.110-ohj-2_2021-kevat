#include <iostream>

int main()
{
    std::cout << "Input an expression in reverse Polish notation (end with #):"
              << std::endl;

    while (true)
    {
        int taulukko[20] = {0}; // Taulukossa tilaa 80 int:ille
        int index = 0;
        int tulos = 0;

        std::string expression = "";
        std::cout << "EXPR> ";
        getline(std::cin, expression);

        for (char &merkki : expression)
        {
            if (index == 0 && !(merkki >= '0' && merkki <= '9'))
            {
                std::cout << "Error: Expression must start with a number"
                          << std::endl;
                return EXIT_FAILURE;
            }
            else if (merkki >= '0' && merkki <= '9')
            {
                taulukko[index] = (merkki - '0');
                ++index;
            }
            else if (merkki == '+')
            {
                tulos = taulukko[index - 1] + taulukko[index - 2];
                taulukko[index - 2] = tulos;
                --index;
            }
            else if (merkki == '-')
            {
                tulos = taulukko[index - 2] - taulukko[index - 1];
                taulukko[index - 2] = tulos;
                --index;
            }

            else if (merkki == '*')
            {
                tulos = taulukko[index - 1] * taulukko[index - 2];
                taulukko[index - 2] = tulos;
                --index;
            }

            else if (merkki == '/')
            {
                if ((taulukko[index - 2] != 0) && (taulukko[index - 1] != 0))
                {
                    tulos = taulukko[index - 2] / taulukko[index - 1];
                    taulukko[index - 2] = tulos;
                    --index;
                }

                else if (index < 2)
                {
                    std::cout << "Error: Too few operands" << std::endl;
                    return EXIT_FAILURE;
                }

                else
                {
                    std::cout << "Error: Division by zero" << std::endl;
                    return EXIT_FAILURE;
                }
            }

            else if (merkki == '#')
            {
                if (index >= 2)
                {
                    std::cout << "Error: Too few operators" << std::endl;
                    return EXIT_FAILURE;
                }

                else if (index < 1)
                {
                    std::cout << "Error: Too few operands" << std::endl;
                    return EXIT_FAILURE;
                }

                else
                {
                    std::cout << "Correct: " << taulukko[0] << " is the result"
                              << std::endl;
                    break;
                }
            }
            else if (merkki == ' ')
            {
                continue;
            }

            else
            {
                std::cout << "Error: Unknown character" << std::endl;
                return EXIT_FAILURE;
            }
        }

        return EXIT_SUCCESS;
    }
}

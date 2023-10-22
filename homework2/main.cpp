#include <iostream>
#include <algorithm>

int main()
{
    for (;;)
    {
        std::string number;
        std::cin >> number;
        if (number == "0")
            break;

        bool shouldPrint = true;

        // Замена 8 на +7
        if (number[0] == '8')
            number.replace(0, 1, "+7");

        if (!((number[0] == '+') && (number[1] == '7')))
        {
            std::cout << "error" << std::endl;
            continue;
        }

        // Удаление пробелов
        number.erase(std::remove_if(number.begin(), number.end(), ::isspace), number.end());

        int openBrackets{}, closeBrackets{};
        for (char c: number)
        {
            if (c == '(')
            {
                if ((openBrackets == 0) && (closeBrackets == 0))
                    openBrackets++;
                else
                {
                    std::cout << "error" << std::endl;
                    shouldPrint = false;
                    break;
                }
            }
            if (c == ')')
            {
                if ((openBrackets == 1) && (closeBrackets == 0))
                    closeBrackets++;
                else
                {
                    std::cout << "error" << std::endl;
                    shouldPrint = false;
                    break;
                }
            }
        }
        if (!shouldPrint)
            continue;

        if ((openBrackets == 1) && (closeBrackets == 1))
        {
            number.erase(number.find('('), 1);
            number.erase(number.find(')'), 1);
        }

        if ((number[0] == '-') || (number[number.length() - 1] == '-'))
            continue;

        for (int i = 0; i < number.length() - 1; i++)
        {
            if ((number[i] == '-') && (number[i] == number[i + 1]))
            {
                shouldPrint = false;
                break;
            }
        }
        if (!shouldPrint)
            continue;
        // Удаление '-'
        number.erase(std::remove_if( number.begin(),  number.end(), [](char c) {return c == '-';}),  number.end());

        for (int i = 1; i < number.length(); i++)
        {
            if (!isdigit(number[i]))
                shouldPrint = false;
        }
        if (!shouldPrint || (number.length() != 12))
        {
            std::cout << "error" << std::endl;
            continue;
        }

        std::cout << number << std::endl;
    }
    return 0;
}

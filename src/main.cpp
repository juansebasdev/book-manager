#include <iostream>
#include <string>
#include <stdlib.h>
#include "Manager.h"

const std::string Menu = "1. Add Book\n2. Show Books\n3. Get Book\n4. Delete Book\n5. Exit\n";

int main()
{
    Manager manager = Manager();
    int op = 0;

    while (true)
    {
        std::cout << "Welcome to your books manager application!!" << std::endl;
        std::cout << "Select an option please: " << std::endl;
        std::cout << Menu << std::endl;
        std::cout << "Select an option: ";

        std::cin >> op;

        system("clear");

        switch (op)
        {
        case 1:
            std::cout << manager.CreateBook() << std::endl;
            break;

        case 2:
            std::cout << manager.ShowBooks() << std::endl;
            break;

        case 3:
            std::cout << manager.GetBook() << std::endl;
            break;

        case 4:
            std::cout << manager.DeleteBook() << std::endl;
            break;

        case 5:
            std::cout << "See you later!" << std::endl;
            std::cout << "\n";
            exit(0);

        default:
            std::cout << "Invalid Input!!!" << std::endl;
            break;
        }

        std::cout << "\n";
    }
}
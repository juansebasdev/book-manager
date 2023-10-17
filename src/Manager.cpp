#include "Manager.h"

std::string Manager::CreateBook()
{
    std::string title;
    std::string description;

    try
    {
        std::cout << "What's the title of the book?" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, title);
        std::cout << "Add a description for the book" << std::endl;
        std::getline(std::cin, description);

        Book *book = new Book(Book::currentId, title, description);

        store.AddBook(book);

        system("clear");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return "An error ocurred, the book could not be saved";
    }

    return "The book has been added to your book store successfully!";
}

std::string Manager::ShowBooks()
{
    if (store.GetBooks().size() == 0)
        return "There are no books in store";

    nlohmann::json jsonBooks = nlohmann::json::array();
    nlohmann::json j;
    Utils utils = Utils();

    for (auto book : store.GetBooks())
    {
        j = utils.ToJson(*book);
        jsonBooks.push_back(j);
    }

    return jsonBooks.dump();
}

std::string Manager::GetBook()
{
    int id;
    try
    {
        std::cout << "Digit the id of the book you would like to get: ";
        std::cin >> id;
        Book *book = store.GetBook(id);

        if (book != nullptr)
            return PrintBook(book);
        else
            return "The book with id " + std::to_string(id) + " does not exist.";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return "An error ocurred. Please, provide a valid id.";
    }
}

std::string Manager::DeleteBook()
{
    int id;
    char answer;
    try
    {
        std::cout << "Digit the id of the book you would like to remove: ";
        std::cin >> id;

        Book *book = store.GetBook(id);

        std::cout << "Are you sure to delete " << book->GetTitle() << " with id " << book->GetId() << "? (y/n)";
        std::cin >> answer;

        system("clear");

        switch (answer)
        {
        case 'y':
            store.DeleteBook(book->GetId());
            return "The book has been deleted of your book store successfully!";

        default:
            return "You have cancelled the operation";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return "An error ocurred, the book could not be saved";
    }
}

std::string Manager::PrintBook(Book *book)
{
    Utils utils = Utils();

    nlohmann::json j = utils.ToJson(*book);

    return j.dump();
}
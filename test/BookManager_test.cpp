#include <gtest/gtest.h>
#include "Book.h"
#include "BookStore.h"

TEST(BookTest, Create)
{
    std::string title = "Fairytale";
    std::string description = "A great Adventure";

    Book book = Book(Book::currentId, title, description);

    ASSERT_EQ(book.GetTitle(), title);
    ASSERT_EQ(book.GetDescription(), description);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
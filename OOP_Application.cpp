#include <iostream>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;

public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {}

    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author << std::endl;
    }

    // Getters
    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
            std::cout << "----------------------\n";
        }
    }

    // In a real-world application, you might want to add more functionalities like
    // searching for a book, removing a book, etc.
};

int main() {
    // Create some books
    Book book1("The Catcher in the Rye", "J.D. Salinger");
    Book book2("To Kill a Mockingbird", "Harper Lee");
    Book book3("1984", "George Orwell");

    // Create a library and add books
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Display all books in the library
    std::cout << "Library Contents:\n";
    library.displayBooks();

    return 0;
}

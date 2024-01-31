#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    int id;  // Dodane pole identyfikatora

public:
    Book(int id, const string& title, const string& author)
        : id(id), title(title), author(author) {}

    void display() const {
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }

    int getID() const {
        return id;
    }
};

class Library {
private:
    vector<Book> books;
    int nextID;  // Dodane pole do śledzenia kolejnego dostępnego ID

public:
    Library() : nextID(1) {}  // Inicjalizacja początkowego ID

    void addBook(const string& title, const string& author) {
        books.emplace_back(nextID, title, author);
        nextID++;
    }

    void removeBook(int id) {
        auto it = remove_if(books.begin(), books.end(), [id](const Book& book) {
            return book.getID() == id;
        });

        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book with ID " << id << " removed successfully.\n";
        } else {
            cout << "Book with ID " << id << " not found.\n";
        }
    }

    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
            cout << "----------------------\n";
        }
    }

    void sortBooks() {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getID() < b.getID();
        });
    }

    void searchBook(int id) const {
        auto it = find_if(books.begin(), books.end(), [id](const Book& book) {
            return book.getID() == id;
        });

        if (it != books.end()) {
            cout << "Book found:\n";
            it->display();
        } else {
            cout << "Book not found.\n";
        }
    }
};

int main() {
    Library library;

    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    cout << "Library Contents (unsorted):\n";
    library.displayBooks();

    // Dodane sortowanie i ponowne wyświetlanie
    library.sortBooks();
    cout << "\nLibrary Contents (sorted by ID):\n";
    library.displayBooks();

    // Dodane wyszukiwanie książki po ID
    cout << "\nSearch for a book by ID:\n";
    library.searchBook(2);

    // Dodane usuwanie książki po ID
    cout << "\nRemoving book by ID:\n";
    library.removeBook(1);

    // Wyświetlanie zaktualizowanej biblioteki
    cout << "\nLibrary Contents after removal:\n";
    library.displayBooks();

    return 0;
}

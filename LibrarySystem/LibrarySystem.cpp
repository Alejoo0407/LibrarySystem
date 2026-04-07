// LibrarySystem.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

// ===== CLASS =====
class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    // Set book details
    void setBookDetails(string t, string a, string i, bool available) {
        title = t;
        author = a;
        ISBN = i;
        isAvailable = available;
    }

    // Display book details
    void displayBookDetails() {
        cout << "\nTitle: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }

    // Borrow book
    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "✅ Book borrowed successfully!\n";
        }
        else {
            cout << "❌ Error: Book already borrowed.\n";
        }
    }

    // Return book
    void returnBook() {
        isAvailable = true;
        cout << "✅ Book returned successfully!\n";
    }

    // Get ISBN
    string getISBN() {
        return ISBN;
    }
};

// ===== MAIN PROGRAM =====
int main() {
    Book books[5];

    // Initialize books
    books[0].setBookDetails("Book A", "Author A", "101", true);
    books[1].setBookDetails("Book B", "Author B", "102", true);
    books[2].setBookDetails("Book C", "Author C", "103", true);
    books[3].setBookDetails("Book D", "Author D", "104", true);
    books[4].setBookDetails("Book E", "Author E", "105", true);

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program ended.\n";
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                books[i].displayBookDetails();
                books[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "❌ Book not found.\n";
        }
    }

    return 0;
}
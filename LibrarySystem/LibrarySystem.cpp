#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    string dateAdd;

public:
    void setBookDetails(string t, string a, string i, bool av, string d) {
        title = t;
        author = a;
        ISBN = i;
        isAvailable = av;
        dateAdd = d;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "----------------------" << endl;
    }

    string getISBN() {
        return ISBN;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully!" << endl;
        }
        else {
            cout << "Error: Book is already borrowed." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully!" << endl;
    }

    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    void setShelfNumber(string shelf) {
        shelfNumber = shelf;
    }

    void displayShelfNumber() {
        cout << "Shelf Number: " << shelfNumber << endl;
    }
};

class EBook : public Book {
private:
    string endOfLicenseDate;

public:
    void setEndOfLicenseDate(string date) {
        endOfLicenseDate = date;
    }

    void displayLicenseDate() {
        cout << "End of License Date: " << endOfLicenseDate << endl;
    }
};

int main() {
    Book books[5];

    books[0].setBookDetails("C++ Basics", "John Smith", "105", true, "2024");
    books[1].setBookDetails("Algorithms", "Jane Doe", "102", true, "2023");
    books[2].setBookDetails("Data Structures", "Mike Lee", "103", false, "2022");
    books[3].setBookDetails("Networks", "Anna Kim", "101", true, "2021");
    books[4].setBookDetails("Security", "David Park", "104", true, "2020");

    Book::sortBookData(books, 5);

    cout << "Library books sorted by ISBN:" << endl;
    cout << "----------------------" << endl;

    for (int i = 0; i < 5; i++) {
        books[i].displayBookDetails();
    }

    string input;

    while (true) {
        cout << "\nEnter ISBN to borrow (0 to exit): ";
        cin >> input;

        if (input == "0") {
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == input) {
                books[i].borrowBook();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found." << endl;
        }
    }
    HardcopyBook hardcopy;
    hardcopy.setBookDetails("Physical C++ Book", "Laura White", "201", true, "2024");
    hardcopy.setShelfNumber("A12");

    EBook ebook;
    ebook.setBookDetails("Digital Algorithms", "Mark Green", "301", true, "2024");
    ebook.setEndOfLicenseDate("2026");

    cout << "\nPhase 2 Book Types:" << endl;
    hardcopy.displayBookDetails();
    hardcopy.displayShelfNumber();

    ebook.displayBookDetails();
    ebook.displayLicenseDate();

    cout << "Program ended." << endl;

    return 0;
}
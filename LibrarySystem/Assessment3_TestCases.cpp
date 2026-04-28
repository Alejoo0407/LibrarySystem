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

void displayArray(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
    }
}

int main() {
    cout << "TEST 1: Correct Book Initialization" << endl;
    Book correctBooks[3];
    correctBooks[0].setBookDetails("C++ Basics", "John Smith", "101", true, "2024");
    correctBooks[1].setBookDetails("Algorithms", "Jane Doe", "205", true, "2023");
    correctBooks[2].setBookDetails("Data Structures", "Mike Lee", "150", false, "2022");
    displayArray(correctBooks, 3);

    cout << "\nTEST 2: Incorrect Book Initialization" << endl;
    Book incorrectBooks[3];
    incorrectBooks[0].setBookDetails("", "", "abc", true, "wrong");
    incorrectBooks[1].setBookDetails("123", "???", "", false, "");
    incorrectBooks[2].setBookDetails("Test", "Author", "-1", true, "future");
    displayArray(incorrectBooks, 3);

    cout << "\nTEST 3: Ascending Order Array" << endl;
    Book ascendingBooks[3];
    ascendingBooks[0].setBookDetails("Book A", "Author A", "101", true, "2024");
    ascendingBooks[1].setBookDetails("Book B", "Author B", "150", true, "2024");
    ascendingBooks[2].setBookDetails("Book C", "Author C", "205", true, "2024");
    Book::sortBookData(ascendingBooks, 3);
    displayArray(ascendingBooks, 3);

    cout << "\nTEST 4: Descending Order Array" << endl;
    Book descendingBooks[3];
    descendingBooks[0].setBookDetails("Book C", "Author C", "205", true, "2024");
    descendingBooks[1].setBookDetails("Book B", "Author B", "150", true, "2024");
    descendingBooks[2].setBookDetails("Book A", "Author A", "101", true, "2024");
    Book::sortBookData(descendingBooks, 3);
    displayArray(descendingBooks, 3);

    cout << "\nTEST 5: Mixed Order Array" << endl;
    Book mixedBooks[3];
    mixedBooks[0].setBookDetails("Book B", "Author B", "150", true, "2024");
    mixedBooks[1].setBookDetails("Book C", "Author C", "205", true, "2024");
    mixedBooks[2].setBookDetails("Book A", "Author A", "101", true, "2024");
    Book::sortBookData(mixedBooks, 3);
    displayArray(mixedBooks, 3);

    return 0;
}
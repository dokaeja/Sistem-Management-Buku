#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include<conio.h>
#include<string.h>
#include<iomanip>

using namespace std;

struct Book {
    string title;
    string author;
    int price;
    int quantity;

    void report() {
        cout << title << setw(30) << author << setw(30) << price << setw(30) << quantity << endl;
    }
};

struct Bookshop {
    vector<Book> books;
    vector<int> initialQuantity;

    void addBook(Book book) {
        system("cls");
        books.push_back(book);
        initialQuantity.push_back(book.quantity);

    }

    void removeBook(string title) {
        system("cls");
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                books.erase(books.begin() + i);
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void searchBook(string title) {
        system("cls");
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Price: Rp. " << books[i].price << ", Quantity: " << books[i].quantity << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void displayBooks() {
        system("cls");
        cout << "\n\n\t\t\t\tBOOK LIST\n\n";
        cout << "============================================================================================\n";
        cout << setw(20) << left << "Title" << setw(20) << left << "Author" << setw(10) << left << "Price" << setw(10) << left << "Quantity" << endl;
        cout << "============================================================================================\n";
        for (int i = 0; i < books.size(); i++) {
            cout << setw(20) << left << books[i].title << setw(20) << left << books[i].author << setw(10) << left << books[i].price << setw(10) << left << books[i].quantity << endl;
        }
        cout << "============================================================================================\n";
    }

    void updatePrice(string title, int price) {
        system("cls");
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                books[i].price = price;
                cout << "price updated successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void sellBook(string title, int quantity) {
        system("cls");
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                if (books[i].quantity >= quantity) {
                    books[i].quantity -= quantity;
                    cout << "Book sold successfully!" << endl;
                    return;
                }
                else {
                    cout << "Not enough quantity in stock!" << endl;
                    return;
                }
            }
        }
        cout << "Book not found!" << endl;
    }

    void restockBook(string title, int quantity) {
        system("cls");
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                books[i].quantity += quantity;
                cout << "Book restocked successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void calculateRevenue() {
        system("cls");
        int revenue = 0;
        for (int i = 0; i < books.size(); i++) {
            int soldQuantity = initialQuantity[i] - books[i].quantity;

            if (soldQuantity > 0) {
                revenue += books[i].price * soldQuantity;
            }
        }
        cout << "Total revenue: Rp. " << revenue << endl;
    }


    void sortBooksByPrice() {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.price < b.price;
            });
    }
    void sortBooksByQuantity() {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.quantity < b.quantity;
            });
    }
};

int main() {
    Bookshop bookshop;
    int choice;
    string title;
    string author;
    int price;
    int quantity;


    while (true) {
        cout << "Bookshop Management System" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Search book" << endl;
        cout << "4. Display books" << endl;
        cout << "5. Sorting by price" << endl;
        cout << "6. Sorting by quantity " << endl;
        cout << "7. Update price" << endl;
        cout << "8. Sell book" << endl;
        cout << "9. Restock book" << endl;
        cout << "10. Calculate revenue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> quantity;
            bookshop.addBook({ title, author, price, quantity });
            break;
        case 2:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            bookshop.removeBook(title);
            break;
        case 3:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            bookshop.searchBook(title);
            break;
        case 4:
            bookshop.displayBooks();
            break;
        case 5:
            bookshop.sortBooksByPrice();
            cout << "Books sorted by price (lowest to highest):" << endl;
            bookshop.displayBooks();
            break;

        case 6:
            bookshop.sortBooksByQuantity();
            cout << "Books sorted by quantity (lowest to highest):" << endl;
            bookshop.displayBooks();
            break;
        case 7:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter new price: ";
            cin >> quantity;
            bookshop.updatePrice(title, quantity);
            break;
        case 8:
            cout << "Enter title : ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter quantity : ";
            cin >> quantity;
            bookshop.sellBook(title, quantity);
            break;
        case 9:
            cout << "Enter title : ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter quantity : ";
            cin >> quantity;
            bookshop.restockBook(title, quantity);
            break;
        case 10:
            bookshop.calculateRevenue();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
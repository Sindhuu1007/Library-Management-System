#include<bits/stdc++.h>
#include "library.h"
using namespace std;

int main() {
    Library library;
    
    string input;
    while(cin >> input) {
        if (input == "Book") {
            string title, author, isbn;
            int copiesAvailable, totalCopies;

            string nextInput;
            cin >> nextInput;

            // case 2 where default constructor needs to be called
            if (nextInput == "None") {
                Book book;
                library.addBook(book);
            }

            // case 3 where copy constructor needs to be called
            else if (nextInput == "ExistingBook") {
                string exisitingBookIsbn;
                cin >> exisitingBookIsbn;

                vector<Book> books = library.getBooks();
                for (int index = 0; index < books.size(); index++) {
                    if (books[index].getIsbn() == exisitingBookIsbn) {
                        string newIsbn;
                        cin >> newIsbn;
                        Book book (books[index], newIsbn);
                        library.addBook(book);
                        break;
                    }
                }
            }

            // case 1 where parameterized constructor needs to be called
            else {
                title = nextInput;
                cin >> author >> isbn >> copiesAvailable >> totalCopies;
                Book book(title, author, isbn, copiesAvailable, totalCopies);
                library.addBook(book);
            }
        }
        else if (input == "UpdateCopiesCount") {
            string isbn;
            int count;
            cin >> isbn >> count;
            vector<Book> books = library.getBooks();
            for (int index = 0; index < books.size(); index++) {
                if (books[index].getIsbn() == isbn) {
                    books[index].updateCopies(count);
                    library.setBooksOnCountUpdate(books);
                    break;
                }
            }
        }
        else if (input == "Member") {
            string memberId, name;
            int borrowLimit;
            
            string nextInput;
            cin >> nextInput;

            if (nextInput == "NoBorrowLimit") {
                cin >> memberId >> name;
                Member member(memberId, name);
                library.registerMember(member);
            }
            else {
                memberId = nextInput;
                cin >> name >> borrowLimit;
                Member member(memberId, name, borrowLimit);
                library.registerMember(member);
            }
        }
        else if (input == "Borrow") {
            string memberId, isbn;
            cin >> memberId >> isbn;
            library.borrowBook(memberId, isbn);
        }
        else if (input == "Return") {
            string memberId, isbn;
            cin >> memberId >> isbn;
            library.returnBook(memberId, isbn);
        }
        else if (input == "PrintBook") {
            string isbn;
            cin >> isbn;
            vector<Book> books = library.getBooks();
            for (int index = 0; index < books.size(); index++) {
                if (books[index].getIsbn() == isbn) {
                    books[index].printDetails();
                    break;
                }
            }
        }
        else if (input == "PrintMember") {
            string memberId;
            cin >> memberId;
            vector<Member> members = library.getMembers();
            for (int index = 0; index < members.size(); index++) {
                if (members[index].getMemberId() == memberId) {
                    members[index].printDetails();
                    break;
                }
            }
        }
        else if (input == "PrintLibrary")
            library.printLibraryDetails();
    }

    return 0;
}

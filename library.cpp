#include "library.h"
#include <bits/stdc++.h>
        
        // constructor
        Library::Library () {}

        // getter methods
        vector<Book> Library::getBooks () {
            return books;
        }

        vector<Member> Library::getMembers () {
            return members;
        }

        // setter method
        void Library::setBooksOnCountUpdate(vector<Book> updatedBooks) {
            books = updatedBooks;
        }

        // utility methods
        bool Library::addBook (Book book) {
            // check if a book with the same isbn already exists of not
            for (int index = 0; index < books.size(); index++) {
                if (books[index].getIsbn() == book.getIsbn()) {
                    cout << "Invalid request! Book with same isbn already exists" << endl;
                    return false;
                }
            }

            // add the book if it is already not there
            books.push_back(book);
            return true;
        }

        bool Library::registerMember (Member member) {
            // check if a member with the same member id already exists of not
            for (int index = 0; index < members.size(); index++) {
                if (members[index].getMemberId() == member.getMemberId()) {
                    cout << "Invalid request! Member with same id already exists" << endl;
                    return false;
                }
            }

            // register the member if it is already not there
            members.push_back(member);
            return true;
        }

        bool Library::borrowBook (string memberId, string isbn) {
            // borrow the book through the utility method of the Book class
            bool bookBorrowPossible = false;
            int bookIndex;
            for (int index = 0; index < books.size(); index++) {
                if (books[index].getIsbn() == isbn) {
                    bookBorrowPossible = books[index].borrowBook();
                    if (bookBorrowPossible)
                        bookIndex = index;
                    break;
                }
            }

            // if the book is available then allocate it to the member through the utility method of the Member class
            if (bookBorrowPossible) {
                for (int index = 0; index < members.size(); index++) {
                    if (members[index].getMemberId() == memberId) {
                        bookBorrowPossible = members[index].borrowBook(isbn);
                        if (!bookBorrowPossible)
                            books[bookIndex].increaseAvailableCount(1);
                        break;
                    }
                }
            }

            return bookBorrowPossible;
        }

        bool Library::returnBook (string memberId, string isbn) {
            // return the book through the utility method of the Book class
            bool bookReturnPossible = false;
            int bookIndex;
            for (int index = 0; index < books.size(); index++) {
                if (books[index].getIsbn() == isbn) {
                    bookReturnPossible = books[index].returnBook();
                    if (bookReturnPossible)
                        bookIndex = index;
                    break;
                }
            }

            // return the book through the utility method of the Member class
            if (bookReturnPossible) {
                for (int index = 0; index < members.size(); index++) {
                    if (members[index].getMemberId() == memberId) {
                        bookReturnPossible = members[index].returnBook(isbn);
                        if (!bookReturnPossible)
                            books[bookIndex].increaseAvailableCount(-1);
                        break;
                    }
                }
            }

            return bookReturnPossible;
        }

        void Library::printLibraryDetails () {
            // print the details of the books
            for (int index = 0; index < books.size(); index++)
                cout << books[index].title << " " << books[index].author << " " << books[index].getCopiesAvailable() << endl;
            
            // print the details of the members
            for (int index = 0; index < members.size(); index++)
                cout << members[index].getMemberId() << " " << members[index].name << endl;
        }

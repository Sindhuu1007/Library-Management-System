#ifndef BOOK_H
#define BOOK_H

#include <bits/stdc++.h>
using namespace std;

class Book{
    public:
        string title;
        string author;

        Book();
        Book(string inTitle,string inAuthor,string inIsbn,int copiesAval,int total);
        Book(Book &B,string newIsbn);

        string getIsbn();
        int getCopiesAvailable();
        int getTotalCopies();
        void updateCopiesCount(int count);
        bool borrowBook();
        bool returnBook();
        void printDetails();

    private:
        string isbn;
        int copiesAvailable;
        int totalCopies;

};

#endif

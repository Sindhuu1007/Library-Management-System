#ifndef LIBRARY_H
#define LIBRARY_H

#include<bits/stdc++.h>
using namespace std;

class Library {
    private:
        vector<Book> books;
        vector<Member> members;
    
    public:
        // constructor
        Library ();

        vector<Book> getBooks ();
        vector<Member> getMembers ();
        void setBooksOnCountUpdate(vector<Book> updatedBooks);
        bool addBook (Book book);
        bool registerMember (Member member);
        bool borrowBook (string memberId, string isbn);
        bool returnBook (string memberId, string isbn);
        void printLibraryDetails ();
};

#endif

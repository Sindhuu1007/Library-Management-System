#ifndef MEMBER_H
#define MEMBER_H

#include<bits/stdc++.h>
using namespace std;

class Member{
    public:
        string name;

        Member(string iname,string imemberID,int limit);
        Member(string inName,string inMemberID);
        string getMemberID();
        int getBorrowLimit();
        int getTotalBooks();
        bool borrowBook(string isbn);
        bool returnBook(string isbn);
        void printDetails();
    
    private:
        string memberID;
        int totalBooksBorrowed;
        map<string,int> borrowedBooks;
        int borrowLimit;
};

#endif

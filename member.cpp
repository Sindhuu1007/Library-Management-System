#include "member.h"
#include<bits/stdc++.h> 

        Member::Member(string iname,string imemberID,int limit){
            name=iname;
            memberID=imemberID;
            borrowLimit=limit;
            totalBooksBorrowed=0;
        }
        Member::Member(string inName,string inMemberID){
            name=inName;
            memberID=inMemberID;
            borrowLimit=3;
            totalBooksBorrowed=0;
        }
        string Member::getMemberID(){return memberID;}
        int Member::getBorrowLimit(){return borrowLimit;}
        int Member::getTotalBooks(){
            int result=0;
            for(auto& b:borrowedBooks){
                result+=b.second;
            }
            return result;
        }
        bool Member::borrowBook(string isbn){
            int totalBorr=0;
            for(auto& book:borrowedBooks){
                totalBorr += book.second;
            }
            if(totalBorr<borrowLimit){
                borrowedBooks[isbn]++;
                return true;
            }else{
                cout<<"Invalid request! Borrow limit exceeded\n";
                return false;
            }
        }
        bool Member::returnBook(string isbn){
            if(borrowedBooks.find(isbn)!=borrowedBooks.end() && borrowedBooks[isbn]>0){
                borrowedBooks[isbn]--;
                return true;
            }
            else{
                cout<<"Invalid request! Book not borrowed\n";
                return false;
            }
        }
        void Member::printDetails(){
            for(auto& book : borrowedBooks){
                if(book.second>0){
                    cout<<memberID<<" "<<name<<" "<<book.first<<" "<<book.second<<"\n";
                }
                
            }
        }

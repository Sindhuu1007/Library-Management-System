#include "book.h"
#include<bits/stdc++.h>
        Book::Book(){
            title="UnknownTitle";
            author="UnknownAuthor";
            isbn="ISBN";
            copiesAvailable=0;
            totalCopies=5;
        }
        Book::Book(string inTitle,string inAuthor,string inIsbn,int copiesAval,int total){
            title=inTitle;
            author=inAuthor;
            isbn=inIsbn;
            copiesAvailable=copiesAval;
            totalCopies=total;
        }
        Book::Book(Book &B,string newIsbn){
            title=B.title;
            author=B.author;
            isbn=newIsbn;
            copiesAvailable=B.getCopiesAvailable();
            totalCopies=B.getTotalCopies();
        }
        string Book::getIsbn(){return isbn;}
        int Book::getCopiesAvailable(){return copiesAvailable;}
        int Book::getTotalCopies(){return totalCopies;}
        void Book::updateCopiesCount(int count){
            int resAval = copiesAvailable+count;
            int resTotal = totalCopies+count;
            if(resAval<0 || resTotal<0){cout<<"Invalid request! Count becomes negative\n";}
            else{
                copiesAvailable=resAval;
                totalCopies=resTotal;
            }
        }   
        bool Book::borrowBook(){
            if((copiesAvailable)<=0){
                cout<<"Invalid request! Copy of book not available\n";
                return false;
            }
            else{
                copiesAvailable--;
                return true;
            }
        }
        bool Book::returnBook(){
            if((copiesAvailable+1)>totalCopies){
                cout<<"Invalid request! Copy of book exceeds total copies\n";
                return false;
            }
            else{
                copiesAvailable++;
                return true;
            }
        }
        void Book::printDetails(){
            cout<<title<<" "<<author<<"\n";
        }

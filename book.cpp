/*Imagine a publishing company which does marketing for book and audio
cassette versions. Create a class publication that stores the title (a string) and
price (type float) of publications. From this class derive two classes: book
which adds a page count (type int) and tape which adds a playing time in
minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter
data and displays the data members. If an exception is caught, replace all the
data member values with zero values*/
#include<iostream>
using namespace std;
class publication
{
protected:
string title;
float price;
public:


publication()
{
    title="";
    price=0.0;
}

publication(string t,float pr)
{
    title=t;
    price=pr;
}

};
class book : public publication
{
    private:
    int pages;
    public:
    book():publication()
    {
        pages=0;
    }
    book(string t,int p,float pr):publication(t,pr)
    {
        if(p>0&&pr>0.0){
            pages=p;
        }else{
            throw(0);
        }
        pages=0;
    }
    void display()
    {
        cout<<title<<"   "<<price<<"   "<<pages<<endl;
    }
};
class tape : public publication
{
    private:
    float mins;
    public:
    tape():publication()
    {
        mins=0.0;
    }
    tape(string t,float p,float pr):publication(t,pr)
    {
        mins=p;
    }
};
int main(){

int pages;
float mins,price;
string title;
cout<<"ENter book detail : t|p|pr "<<endl;
cin>>title>>pages>>price;
string t;
float pr;
cout<<"ENter book detail : t|mi|pr "<<endl;
cin>>t>>mins>>pr;
book b;
try
{
b=book(title ,pages,price);
}
catch(...)
{
    b.display();
    b=book("",0,0);
}
b.display();
    return 0;
}

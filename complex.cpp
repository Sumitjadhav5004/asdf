/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/
#include<iostream>
using namespace std;
class  complex{

    private:
    int r,i;
    public:
    complex(){
      r=0;
      i=0;
    }
    complex operator+(complex &c)
{
   complex temp;
   temp.r= r+ c.r;
   temp.i = i + c.i;
   return temp;
}
complex operator*(complex &c)
{
 complex temp;
   temp.r= (r*c.r) - (i*c.i);
   temp.i = (i*c.i) + (r*c.r);
   return temp;   
}
friend istream & operator>>(istream &in,complex &c);
friend ostream & operator<<(ostream &out,complex &c);

};
 istream & operator>>(istream &in,complex &c)
{

cout<<"Enter the real and imaginary part : "<<endl;
in>>c.r>>c.i;

}
ostream & operator<<(ostream &out,complex &c)
{
   out<<" the real and imaginary part : "<<endl;
cout<<c.r<<"   "<<c.i <<"i"<<endl;
}

int main(){

complex c1,c2;
cin>>c1;
cin>>c2;
complex c3 = c1+ c2;
complex c4 = c1*c2;
cout<<c3;
cout<<c4;


    return 0;
}

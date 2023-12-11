/*Write a C++ program that creates an output file, writes information to it,
closes the file, open it again as an input file and read the information from the
file*/
#include<iostream>
#include<fstream>
using namespace  std;

int main(){

ofstream outfile;
outfile.open("temp.txt",ios::app);
string s;
while(1)
{
    int ch;
cout<<"ENter 1-line 0- exit "<<endl;
cin>>ch;
if(ch==1)
{
    cin.get();
    getline(cin,s);
outfile<<s<<endl;
}
else if(ch==0)
{
cout<<"Exited "<<endl;
break;
}
}
outfile.close();
ifstream infile;
infile.open("temp.txt",ios::in);
cout<<"File contents are : "<<endl;
while(!infile.eof())
{
    getline(infile,s);
    cout<<s<<endl;
}
    return 0;
}

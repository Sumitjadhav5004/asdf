/*Write a program in C++ to use map associative container. The keys will be
the names of states and the values will be the populations of the states. When
the program runs, the user is prompted to type the name of a state. The
program then looks in the map, using the state name as an index and returns
the population of the state*/

#include<iostream>
#include<map>
using namespace std;
int main()
{
map<string,int>state;

state.insert(pair<string,int>("maharashtra",22312));
state.insert(pair<string,int>("goa",4212));
state.insert(pair<string,int>("karnataka",23234212));
state.insert(pair<string,int>("rajasthan",9812));
state.insert(pair<string,int>("punjab",99212));
state.insert(pair<string,int>("delhi",34212));
state.insert(pair<string,int>("asam",3412));
string search;
cout<<"Enter the state to be searched : "<<endl;
cin>>search;
map<string,int>::iterator i;
int f=0;
for(i=state.begin();i!=state.end();i++)
{
    if(search==i->first)
    {
        f++;
        cout<< "The population of"<<i->first<<" = "<<i->second<<endl; 
    }
}

if (f==0)
  cout<<"State not found "<<endl;
    return 0;
}

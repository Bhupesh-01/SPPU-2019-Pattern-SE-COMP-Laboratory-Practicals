/*
C7 : Problem Statement: Write a program in C++ to use map associative container. The keys will be the names of states, and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index, and returns the population of the state.
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
map<string, int> state;
state.insert(pair<string, int>("Maharashtra", 900909));
state.insert(pair<string, int>("Goa", 234909));
state.insert(pair<string, int>("Karnataka", 134509));
state.insert(pair<string, int>("Jammu", 9090909)); 
state.insert(pair<string, int>("Haryana", 8797709));
state.insert(pair<string, int>("Himachal", 5670909));
state.insert(pair<string, int>("Odisha", 6780909)); 

string search;
cout<<"Enter the State to be searched: "<<endl;
cin>>search;
map<string, int>::iterator i;
int f=0;
for(i=state.begin(); i!=state.end();i++)
{
   if (search==i->first)
   {
     f++;
      cout<<"The Population of "<<i->first<<" = "<<i->second<<endl;
    }
}
if(f==0)
 cout<<"State not found."<<endl;
return 0;
}
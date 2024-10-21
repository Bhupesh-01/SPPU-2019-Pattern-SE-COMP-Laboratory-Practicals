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
cout<<"Enter the State to be searched: "<<endl; cin>>search;
map<string, int>::iterator i;
int f=0;
for(i=state.begin(); i!=state.end();i++)
{
if(search==i->first)
{
f++;
cout<<"The Population of "<<i->first<<" = "<<i->second<<endl;
}
}
if(f==0)
cout<<"State not found."<<endl;
return 0;
}
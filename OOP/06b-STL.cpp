/*
C6b : Write C++ program using STL for sorting and searching user defined records such as 
Item records (Item code, name, cost, quantity etc) using vector container.
*/
#include <iostream>
#include <vector> 
using namespace std;
class items
{
private:
  string name;
  int cost;
  int quantity;
public:
  int code;
  items(int a, string b, int c,int d)
  {
   code = a;
   name = b;
   cost = c;
   quantity = d;
  }
void display()
{
cout<<"Item Code = "<<code<<" | Name = "<<name<<" | Cost = "<<cost;
cout<<" | Quantity = "<<quantity<<endl;
}
};

int main()
{
    vector<items> v1;
    int choice;
    while(1)
   {
      cout<<"Enter 1-Inserting Item | 2-Print all items | 3-Search an item | 4- Sort | 0-Exit"<<endl;
      cin>>choice;
     if(choice==1)
     {
    string name;
    int cost, quantity, code;
    cout<<"Enter Item Details: Code Name | Cost Qty: "<<endl;
    cin>>code>>name>>cost>>quantity;
    items item(code, name, cost, quantity);
    v1.push_back(item);
     }
    else if (choice==2)
   {
    for(int i=0;i<v1.size();i++)
    {
     v1[i].display();
    }
   }
   else if(choice==3)
   {
    int c;
    cout<<"Enter the item code to be searched:"<<endl;
    cin>>c;
    int flag =0;
    for(int i=0;i<v1.size();i++)
   {
   if(v1[i].code==c)
   {
   v1[i].display();
   flag = 1;
   break;
   }
  }
   if(flag==0)
  cout<<"Item not found."<<endl;
  }
  else if (choice==4)
 {
 }
 else if(choice==0)
 {cout<<"Exited."<<endl;
 }

    return 0;
 }
}
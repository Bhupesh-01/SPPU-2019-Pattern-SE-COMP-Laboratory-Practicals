/*
B4: Write a C++ program that creates an output file, writes information to it, 
closes the file and open it again as an input file and read the information from the file.
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()

{

    ofstream outfile;
    outfile.open("temp.txt",ios::app);
    string s;
   while(1)
  {
    cout<<"Enter choice :\n 1-Line\n 0-EXIT"<<endl;
    int ch;
    cin>>ch;
    if(ch==1) 
    {
        cin.get();
        getline(cin, s);
        outfile<< s <<endl;
        }
       else if(ch==0) {
        cout<<"EXITED"<<endl;
        break;
}
}

outfile.close();
ifstream infile;
infile.open("temp.txt",ios::in);
cout<<"FILE CONTENTS:"<<endl;
while(!infile.eof())
{
    getline(infile, s);
    cout<<s<<endl;
}

return 0;
}
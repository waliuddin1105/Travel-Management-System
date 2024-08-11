#include<iostream>
#include<math.h>
#include<fstream>
#include<windows.h>
#include<string.h>
#include<stdexcept>
using namespace std;

class menu;
void menuConstructor();
template<typename T>
class manageMenu{
    T adminName;
    public:
    manageMenu(){
    	system("color 09");
        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tEnter your name to progress further:";
        cin>>adminName;
        system("cls");
        menuConstructor();
    }
    ~manageMenu(){};
};
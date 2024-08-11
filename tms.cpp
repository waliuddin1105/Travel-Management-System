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

class customer{
    protected:
    string name, gender, adress;
    int age, mobile,retMenu;
    static int cusId;
    char all[999];

    public:

    customer(){}

    void getDetails()
    {
    	system("cls");
        ofstream out("Old_customers.txt",ios::app);// append mode 
        { 
            cout<<"\n\n\nEnter customer Id:";
            cin>>cusId;
            cout<<"Enter customer name:";
            cin>>name;
            cout<<"Enter age:";
            cin>>age;
            cout<<"Enter mobile number:";
            cin>>mobile;
            cout<<"Enter Adress:";
            cin>>adress;
            cout<<"Enter gender f/m:";
            cin>>gender;
            try{
                if(gender!="f" && gender!="m")
                throw invalid_argument("Invalid input, Gender can only be male or female");
            }
             catch(const invalid_argument &i)
            {
                cout<<i.what()<<endl<<"Please enter f/m only:";
                cin>>gender;
            }          
        }
        out<<"\n\nCustomer ID:"<<cusId<<endl<<"Customer Name:"<<name<<endl<<"Age:"<<age<<endl<<"Mobile number:"<<mobile<<endl<<"Adress:"<<adress<<endl<<"Gender:"<<gender<<endl;
    }
     friend class menu;
};
int customer::cusId=0;

template<typename i=int,typename d=double,typename s=string>
class cabs{
    protected:
    i choice,kilometers;
    d cabCost,lastCabCost;
    s retMenu;
    public:
    cabs(){}
    void cabDetails()
	{
        cout<<"---------------Metro Cabs---------------\n"<<endl<<endl;
        cout<<"1. Rent a Standard Cab- Rs.30 per KM"<<endl;
        cout<<"2. Rent a Luxury Cab- Rs.50 per KM"<<endl;

        cout<<"\nTo calculate the total cost of your journey!"<<endl<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"Enter which type of cab you wanna use:";
        cin>>choice;
        cout<<"How many kilo meters you wanna travel:";
        cin>>kilometers;
        i hirecab;

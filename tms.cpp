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
if(choice==1)
        {
            cabCost=kilometers*30;
            cout<<"\nYour tour will cost "<<cabCost<<" rupees for a standard cab"<<endl<<endl;
            cout<<"Press 1 to hire this cab or "<<endl;
            cout<<"Press 2 to select another cab: ";
            cin>>hirecab;
            
             try{
                if(hirecab!=1 && hirecab!=2)
                {
                    string g="Invalid input please enter choice 1 or 2 only!";
                throw g;
                }
                
            }
            catch(s g)
                {
                    cout<<g<<endl;
                    cin>>hirecab;
            }
            if(hirecab==1){
                lastCabCost=cabCost;
                cout<<"\nYou have succesfully hired the standard cab!"<<endl<<"Go to the main menu to receive your receipt"<<endl;
            }
            else if(hirecab==2)
            {
            	 system("CLS");
            	cabDetails();
			}   
        }

        else if(choice==2)
        {
            cabCost=50*kilometers;
             cout<<"\nYour tour will cost "<<cabCost<<" rupees for a luxury cab"<<endl<<endl;
            cout<<"Press 1 to hire this cab or "<<endl;
            cout<<"Press 2 to select another cab: ";
            cin>>hirecab;
            try{
                if(hirecab!=1 && hirecab!=2)
                {
                    s g="Invalid input please enter choice 1 or 2 only!";
                throw g;
                }
                
            }
            catch(s g)
                {
                    cout<<g<<endl;
                    cin>>hirecab;
            }
            if(hirecab==1){
                lastCabCost=cabCost;
                cout<<"You have succesfully hired the luxury cab!"<<endl<<"Go to the main menu to recieve your receipt"<<endl;
            }
            else if(hirecab==2)
            {
            	system("CLS");
            	cabDetails();
			}
			lastCabCost = cabCost;
            
        }
        

        cout<<"\nPress any key to return to the main menu:";
        getline(cin,retMenu);
        cin.ignore();
        if(retMenu=="a")
        {
        	system("cls");
        	menuConstructor();
		}
        else
        {
        	system("cls");
        	menuConstructor();
		}
    }
    friend class menu;
     friend ostream &operator<<(ostream &umer_wali, const cabs &cab)
    {
        umer_wali << "Cab Choice: " << (cab.cabChoice == 1 ? "Standard Cab" : "Luxury Cab") << "\nKilometers: " << cab.kilometers << "\nCost: " << cab.cabCost << endl;
        return umer_wali;
    }
};

class booking{
    protected:
    int hotelChoice,pack;string retMenu;
    static double hotelCost;
    public:
    booking(){}
    void hotels(){
        string hotel[3]={"Avari Towers","Pearl Continental","Beach Luxury Hotel"};
        for(int i=0;i<3;i++)
        {
            cout<<i+1<<". "<<hotel[i]<<endl;
        }
    cout<<"\nSelect which hotel do you wanna book or check details of:"<<endl<<"Or press any other key to go back to the main menu"<<endl;
    cin>>hotelChoice;
system("CLS");
        if(hotelChoice==1)
        {
            cout<<"\n\t\t\t\tWELCOME TO AVARI TOWERS!"<<endl<<"The highest rated 5 star hotel in Karachi!\nEnjoy the food, the gym, the pool, the garden, luxury suites and much more with Avari Towers"<<endl;
            cout<<"\nPackages offered by Avari Towers:"<<endl<<endl;
            cout<<"1.Standard Pack"<<endl;
            cout<<"All the basic facilities you need"<<endl<<"Price:Rs 50,000.00 per night"<<endl<<endl;
            cout<<"2.Premium Pack"<<endl;
            cout<<"Enjoy the Premium lifestyle!"<<endl<<"Price:Rs 100,000.00 per night"<<endl<< endl;
            cout<<"3.Luxury Pack"<<endl;
            cout<<"Enjoy the Luxury at Avari Towers:"<<endl<<"Price:Rs 160,000.00 per night" <<endl<<endl;
            cout<<"\nEnter which pack you want to avail\nOr press any other key to go back:"<<endl<<endl;
            cin>>pack;


            if(pack==1){
                hotelCost=50000.00;
                cout<<"\nYou have succesfully availed the Standard package at the Avari Towers!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else if(pack==2){
                hotelCost=100000.00;
                cout<<"\nYou have succesfully availed the Premium package at the Avari Towers!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else if(pack==3)
            {
                hotelCost=160000.00;
                cout<<"\nYou have succesfully availed the Luxury package at the Avari Towers!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else
            {
            	system("CLS");
            	hotels();
			}
           
			cout<<"\nPress any key to return to the main menu:";
	        getline(cin,retMenu);
	        cin.ignore();
	        if(retMenu=="a")
	        {
	        	system("cls");
	        	menuConstructor();
			}
	        else
	        {
	        	system("cls");
	        	menuConstructor();
			}
        }

        else if(hotelChoice==2)
        {
            cout<<"\n\t\t\t\tWELCOME TO PEARL CONTINENTAL!"<<endl<<"The HIGHEST rated Luxury and event hotel in Karachi!\nEnjoy the ambiance, the feel, the restaurants, the pools , fitness centers, Family rooms and much more with Pearl Continental"<<endl;
            cout<<"\nPackages offered by Pearl Continental:"<<endl<<endl;
            cout<<"1.Vacation Pack"<<endl;
            cout<<"Get the full vacation experience"<<endl<<"Price:Rs 40,000.00 per night" <<endl<<endl;
            cout<<"2.Famly Pack"<<endl;
            cout<<"The total family package"<<endl<<"Price:Rs 60,000.00 per night"<<endl<<endl;
            cout<<"3.Event Pack"<<endl;
            cout<<"The package for the best event experience!"<<endl<<"Price:Rs 140,000.00 per night"<<endl<< endl;
            
            cout<<"\nEnter which pack you want to avail\nOr press any other key to go back:";
            cin>>pack;
            

            if(pack==1){
                hotelCost=40000.00;
                cout<<"\nYou have succesfully availed the Vacation package at Pearl Continental!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else if(pack==2){
                hotelCost=60000.00;
                cout<<"\nYou have succesfully availed the Family package at Pearl Continental!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else if(pack==3)
            {
                hotelCost=140000.00;
                cout<<"\nYou have succesfully availed the Event package at Pearl Continental!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else
            {
            	system("CLS");
            	hotels();
			}
            
            cout<<"\nPress any key to return to the main menu:";
        	getline(cin,retMenu);
        	cin.ignore();
        	if(retMenu=="a")
	        {
	        	system("cls");
	        	menuConstructor();
			}
	        else
	        {
	        	system("cls");
	        	menuConstructor();
			}
    
	    }

         else if(hotelChoice==3) 
        {
            cout<<"\n\t\t\t\tWELCOME TO Beach Luxury Hotel!"<<endl<<"Set near the mangroves at the coast of the Arabian Sea, get ready for an adventure like never before at the Beach Luxury Hotel!"<<endl;
            cout<<"\nPackages offered by Beach Luxury Hotel:"<<endl<<endl;
            cout<<"1.Beach Pack"<<endl;
            cout<<"Book your own hut at the beach and enjoy the wonders"<<endl<<"Price:Rs 55,000.00 per day" <<endl<<endl;
            cout<<"2.Special Pack"<<endl;
            cout<<"Get the full access to all the facilities"<<endl<<"Price:Rs 90,000.00 per day"<<endl<<endl;
            
            cout<<"\nEnter which pack you want to avail\nOr press any other key to go back:";
            cin>>pack;

            if(pack==1){
                hotelCost=55000.00;
                cout<<"\nYou have succesfully availed the Beach package at the Beach Luxury hotel!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else if(pack==2){
                hotelCost=90000.00;
                cout<<"\nYou have succesfully availed the Special package at the Beach Luxury hotel!"<<endl;
                cout<<"You can get your receipt from the main menu:"<<endl;
            }
            else
            {
            	system("cls");
            	hotels();
			}
            cout<<"Press any key to return to the main menu:";
            getline(cin,retMenu);
            cin.ignore();
            system("CLS");
            if(retMenu=="a")
            menuConstructor();
            else
            menuConstructor();
        }
        else
        {
            system("CLS");
            menuConstructor();
        }

    }
friend class menu;
    
    };

int main()
{
    return 0;
}
 
//---------------------------Vaccine Management System project by using c++ programming language--------------------------
//---------------------------------------header file start-----------------------------------------
#include<iostream>
#include<stdio.h>//standard input output
#include<fstream>//open a file for writing or reading 
#include<conio.h>//console input output
#include<string.h>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>//manipulte date and time info
#define num_of_vaccine 200
using namespace std;
int password();//b
void menu();//c
void show();//a
class Vaccine

{
	int age;
	int temperature;
	int bloodPressure;
	char gender;
	char name[100];
	char citizenship[100];
	char profession[100];
	char address[100];
	char mobileNumber[100];
	char vaccine[100];
	int unique_id;
	public:
		void setData();//1
		void addNew();//2
		void showData();//3
		void showList();//4
		void viewVaccine();//5
		void searchData();//6
		void search_by_citizenship();//6.1
    	void search_by_age();//6.2
    	void search_by_profession();//6.3
    	void search_by_gender();//6.4
    	void search_by_vaccine();//6.5
    	void view_all();//6.6
    	void search_by_unique();//6.7
    	void infection();//7
};
//----------------------------------------
void Vaccine::setData()//1
{
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t C-Cure "<<endl<<endl;
    cout<<"\n\t\t\t*****************\n";
    cout<<"\t\t\tENTER THE DETAILS ";
    cout<<"\n\t\t\t*****************\n\n";
    fflush(stdin);//clear or flush the output buffer
        cout<<"\n\t\t Enter your name :-  ";
        gets(name);
        cout<<"\n\t\t Enter your citizenship no :-  ";
        gets(citizenship);
        cout<<"\n\t\t Enter your gender (M|F) :-  ";
        cin>>gender;
        cout<<"\n\t\t Enter your age:- ";
        cin>>age;
        fflush(stdin);
        cout<<"\n\t\t Enter your profession :-  ";
        gets(profession);
        cout<<"\n\t\t Enter your B.P. :-  ";
        cin>>bloodPressure;
        cout<<"\n\t\t Enter your Body temperature:-  ";
        cin>>temperature;
        fflush(stdin);
        cout<<"\n\t\t Enter your permanent address :-  ";
        gets(address);
        cout<<"\n\t\t Enter your Mobile number :- ";
        gets(mobileNumber);
        cout<<"\n\t\t Enter the vaccine injected :- ";
        gets(vaccine);
        cout<<"\n\t\t Create your unique Number (Do not share to anyone) :- ";
        cin>>unique_id;
}
//------------------------------------------------------
void Vaccine::addNew()//2
{
    fstream outin;
    outin.open("vaccinetrial.txt",ios::app|ios::out);
    setData();
    outin.write((char*)this,sizeof(Vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    getch();
    outin.close();
}
//---------------------------------------------
void Vaccine::showData()//3
{
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t*******\n";
    cout<<"\t\t\tDETAILS  ";
    cout<<"\n\t\t\t*******\n\n";
  	cout<<"\t\t Name is: "<<name<<endl;
   	cout<<"\t\t Citizenship number is: "<<citizenship<<endl;
    cout<<"\t\t Your age is "<<age<<endl;
    cout<<"\t\t Profession is : "<<profession<<endl;
    cout<<"\t\t Gender is : "<<gender<<endl;
    cout<<"\t\t Blood pressure is :"<<bloodPressure<<endl;
    cout<<"\t\t Body temperature is : "<<temperature<<endl;
    cout<<"\t\t Address is "<<address<<endl;
    cout<<"\t\t Mobile number is: "<<mobileNumber<<endl;
    cout<<"\n\t\t vaccine injected : "<<vaccine<<endl;
    
    
}
//------------------------------------------
void Vaccine::showList()//4
{
	//setw-(set-width)=specifies the minimum number of character positions a var will consume
    cout<<"\n";
    cout<<setw(15)<<setiosflags(ios::left)<<name;
    cout<<setw(15)<<citizenship;
    cout<<setw(15)<<age;
    cout<<setw(15)<<profession;
    cout<<setw(15)<<bloodPressure;
    cout<<setw(15)<<temperature;
    cout<<setw(15)<<gender;
    cout<<setw(15)<<mobileNumber;
    cout<<setw(15)<<address;
    cout<<setw(15)<<vaccine<<endl;
   
    
}
//-----------------------------------------
void Vaccine ::viewVaccine()//5
{

    
    ifstream ind; //ifstream=Represents  input file stream and is used to read info from files
    int i=0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(Vaccine)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s=num_of_vaccine-i;
       cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t********************************\n";
    cout<<"\t\t\tVACCINE STATISTICS AND USER DATA";
    cout<<"\n\t\t\t********************************\n\n";
    cout<<"\t\t 1. Add more Vaccine       \t\t 2.View available Vaccines \t 3. View all Users Data"<<endl<<endl;
    cout<<"\t\t 4. Search by citizenship   \t\t 5.Search by age \t\t 6.Search by Profession"<<endl<<endl;
    cout<<"\t\t 7. Search by Gender        \t\t 8.Search by Vaccine  \t\t 9.Back "<<endl;
    cout<<endl<<endl<<"Enter the Choice : ";
    cin>>ch;
    int f_var=0;
    fstream file("count.txt",ios::in);//open file for reading
    file>>f_var;
    file.close();
    switch(ch)
    {
    case 1:
        int m;
        cout<<"\t Enter number of vaccines you want to add :"<<endl;
        cin>>m;
        f_var=f_var+m;
        file.open("count.txt",ios::out);
        file.seekg(0);
        file<<f_var;
        cout<<"\t\t Now total number of vaccines are : "<<f_var+s;
         getch();
     //   Sleep(2000);
        file.close();
        system("cls");
        viewVaccine();
        break;
    case 2:
    	file.open("count.txt",ios::in);//open file for writing
        cout<<"\n\nAvailable number of vaccines are : "<<s+f_var;
        getch();
        file.close();
        system("cls");
        viewVaccine();
        break;
    case 3:
		system("cls");
        view_all();
        system("cls");
        viewVaccine();
        break;
    case 4:
        system("cls");
        search_by_citizenship();
        getch();
        system("cls");
        viewVaccine();
        break;
    case 5:
        system("cls");
        search_by_age();
        getch();
        system("cls");
        viewVaccine();
        break;
    case 6:
        system("cls");
        search_by_profession();
        getch();
        system("cls");
        viewVaccine();
        break;
    case 7:
        system("cls");
        search_by_gender();
        getch();
        system("cls");
        viewVaccine();
        break;
    case 8:
        system("cls");
        search_by_vaccine();
        getch();
        system("cls");
        viewVaccine();
        break;
    case 9:
        system("cls");
        menu();
        break;
    default:
        system("cls");
        cout<<"\nEnter valid option "<<endl;
        getch();
        system("cls");
        viewVaccine();
    }
    file.close();
    getch();
}
//-----------------------------------------
void Vaccine::searchData()//6
{
    Vaccine item;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
	
    cout<<"\n\t\t\t**********\n";
    cout<<"\t\t\tUSER LOGIN";
    cout<<"\n\t\t\t**********\n\n";
    cout<<"From which option you want to perform searching "<<endl;
    cout<<"\n\t\t 1. By Unique ID \t\t\t 2. Back to Main Menu "<<endl;
   
    cout<<"\n\n\t\tEnter your choice : ";
    int ch;
    cin>>ch;
    switch(ch)
    {
    /*case 1:
        system("cls");
        search_by_citizenship();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;*/
     case 1:
        system("cls");
        search_by_unique();
        getch();
        break;
   /* case 4:
        system("cls");
        search_by_profession();
        getch();
        break;
    case 5:
        system("cls");
        search_by_gender();
        getch();
        break;
    case 6:
        system("cls");
        search_by_vaccine();
        getch();
        break;*/
    case 2:
    	system("cls");
        menu();
        break;
    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        menu();
    }
}
//------------------------------------------------
void Vaccine::search_by_citizenship()//6.1
{
    ifstream in;
	in.open("vaccinetrial.txt");
	int flag,p =0;
    char cs[100];
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t*********************\n";
    cout<<"\t\t\tCitizenship SEARCHING ";
    cout<<"\n\t\t\t*********************\n\n";
    cout<<"Enter your Citizenship number "<<endl;
  	fflush(stdin);
    gets(cs);
    show();
    while(!in.eof())
	{
		//reinterpret_cast=convert pointer of some data type into a pointer of another data type even if the data types before and after conversion are different
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){
        if(strcmp(cs,citizenship)==0)
        {
            showList();
            flag=1;
            p++;
			
        }
		}
    }
    if(flag=0)
    {
    	    cout<<"Citizenship you entered doesnot exist";
	}
	cout<<"\n\n\n\nNO of people vaccinated  by this age : "<<p;
    in.close();
}
//---------------------------------------------------
void Vaccine::search_by_age()//6.2
{
   ifstream in;
   in.open("vaccinetrial.txt");
    int flag =0;
    int a,p=0;
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t*************\n";
    cout<<"\t\t\tAGE SEARCHING ";
    cout<<"\n\t\t\t*************\n\n";
    cout<<"Enter Age by which you want to search "<<endl;
    cin>>a;
    show();
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){
        if(a==this->age)
        {
            showList();
            flag=1;
            p++;
			
            
        }
		}
    }
    if(flag==0)
    {
    cout<<"Age you entered is not found"<<endl;
    }
    cout<<"\n\n\n\nNO of people vaccinated  by this age : "<<p;
    in.close();
}
//----------------------------------------------------------------------------------
void Vaccine::search_by_profession()//6.3
{
    ifstream in;
	in.open("vaccinetrial.txt");
    int flag =0;
    int p=0;
    char pf[100];
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t********************\n";
    cout<<"\t\t\tPROFESSION SEARCHING ";
    cout<<"\n\t\t\t********************\n\n";
    cout<<"Enter Profession by which you want to search:"<<endl;
    fflush(stdin);
    gets(pf);
    show();
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))>0){
        if(strcmp(pf,profession)==0)
        {
            showList();
            flag=1;
            p++;
           // return;
			
            
        }
		}
    }
    if(flag==0)
    {
    cout<<"SORRY!! No people by this Profession is vaccinated."<<endl;
    }
    cout<<"\n\n\n No of people vaccinated by this profession: "<<p<<endl;
    in.close();
}
//-------------------------------------------------------------------
void Vaccine::search_by_gender()//6.4
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    char g;
    int p=0;
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t****************\n";
    cout<<"\t\t\tGENDER SEARCHING ";
    cout<<"\n\t\t\t****************\n\n";
    cout<<"Enter gender by which you want to search "<<endl;
    cin>>g;
    show();
    while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){
        if(g==this->gender)
        {
            showList();
            flag=1;
            p++;
			
        }
		}
    }
    if(flag==0)
    {
    cout<<"SORRY!! No people by this Gender is vaccinated."<<endl;
    }
    cout<<"\n\n\n NO. of people vaccinated by this gender: "<<p<<endl;
    in.close();
}
//-------------------------------------------------------------------------
void Vaccine::search_by_vaccine()//6.5
{
    ifstream in;
	in.open("vaccinetrial.txt");
    int flag =0;
    int p=0;
    char pf[100];
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t********************\n";
    cout<<"\t\t\tPROFESSION SEARCHING ";
    cout<<"\n\t\t\t********************\n\n";
    cout<<"Enter Vaccine to search: ";
    fflush(stdin);
    gets(pf);
    show();
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){
        if(strcmp(pf,vaccine)==0)
        {
            showList();
            flag=1;
            p++;
           // return;
			
            
        }
		}
    }
    if(flag==0)
    {
    cout<<"SORRY!! No people by this vaccine is vaccinated."<<endl;
    }
    cout<<"\n\n\n No of people vaccinated by this vaccine: "<<p<<endl;
    in.close();
}
//---------------------------------------------------------
void Vaccine::search_by_unique()//6.7
{
   ifstream in;
   in.open("vaccinetrial.txt");
    int flag =0;
    int a,p=0;
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    cout<<"\n\t\t\t*******************\n";
    cout<<"\t\t\tUNIQUE ID SEARCHING ";
    cout<<"\n\t\t\t*******************\n\n";
    cout<<"Enter your unique number -  "<<endl;
    cin>>a;
    show();
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){
        if(a==this->unique_id)
        {
            showList();
            flag=1;
            p++;
			
            
        }
		}
    }
    if(flag==0)
    {
    cout<<"Invalid Number"<<endl;
    }
   // cout<<"\n\n\n\nThis unique number do not exist "<<p;
    in.close();
}

void show()//a
{
	cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Name ";
    cout<<setw(15)<<"Aadhar No.";
    cout<<setw(15)<<"Age";
    cout<<setw(15)<<"Profession";
    cout<<setw(15)<<"B.P.";
    cout<<setw(15)<<"Temperature";
    cout<<setw(15)<<"gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<setw(15)<<"Address";
    cout<<setw(15)<<"Vaccine"<<endl;
}
//-------------------------------------------------6.6
void Vaccine::view_all(){
			fstream outfile;
		//	outfile.open("vaccinetrial.txt",ios::binary|ios::in);
				outfile.open("vaccinetrial.txt");
			if(!outfile){
				cout<<"File doesnot exist";
			}
			cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    		
    		cout<<"\n\t\t\t********\n";
    		cout<<"\t\t\tALL DATA ";
    		cout<<"\n\t\t\t********\n\n";
			show();
			while(!outfile.eof()){
				if(outfile.read(reinterpret_cast<char*>(this),sizeof(*this))){
					showList();
				}	
			}
			getch();
			outfile.close();
}
//---------------------------------------------------------
//--------------------------------------------------------------------
int password()//b
{
    char cname[30],pass[20];
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap=rand();
    cout<<"\n\n\t\t\t\t\tCAPTURE:-> "<<cap<<endl;
    cout<<" Please enter the valid capture :-   ";
    cin>>capt;
    if( (strcmp(cname,"admin")==0) && (strcmp(pass,"admin")==0) && cap==capt)
        return 1;
    else
        return 0;
}
//----------------------------------------
void menu()//c
{
	system("Color E4");
    system("cls");
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
	
    cout<<"\n\t\t\t************************\n";
    cout<<"\t\t\tWELCOME TO THE MAIN MENU";
    cout<<"\n\t\t\t************************\n";
    cout<<"\n\t\t1: Add NEW Record\t\t\t 2: ADMIN Login"<<endl;
    cout<<"\n\t\t3: USER Login   \t\t\t 4: Check Infection Rate"<<endl;
    cout<<"\n\t\t5: exit"<<endl;
}
void Vaccine :: infection()
{
		char s1 , s2 , s3 , s4 , s5 ;
	cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
	cout<<"\t\tGive the answer only in 'y' or 'n'"<<endl;
	cout<<endl<<"\t\tType y for Yes and n for No"<<endl;
	cout<<endl<<endl<<"1) Do you have cough, fever, cold :-  ";
	cin>>s1;
	cout<<endl<<endl<<"2) Do you have Headache Or Bodypain :-  ";
	cin>>s2;
	cout<<endl<<endl<<"3) Do you have Difficulty in Breathing :-  ";
	cin>>s3;
	cout<<endl<<endl<<"4) Do you able to identify the Taste or Smell :-  ";
	cin>>s4;
	cout<<endl<<endl<<"5) Are you in contact with covid patient in last 14 days :-  ";
	cin>>s5;
	cout<<endl<<endl;
	if(s1=='n'&&s2=='n'&&s3=='n'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Are perfectly Fine ....... ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='n'&&s3=='n'&&s4=='n'&&s5=='n')
	{
		cout<<endl<<"********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 10%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	
	else if(s1=='n'&&s2=='n'&&s3=='y'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 10%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='n'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 10%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='y'&&s3=='n'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 10%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='n'&&s3=='n'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 10%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='y'&&s2=='y'&&s3=='n'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='y'&&s3=='y'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='y'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='n'&&s3=='y'&&s4=='n'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='n'&&s3=='n'&&s4=='n'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='n'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='n'&&s3=='y'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='n'&&s2=='y'&&s3=='n'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='n'&&s4=='n'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 30-40%........ ";
		cout<<endl<<"\t\t\tStay Safe and Take Care ...."<<endl;
	}
	else if(s1=='y'&&s2=='y'&&s3=='y'&&s4=='y'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 60-70%........ ";
		cout<<endl<<"\t\t\tYou are recommended to consult a doctor...."<<endl;
	}
	else if(s1=='n'&&s2=='y'&&s3=='y'&&s4=='n'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 60-70%........ ";
		cout<<endl<<"\t\t\tYou are recommended to consult a doctor...."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='y'&&s4=='n'&&s5=='n')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 60-70%........ ";
		cout<<endl<<"\t\t\tYou are recommended to consult a doctor...."<<endl;
	}
	else if(s1=='y'&&s2=='y'&&s3=='n'&&s4=='n'&&s5=='n')
	{
		cout<<endl<<"********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 60-70%........ ";
		cout<<endl<<"\t\t\tYou are recommended to consult a doctor...."<<endl;
	}
	else if(s1=='y'&&s2=='y'&&s3=='n'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 60-70%........ ";
		cout<<endl<<"\t\t\tYou are recommended to consult a doctor...."<<endl;
	}
	else if(s1=='n'&&s2=='y'&&s3=='n'&&s4=='n'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 60-70%........ ";
		cout<<endl<<"\t\t\tYou are recommended to consult a doctor...."<<endl;
	}else if(s1=='y'&&s2=='n'&&s3=='n'&&s4=='n'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 60-70%........ ";
		cout<<endl<<"\t\t\tYou are recommended to consult a doctor...."<<endl;
	}
	else if(s1=='y'&&s2=='y'&&s3=='y'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 90%........ ";
		cout<<endl<<"\t\t\tYou are recommended to go for Covid Test....."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='y'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 90%........ ";
		cout<<endl<<"\t\t\tYou are recommended to go for Covid Test....."<<endl;
	}
	else if(s1=='y'&&s2=='y'&&s3=='y'&&s4=='n'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 90%........ ";
		cout<<endl<<"\t\t\tYou are recommended to go for Covid Test....."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='y'&&s4=='y'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 90%........ ";
		cout<<endl<<"\t\t\tYou are recommended to go for Covid Test....."<<endl;
	}
	else if(s1=='y'&&s2=='n'&&s3=='y'&&s4=='n'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 90%........ ";
		cout<<endl<<"\t\t\tYou are recommended to go for Covid Test....."<<endl;
	}
	else if(s1=='y'&&s2=='y'&&s3=='n'&&s4=='n'&&s5=='y')
	{
		cout<<endl<<"\t\t********** --> REPORT <-- *************"<<endl;
		cout<<endl<<"\t\t\tYour  Infection Rate is 90%........ ";
		cout<<endl<<"\t\t\tYou are recommended to go for Covid Test....."<<endl;
	}
	
	getch();
}
//----------------------------------------
int main()//MAINFUNCTION---------------------------------------------------------------------------------------------
 {
 	//First Background then Text
 	 system("Color E4");
 	
     Vaccine obj;
     int k=3;
     int num_vac;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
	
    cout<<"\t\n\n Press any key to continue.............  "<<endl;
    getch();
    
    system("cls");
    cout<<"  \n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t****************************";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t********************************\n";
   /* while(k>=1)
    {
    int c = password();
    if(c==1)
        break;
    else
        cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
    k--;
    if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
              system("cls");
              cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
              cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
              Sleep(1000);
            }
              k=3;
              goto B;
        }
    }*/
      int ch;
      do{
            cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 C-Cure  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
            
            menu();
            cout<<"\n\t\n\tChoose according to your need : ";
            cin>>ch;
             Vaccine v1;
      switch(ch)
       {
         case 1:system("Color 0A");
		 		system("cls");
	             obj.addNew();
                 break;
                 
         case 2:  system("Color F4");
		 		B: 
		 		system("cls");
         		 
				while(k>=1)
 				   {
 				 	  int c = password();
 					   if(c==1)
   			    	 break;
   					 else
   				     cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
  					  k--;
  					  system("cls");
  					  if(k<1)
   					     {
 				           for(int i=59; i>=0; i--)
         				   {
          				    system("cls");
             				 cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
            				  cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
            				  Sleep(1000);
            				}
            				  k=3;
           				   goto B;
        				}
    				}
    			system("cls");
       	   	  	 obj.viewVaccine();
                 break;
         case 3:system("cls");
            	obj.searchData();
                break;
          case 4:system("Color E5");
		  		system("cls");
            	obj.infection();
                break;
        
         case 5:  system("cls");
                    exit(0);
         default: system("cls");
                  cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                  cout<<"\n\n\t\t\t\t\t***HAVE A NICE DAY**";
                  Sleep(3000);
                  exit(0);
       }
      }while(ch!=0);
      return 0;
}
//----------------------------------------------------------------------------------------------------------------------

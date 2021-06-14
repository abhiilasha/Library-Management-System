#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<cstdio>
#include<iomanip>
#include<string.h>
#include<fstream>

using namespace std;
void mainmenu();
void adminmenu();

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class book
{
    char serial[6];
    char bname[50];
    char author[30];
   // int d,m,y;

public:
    void createbook()
    {
        cout<< "\nEnter the serial number of the book.";
        cin>>serial;
        cout<< "\nEnter book's  name: ";
        gets(bname);
        gets(bname);
        cout<< "\nEnter author's name: ";
        gets(author);
        cout<< "\n\nNew book created"<<endl;

    }

    void dispbook()
    {
        cout<< "\nSerial number: "<<serial;
        cout<< "\nBook name:";
        puts(bname);
        cout<< "\nAuthor:";
        puts(author);
        //cout<< "\nNumber of books available: "<<q<<endl;

    }

    void modifybook()
    {
        cout<< "\nSerial Number: "<<serial;
        cout<< "\nModify name:";
        gets(bname);
        gets(bname);
        cout<< "\nModify Author:";
        gets(author);
    }

    char* retserial()
    {
        return serial;
    }

    void report()
    {
        cout<<serial<<setw(45)<<bname<<setw(40)<<author<<endl;
    }

    int displaybook(int);
    int searchb(int);
    void bookissue();
    void deletebook();
    void pass();
    void password();
    int fine(int,int,int,int,int,int);
    void bookdeposit();
    void modifyb();
    void writebook();
    //int category(int x);
    void stu();
    void bookrec();
    int displayxbook(char n[]);
};

class student
{
  char rollno[9];
  char name[20];
  char stdbno[6];
  int token;

  public:
      void createst()
    {
        system("cls");
        cout<< "\nEnter the roll number of student: ";
        cin>>rollno;
        cout<< "\nEnter student's name: ";
        gets(name);
        gets(name);
        token=0;
        stdbno[0]='\0';
        cout<< "\n\nNew Student record created"<<endl;

    }

    void dispst()
    {
        cout<< "\nRoll number: "<<rollno;
        cout<< "\nName:";
        puts(name);
        cout<< "\nNumber of books issued:"<<token;
        if(token==1)
        {
            cout<< "\nBook's serial number:"<<stdbno;
        }
    }

    void modifyst()
    {
        cout<< "\nRoll Number: "<<rollno;
        cout<< "\nModify name:";
        gets(name);
        gets(name);
    }

    char* retrollno()
    {
        return rollno;
    }
    char* retstdbno()
    {
        return stdbno;
    }
    int rettoken()
    {
        return token;
    }
    void addtoken()
    {
       token=1;
    }

    void resettoken()
    {
        token=0;
    }

    void getstdbno(char t[])
    {
       strcpy(stdbno,t);
    }
    void report()
    {
        cout<<rollno<<setw(30)<<name<<setw(30)<<token<<endl;
    }
    friend void stu();
    void writest();
    int displayxst(char n[]);
    void modifystudent();
    void deletest();
    void displayst();
    void studentrec();
      };
 fstream fp,fp1;
 book b;
 student st;

 void book::writebook()
 {

     //int c=category(2);
     char ch;
     fp.open("book.txt",ios::out|ios::app);

     do{
        system("cls");
        createbook();
        fp.write((char*)&b,sizeof(book));
        cout<< "\n\nDo you want to add more book data?(y/n)";
        cin>>ch;
     }
     while(ch=='y'||ch== 'Y');
     fp.close();
 }

 void student::writest()
 {
     char ch;
     fp.open("student.txt",ios::out|ios::app);
     do{
        system("cls");
        createst();
        fp.write((char*)&st,sizeof(student));
        cout<< "\n\nDo you want to add more student data?(y/n)";
        cin>>ch;
     }
     while(ch=='y'||ch== 'Y');
     fp.close();
 }

 int book:: displayxbook(char n[])
 {
     cout<< "\nBOOK DETAILS:\n";
     int flag=0;
     fp.open("book.txt",ios::in);
     while(fp.read((char*)&b,sizeof(book)))
     {
         if(strcmpi(b.retserial(),n)==0)
         {
             b.dispbook();
             flag=1;
         }
     }
     fp.close();
     if(flag==0)
     {
         cout<< "\n\nBook not found."<<endl;

     }
     _getch();
 }

  int student:: displayxst(char n[])
 {
     cout<< "\nSTUDENT DETAILS:\n";
     int flag=0;
     fp.open("student.txt",ios::in);
     while(fp.read((char*)&st,sizeof(student)))
     {
         if(strcmpi(st.retrollno(),n)==0)
         {
             st.dispst();
             flag=1;
         }
     }
     fp.close();
     if(flag==0)
     {
         cout<< "\n\nStudent not found."<<endl;

     }
     _getch();
 }

 void book::modifyb()
 {
     char n[6];
     int found=0;
     system("cls");

     cout<< "\n\nModify data\n"<<endl;
     cout<< "enter book's serial number";
     cin>>n;
     fp.open("book.txt",ios::in|ios::out);
     while(fp.read((char*)&b,sizeof(book))&& found==0)
     {
         if(strcmpi(b.retserial(),n)==0)
         {
             dispbook();
             cout<< "\nEnter new details:"<<endl;
             modifybook();
             int pos = -1*sizeof(b);
             fp.seekp(pos,ios::cur);
             fp.write((char*)&b,sizeof(book));
             cout<< "\nRecord updated.";
             found=1;
         }
     }
     fp.close();
     if(found==0)
     {
         cout<< "\nBook does not exist."<<endl;
         modifyb();
     }
     _getch();
     bookrec();
 }

 void student:: modifystudent()
 {
     char n[9];
     int found=0;
     system("cls");
     cout<< "\n\nModify data"<<endl;
     cout<< "enter roll number";
     cin>>n;
     fp.open("student.txt",ios::in|ios::out);
     while(fp.read((char*)&st,sizeof(student))&& found==0)
     {
         if(strcmpi(retrollno(),n)==0)
         {
             dispst();
             cout<< "\nEnter new details:"<<endl;
             modifyst();
             int pos = -1*sizeof(st);
             fp.seekp(pos,ios::cur);
             fp.write((char *)&st,sizeof(student));
             cout<< "\nRecord updated.";
             found=1;
         }
     }
     fp.close();
     if(found==0)
     {
         cout<< "\nStudent does not exist."<<endl;
     }
     _getch();
     studentrec();
 }

 void student:: deletest()
 {
     char n[9];
     int flag=0;
     system("cls");
     cout<< "\nDelete record";
     cout<< "\nEnter roll number:";
     cin>>n;
     fp.open("student.txt",ios::in|ios::out);
     fstream fp2;
     fp2.open("temp.txt",ios::out);
     fp.seekg(0,ios::beg);
     while(fp.read((char*)&st,sizeof(student)))
     {
         if(strcmpi(st.retrollno(),n )!=0)
         {
            fp2.write((char*)&st,sizeof(student));
         }
         else {
            flag=1;
         }
     }
     fp2.close();
     fp.close();
     remove("student.txt");
     rename("temp.txt","student.txt");
     if(flag==1)
     {
         cout<< "\nRecord Deleted";
     }
     else{
        cout<< "\nRecord not found.";
     }
     _getch();
     studentrec();
 }

 void book:: deletebook()
 {
     char n[6];
     //int i;
     //int c=category(2);
     int flag=0;
     system("cls");
     cout<< "\nDelete record";
     cout<< "\nEnter book serial number:";
     cin>>n;
     fp.open("book.txt",ios::in|ios::out);
     fstream fp2;
     fp2.open("Temp.txt",ios::out);
     fp.seekg(0,ios::beg);
     while(fp.read((char*)&b,sizeof(book)))
     {
        if(strcmpi(retserial(),n)!=0)
         {

             fp2.write((char*)&b,sizeof(book));

         }
         else {
            flag=1;
         }

     }
     fp2.close();
     fp.close();
     remove("book.txt");
     rename("Temp.txt","book.txt");
     if(flag==1)
     {
         cout<< "\nRecord Deleted";
     }
     else{
        cout<< "\nRecord not found.";
     }
     cout<< "Press any key to exit..\n";
     _getch();
     bookrec();
 }

void student:: displayst()
{
    system("cls");
    fp.open("student.txt",ios::in);
    if(!fp)
    {
        cout<< "File could not open.";
        _getch();
        studentrec();
    }
    cout<< "\n\nSTUDENT LIST"<<endl;
    cout<< "**************************"<<endl;
    cout<< "Roll number"<<setw(25)<<"Name"<<setw(30)<< "Book Issued"<<endl;
    cout<< "-------------------------------------------------------------------\n";
    while(fp.read((char*)&st,sizeof(student)))
    {
        report();
    }
    fp.close();
    cout<< "press any key to continue....\n";
    _getch();
    studentrec();
}

int book::displaybook(int i)
{
    system("cls");
    //int c=category(i);
    //system("cls");
    fp.open("book.txt",ios::in);
    if(!fp)
    {
        cout<< "File not found..\nPress any key to continue...";
        _getch();


    }

    cout<< "\n\nBOOK LIST"<<endl;
    cout<< "******************"<<endl;
    cout<< "Serial number"<<setw(30)<<"Title"<<setw(40)<< "Author"<<setw(40)<< endl;
    cout<< "-----------------------------------------------------------------------------------\n";
    while(fp.read((char*)&b,sizeof(book)))
    {
        b.report();
        }

    fp.close();
    cout<< "Press any key to continue....";
    _getch();
    system("cls");
    if(i==1)
        stu();
    else
        bookrec();
}

void book:: bookissue()
{
    char rollno[9],serial[6];
    int found=0,flag=0;
    system("cls");
    cout<< "\n\n Book issue:\n\n";

    //system("cls");
    cout<< "Enter roll number of student: ";
    cin>>rollno;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&& found==0)
{
        if(strcmpi(st.retrollno(),rollno)==0)
           {
               found=1;
               if(st.rettoken()==0)
                {
                    cout<< "\nEnter book's serial number: ";
                    cin>>serial;
                    //getdate();
                    while(fp1.read((char*)&b,sizeof(book))&& flag==0)
                    {
                        if(strcmpi(b.retserial(),serial)==0)
                        {
                            flag=1;

                            st.addtoken();
                            st.getstdbno(b.retserial());
                            int pos= -1*sizeof(st);
                            fp.seekg(pos,ios::cur);
                            fp.write((char*)&st,sizeof(student));
                            cout<< "\n\nBook Issued SUCCESFULLY!\n\nNote:Please return the book within 15 days otherwise a fine of rs 5 per day will be imposed\n\n";
                        }
                    }
                    if(flag==0)
                    {
                        cout<< "\nBook number does not exist";
                    }
                }
                else{
                    cout<< "You have not returned the previous book\n";
                }
           }
}


    if(found==0)
    {
        cout<< "\nstudent record does not exist."<<endl;
    }
    _getch();
    fp.close();
    fp1.close();

  adminmenu();
}


void book:: bookdeposit()
{
    char rollno[9],serial[6];
    //int dd,mm,yy;
    int found=0,flag=0,day,fine;
    system("cls");
    cout<< "\n\nBook deposit:"<<endl;
    cout<< "Enter roll number of student";
    cin>>rollno;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&& found==0)
    {
        if(strcmpi(st.retrollno(),rollno)==0)
           {
               found=1;
               if(st.rettoken()==1)
                {
                    while(fp1.read((char*)&b,sizeof(book))&& flag==0)
                    {
                        if(strcmpi(b.retserial(),st.retstdbno())==0)
                        {
                            flag=1;

                            dispbook();
                            //fine(d,m,y,dd,mm,yy);

                            cout<< "Book deposited in number of days: ";
                            cin>>day;
                            if(day>15)
                            {
                                fine=(day-15)*5;
                                cout<< "\nFine to be deposited: "<< fine;
                            }
                            st.resettoken();
                            int pos= -1*sizeof(st);
                            fp.seekg(pos,ios::cur);
                            fp.write((char*)&st,sizeof(student));
                            cout<< "\n\nBook Deposited SUCCESFULLY!\n ";

                        }
                    }
                    if(flag==0)
                    {
                        cout<< "\nBook number does not exist";
                    }
                }
                else{
                    cout<< "No book is issued...";
                }
           }

    }
    if(found==0)
    {
        cout<< "\nstudent record does not exist."<<endl;
    }
    _getch();
    fp.close();
    fp1.close();
    adminmenu();
}

int book::searchb(int x)
{
    //int cont=0,i;
    int i;
    //int c;
    char name[100];
    system("cls");
    fp.open("book.txt",ios::in);
    if(!fp)
    {
        cout<< "\nFile could not open.";
        cout<< "\nPress any key to continue....";
        _getch();
        if(x==1)
            stu();
            else
            bookrec();
    }
    else
    {
    cout<< "Searching by Name:\n ";
    fp.read((char*)&b,sizeof(book));
    cout<< "\nEnter book's name:";
    gets(name);
    gets(name);
          while(!fp.eof())
          {
            for(i=0;bname[i]!='\0'&&name[i]!='\0'&&(name[i]==bname[i]||name[i]==bname[i]+32);i++);
            if(bname[i]=='\0'&&name[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        dispbook();
                        //cont++;
                        break;
                }
             fp.read((char*)&b,sizeof(book));
          }
    }
cout<< "press any key to continue...";
_getch();
system("cls");
    if(x==1)
    stu();
    else
    bookrec();
}

void book::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=_getch();
    if(ch==13)      //carriage return character //return to the beginning of current line.
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0) //backspace
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    fp.open("password.txt");
    fp>>ch1;    //initialised to pass
    fp.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        adminmenu();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        _getch();
        system("cls");
        pass();
        //_getch();
    }
}
void book::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\n\t\tEnter Old Password : ";
    while(1)
    {
    ch=_getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    fp.open("password.txt");
    fp>>ch1;
    fp.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
        cout<<"\n\t\tEnter New Password : ";
        //fflush(stdin);  //flushes buffer
        i=0;
        while(1)
        {
        j++;
        ch=_getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                _getch();
                system("cls");
                password();
                adminmenu();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        fp1.open("password.txt");
        fp1<<st;
        fp1.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        _getch();
        system("cls");
        adminmenu();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n";
        cout<<"\n\t\tEnter 1 to retry or 2 to return to menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            adminmenu();
        }
    }
}
void book:: bookrec()
{
    system("cls");
    int ch;
    cout<< "\n\n\tBOOK RECORD";
    cout<< "\n 1. Add a new book." ;
    cout<< "\n 2. Display all books.";
    cout<< "\n 3. Display a particular book's record";
    cout<< "\n 4. Modify book record";
    cout<< "\n 5. Delete book record";
    cout<< "\n 6. Back to ADMIN MENU"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        writebook();
        break;

    case 2:
        displaybook(0);
        break;

    case 3:
        char serial[6];
        system("cls");
        cout<< "\nEnter serial number of the book.";
        cin>>serial;
        displayxbook(serial);
        break;

    case 4:
        modifyb();
        break;

    case 5:
        deletebook();
        break;

    case 6:
        adminmenu() ;
        break;

    default:
        cout<< "Invalid choice. Try again.";
            }

bookrec();
}

void student::studentrec()
{
    system("cls");
    int ch;
    cout<< "\n\n\tSTUDENT RECORD";
    cout<< "\n\n 1. Add a new student record.";
    cout<< "\n 2. Display all student records.";
    cout<< "\n 3. Display a particular student's record";
    cout<< "\n 4. Modify student record";
    cout<< "\n 5. Delete student record";
    cout<< "\n 6. Return to ADMIN MENU";
    cin>>ch;
    switch(ch)
    {
    case 1:
        writest();
        break;

    case 2:
        displayst();
        break;

    case 3:
        char num[9];
        ("cls");
        cout<< "\nEnter roll number.";
        cin>>num;
        displayxst(num);
        break;

    case 4:
        modifystudent();
        break;

    case 5:
        deletest();
        break;
    case 6:
        adminmenu();
        break;

        default:
        cout<< "Invalid choice. Try again.";
            }
studentrec();
}

void book::stu()
{
    int ch;
    cout<< "\n\n1. View all books";
    cout<< "\n2. Search book.";
    cout<< "\n3. Go to main menu";
    cout<< "\n4.exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        displaybook(1);
        break;
    case 2:
        searchb(1);
        break;
    case 3:
        mainmenu();
        break;
    case 4:
        exit(0);
        break;

    default:
        cout<< "\nInvalid Choice. Try Again";

    }
    system("cls");
    stu();
}


void start()
{
   ("cls");
   gotoxy(33,9);
   cout<< "*****************************";
   gotoxy(35,11);
   cout<< "LIBRARY MANAGEMENT SYSTEM";
   gotoxy(40,13);
   cout<< "(By:Abhilasha)";
   gotoxy(33,16);
   cout<< "*****************************"<<endl;


}


void adminmenu()
{
    system("cls");
    int ch;
    cout<< "\n\n ADMINISTRATOR MENU";
    cout<< "\n\n 1. STUDENT RECORD";
    cout<< "\n 2. BOOK RECORD" ;
    cout<< "\n3. ISSUE BOOK";
    cout<< "\n4. DEPOSIT BOOK";
    cout<< "\n5. BACK TO MAIN MENU";
    cout<< "\n6. CHANGE PASSWORD";
    cout<< "\n7. EXIT"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        st.studentrec();
        break;

    case 2:
        b.bookrec();
        break;

    case 3:
       b. bookissue() ;
        break;
    case 4:
           b.bookdeposit();
           break;

    case 5:
        system("cls");
        mainmenu();
        break;
    case 6:
        b.password();
        break;
    case 7:
        exit(0);
        break;

    default:
        cout<< "Invalid choice. Try again.";
            }
adminmenu();
}

void mainmenu()
{
    int ch;
    do{
       // system("cls");
        cout<< "\n\n MAIN MENU";
        cout<< "\nChoose login option:";
        cout<< "\n\n 1.STUDENT";
        cout<< "\n 2.ADMINISTRATOR";
        cout<< "\n 3.EXIT"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            b.stu();
            break;

        case 2:
            b.pass();
            break;

        case 3:
            exit(0);
            break;

        default:
            cout<< "Invalid choice. Try again.";
        }

    }
    while (ch>4);
}

int main()
{
    student st;
    book b;
    start();
    mainmenu();


}

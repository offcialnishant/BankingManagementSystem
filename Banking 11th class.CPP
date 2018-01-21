#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
char nm[20];
char p[20];
long double an;
long double im;
struct info
{
char gen[12];
char birth[14];
int age;
char fnm[20];
};
void first(void);
void setup(void);
void menu(void);
void withdraw(void);
void deposit(void);
void balance(void);
void loan(void);
void login(void);
void main()
{
clrscr();
first();
setup();
login();
menu();
getch();
}
void first(void)
{
gotoxy(25,10);
cout<<"WELCOME TO A-R BANK OF C++\n";
delay(1500);
gotoxy(17,12);
cout<<"MADE BY NISHANT AGGARWAL AND SHASHANK GUPTA";
delay(3000);
clrscr();
gotoxy(15,10);
cout<<"SOFTWARE LOADING ,PLEASE WAIT ";
for (int i=0;i<26;i++)
{
cout<<"Þ";
delay(150);
}
clrscr();
}
void setup(void)
{
gotoxy(17,10);
cout<<"kINDLY OPEN YOUR CAPS LOCK TO AVOID INCONVINIENCE";
delay(3500);
clrscr();
cout<<"\nPRESS 1 IF YOU ARE AN EXISTING USER";
cout<<"\n\nPRESS 0 IF YOU ARE A NEW USER\n";
int a;
cin>>a;
clrscr();
if (a==0)
{
info i1;
cout<<"\nFULL NAME\t";
gets(::nm);
cout<<"\nSEX (MALE OR FEMALE)\t";
gets(i1.gen);
cout<<"\nDATE OF BIRTH\t";
gets(i1.birth);
cout<<"\nAGE\t";
cin>>i1.age;
cout<<"\nFATHER'S NAME\t";
gets(i1.fnm);
cout<<"\nACCOUNT NUMBER\t";
cin>>::an;
cout<<"\nINITIAL DEPOSIT (SHOULD NOT BE LESS THAN 500)\t";
cin>>::im;
clrscr();
a:;
cout<<"\nENTER PASSWORD FOR YOUR ACCOUNT(MAX 10 CHARACTERS) ";
char s[20];
int flag=1;
gets(::p);
int sp=strlen(::p);
cout<<"\nAGAIN ENTER YOUR PASSWORD FOR VERIFICATION ";
gets(s);
int ss=strlen(s);
for (int i=0;::p[i]!='\0';i++)
{
if (::p[i]!=s[i])
{
flag=0;
}
}
if (flag==0 || sp!=ss)
{
cout<<"\nYOU HAVE ENTERED WRONG PASSWORD.";
goto a;
}
else if (flag==1 )
{
start:
cout<<"\nVERIFICATION CODE\t12345";
char ver[10];
cout<<"\nENTER THE VERIFICATION CODE\n";
gets(ver);
int sver=strlen(ver);
int fla=1;
char asl[10]="12345";
int sasl=strlen(asl);
for (int j=0;asl[j]!='\0';j++)
{
if (ver[j]!=asl[j])
{
fla=0;
}
}
if (fla==0 || sasl!=sver)
{
cout<<"\nYOU HAVE ENTERED WRONG CODE.ENTER AGAIN";
goto start;
}
else if (fla==1)
{
cout<<"\nYOUR ACCOUNT IS VERIFIED.YOU CAN NOW ACCESS YOUR ACCOUNT\n";
cout<<"\nPRESS 1 TO CONTINUE : ";
int a;
cin>>a;
}
}
}
}
void login(void)
{
clrscr();
gotoxy(24,2);
cout<<"\nA-R BANK LOGIN PAGE";
int f=1;
hell:;
cout<<"\n\nENTER YOUR ACCOUNT NUMBER\t";
long double d;
cin>>d;
if (d!=::an)
{
cout<<"\n\nTHE ENTERED ACCOUNT NUMBER DOES NOT EXIST.";
cout<<"\n\nENTER A VALID ACCOUNT NUMBER";
goto hell;
}
else
{
yes:;
cout<<"\n\nENTER YOUR PASSWORD\t";
char t[20];
gets(t);
int st=strlen(t);
int sp=strlen(::p);
for (int i=0;::p[i]!=0;i++)
{
if (t[i]!=::p[i])
{
f=0;
}
}
if (f==0 || st!=sp)
{
cout<<"\n\nYOU HAVE ENTERED WRONG PASSWORD.";
goto yes;
}
}
}
void menu(void)
{
man:;
clrscr();
cout<<"\nSERVICES AVAILABLE :\n\n";
cout<<"1.\tWITHDRAW MONEY\n2.\tDEPOSIT MONEY\n3.\tCHECK BALANCE\n";
cout<<"4.\tTAKE A LOAN\n5.\tEXIT\n";
cout<<"\nENTER YOUR CHOICE :\t";
int a;
cin>>a;
clrscr();
switch(a)
{
case 1:withdraw();
       break;
case 2:deposit();
       break;
case 3:balance();
       break;
case 4:loan();
       break;
case 5:exit(0);
       break;
default:cout<<"\nINVALID CHOICE.ENTER YOUR CHOICE AGAIN.\t";
	goto man;
}
}
void withdraw(void)
{
clrscr();
cout<<endl;
cout<<"HELLO ";
puts(::nm);
cout<<"\n\nCURRENT MONEY IN YOUR ACCOUNT\t"<<::im;
cout<<"\n\nAMOUNT THAT CAN BE WITHDRAWED\t"<<(::im-500);
cout<<"\n\nENTER THE AMOUNT YOU WANT TO WITHDRAW\t";
long double a;
cin>>a;
if (a>(::im-500))
{
cout<<"\n\nYOU CANNOT WITHDRAW THIS MUCH AMOUNT";
}
else if(a<=(::im-500))
{
cout<<"\n\nAMOUNT SUCCESSFULLY WITHDRAWED FROM YOUR ACCOUNT";
::im=::im-a;
cout<<"\n\nNEW BALANCE ="<<::im;
}
cout<<"\n\nPRESS 1 TO GO BACK TO MAIN MENU.\t";
int t;
cin>>t;
menu();
}
void deposit(void)
{
clrscr();
cout<<endl;
cout<<"HELLO ";
puts(::nm);
cout<<"\n\nCURRENT BALANCE IN YOUR ACCOUNT\t"<<::im;
cout<<"\n\nENTER THE AMOUNT YOU WANT TO DEPOSIT\t";
long double a;
cin>>a;
cout<<"\n\nENTER THE TYPE OF DEPOSIT YOU WANT TO MAKE :\n";
cout<<"1.\tCASH DEPOSIT\n2.\tCHEQUE DEPOSIT\n";
j:;
cout<<"\nENTER YOUR CHOICE :\t";
int b;
cin>>b;
switch(b)
{
case 1:cout<<"\n\nAMOUNT SUCCESSFULLY TRANSFERRED TO YOUR ACCOUNT";
       ::im=::im+a;
       cout<<"\n\nNEW BALANCE ="<<::im;
       break;
case 2:cout<<"\n\nENTER YOUR CHEQUE NUMBER\t";
       long double d;
       cin>>d;
       cout<<"\n\nAMOUNT SUCCESSFULLY TRANSFERRED TO YOUR ACCOUNT";
       ::im=::im+a;
       cout<<"\n\nNEW BALANCE ="<<::im;
       break;
default:cout<<"\n\nENTER A VALID CHOICE";
	goto j;
}
cout<<"\n\nPRESS 1 TO GO BACK TO MAIN MENU.\t";
int t;
cin>>t;
menu();
}
void balance(void)
{
clrscr();
cout<<endl;
cout<<"HELLO ";
puts(::nm);
cout<<"\n\nCURRENT BALANCE IN YOUR ACCOUNT\t"<<::im;
cout<<"\n\nPRESS 1 TO GO BACK TO MAIN MENU.\t";
int t;
cin>>t;
menu();
}
void loan()
{
clrscr();
cout<<"\nRULES FOR TAKING LAON IN A-R BANK:";
cout<<"\n- MIMIMUM LOAN AMOUNT IS 1 THOUSAND";
cout<<"\n- MAXIMUM LOAN AMOUNT IS 10 LAKHS";
cout<<"\n- APPLICANT WILL BE CHARGED 12 % INTERST ANNUALLY";
cout<<"\n- DELAY IN LOAN REPAYMENT WILL BE TAKEN SERIOUSLLY BY BANK";
cout<<"\n\nPRESS 1 TO TAkE LOAN";
int a;
cin>>a;
clrscr();
cout<<"\nENTER THE AMOUNT OF LOAN YOU WANT TO TAKE\t";
long double c;
cin>>c;
if (c<=1000  && c>=1000000)
{
hell:;
cout<<"\n\nENTER YOUR ACCOUNT NUMBER\t";
long double d;
cin>>d;
if (d!=::an)
{
cout<<"\n\nTHE ENTERED ACCOUNT NUMBER DOES NOT EXIST.";
cout<<"\n\nENTER A VALID ACCOUNT NUMBER";
goto hell;
}
else
{
yes:;
int f=1;
cout<<"\n\nENTER YOUR PASSWORD\t";
char t[20];
gets(t);
int st=strlen(t);
int sp=strlen(::p);
for (int i=0;::p[i]!=0;i++)
{
if (t[i]!=::p[i])
{
f=0;
}
}
if (f==0 || st!=sp)
{
cout<<"\n\nYOU HAVE ENTERED WRONG PASSWORD.";
goto yes;
}
}
}
else
{
clrscr();
cout<<"\nTHE LOAN AMOUNT IS TRANSFERRED TO YOUR ACCOUNT.";
::im=::im+c;
cout<<"\n\nYOUR NEW BALANCE ="<<::im;
}
cout<<"\n\nPRESS 1 TO GO BACK TO MAIN MENU\t";
int k;
cin>>k;
menu();
}
























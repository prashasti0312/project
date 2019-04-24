#include<iostream .h>
#include<conio .h>
#include<string .h>
#include<graphics .h>
#include<dos .h>
#include<stdio .h>
#include<fstream .h>
#include<iomanip .h>
#include<stdlib .h>
 
 
//********************************************
// THIS CLASS CONTAINS FUNTIONS FOR FOOD
//********************************************
 
 
class food
{
   private:
     fstream p1;
     int c;
     char ap;
     struct fd
     {
	  char name[55];
	  float price;
     }f;
   public:
     food()
     {
	  c=0;
     }
     void food_menu(void);
     void app_fmenu(void);
     void food_bill();
     void del_all();
};
//*****************************************************
//  FUNCTION FOR DISPLAYING FOOD MENU
//*****************************************************

     void food::food_menu(void)
     {
	  cleardevice();
	  setfillstyle(7,1);
	  floodfill(0,0,4);
	  setfillstyle(7,10);
	  bar(17,40,605,420);
	  rectangle(17,40,605,420);
	  setfillstyle(1,10);
	  bar(24,47,598,413);
	  rectangle(24,47,598,413);
	  p1.close();
	  c=0;
	  p1.open("food.txt",ios::in|ios::binary);
	  outtextxy(30,50,"S.N.       ITEM NAME             PRICE");
	  gotoxy(4,5);
	  char h[5],pr[15];
	  while(p1.read((char*)&f,sizeof(f)))
	  {
	       c++;
	       settextstyle(4,0,1);
	       itoa(c,h,10);
	       outtextxy(40,60+20*c,h);
	       outtextxy(150,60+20*c,f.name);
	       itoa(f.price,pr,10);
	       outtextxy(390,60+20*c,pr);
	  }//END OF WHILE
	  p1.close();
	  settextstyle(15,0,1);
	  outtextxy(30,325,"DO YOU WANT TO ADD AN ITEM - (Y/N)");
	  gotoxy(60,20);
	  cin>>ap;
	  if(ap=='y'||ap=='Y')
	  {
	       app_fmenu();
	   //CALLING APPEND FUNCTION
        	  }
	  else
	  {
	       if(ap=='n'||ap=='N')
	       {
		    outtextxy(30,360,"DO YOU WANT TO DELETE ALL  (Y/N)");
		    char ch;
		    gotoxy(60,23);
		    cin>>ch;
		    if(ch=='y'||ch=='Y')
		    {
			 del_all();
			 //CALLING DELETE FUNCTION
		    }
	       }
	  }
     }

//***************************************
//  FUNCTION TO APPEND IN FOOD MENU
//***************************************

     void food::app_fmenu(void)
     {
	  p1.open("food.txt",ios::app|ios::binary);
	  outtextxy(30,360,"ENTER ITEM NAME U WANTTO ADD");
	  gotoxy(60,23);
	  gets(f.name);
	  outtextxy(30,380,"ENTER THE PRICE");
	  gotoxy(60,24);
	  cin>>f.price;
	  p1.write((char*)&f,sizeof(f));
	  p1.close();
	  getch();
     }

//*****************************
//  FUNCTION FOR FOOD BILL
//*****************************

     void food::food_bill()
     {
	  double bill=-1;
	  char c_name[20],f_name[20];
	  int dt;
	  cleardevice();
	  setfillstyle(7,1);
	  floodfill(0,0,4);
	  setfillstyle(7,10);
	  bar(17,40,605,420);
	  rectangle(17,40,605,420);
	  setfillstyle(1,7);
	  bar(24,47,598,413);
	  rectangle(24,47,598,413);
	  setcolor(4);
	  settextstyle(7,0,1);
	  outtextxy(30,70,"ENTER CUSTOMER NAME ");
	  gotoxy(50,6);
	  cin>>c_name;
	  outtextxy(30,120,"ENTER ITEM NAME TAKEN");
	  gotoxy(50,9);
	  cin>>f_name;
	  outtextxy(30,170,"ENTER THE QUANTITY");
	  gotoxy(50,12);
	  cin>>dt;
	  p1.close();
	  p1.open("food.txt",ios::in|ios::binary);
	  while(p1.read((char*)&f,sizeof(f)))
	  {
	       if(strcmp(f.name,f_name)==0)
	       {
		    bill=dt*f.price;
	       }
	  }//END OF WHILE
	   if(bill==-1)
	  {
	       setcolor(1);

	       for(int i=0;i<=20;i++)
	       {
	       setcolor(1);
	       outtextxy(30,220,"ITEM IS NOT PRESENT");
	       delay(100);
	       setcolor(WHITE);
	       outtextxy(30,220,"ITEM IS NOT PRESENT");
	       delay(100);
	     //  delay(2500);
	     }
	  }
	  else
	  {
	       char t[5],b[5];
	       setcolor(1);
	       itoa(dt,t,10);
	       itoa(bill,b,10);
	       outtextxy(30,250,"NAME FOOD.NAME      QUANTITY      BILL ");
	       setcolor(1);
	       settextstyle(4,0,1);
	       outtextxy(30,280,c_name);
	       outtextxy(140,280,f_name);
	       outtextxy(320,280,t);
	       outtextxy(445,280,b);
	       getch();
	  }
     }
//************************************
//  FUNCTION TO DELETE FOOD MENU
//******************************
     void food::del_all()
     {
	  remove("food.txt");
	  p1.open("food.txt",ios::out);
	  p1.close();
	  c=0;
     }


//END OF CLASS FOOD
//***************************************
// THIS CLASS CONTAINS INFORMATION
//   RELATED TO CUSTOMER
//***************************************
 
 
class customer
{
   private:
     int q,w;
     fstream f1;
     struct cust
     {
	  int c_no;
	  char c_name[20];
	  char c_add[80];
	  int a_date;
	  int a_month;
	  int a_year;
	  int d_date;
	  int d_month;
	  int d_year;
	  int room_no;
	  char room_type[25];
     }p;
   public:
     food j;

     customer()
     {
	  p.c_no=0;
	  p.d_date=0;
	  p.d_month=0;
     }

//**********************************
//  FUNCTION FOR CUSTOMER BILL
//*****************************

void cust_bill()
     {
	  int cho;
	  do
	  {
	       cleardevice();
	       f1.close();
	       setfillstyle(7,1);
	       floodfill(0,0,4);
	       setfillstyle(7,10);
	       bar(10,70,600,450);
	       rectangle(10,70,600,450);
	       setfillstyle(1,7);
	       bar(17,77,593,443);
	       rectangle(17,77,593,443);
	       setcolor(5);
	       setfillstyle(1,2);
	       settextstyle(7,0,1);
	       setcolor(9);
	       setfillstyle(1,2);
	       bar(210,140,410,238);
	       rectangle(210,140,410,158);
	       rectangle(210,140,410,174);
	       rectangle(210,140,410,190);
	       rectangle(210,140,410,206);
	       rectangle(210,140,410,222);
	       rectangle(210,140,410,238);
	       setcolor(4);
	       settextstyle(1,0,4);
	       outtextxy(180,20,"HOTEL BILL");
	       line(180,60,383,60);
	       setcolor(4);
	       settextstyle(1,0,1);
	       outtextxy(210,137,"  1.  ROOM BILL");
	       outtextxy(210,170,"  2.  FOOD BILL");
	       outtextxy(210,200,"  3.  MAIN MENU");
	       outtextxy(63,318,"ENTER CHOICE FOR WHICH YOU WANT THE BILL");
	       gotoxy(67,21);
	       cin>>cho;
	       choose(cho);
	  }while(cho!=3);//END OF WHILE
     }

//managing rooms (adding and searching available rooms)
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
cout&lt;&lt;"\n### Manage Rooms ###";
cout&lt;&lt;"\n1. Add Room";
cout&lt;&lt;"\n2. Search Room";
cout&lt;&lt;"\n3. Back to Main Menu";
cout&lt;&lt;"\n\nEnter Option: ";
cin&gt;&gt;opt;


struct Node* temp;
if (top == NULL)
{
printf("\nStack Underflow");
exit(1);
}
else
{
temp = top;
while (temp != NULL)
{
printf("%d->", temp->data);
temp = temp->link;
}


int main()
{
push(11);
push(22);
push(33);
push(44);

display();

printf("\nTop element is %d\n", peek());

pop();
pop();

display();

printf("\nTop element is %d\n", peek());


//switch statement
switch(opt)
{
case 1:
cout&lt;&lt;"\nEnter Room Number: ";
cin&gt;&gt;rno;
i=0;
for(i=0;i&lt;count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
cout&lt;&lt;"\nRoom Number is Present.\nPlease enter unique Number";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}


break;
case 2:
cout&lt;&lt;"\nEnter room number: ";
cin&gt;&gt;rno;
room.searchRoom(rno);
break;
case 3:
//nothing to do
break;
default:
cout&lt;&lt;"\nPlease Enter correct option";
break;
}
}while(opt!=3);
}
using namespace std;
int main()
{
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];

system("cls");

do
{
system("cls");
cout&lt;&lt;"######## Hotel Management #########\n";
cout&lt;&lt;"\n1. Manage Rooms";
cout&lt;&lt;"\n2. Check-In Room";
cout&lt;&lt;"\n3. Available Rooms";
cout&lt;&lt;"\n4. Search Customer";
cout&lt;&lt;"\n5. Check-Out Room";
cout&lt;&lt;"\n6. Guest Summary Report";
cout&lt;&lt;"\n7. Exit";
cout&lt;&lt;"\n\nEnter Option: ";
cin&gt;&gt;opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout&lt;&lt;"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.checkIn();
break;
case 3:
if(count==0)
{
cout&lt;&lt;"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}

using namespace std;

struct Node
{
int data;
struct Node* link;
};

struct Node* top;

void push(int data)
{
struct Node* temp;
temp = (struct Node*)malloc(sizeof(struct Node));

if (!temp)
{
printf("\nHeap Overflow");
exit(1);
}

temp->data = data;

temp->link = top;

top = temp;
}

int isEmpty()
{
return top == NULL;
}


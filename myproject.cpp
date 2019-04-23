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

#include <stdio.h>
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <iomanip>

using namespace std;
int main()
{
	FILE *ft,*fp;
	char another, choice;
	struct student 
	{
		char first_name[50], last_name[50];
		char course[100];
		int section ;
	};
		struct student e;
		char xfirst_name[50], xlast_name[50];
		long int recsize;
		fp = fopen ("users.txt","rb+");
		if (fp==NULL)
		{
		fp = fopen ("users.txt","wb+");
		if (fp==NULL)
		{
			puts ("Cannot open file");
			return 0;
		}
		}
recsize = sizeof (e);
while (1)
{
	system ("cls");
	cout <<"\t\t ******* STUDENT DATABASE MANAGEMENT SYSTEM *******\t\t\t\t\t";
	cout <<"\n";
	cout <<"\n\t\t\t\t\t 1. Add Records";
	cout <<"\n\t\t\t\t\t 2. list Records";
	cout <<"\n\t\t\t\t\t 3. Modify Records";
    cout <<"\n\t\t\t\t\t 4. Delete Records";
	cout <<"\n\t\t\t\t\t 5. Exit Program";
	cout <<"\n\n";
    cout <<"\n Select Your Choice : ";
    fflush (stdin);
    choice=getche();
    switch (choice)
	{
    case '1':
	fseek(fp,0,SEEK_END);
	another='Y';
	while (another =='Y'|| another=='y')
	{
		system ("cls");
		cout <<"Enter the first name :";
		cin>>e.first_name;
		cout <<"Enter the last name : ";
		cin >>e.last_name;
		cout <<"Enter the course :";
		cin>>e.course;
		cout <<"Enter the section : ";
		cin >>e.section;
		fwrite (&e,recsize,1,fp);
		cout <<"\n Add another record ? (y/n) ";
		fflush (stdin);
		another = getchar();
		}	
		break;
		case '2':
			system ("cls");
			rewind (fp);
			cout <<" \t\t\t\t ***** VIEW THE RECORDSIN THE DATABASE ***** ";
			cout <<"\n";
			while (fread(&e,recsize,1,fp)==1)
			{
				cout <<"\n";
				cout <<"\n"<<e.first_name<<setw(10)<< e.last_name;
				cout <<"\n";
				cout <<"\n"<<e.course<<setw(8)<<e.section;
			}
			cout <<"\n";
			system ("pause");
			break;
			case '3':
					system ("cls");
					another ='Y';
	while (another =='Y'|| another=='y')
	cout <<"Enter the last name of the student : ";
	cin >>xlast_name;
	rewind (fp);
	while (fread(&e,recsize,1,fp)==1)
	{
		if (strcmp (e.last_name,xlast_name)==0)
		{
		 	cout <<"Enter the new First Name :";
			 cin>>e.first_name;
			 	cout <<"\n Enter the new last name : ";
				 cin>>e.last_name;	
				 cout <<"\n Enter the new course : ";
	    	 cin >>e.course;
		 	cout <<"\n Enter the new section : ";
			 cin>>e.section;
			 fseek(fp,-recsize ,SEEK_CUR);
			 fwrite (&e,recsize,1,fp);
			break;
		}
		else 
		cout <<"Record not found";
	}
	cout <<"Modify another record ? (y/n) ";
		fflush (stdin);
		another = getchar();
	break;
	
	case '4':
			system ("cls");
					another='Y';
	while (another =='Y'|| another=='y')
	{
		cout <<"Enter last name of the student to delete : ";
		cin>> xlast_name;
		ft==fopen("temp.dat","wb");
			rewind (fp);
	while (fread(&e,recsize,1,fp)==1)
	if (strcmp(e.last_name,xlast_name)!=0)
	fwrite (&e,recsize,1,ft);
	fclose(fp);
	fclose(ft);
	remove ("users.txt");
	rename ("temp.dat","users.txt");
	fp=fopen("usrs.txt","rb+");
	cout <<"Delete another record. (y/n)";
		fflush (stdin);
		another = getchar();
	}
	break;
	case '5':
		fclose(fp);
		cout<<"\n";
		cout<<"Thanks !! \t\t\t Good day !!";
      exit(0);
}
}
return 0;
}




















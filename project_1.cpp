#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;
static int p=0;
class a
	
{
	char total_seat[10], busn[5],driver [10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public : 
	void Bus_Registration ();
	void install();
	void allotment();
	void empty();
	void show();
	void avail();
	void position (int i);
	
} bus[10];
void vline (char ch)
{
	for (int i=80;i>0;i--)
	cout <<ch;
}
void a ::Bus_Registration()
{
 cout.setf(ios::right,ios::adjustfield);
 cout.width(15);
cout<<"\nEnter Bus No:";
cin>>bus[p].busn;
 cout.setf(ios::right,ios::adjustfield);
 cout.width(15);
cout<<"\nFrom: ";
cin>>bus[p].from;
 cout.setf(ios::right,ios::adjustfield);
 cout.width(15);
cout<<"\nTo: ";
cin>>bus[p].to;
 cout.setf(ios::right,ios::adjustfield);
 cout.width(15);
cout<<"\nDeparture: ";
cin>>bus[p].depart;
 cout.setf(ios::right,ios::adjustfield);
 cout.width(15);
cout<<"\nTotal seats: ";
cin>>bus[p].total_seat;
 
p++;
cout<<"\n";
cout<<"Bus Information Added!!\n";
system("PAUSE");
system("CLS");
 
}
void a::install()
{
	cout <<"Enter bus no. ";
	cin >>bus[p].busn;
	cout <<" \n Enter driver's name ";
	cin >>bus[p].driver;
	cout <<"\n Arrival time : ";
	cin >>bus[p].arrival;
	cout <<"\n departure : ";
	cin >>bus[p].depart;
	cout <<"\t\t From : ";
	cin >>bus[p].from;
	cout <<"\t\t To : ";
	cin >>bus[p].to;
	bus[p].empty();
	p++;
}

void a::allotment()
{
	int seat ;
	char number[5];
	top:
	cout <<"Bus no. : ";
	cin>>number ;
	int n;
	for (n=0;n <=p;n++)
{
	if (strcmp(bus[n].busn , number)==0)
    break;
	}
	while (n <=p)
	{
	cout <<"Seat number : ";
	cin>>seat;
	if (seat>32)
{
	cout <<"\n There are only 32 seats available in this bus.";
}
	else
{
    if (strcmp(bus[p].seat[seat/4][(seat%4)-1],"Empty")==0)
{
	cout <<"\n Enter passenger's name : ";
	cin>>bus[p].seat[seat/4][(seat%4)-1];
	break;
}
	else 
	cout <<"\n The seat is already reserved.";
}
}
	if (n>p)
{
	cout <<"\n Enter correct bus number. \n";
	goto top ;
}
}

void a::empty()
{
	for (int i=0;i<8;i++)
{
	for (int j =0; j<4;j++)
{
	strcpy (bus[p].seat[i][j],"Empty");
}
}
}

void a :: show()
{
	int n;
	char number[5];
	cout <<"Enter bus number : ";
	cin>>number;
	for (n=0;n<=p;n++)
{
	if (strcmp(bus[n].busn,number)==0)
    break;
}
	while (n<=p)
{
	vline ('*');
	cout << "\n Bus number : \t\t "<<bus[n].busn<< "\n Bus driver: \t\t"<<bus[n].driver
	<< "\n Arrival time: \t\t "<<bus[n].arrival<< "\n Departure time: \t\t "<<bus[n].depart
	<< "\n From : \t\t"<<bus[n].from << "\n TO : \t\t "<<bus[n].to<<"\n\n";
	vline ('*');
	bus[0].position(n);
	int a=1;
	for(int i=0;i<8;i++)
{
	for (int j=0;j<4;j++)
{
	a++;
	if (strcmp(bus[n].seat[i][j],"empty")!=0)
	cout<<"\n The seat number "<<(a-1)<<"is reserved for "<<bus[n].seat[i][j]<<'.';
}
}
    break;
}
	if (n>p)
	cout <<"Enter correct bus no. ";
}
void a :: position(int=1)
{
	int s=0;p=0;
	for(int i=0;i<8;i++)
{
	cout <<"\n";
	for (int j=0;j<4;j++)
{
	s++;
	if (strcmp(bus[1].seat[i][j],"empty")==0)
{
	cout.width(5);
	cout.fill('.');
	cout<<s<<".";
	cout.width(10);
	cout.fill('.');
	cout<<bus[1].seat[i][j];
	p++;
}
else
{
	cout.width(5);
	cout.fill('.');
	cout<<s<<".";
	cout.width(10);
	cout.fill('.');
	cout<<bus[1].seat[i][j];
}
}
}
	cout <<"\n\n There are "<< p <<"seats empty in the bus number : "<<bus[1].busn;
}
void a::avail()
{
	for (int n=0;n<p;n++)
	{
	vline ('*');
	cout << "\n Bus number : \t\t "<<bus[n].busn << "\n Bus driver: \t\t"<<bus[n].driver
	<< "\n Arrival time: \t\t "<<bus[n].arrival<< "\n Departure time: \t\t "<<bus[n].depart
	<< "\n From : \t\t"<<bus[n].from << "\n TO : \t\t "<<bus[n].to<<"\n\n";
	vline ('*');
	vline ('_');
	}
}

int main ()
{
	system ("cls");
	int w;
	while(1)
	{
	cout <<"\t\t\t 1. Bus registration \n "<< "\t\t\t 2. Install \n"<<"\t\t\t 3.Reservation \n"<<"\t\t\t 4.Show \n"<<"\t\t\t 5.Busses available.\n"<<"\t\t\t 6.Exit";
		
	cout <<" \t\t\t\t\n Enter your choice : ";
	cin>>w;
	switch (w)
		{
		case 1: bus[p].Bus_Registration();
		break;	
		case 2: bus[p].install();
		break;
		case 3: bus[p].allotment();
		break;
		case 4: bus[0].show();
		break;
		case 5: bus[0].avail();
		break;
		case 6: exit(0);
		}
	}
	return 0;
}

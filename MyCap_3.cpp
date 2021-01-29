//c++ program to check the eligibility of a person to vote
//included the facility of gender recognition 
#include <iostream>
using namespace std;
int main ()
{
	int choice;
	int age;
	cout <<"Hello !";
	cout <<endl <<" Enter the choice that suits you" <<endl <<" 1 for male"<<endl<<"2 for female"<<endl ;
	cin>>choice ;
	if (choice==1)
	{
		cout <<"Sir, please enter your age"<<endl;
	}
	else if (choice ==2)
	{
	cout <<" Mam please enter your age"<<endl;
	}
	else 
	cout <<"invalid input"<<endl;
       cin>>age;
	
	if ( age >= 18)
	{
		cout <<"\n Your are eligibile to vote"<<endl;
	}
	else
	{
	    cout <<"\n Not eligibile to vote"<<endl;
	    cout <<"\n wait for"<< 18-age <<"years "<<endl;
	}
	cout <<" Thanks !";
	return 0;
}

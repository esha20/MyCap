#include <iostream>
using namespace std;
int func(int j)
{
	int i; 
	int c=1;
	for (i=2; i<= j/2; ++i)
	{
		if (j%i==0)
		{
			c=0;
	break;		
		}	
}
     return c;
}
int main () {
 int j,i;
cout <<" Enter a positive number : \n";
cin >> j;

for (i=2; i<= j/2; ++i)

	{
	if (func(i))
	{
		if (func(j-i))
		{
			cout <<j<<"="<<i<<"+"<<j-i<<endl;
		}
	}
  }
return 0;
}

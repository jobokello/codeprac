
 #include <iostream>
 #include <fstream>
 #include <cstring>
 #include <cmath>
 #include <cstdlib>
 #include <string>
using namespace std;


void encrypt();
void decrypt();
void print_out_array();
int powmod (int, int, int);
void  checkPrimeNumber();
void find_totient();
void find_n();
int gcd(int a, int h);
void finding_d();
void multiplicative_inverse(int e, int phi);
void finding_and_printing_E();
void set_n_e();

//Globals
int p, q,  phi,  d, base, e, n;



int main()
{
      int option;
      do
      {
     cout<<endl<<endl;
     cout<<"What would you like to do?"<<endl<<endl;
     cout<<"1: Encrypt"<<endl;
     cout<<"2: Decrypt"<<endl;
     cout<<"3: Read Encrypted File"<<endl;
     cout<<"4: Check if Prime"<<endl;
     cout<<"5: Find N"<<endl;
     cout<<"6: Find Totient"<<endl;
     cout<<"7: Find E"<<endl;
     cout<<"8: Find D"<<endl;
     cout<<"9: Exit "<<endl;

     cin>>option;cin.ignore();
     switch (option)
     {
         case 1: encrypt();                 break;
         case 2: decrypt();                 break;
         case 3: print_out_array();         break;
         case 4: checkPrimeNumber();        break;
         case 5: find_n();                  break;
         case 6: find_totient();            break;
         case 7: finding_and_printing_E();  break;
         case 8: finding_d();               break;
         case 9: break;
     }
      }
     while (option!=9);


     return 0;
}
//-----------------------------------------------------------------------------------
 int powmod (int base,int n, int e)
{

    int pow;
 pow = base;
 e = e - 1;
 while (e > 0)
  {
  pow = pow * base;
  e = e - 1;
  while (pow < n && e > 0)
   {
   pow = pow * base;
   e = e - 1;
   }
  pow = pow % n;
  }
 pow = pow % n;
 return pow;
}

//-------------------------------------------------------------

   void encrypt()
{
    char input[1000], cpy[1000]; int cnt;

     ofstream data ("data.txt", ios::out|ios::app);

     cout<<"Enter n: "; cin>>n;
     cout<<"Enter e: "; cin>>e;
     cin.ignore();
     cout<<"Enter text ";
     cin.getline (input,100);
     cnt = strlen (input);

     for (int i=0; i<=cnt; i++)
    {
        cpy[i]=input[i];
        cout<<' '<<powmod(cpy[i],n,e);
        data<<' '<< powmod(cpy[i],n,e);

    }
    data.close();
}
//---------------------------------------------------------
 void decrypt()
{
   ifstream data ("data.txt", ios::in);

      cout<<"Enter n: "; cin>>n;
     cout<<"Enter d: "; cin>>e;
     cin.ignore();
    int linecount = 0; int tempArray[10000]; int *finalArray;
    char cpy3[10000];
    char cpy4[10000];




    while (!data.eof())
	{
		data >> tempArray[linecount];
		linecount++;
	}
    finalArray = new int[linecount];
	for (int i = 0; i < linecount; i++)
	  {
		finalArray[i] = tempArray[i];
	  }

   for (int i = 0; i < linecount; i++)
	  {

        cpy3[i]=finalArray[i];
		cpy4[i]=powmod(cpy3[i], n, e);
		cout<<cpy4[i];
	  }
  data.close();
}
//---------------------------------------------------------------------------------
void print_out_array()
{
   ifstream data ("data.txt", ios::in);
    int linecount = 0; int tempArray[100]; int *finalArray;

    while (!data.eof())
	   {
		data >> tempArray[linecount];
		linecount++;
	   }

     finalArray = new int[linecount];
	for (int i = 0; i < linecount; i++)
	  {
		finalArray[i] = tempArray[i];
	   }

    for (int i = 0; i < linecount; i++)
	   {

		cout <<' '<< finalArray[i];
	   }

data.close();
}
//---------------------------------------------------------------
void  checkPrimeNumber()
{
  int n, i;
  bool isPrime = true;

  cout << "Enter a positive integer: ";
  cin >> n;

  for(i = 2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
          isPrime = false;
          break;
      }
  }
  if (isPrime)
      cout << "This is a prime number";
  else
      cout << "This is not a prime number";

}
//----------------------------------------------------------------------

int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}

//-------------------------------------------------------------------
void finding_d()
{

     cout<<"Enter E:  ";
     cin>>e;
     cout<<"Enter phi: ";
     cin>>phi;





    multiplicative_inverse(e,phi);


}
//
//---------------------------------------------------------------------------------------------------
void multiplicative_inverse(int e, int phi)
{
    int d=0, x1=0, x2=1, y1=1, temp_phi=phi, temp1, temp2,x,y;
    while (e>0)
    {
        temp1=temp_phi/e;
        temp2=temp_phi-temp1*e;
        temp_phi=e;
        e=temp2;

        x=x2-temp1*x1;
        y=d-temp1*y1;

        x2=x1;
        x1=x;
        d=y1;
        y1=y;


    }
    if (temp_phi==1)
            cout<< d+phi;
}


//---------------------------------------------------------------------------------------------------------------
void finding_and_printing_E()
   {
     int phi;
     cout<<"Enter Phi: "<<endl;
     cin>>phi;
     cout<<"These numbers are co-prime to phi: "<<endl;
     for (int i=1; i<=phi; i++)
     {
         gcd(i,phi);
         if (gcd(i,phi)==1)
            cout<<i<<endl;
    }

  }
//-------------------------------------------------
void find_totient()
{
    int prime1, prime2, totient;
    cout<<"Enter first prime: ";
    cin>>prime1;
    cout<<"Enter second prime: ";
    cin>>prime2;
    totient=(prime1-1)*(prime2-1);
    cout<<totient;
}
void find_n()
{
    int prime1, prime2, n;
    cout<<"Enter first prime: ";
    cin>>prime1;
    cout<<"Enter second prime: ";
    cin>>prime2;
    n=prime1*prime2;
    cout<<n<<endl;

}
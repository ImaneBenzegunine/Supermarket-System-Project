#include <iostream>
#include <fstream>

using namespace std;
class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
};
void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t_______________________________\n";
	cout<<"\t\t\t                               \n";
	cout<<"\t\t\t        SUPERMARKET MENU       \n";
	cout<<"\t\t\t                               \n";
	cout<<"\t\t\t_______________________________\n";
	cout<<"\t\t\t        >1- Administartor      \n";
	cout<<"\t\t\t        >2- Buyer              \n";
	cout<<"\t\t\t        >3- Exit               \n";
	cout<<"\t\t\t_______________________________\n";
	cout<<"\t\t\t      Please select a number  :";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t_______________________________\n";
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email : ";
			cin>>email;
			cout<<"\t\t\t Password    : ";
			cin>>password;
			if((email=="imane@gmail.com" && password=="imane@0000") || (email=="imane.benzegunine@gmail.com" && password=="imane@211") )
			{
				administrator();
			}
			else {
				cout<<"\t\t\tInvalide emain/password, try again\n";
			}			
			break;
			case 2: 
			{
				buyer();
			}
			case 3: {
				exit(0);
			}
		
			default :
			{
				cout<<"\t\t\tPlease select from the given options.\n";
			}
	}

	goto m;
}

void shopping::administrator()
{
	m:
	int choice;
	cout<<"\n\n\t\t\t\t****************************\n";
	cout<<"\t\t\t\t** Administrator menu  **   \n";
	cout<<"\n\n\t\t\t\t****************************\n";
	cout<<"\t\t\t ** 1 ** Add product      \n";
	cout<<"\t\t\t ** 2 ** Modify product      \n";
	cout<<"\t\t\t ** 3 ** Delete product      \n";
	cout<<"\t\t\t ** 4 ** back to menu      \n";
	
	cout<<"\n\n PLease enter your choice\n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2: 
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"\t\t\tInvalide choice!\n";				
	}
	goto m;
}
void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\n\t\t\t ===============================\n";
	cout<<"\t\t\t        Buyer      \n";
	cout<<"\t\t\t ===============================\n";
	cout<<"\t\t\t 1 = Buy product \n";
	cout<<"\t\t\t 2 = Go back \n";
	cout<<"\t\t\t Enter your choice\n";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2: 
			menu();
		default:
			cout<<"Invalide choice!\n";
					
	}
	goto m;
}

void shopping::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t``````````````````````````````````````\n";
	cout<<"\t\t  Add new product \n";
	cout<<"\n\n\t\t``````````````````````````````````````\n";
	cout<<"Product code:";
	cin>>pcode;
	cout<<"Name of the product:";
	cin>>pname;
	cout<<"Price of the product:";
	cin>>price;
	cout<<"Discount on product:";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else 
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	if(token==1)
	  goto m;
	else
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}  

	cout<<"\n\n\t\t Record inserted !\n";
	
}


void shopping :: edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code : ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n`````  File doesn't exist!  `````";
		
	}
	else 
	{
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t\tProduct new code :";
				cin>>c;
				cout<<"\n\t\t\tName of the product :";
				cin>>n;
				cout<<"\n\t\t\tPrice";
				cin>>p;
				cout<<"\n\t\t\tDiscount";
				cin>>d;
				
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited\n";
				token++;
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
			
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n ~~~~~~~~  Record not found sorry!  ~~~~~~~~~\n";
		}
		
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\t\tDelete product\n";
	cout<<"\t\tProduct code:";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n`````  File does not exist  ``````\n";
	}
	else 
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully\n";
				token++;
				
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("datbase1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}	
	}
}

void shopping ::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n____________________________________\n";
	cout<<"ProNO\t\tName\t\tPrice\n";
	cout<<"\n\n____________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}
void shopping::receipt()
{
	fstream data;
	
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float totale=0;
	
	
	cout<<"\n\t\t\t RECEIPT\n";
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		cout<<"\n~~~~~~~~  Empty database  ~~~~~~\n";
		
	}
	else
	{
		data.close();
		list();
		cout<<"\n___________________________________\n";
		cout<<"\n         Please place the order          \n";
		cout<<"\n___________________________________\n";
		do
		{
			m:
			cout<<"\n\nEnter product code:";
			cin>>arrc[c];
			cout<<"\n\nEnter  the product quantity :";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate product code.plrase try again  \n";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product ? press y/n \n";
			cin>>choice;
		}
		while(choice=='y');
		system("cls");
		cout<<"\n\n\t\t\t__________RECEIPT______________\n";
		cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";
			
			
		for(int i=0;i<c;i++) 
			{
				data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])   
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						totale =totale+ dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;	
					}
					   data>>pcode>>pname>>price>>dis;  
				}
				data.close();
			}
			cout<<"\n\n\t\t\t----------------------------------------\n";
			cout<<"\n \t\t\tTotal Amount : "<<totale;
		}
	}
int main()
{
	shopping s;
	s.menu();
}














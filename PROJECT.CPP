//Cruise management
#include<dos.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<iomanip.h>
void screen();
char id[10];
int members;

class travdetails
{
	char source[20],destination[20];
	int day,month,year;
	char ticketid[10],phno[10];
	public:
	void details1();
	void display1();
	char *retid();
}t;

char *travdetails :: retid()
{
	return ticketid;
}

void travdetails :: details1()
{
	strcpy(ticketid,id);

	int choice;
	cout<<"\t\tBoarding Point\n";
	cout<<"1.Mumbai\n2.Chennai\n3.Cochin\n";

	while(1)
	{
		cin>>choice;
		if ((choice>=1)&&(choice<=3))
			break;
		else
			cout<<"Invalid input! Please enter again\n";
	}

	switch (choice)
	{
		case 1: strcpy(source,"Mumbai");
		break;
		case 2: strcpy(source,"Chennai");
		break;
		case 3: strcpy(source,"Cochin");
		break;
	}


	cout<<"\t\tSelect Destination\n";
	cout<<"1.New York\t\t2.Dubai\t\t3.Miami\n";
	cout<<"4.Lisbon\t\t5.Cairo\t\t6.London\n";
	cout<<"7.Perth\t\t8.Colombo\t\t9.Sydney\n";
	cout<<"10.Hong Kong\t\t11.Cape Town\t\t12.Wellington\n";

	while(1)
	{
		cin>>choice;
		if ((choice>=1)&&(choice<=12))
			break;
		else
			cout<<"Invalid input! Please enter again\n";
	}
	switch (choice)
	{
		case 1: strcpy(destination,"New York");
		break;
		case 2: strcpy(destination,"Dubai");
		break;
		case 3: strcpy(destination,"Miami");
		break;
		case 4: strcpy(destination,"Lisbon");
		break;
		case 5: strcpy(destination,"Cairo");
		break;
		case 6: strcpy(destination,"London");
		break;
		case 7: strcpy(destination,"Perth");
		break;
		case 8: strcpy(destination,"Colombo");
		break;
		case 9: strcpy(destination,"Sydney");
		break;
		case 10: strcpy(destination,"Hong Kong");
		break;
		case 11: strcpy(destination,"Cape Town");
		break;
		case 12: strcpy(destination,"Wellington");
		break;
	}

	struct date d;
	getdate(&d);


	cout<<"\t\tEnter Date of Departure\n";
	while(1)
	{
		cout<<"Enter year ---> ";
		cin>>year;
		if (year>=(d.da_year)&&year<=2019)
			break;
		else
			cout<<"Invalid year!\n";
	}

	while(1)
	{
		cout<<"Enter month ---> ";
		cin>>month;
		if(year==2019)
		{       if (month>=1&&month<=12)
				break;
			else
				cout<<"Invalid month!\n";
		}
		else if (month>=(d.da_mon)&&month<=12)
			break;
		else
			cout<<"Invalid month!\n";
	}
	while(1)
	{
		cout<<"Enter day ---> ";
		cin>>day;
		int flag=0;
		switch (month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:if (month==d.da_mon)
				{	if(day>=1&&day<=31)
						flag=1;
				}
				else if(day>=(d.da_day)&&day<=31)
					flag=1;
			break;
			case 4:
			case 6:
			case 9:
			case 11:if (month=d.da_mon)
				{	if(day>=1&&day<=30)
						flag=1;
				}
				else if(day>=(d.da_day)&&day<=30)
					flag=1;
			break;
			case 2: if (month==d.da_mon)
				{	if(day>=1&&day<=28)
						flag=1;
				}
				else if(day>=(d.da_day)&&day<=28)
					flag=1;
			break;
		}
		if (flag==1)
			break;
		else
			cout<<"Invalid date!\n";
	}
	while (1)
	{
		cout<<"Phone number : ";
		cin>>phno;
		if (strlen(phno)==10)
			break;
		else
			cout<<"Wrong choice! Please enter agian\n";
	}

}//Function ends




class persdetails
{
	char name1[10],name2[10],sex;
	int age,passport;
	char ticketid[10];

public:
	void details2();
	void display2();
	char *retid();

}p[10];


char *persdetails :: retid()
{
	return ticketid;
}


void persdetails:: details2()
{
	strcpy(ticketid,id);


	cout<<"First name : ";
	gets(name1);
	cout<<"Second name : ";
	gets(name2);
	cout<<"Age : ";
	cin>>age;
	while (1)
	{
		cout<<"Sex (M/F/T) : ";
		cin>>sex;
		if(sex=='M'||sex=='F'||sex=='T')
			break;
		else if(sex=='m'||sex=='f'||sex=='t')
			break;
		else
			cout<<"Wrong choice! Please enter agian\n";
	}

	cout<<"Passport number : ";
	cin>>passport;


}//function ends

void file()
{
	ofstream f1;
	f1.open("Travel.dat",ios::binary|ios::app);
	t.details1();
	f1.write((char *)&t, sizeof(t));

	ofstream f2;
	f2.open("Personal.dat",ios::binary|ios::app);

	cout<<"Enter the no. of people travelling";
	cin>>members;
	clrscr();
	for(int i=0; i<members; ++i)
	{
		cout<<"Enter details of "<<i+1<< " member\n";
		p[i].details2();
	}

	f2.write((char *)&p, sizeof(p));

	f1.close();
	f2.close();




}


void travdetails :: display1()
{
	cout<<"Boarding point : ";
	cout<<source<<endl;
	cout<<"Destination : ";
	cout<<destination<<endl;
	cout<<"Date of journey : ";
	cout<<day<<'/'<<month<<'/'<<year<<endl<<endl;
}


void persdetails :: display2()
{
	cout<<name1<<' '<<name2<<"\t\t"<<age<<"\t\t"<<sex<<"\t\t"<<passport<<endl;
}



class login
{
	char loginid[10];
	char pass[15];
	public:
	void password();
	char *retlogid();
	char *retpass();
};

char *login::retlogid()
{
	return loginid;
}

char *login::retpass()
{
	return pass;
}

void login::password()
{
	cout<<"Enter Username\n";
	gets(loginid);
	strcpy(id,loginid);

	cout<<"\n\t\t\tENTER PASSWORD: ";
	for(int i=0;i<15;i++)
	{
		password:
		pass[i]=getch();
		if(i==0&&pass[i]==13)//enter key's ASCII value is 13
		{
			goto password;
		}
		else
		{
			if(pass[i]==13)
			     break;
			else if(pass[i]=='\b')
			{
			  i--;
			  cout<<"\b \b";//backSPACE
			  goto password;
			}
		}
		cout<<"*";
	}//end of for loop
	pass[i]='\0';
}

void signup()
{
	ofstream fout;
	fout.open("Password.dat",ios::binary|ios::app);
	login l;
	l.password();
	fout.write((char *)&l, sizeof(l));
	fout.close();
}

void signin()
{
	ifstream fin;
//	fin.open("Password.dat",ios::binary);
  //	cout<<"Enter Username : ";
	login l;

	while (1)
	{
		fin.open("Password.dat",ios::binary);
		cout<<"Enter Username : ";
		gets(id);

		int flag=0;



		fin.seekg(0,ios::beg);
		cout<<fin.tellg();
		while (fin.read((char *)&l, sizeof(l)))
		{
			//char *username=l.retlogid();
			if(strcmp(id,l.retlogid())==0)
			{
				flag=1;
				break;
			}
		}

		if (flag==1)
			break;
		else
		{
			cout<<"Username does not exist ! Enter again\n";
			fin.close();
		}
	}

	//use seekg and tellg to to check for corresponding password
	char *passcode=l.retpass();
	char pw[15];
	cout<<"\n\t\t\tENTER PASSWORD: ";
	for(int i=0;i<15;i++)
	{
		password:
		pw[i]=getch();
		if(i==0&&pw[i]==13)//enter key's ASCII value is 13
		{
			goto password;
		}
		else
		{
			if(pw[i]==13)
			     break;
			else if(pw[i]=='\b')
			{
			  i--;
			  cout<<"\b \b";//backSPACE
			  goto password;
			}
		}
		cout<<"*";
	}//end of for loop
	pw[i]='\0';

	if(strcmp(passcode,pw)==0)//condition to check password
	{
	       cout<<"\n\nCORRECT PASSOWRD\n\n";
	}

	else
	{ 	clrscr();
		cout<<"\n\t\t\tWRONG PASSWORD! Try Again!!!\n\t\t\t";
		i=0;
		goto password;
		getch();
	}

}


void bill()
{
	clrscr();
	ifstream f2;
	f2.open("Personal.dat",ios::binary|ios::app);
	persdetails p2;
	cout<<"\t\t\t\t_____Invoice_____\n\n";
	cout<<setw(32)<<"Name\t\t\tAge\t\tsex\t\tPassport no.\n";
	while(f2.read((char *)&p2, sizeof(p2)))
	{
		char *cd=p2.retid();
		if (strcmpi(id,cd)==0)
		{
			p2.display2();
		}
	}

	f2.close();
 cout<<"\n\n\nTotal number of people travelling= "<<members<<endl;
 cout<<"Price of 1 person = Rs 2500\n";
 cout<<"Grand total = Rs "<<2500*members<<endl;
 }


void del()
{
	ifstream f1;
	f1.open("Travel.dat",ios::binary|ios::app);

	ifstream f2;
	f2.open("Personal.dat",ios::binary|ios::app);

	ofstream fout;
	fout.open("temp.dat",ios::binary);

	travdetails t;

	while(f1.read((char*)&t,sizeof(t)))
	{
		if(strcmp(t.retid(),id))
		{
			fout.write((char*)&t,sizeof(t));
		}
	}
	f1.close();
	fout.close();
	remove("Travel.dat");
	rename("temp.dat","Travel.dat");

	fout.open("temp.dat",ios::binary);

	while(f2.read((char*)&p,sizeof(p)))
	{
		if(strcmp(p[0].retid(),id))
		{
			fout.write((char*)&p,sizeof(p));
		}
	}
	f2.close();
	fout.close();
	remove("Personal.dat");
	rename("temp.dat","Personal.dat");

	cout<<"\n\n\t\t\t___Ticekt succefully canceled___\n";
}

void main()
{
	clrscr();
	cout<<"\t\tWelcome To The Cruise Database Management System\n\n";
	cout<<"\t\tPress 1 to sign in\n\n";
	cout<<"\t\tNew here? Press any other key to sign up\n";
	char a;
	cin>>a;
	if (a=='1')
		signin();
	else
		signup();

	clrscr();

	menu:

	cout<<"Please select from the following :\n";
	cout<<"1.New Booking\n2.Manage old booking\n3.Logout\n";
	int choice;
	while(1)
	{
		cin>>choice;
		if ((choice>=1)&&(choice<=3))
			break;
		else
			cout<<"Invalid input ! Please enter again\n";
	}
	switch (choice)
	{
		case 1: file();
			bill();
			cout<<"\n\n\t\t\tPress 1 to go to the main menu\n";
			int go;
			cin>>go;
			if(go==1)
				goto menu;
			else
				exit(1);
		break;
		case 2: cout<<"1.View Ticket\n2.Cancel Ticket\n";
			ifstream f1;
			f1.open("Travel.dat",ios::binary|ios::app);

			ifstream f2;
			f2.open("Personal.dat",ios::binary|ios::app);

			int a;
			while(1)
			{
				cin>>a;
				if ((a>=1)&&(a<=2))
					break;
				else
					cout<<"Invalid input ! Please enter again\n";
			}
			clrscr();

			switch(a)
			{
				case 1:travdetails t2;
					persdetails p2;
					f1.read((char *)&t2,sizeof(t2));
					char *ab=t2.retid();
					if (strcmpi(id,ab)==0)
					{
						t2.display1();
					}
					cout<<setw(32)<<"Name\t\t\tAge\t\tsex\t\tPassport no.\n";
					while(f2.read((char *)&p2, sizeof(p2)))
					{
						char *cd=p2.retid();
						if (strcmpi(id,cd)==0)
						{
							p2.display2();
						}
					}

					f1.close();
					f2.close();
				break;

				case 2:del();
				break;
				}

				cout<<"\n\n\t\t\tPress 1 to go to the main menu\n";
				cin>>go;
				if(go==1)
					goto menu;
				else
					exit(1);
		break;

		case 3: exit(1);
	}
	goto menu;
getch();
}











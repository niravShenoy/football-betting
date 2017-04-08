#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<process.h>
#include<dos.h>

fstream frw;
float fw, fd, fl;

class Team{
	public:
	float w;
	float d;
	float l;
	int code;
	char name[20];

	Team(){};
	Team(float a, float b, float c, int d1, char e[20]){
		w=a;
		d=b;
		l=c;
		code=d1;
		strcpy(name, e);
	}
	void putdata()
	{
		cout<<"\n\nTeam: "<<name;
		cout<<"\n% winning: "<<w;
		cout<<"\n% losing: "<<l;
		cout<<"\n% drawing: "<<d;
	}
} t1, t2, t3, t4, t5, t6;;
Team Club[6]={	Team(68.0, 32.0, 0.0, 1, "Arsenal"),
		Team(63.0, 18.5, 18.5, 2, "Chelsea"),
		Team(39.5, 29.0, 31.5, 3, "Liverpool"),
		Team(34.2, 15.8, 50.0, 4, "Tottenham"),
		Team(21.0, 23.7, 55.3, 5, "Manchester City"),
		Team(18.4, 31.6, 50.0, 6, "Manchester United")};


fstream x1;
//char get;
/*x1.open("Stats.dat", ios::in|ios::out);
while(x1.eof()){
	cin.get(get);
	x1.write((char*)&a, sizeof(a));
	cin.get(get);
	x1.write((char*)&c, sizeof(c));
	cin.get(get);
	x1.write((char*)&l, sizeof(l));
	cin.get(get);
	x1.write((char*)&t, sizeof(t));
	cin.get(get);
	x1.write((char*)&mc, sizeof(mc));
	cin.get(get);
	x1.write((char*)&mu, sizeof(mu));
}
x1.close();  */

class final:public Team{
	int flag;
	int value1[6];
	Team t11, t22;

	public:
	final(){
		flag=0;
	}
	final(float a, float b, float c, int d, char e[20]):Team(a, b, c, d, e){
	}
	int calculate(Team, Team);
	double teamChoose();
	double bet();
}id, calc;

int g=0;

int a1, a2, a3, b1, b2, b3, c1, c2, c3;

double bet();

double final::teamChoose(){    		   //returns amount won
	cout<<'\n';
	int i,j;
	/*
		if(i==0){
			a1=aa;
			b1=b;
		 }
		 if(i==1){
			a2=aa;
			b2=b;
		 }
		 if(i==2){
			a3=aa;
			b3=b;     */

	int aa;	 //Point to code of team
//	int b;
	srand(time(NULL));
	for(i=0;i<6;i++){
		 int check1=0;
		do
		{
		 aa=rand()%6;
		 check1=1;
		 for(j=0;j<i;j++){
			if(aa==value1[j])
			{
				check1=0;
				break;
			}
		 }
		}while(check1==0);
		value1[i]=aa;
	  /*	do
		{
		 b=rand()%6;
		 check2=1;
		 for(j=0;j<i;j++){
			if(b==value2[j])
			{
				check2=0;
				break;
			}
		 }
		}while(check2==0);
		value2[i]=b;      */
	}
	for(i=0;i<6;i++)
	{
		cout<<value1[i]<<"\n";
	}
		 x1.open("Stats.dat", ios::in|ios::out|ios::binary);
		 Team test;
		 char d1[20], d2[20];
		 x1.seekg(0);
		 t1=Club[value1[0]];
		 t2=Club[value1[1]];
		 t3=Club[value1[2]];
		 t4=Club[value1[3]];
		 t5=Club[value1[4]];
		 t6=Club[value1[5]];
		 cout<<"1."<<t1.name<<" vs. "<<t4.name<<"\n";
		 cout<<"2."<<t2.name<<" vs. "<<t5.name<<"\n";
		 cout<<"3."<<t3.name<<" vs. "<<t6.name<<"\n";
	       /*		for(i=0;i<6;i++){
			if(value1[i]==test.code){
				for(j=0;j<i;j++)
				{
					if(value1[i]==value2[j]){
						check2=1;
						break;
					}
				}
				if(check2==0){
					flag++;
					t11=test;
					strcpy(d1,test.name);
					value2[k++]=value1[i];
				}
			}
			else if(value2[i]==test.code){
				for(j=0;j<i;j++)
				{
					if(value2[i]==value3[j]){
						check4=1;
						break;
					}
				}
				if(check4==0){
					flag++;
					t22=test;
					strcpy(d2,test.name);
					value4[l++]=value2[i];
				}
			}
			 cout<<"1."<<d1<<" vs "<<d2;
		 }
		 }while(flag<6);
		 x1.close();           /*

 /*	cout<<"Arsenal"<<" vs "<<"Liverpool"<<'\n';
	cout<<"Chelsea"<<" vs "<<"Manchester United"<<'\n';
	cout<<"Tottenham"<<" vs "<<"Manchester City"<<'\n';    */
	cout<<"\n\n0. Back\n1. Bet!\n2. Recharge Account";
	cout<<"\n\nEnter your option: ";
	int choice;
	double win;
	cin>>choice;
	switch(choice){
		case 0:{
			break;
		}
		case 1:{
			win=bet();
			return win;
		}
		case 2:{
			g=1;
			break;
		}
		default:{
			cout<<"\n\nWrong option. Try again.";
			getch();
		}
	}
	return 0;
}

double final::bet(){
	int amt;
	int ch;
	cout<<"\n\n\n";
	cout<<"Which fixture do you want to bet on? ";
	cin>>ch;
	cout<<"\nEnter amount to bet: ";
	cin>>amt;
/*	Team t1, t2, t3, t4, t5, t6;
	t1=Club[value1[0]];
	t2=Club[value1[1]];
	t3=Club[value1[2]];
	t4=Club[value1[3]];
	t5=Club[value1[4]];
	t6=Club[value1[5]];
	if(a1==1){
		t1=a;
	}
	else if(a1==2){
		t1=c;
	}
	else if(a1==3){
		t1=l;
	}
	else if(a1==4){
		t1=t;
	}
	else if(a1==5){
		t1=mc;
	}
	else if(a1==6){
		t1=mu;
	}
	else if(a2==1){
		t2=a;
	}
	else if(a2==2){
		t2=c;
	}
	else if(a2==3){
		t2=l;
	}
	else if(a2==4){
		t2=t;
	}
	else if(a2==5){
		t2=mc;
	}
	else if(a2==6){
		t2=mu;
	}
	else if(b1==1){
		t4=a;
	}
	else if(b1==2){
		t4=c;
	}
	else if(b1==3){
		t4=l;
	}
	else if(b1==4){
		t4=t;
	}
	else if(b1==5){
		t4=mc;
	}
	else if(b1==6){
		t4=mu;
	}
	else if(b2==1){
		t5=a;
	}
	else if(b2==2){
		t5=c;
	}
	else if(b2==3){
		t5=l;
	}
	else if(b2==4){
		t5=t;
	}
	else if(b2==5){
		t5=mc;
	}
	else if(b2==6){
		t5=mu;
	}
	else if(a3==1){
		t3=a;
	}
	else if(a3==2){
		t3=c;
	}
	else if(a3==3){
		t3=l;
	}
	else if(a3==4){
		t3=t;
	}
	else if(a3==5){
		t3=mc;
	}
	else if(a3==6){
		t3=mu;
	}
	else if(b3==1){
		t6=a;
	}
	else if(b3==2){
		t6=c;
	}
	else if(b3==3){
		t6=l;
	}
	else if(b3==4){
		t6=t;
	}
	else if(b3==5){
		t6=mc;
	}
	else if(b3==6){
		t6=mu;
	} */
	int result;
	double win;  		//Profit or loss
	switch(ch){
		case 1:{
			cout<<"\n\nWhich team?\n1. "<<t1.name<<"\n2. "<<t4.name<<"\n\n";
			int tc;
			cin>>tc;
			result=calc.calculate(t1, t4);
			clrscr();
			cout<<"Game In Progress...";
			delay(2000);
			if(t1.w>t4.w){
				if(result==1){
					clrscr();
					cout<<"The winner is "<<t1.name<<"!";
					if(tc==1){
						fl=t4.w;
						cout<<"\nYour bet was on "<<t1.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fw=t1.w;
					cout<<"\nYour bet was on "<<t4.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
				else if(result==2){
					clrscr();
					cout<<"It's a draw!";
					if(tc==1){
						fd=t1.d;
						cout<<"\nYour bet was on "<<t1.name;
						win=(fd/100)*amt;
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fd=t4.d;
					cout<<"\nYour bet was on "<<t4.name;
					win=(fd/100)*amt;
					cout<<"\nYou have won  $"<<win;
					getch();
					return win;
					}
				}
				else if(result==3){
					clrscr();
					cout<<"The winner is "<<t4.name<<"!";
					if(tc==2){
						fl=t1.w;
						cout<<"\nYour bet was on "<<t4.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==1){
					fw=t4.w;
					cout<<"\nYour bet was on "<<t1.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
			}
			else{
				if(result==1){
					clrscr();
					cout<<"The winner is "<<t4.name<<"!";
					if(tc==2){
						fl=t1.w;
						cout<<"\nYour bet was on "<<t4.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==1){
					fw=t4.w;
					cout<<"\nYour bet was on "<<t1.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
				else if(result==2){
					clrscr();
					cout<<"It's a draw!";
					if(tc==1){
						fd=t1.d;
						cout<<"\nYour bet was on "<<t1.name;
						win=(fd/100)*amt;
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fd=t4.d;
					cout<<"\nYour bet was on "<<t4.name;
					win=(fd/100)*amt;
					cout<<"\nYou have won  $"<<win;
					getch();
					return win;
					}
				}
				else if(result==3){
					clrscr();
					cout<<"The winner is "<<t1.name<<"!";
					if(tc==1){
						fl=t4.w;
						cout<<"\nYour bet was on "<<t1.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fw=t1.w;
					cout<<"\nYour bet was on "<<t4.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
			}
		}
		case 2:{
			cout<<"\n\nWhich team?\n1. "<<t2.name<<"\n2. "<<t5.name<<"\n";
			int tc;
			cin>>tc;
			result=calc.calculate(t2, t5);
			clrscr();
			cout<<"Game In Progress...";
			delay(2000);
			if(t2.w>t5.w){
				if(result==1){
					clrscr();
					cout<<"The winner is "<<t2.name<<"!";
					if(tc==1){
						fl=t5.w;
						cout<<"\nYour bet was on "<<t2.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fw=t2.w;
					cout<<"\nYour bet was on "<<t5.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
				else if(result==2){
				clrscr();
					cout<<"It's a draw!";
					if(tc==1){
						fd=t2.d;
						cout<<"\nYour bet was on "<<t2.name;
						win=(fd/100)*amt;
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fd=t5.d;
					cout<<"\nYour bet was on "<<t5.name;
					win=(fd/100)*amt;
					cout<<"\nYou have won  $"<<win;
					getch();
					return win;
					}
				}
				else if(result==3){
					clrscr();
					cout<<"The winner is "<<t5.name<<"!";
					if(tc==2){
						fl=t2.w;
						cout<<"\nYour bet was on "<<t5.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==1){
					fw=t5.w;
					cout<<"\nYour bet was on "<<t2.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
			}
			else{
				if(result==1){
					clrscr();
					cout<<"The winner is "<<t5.name<<"!";
					if(tc==2){
						fl=t2.w;
						cout<<"\nYour bet was on "<<t5.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==1){
					fw=t5.w;
					cout<<"\nYour bet was on "<<t2.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}

				}
				else if(result==2){
					clrscr();
					cout<<"It's a draw!";
					if(tc==1){
						fd=t2.d;
						cout<<"\nYour bet was on "<<t2.name;
						win=(fd/100)*amt;
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fd=t5.d;
					cout<<"\nYour bet was on "<<t5.name;
					win=(fd/100)*amt;
					cout<<"\nYou have won  $"<<win;
					getch();
					return win;
					}
				}
				else if(result==3){
					clrscr();
					cout<<"The winner is "<<t2.name<<"!";
					if(tc==1){
						fl=t5.w;
						cout<<"\nYour bet was on "<<t2.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fw=t2.w;
					cout<<"\nYour bet was on "<<t5.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
			 }
		}
		case 3:{
			cout<<"\n\nWhich team?\n1. "<<t3.name<<"\n2. "<<t6.name<<"\n";
			int tc;
			cin>>tc;
			result=calc.calculate(t3, t6);
			clrscr();
			cout<<"Game In Progress...";
			delay(2000);
			if(t3.w>t6.w){
				if(result==1){
					clrscr();
					cout<<"The winner is "<<t3.name<<"!";
					if(tc==1){
						fl=t6.w;
						cout<<"\nYour bet was on "<<t3.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fw=t3.w;
					cout<<"\nYour bet was on "<<t6.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
				else if(result==2){
				clrscr();
					cout<<"It's a draw!";
					if(tc==1){
						fd=t3.d;
						cout<<"\nYour bet was on "<<t3.name;
						win=(fd/100)*amt;
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fd=t6.d;
					cout<<"\nYour bet was on "<<t6.name;
					win=(fd/100)*amt;
					cout<<"\nYou have won  $"<<win;
					getch();
					return win;
					}
				}
				else if(result==3){
					clrscr();
					cout<<"The winner is "<<t6.name<<"!";
					if(tc==2){
						fl=t3.w;
						cout<<"\nYour bet was on "<<t6.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==1){
					fw=t6.w;
					cout<<"\nYour bet was on "<<t3.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
			}
			else{
				if(result==1){
					clrscr();
					cout<<"The winner is "<<t6.name<<"!";
					if(tc==2){
						fl=t3.w;
						cout<<"\nYour bet was on "<<t6.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==1){
					fw=t6.w;
					cout<<"\nYour bet was on "<<t3.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
				else if(result==2){
					clrscr();
					cout<<"It's a draw!";
					if(tc==1){
						fd=t3.d;
						cout<<"\nYour bet was on "<<t3.name;
						win=(fd/100)*amt;
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fd=t6.d;
					cout<<"\nYour bet was on "<<t6.name;
					win=(fd/100)*amt;
					cout<<"\nYou have won  $"<<win;
					getch();
					return win;
					}
				}
				else if(result==3){
					clrscr();
					cout<<"The winner is "<<t3.name<<"!";
					if(tc==1){
						fl=t6.w;
						cout<<"\nYour bet was on "<<t3.name;
						win=(fl/100)*amt;
						cout<<"\nYou have won!";
						cout<<"\nYou have won  $"<<win;
						getch();
						return win;
					}
					else if(tc==2){
					fw=t3.w;
					cout<<"\nYour bet was on "<<t6.name;
					win=-(fw/100)*amt;
					cout<<"\nYou have lost!";
					cout<<"\nYou have lost  $"<<-win;
					getch();
					return win;
					}
				}
			}
		}
	}
	return 0;
}

int final::calculate(Team t1, Team t2){
	float x, y, z, t, a, b, c, p, q, r, s;
	//Nirav theorem of weighted probability.
	x=t1.w*t2.l;
	x/=100;
	y=t2.w*t1.l;
	y/=100;
	z=t1.d+t2.d;
	z/=100;
	t=100-(x+y+z);
	s=x+y+z;
	a=x*t;
	a/=s;
	b=y*t;
	b/=s;
	c=z*t;
	c/=s;
	p=x+a;
	q=y+b;
	r=z+c;
	p=(int)p;       //Win
	q=(int)q;       //Draw
	r=(int)r;       //Lose (Mostly United)
	fw=p;
	fd=q;
	fl=r;
	//cout<<"\n\n\n"<<p<<"   "<<q<<"   "<<r;
	q+=p;
	r+=q;
	/*struct Node{
		int num;
		char info;
		Node *next;
	}*start, *newptr, *save, *ptr;

	//Node *create(int);
	void insert(Node*);

	Node *create(char n, int v){
		ptr=new Node;
		ptr->info=n;
		ptr->num=v;
		ptr->next=NULL;
		return ptr;
	}

	void insert(Node *np){
		if(start==NULL){
			start=np;
		}
		else{
			save=start;
			start=np;
			np=np->next;
		}
	}
	for(int i=0;i<p;i++){
		newptr=create('w', (i+1));
		insert(newptr);
	}
	for(;i<p+q;i++){
		newptr=create('d', (i+1));
		insert(newptr);
	}
	for(;i<p+q+r;i++){
		newptr=create('l', (i+1));
		insert(newptr);
	}       */

	int res=0;
	int i=1;
	int d=2;
	int w=3;
	//randomise a number between 1 and 99. res = this number.
	randomize();
	res=rand() % 100 + 1;
	//cout<<"\n\n\n"<<res;
	//getch();
	if(res<=p){
		return i;             //Win
	}
	else if(res<=q){
		return d;	      //Draw
	}
	else{
		return w;	      //Lose
	}
	return 0;
}


class account{
	public:
	char ID[20];
	char pass[20];
	char ccNo[10];
	double balance;
	char name[50];
	account(){
		balance=10000;
	}

	void signUp();
	int signIn();
	void recharge();
	double getBalance(){
		return balance;
	}
	void updateBalance(double win){
		balance+=win;
	}
}info, log, test;

void account::signUp(){
	clrscr();
	char ch;
	int flag=0;
	cin.get(ch);
	cout<<"Enter Name: ";
	cin>>name;
	account test;
	fstream llb;
	llb.open("DB.dat", ios::in|ios::out|ios::binary);
	do{
		cout<<"\nEnter desired username: ";
		cin>>ID;
		while(llb){
			llb.read((char*)&test, sizeof(test));
			if(strcmp(test.ID, ID)==0){
				flag=1;
				break;
			}
			else{
				flag=0;
			}
			if(frw.eof()){
				break;
			}
		}
		if(flag==1){
		cout<<"\n\nSorry username taken!";
		}
	}while(flag==1);
	cout<<"\nEnter password: ";
	cin>>pass;
	int b=0;
	char c[20];
	do{
		cout<<"\nRe-enter password: ";
		cin>>c;
		if(strcmp(c, pass)==0){
			b=1;
		}
		else{
		cout<<"\n\nPasswords don't match!";
		}
	}while(b==0);
	cout<<"\nEnter credit card number: ";
	cin>>ccNo;
	cout<<"\n\nSign up successful!";
	getch();
	llb.close();
}

int account::signIn(){
	clrscr();
	char a[20];
	char b[20];
	account see;
	fstream ppg;
	cout<<"Username: ";
	cin>>a;
	cout<<"\nPassword: ";
	cin>>b;
	int flag=0;
	ppg.open("DB.dat", ios::in|ios::out|ios::binary);
	ppg.seekg(0);
	while(!ppg.eof()){
		ppg.read((char*)&see, sizeof(see));
		if(((strcmp(see.ID, a)==0)&&(strcmp(see.pass, b)==0))){
			flag=1;
			log=see;
			break;
		}
		if(ppg.eof()){
			break;
		}
	}
	ppg.close();
	if(flag==0){
		cout<<"\nIncorrect username or password. Please try again.";
		getch();
		clrscr();
		info.signIn();
	}
	if(flag){
		return 1;
	}
	return 0;
}

void account::recharge(){
	clrscr();
	cout<<"Your current balance is: ";
	int bal=this->getBalance();
	cout<<bal;
	cout<<"\nEnter amount to recharge: ";
	double rec;
	cin>>rec;
	this->updateBalance(rec);
	cout<<"\nAccount succesfully recharged!";
	cout<<"\nYour balance is now: ";
	bal=this->getBalance();
	cout<<bal;
	getch();
}

void logoPrint(){
	cout<<"\n\n";
	cout<<"\t||||||||    ||||||||||  ||||||||||||   ||||||||   ||||||||  ||||||||	\n";
	cout<<"\t|||   |||   |||             |||             |||   |||	    |||		\n";
	cout<<"\t|||  |||    |||             |||             |||   |||	    |||		\n";
	cout<<"\t|||||||     ||||||||||      |||          ||||||   ||||||||  ||||||||	\n";
	cout<<"\t|||  |||    |||             |||             |||   |||  |||  |||  |||	\n";
	cout<<"\t|||   |||   |||             |||             |||   |||  |||  |||  |||	\n";
	cout<<"\t||||||||    ||||||||||      |||        ||||||||   ||||||||  ||||||||	\n";
	cout<<"\n\n";
}


void main(){
	int opt, check=0,signIn;
	double win;
	fstream ffs;
	do{
		clrscr();
		logoPrint();
		cout<<"1. Sign up\n2. Sign in";
		cout<<"\n\nEnter your option: ";
		cin>>opt;
		switch(opt){
			case 1:{
				info.signUp();
				ffs.open("DB.dat", ios::in|ios::out|ios::binary|ios::ate);
				ffs.write((char*)&info, sizeof(info));
				ffs.close();
				clrscr();
				break;
			}
			case 2:{
				signIn=info.signIn();
				check=1;
				break;
			}
		}
	}while (opt!=2);
	if(check==1){
		clrscr();
		Team test;
		x1.open("Stats.dat", ios::in|ios::out|ios::binary|ios::noreplace);
		for(int i=0;i<6;i++)
		{
			x1.write((char*)&Club[i],sizeof(Club[i]));
		}
	   //     x1.close();
		clrscr();
	   //	x1.open("Stats.dat", ios::in|ios::out|ios::binary);
		x1.seekg(0);
		/*cout<<"Details of the club:\n";
		for(i=0;i<6;i++){
			x1.read((char*)&Club[i], sizeof(Club[i]));
			Club[i].putdata();
		}
		delay(1000);*/
		x1.close();
		int opti=1;
		double upd=10000;
		if(log.getBalance()!=10000){
			log.updateBalance(upd);
		}
		do{
			clrscr();
			logoPrint();
			cout<<"\n\nWelcome "<<log.name<<"!";
			cout<<" Your account balance is "<<log.getBalance();
			cout<<"\n\n1. See fixtures\n2. Logout";
			cout<<"\n\nEnter your option: ";
			cin>>opti;
			switch(opti){
				case 1:{
					cout<<"\n\nToday's fixtures are:\n";
					win=id.teamChoose();
					log.updateBalance(win);
					if(g==1){
						log.recharge();
						g=0;
					}
					break;
				}
				case 2:{
					exit(-1);
				}
				default:{
					clrscr();
					cout<<"Please enter a valid option";
				}
			}
		}while (opti==1);
	}
}
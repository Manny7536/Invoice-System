
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Software{
private:
    string password;
protected:
    char Pname[100];
    int Pcode;
    char Psize[10];
    double Pprice;
    float Ptax;
    long long int Numb;
    char name[50];
public:
    void Run(){
    int option;
string password;
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\t\t\t\t\t\t\t\t\t HIPPO MART FERGUSON \t\t \n";
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<" Welcome To system log In. Select an option. \n";
cout<<"\n"<<endl;
cout<<"\n"<<endl;
cout<<"\t1)   Admin\n";
cout<<"\n"<<endl;
cout<<"\t2)   User 1\n";
cout<<"\n"<<endl;
cout<<"\t3)   User 2\n";
cout<<"\n"<<endl;
cout<<"\t4)   Exit\n"<<endl;
cout<<"\n"<<endl;
cin>>option;
cout<<"\n"<<endl;

    switch(option){

case 1:
    cout<<"Enter Admin Password:\t";
    cin>>password;

    if(password == "Admin"){
        Admin();
        cout<<"\n";
    }
    else {
        cout<<"\n ****Incorrect Password****"<<endl;
        cout<<"    Try Again !!!\n";
        Run();
    }
    break;

case 2:

    cout<<"Enter User1 Password:\t";
    cin>>password;


    if(password == "User"){
        User1();
        cout<<"\n";
    }
    else {
        cout<<"\n ****Incorrect Password****"<<endl;
        cout<<"    Try Again !!!\n";
        Run();
    }
    break;
case 3:

    cout<<"Enter User2 Password:\t";
    cin>>password;

    if(password == "Users"){
        User2();
        cout<<"\n";
    }
    else {
        cout<<"\n ****Incorrect Password****"<<endl;
        cout<<"    Try Again !!!";

    break;
}
case 4:
    exit(0);
    break;

default:
    cout<<"Invalid Selection\n";
    Run();
    }
    }
    void Admin();
    void User1();
    void User2();
    void Sales();
    void SalesReturn();
    void PrintInvoice();
    void inventory();
    void salessummary();
    void producttype();
    void Viewinventory();
    void addBeerWine();
    void addGrocery();
    void editinventory();
    void Deleteinventory();
    void Display(){

cout<<"\t"<<Pcode<<"\t\t"<<Pname<<"\t\t\t\t"<<Psize<<"\t\t\t"<<Pprice<<".00\t\t"<<Ptax<<"%"<<endl;

    }
};
class Customer:public Software{
public:
void display(){
cout<<"\t\tCustomer Name:\t"<<name<<"\n";
cout<<"\t\tCustomer Phone Number:\t"<<Numb<<"\n";
}
void CustomerData(){

  ofstream data;
  Customer x;
  cout<<"Insert Record\n";
  data.open("Cinfo.txt",ios::app|ios::binary);
  cout<<"Enter Customer Phone Number: ";
  cin>>x.Numb;
  cout<<"Enter Customer Name: ";
   cin.ignore(1);
    cin.getline(x.name,50);
  data.seekp(0,ios::beg); //go to start
  data.write((char*)&x,sizeof(x));
  data.close();
  cout<<"\n\n\tCustomer Information saved successfully...\n";
  Admin();
}
void CustomerInformation (){
fstream file;
    Customer x;
    file.open("Cinfo.txt",ios::binary|ios::in);
    if(!file){
        cout<<"ERROR IN OPENING FILE \n";
        return;
    }
    while(file){
    if(file.read((char*)&x,sizeof(x)))
    cout<<"\n"<<endl;
       x.display();
    }
  file.close();
  Admin();
}
};
void Software::Admin(){
int Option;
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\t\t\t\t\t\t\t\tHIPPO MART FERGUSON (ADMIN PANEL)\t\t \n";
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\n"<<endl;
cout<<" Hi There, Select an option To Proceed. \n";
cout<<"\n"<<endl;
cout<<"     1)\t Inventory \n"<<endl;
cout<<"\n"<<endl;
cout<<"     2)\t View Customer Data \n"<<endl;
cout<<"\n"<<endl;
cout<<"     3)\t Sales Summary\n"<<endl;
cout<<"\n"<<endl;
cout<<"     4)\t Return to Main Menu\n"<<endl;
cout<<"\n"<<endl;
cin>>Option;
switch (Option) {
        case 1: {
            inventory();
            break;
        }
        case 2: {
            Customer j;
            j.CustomerInformation();
            break;
        }

         case 3: {
            salessummary();
            break;
        }
         case 4: {
            Run();
            break;
        }
        default:
            cout << "Invalid Selection Try Again\n"<<endl;
            Admin();
        }
}
void Software::User1(){

int Option;
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\t\t\t\t\t\t\t\tHIPPO MART FERGUSON (USER 1)\t\t \n";
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\n"<<endl;
cout<<" Hi There, Select an option To Proceed. \n";
cout<<"\n"<<endl;
cout<<"     1)\t Sales\n"<<endl;
cout<<"\n"<<endl;
cout<<"     2)\t Sales Return\n"<<endl;
cout<<"\n"<<endl;
cout<<"     3)\t Print Invoice\n"<<endl;
cout<<"\n"<<endl;
cout<<"     4)\t Add Customer Information\n"<<endl;
cout<<"\n"<<endl;
cout<<"     5)\t Return to Main Menu\n"<<endl;
cout<<"\n"<<endl;
cin>>Option;
switch (Option) {
        case 1: {
            Sales();
            break;
        }
        case 2: {
            SalesReturn();
            break;
        }
        case 3: {
            PrintInvoice();
            break;
        }
         case 4: {
            Customer d;
            d.CustomerData();
            break;
        }
         case 5: {
            Run();
            break;
        }
        default:
            cout << "invalid choice\n"<<endl;
            User1();
        }
}
void Software::Sales(){

 Software x;
 char Choice;
 double d,f,t,Total=0.0;
 double z[32];
 double c[32];
 double tax, tamount;
 long long int N;
int i=1;

 int found=0;
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"\tITEM CODE\tDESCRIPTION                   Variable      \t\tPrice           Tax\n";
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        fstream file;
    file.open("product.txt",ios::binary|ios::in);
    if(!file){
        cout<<"ERROR IN OPENING FILE \n";
        return;
    }
    while(file){
    if(file.read((char*)&x,sizeof(x)))
       x.Display();
    }
  file.close();
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"\n"<<endl;
cout<<"\t\t>>>>>>>>>>>>>>>>>>>>>>>>>    CREATE NEW SALE    <<<<<<<<<<<<<<<<<<<<<<<<<\t\n";
cout<<"\n"<<endl;
    Customer k;
    fstream in;
    in.open("Cinfo.txt",ios::binary|ios::in);
    cout<<"\t\tEnter Phone Number:\t";
    cin>>N;
    cout<<"\n";
    cout<<"\n";

    while(in.read((char*)&k,sizeof(Customer)))
    {


	  	 if(N==k.Numb){
	  	    cout<<"\t\tMember Record  !!\n";
	  	    cout<<"\n";
	  	    k.display();
	  	  found=1;
	  	 }
	  	 else
         {
          cout<<"\t\tNo Customer Recored Found\n";
         }
         in.close();
    }

  do {
cout<<"\n"<<endl;
cout<<"\t\tEnter Product Code to Add Item:\t";
cin>>z[i];
cout<<"\t\tEnter Product Quantity:\t";
cin>>c[i];
cout<<"\t\tAdd More Item [Y/N]:\t";
cin>>Choice;
cout<<"\n";
cout<<"\n";
cout<<"\n";
i++;
}
while(Choice=='y');

std::fstream filee("Product.txt", std::ios::binary | std::ios::in);
if (!filee) {
        std::cout << "ERROR IN OPENING FILE\n";
        return ; // Exit with an error code
    }
    filee.seekg(0, std::ios::beg);

   Software p;
    while (filee.read((char*)&p, sizeof(p))) {
        for (int j = 0; j < i; ++j) {
            if (z[j] == p.Pcode) {
                for (int h = 0; h < c[j]; h++) {
                    // Output product details
                    std::cout << "\t\t" << p.Pcode << "  " << p.Pname << "  " << p.Psize << "  " << p.Pprice << "  " << p.Ptax << "\n";
                }
                // Calculate cost for this product and add to total
                double Cost = p.Pprice * c[j];
                Total += Cost;
            }
        }
    }
filee.close();


                cout<<"\n";
	  	    tax=Total*6.25/100;
	  	    tamount=tax+Total;
	  	    cout<<"\t\tSUBTOTAL\t= "<<Total;
	  	    cout<<"\n";
	  	    cout<<"\t\tTAX\t\t= "<<tax;
	  	    cout<<"\n";
	  	    cout<<"\t\tTOTAL\t\t= "<<tamount;
	  	    cout<<"\n";
	  	    cout<<"\t\tCash Tend\t=  " ;
	  	    cin>>f;
	  	    cout<<"\n";
	  	    t=f-tamount;
	  	    cout<<"\t\tChange Due=\t"<<t;


	  	  found=1;
	  	 }
void Software::SalesReturn(){

cout<<"working on it";

}
void Software::PrintInvoice(){

cout<<"working on it";
}
void Software::User2(){


int Option;
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\t\t\t\t\t\t\t\tHIPPO MART FERGUSON (USER 2)\t\t \n";
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\n"<<endl;
cout<<" Hi There, Select an option To Proceed. \n";
cout<<"\n"<<endl;
cout<<"     1)\t Sales\n"<<endl;
cout<<"\n"<<endl;
cout<<"     2)\t Sales Return\n"<<endl;
cout<<"\n"<<endl;
cout<<"     3)\t Print Invoice\n"<<endl;
cout<<"\n"<<endl;
cout<<"     4)\t Add Customer Information\n"<<endl;
cout<<"\n"<<endl;
cout<<"     5)\t Return to Main Menu\n"<<endl;
cout<<"\n"<<endl;
cin>>Option;
switch (Option) {
        case 1: {
            Sales();
            break;
        }
        case 2: {
            SalesReturn();
            break;
        }
        case 3: {
            PrintInvoice();
            break;
        }
         case 4: {
            Customer d;
            d.CustomerData();
            break;
        }
         case 5: {
            Run();
            break;
        }
        default:
            cout << "invalid choice\n"<<endl;
            User2();
        }
}
void Software::inventory(){

    int Option;
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\t\t\t\t\t\t\t\t\tINVENTORY MANAGEMENT \t\t \n";
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\n"<<endl;
cout<<" Hi There, Select an option To Proceed. \n";
cout<<"\n"<<endl;
cout<<"     1)\t Add New Product \n"<<endl;
cout<<"\n"<<endl;
cout<<"     2)\t Update Product \n"<<endl;
cout<<"\n"<<endl;
cout<<"     3)\t Delete Product \n"<<endl;
cout<<"\n"<<endl;
cout<<"     4)\t View Inventory \n"<<endl;
cout<<"\n"<<endl;
cout<<"     5)\t Return to Main Menu\n"<<endl;
cout<<"\n"<<endl;
cin>>Option;
switch (Option) {
        case 1: {
            producttype();
            break;
        }
        case 2: {
            editinventory();
            break;
        }
        case 3: {
            Deleteinventory();
            break;
        }
         case 4: {
            Viewinventory();
            break;
        }
         case 5: {
            Admin();
            break;
        }

        default:
            cout << "invalid choice";
        }
}
void Software::producttype(){
    int a;
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\t\t\t\t\t\t\t\t\tINVENTORY MANAGEMENT \t\t \n";
cout<<"____________________________________________________________________________________________________________________________________________________________________________\n";
cout<<"\n"<<endl;
cout<<" Hi There, Select a Departmen To Add New Product. \n";
cout<<"\n"<<endl;
cout<<"     1)\t Beer & Wine \n"<<endl;
cout<<"\n"<<endl;
cout<<"     2)\t Grocery \n"<<endl;
cout<<"\n"<<endl;
cout<<"     3)\t Return To Main Menu \n"<<endl;
cout<<"\n"<<endl;
cin>>a;
switch(a)
{
        case 1:
            {
            addBeerWine();
            break;
        }
        case 2: {
            addGrocery();
            break;
        }
        case 3: {
            inventory();
            break;
        }
        default:
            cout << "invalid choice";
        }
};
void Software::addBeerWine(){
ofstream fout;
  Software s;
  cout<<"Enter Product Code:\t";
  cin>>s.Pcode;
  cout<<"Enter Product Name:\t";
  cin.ignore(1);
  cin.getline(s.Pname,100);
  cout<<"Enter Product Size:\t"<<endl;
  cin.ignore(0);
  cin.getline(s.Psize,10);
  cout<<"Enter Product Price:\t"<<endl;
  cin>>s.Pprice;
  cout<<"Enter Product Tax Rate:\t"<<endl;
  cin>>s.Ptax;
  fout.open("product.txt",ios::app|ios::binary);
  fout.seekp(0,ios::beg); //go to start
  fout.write((char*)&s,sizeof(s));
  fout.close();
  cout<<"\tItem Added successfully...\n"<<endl;
  inventory();
}
void Software::addGrocery(){

  ofstream fout;
  Software s;
  cout<<"Enter Product Code:\t";
  cin>>s.Pcode;
  cout<<"Enter Product Name:\t";
  cin.ignore(1);
  cin.getline(s.Pname,100);
  cout<<"Enter Product Size:\t"<<endl;
   cin.ignore(0);
  cin.getline(s.Psize,10);
  cout<<"Enter Product Price:\t"<<endl;
  cin>>s.Pprice;
  cout<<"Enter Product Tax Rate:\t"<<endl;
  cin>>s.Ptax;
  fout.open("product.txt",ios::app|ios::binary);
  fout.seekp(0,ios::beg); //go to start
  fout.write((char*)&s,sizeof(s));
  fout.close();
  cout<<"\t Item Added successfully...\n"<<endl;
  inventory();
}
void Software::salessummary(){

cout<<"working on it";
}
void Software::Viewinventory(){

        Software x;
        fstream file;
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"\tITEM CODE\tDESCRIPTION                   Variable      \t\tPrice           Tax\n";
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    file.open("product.txt",ios::binary|ios::in);
    if(!file){
        cout<<"ERROR IN OPENING FILE \n";
        return;
    }
    while(file){
    if(file.read((char*)&x,sizeof(x)))
       x.Display();
    }
  file.close();
  cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
  inventory();
}
void Software::editinventory(){

 int code;
    int found = 0;
    Software s;
    ofstream fout("temp.txt", ios::binary);
    ifstream fin("product.txt", ios::binary);

    cout << "\n Enter Product Code To Update: ";
    cin >> code;

    while (fin.read((char*)&s, sizeof(Software)))
    {
        if (code == s.Pcode)
        {
            found = 1;
            cout << "Enter Product Code:\t";
            cin >> s.Pcode;
            cout << "Enter Product Name:\t";
            cin.ignore(1);
            cin.getline(s.Pname, 100);
            cout << "Enter Product Size:\t";
            cin.ignore(1);
            cin.getline(s.Psize, 10);
            cout << "Enter Product Price:\t";
            cin >> s.Pprice;
            cout << "Enter Product Tax Rate:\t";
            cin >> s.Ptax;
        }
        fout.write((char*)&s, sizeof(Software));
    }

    fin.close();
    fout.close();

    remove("product.txt");
    rename("temp.txt", "product.txt");

    if (found != 0)
        cout << "\n Product Updated Sucessfully....\n";
    else
        cout << "\n Record does not exist...\n";
        inventory();
}
void Software::Deleteinventory(){
 int code;
	int found=0;
	Software s;
	ofstream fout("temp.txt",ios::binary);
	ifstream fin ("product.txt",ios::binary);
	cout<<"\n Enter Product Code To Delete Item  :";
	cin>>code;
	while(fin.read((char*)&s,sizeof(Software)))
	  {
	  	 if(code!=s.Pcode){
	  	    fout.write((char*)&s,sizeof(Software));
	  	  found=1;

	  	 }

	  }
	fin.close();
	fout.close();
	remove("product.txt");
	rename("temp.txt","product.txt");
	if(found!=0)
		cout<<"\n Product Removed From Inventory Sucessfully....\n"<<endl;
	else
		cout<<"\n Record does not exist...\n";
		inventory();
}

int main(){

Software I;
I.Run();

return 0;
}

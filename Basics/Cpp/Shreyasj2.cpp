#include <iostream>
#include <string>
using namespace std;
int i;
int pos;
int size;
class Toothpaste_supplier // class declaration
{
private:
  string customer_name; // private data members of class
  int customer_age;
  long int customer_mobile_no;
  string brand;
  string customer_email;
  string customer_address;

public:
  void read_the_data() // member function to read data
  {
    cout << "\nENTER THE NAME :";
    cin >> customer_name;
    cout << "ENTER THE AGE :";
    cin >> customer_age;
    cout << "ENTER THE MOBILE NUMBER :";
    cin >> customer_mobile_no;
    cout << "ENTER THE TOOTHPASTE BRAND NAME :";
    cin >> brand;
    cout << "ENTER THE EMAIL ID :";
    cin >> customer_email;
    cout << "ENTER THE ADDRESS :";
    cin >> customer_address;
  }

  void display_the_data() // member function to display data
  {
    cout << "\nNAME :" << customer_name << endl;
    cout << "AGE :" << customer_age << endl;
    cout << "MOBILE NUMBER :" << customer_mobile_no << endl;
    cout << "TOOTHPASTE BRAND :" << brand << endl;
    cout << "EMAIL ID :" << customer_email << endl;
    cout << "ADDRESS :" << customer_address << endl;
  }

  void insert_item(); // member function declaration
  void delete_item();
  void update();
};

void Toothpaste_supplier ::insert_item() // member function initalization outside the class
{
  read_the_data();
}

void Toothpaste_supplier ::delete_item() // mmber function to delete data
{
  customer_name = " ";
  customer_age = 0;
  customer_mobile_no = 0;
  brand = " ";
  customer_email = " ";
  customer_address = " ";
}

void Toothpaste_supplier ::update() // member function to update data
{
  cout << "\nENTER THE NEW NAME :";
  cin >> customer_name;
  cout << "ENTER THE NEW AGE :";
  cin >> customer_age;
  cout << "ENTER THE NEW MOBILE NUMBER :";
  cin >> customer_mobile_no;
  cout << "ENTER THE TOOTHPASTE BRAND NAME : ";
  cin >> brand;
  cout << "ENTER THE NEW EMAIL ID :";
  cin >> customer_email;
  cout << "ENTER THENEW  ADDRESS :";
  cin >> customer_address;
}

int main()
{
  int choice, size;
  Toothpaste_supplier obj[5]; // array of object creation
  cout << "ENTER THE NUMBER OF CUSTOMER DETAILS YOU WANT TO ADD : ";
  cin >> size;
  cout << "ENTER " << size << " CUSTOMERS DETAILS: " << endl;
  for (i = 0; i < size; i++)
    obj[i].read_the_data();

  cout << "\nDISPLAY THE DETAILS";
  for (i = 0; i < size; i++)
    obj[i].display_the_data();

  cout << "\n1.INSERT DETAILS" << endl
       << "2.DELETE DETAILS " << endl
       << "3.UPDATE DETAILS" << endl
       << "0.EXIT";
  cout << "\nENTER YOUR CHOICE: ";
  cin >> choice;
  while (choice != 0)
  {
    if (choice == 1)
    {
      cout << "\n ENTER THE POSTION YOU WANT TO INSERT DATA: ";
      cin >> pos;
      size++;
      for (i = size; i >= pos; i--)
        obj[i] = obj[i - 1];
      obj[pos - 1].insert_item();
      cout << "DISPLAY DETAILS AFTER INSERTING NEW DATA";
      for (i = 0; i < size; i++)
        obj[i].display_the_data();
    }

    else if (choice == 2)
    {
      cout << "\n ENTER THE POSTION YOU WANT TO DELETE THE DATA: ";
      cin >> pos;
      obj[pos - 1].delete_item();
      for (i = pos - 1; i < size + 1; i++)
        obj[i] = obj[i + 1];
      cout << "\nDISPLAY DETAILS AFTER DELETING DATA";
      for (i = 0; i < size; i++)
        obj[i].display_the_data();
    }

    else if (choice == 3)
    {
      cout << "\n ENTER THE POSTION YOU WANT TO UPDATE DATA: ";
      cin >> pos;
      obj[pos - 1].update();
      cout << "\nDISPLAY DETAILS AFTER UPDATING NEW DATA";
      for (i = 0; i < size; i++)
        obj[i].display_the_data();
    }
    cout << "\n1.INSERT DETAILS" << endl
         << "2.DELETE DETAILS " << endl
         << "3.UPDATE DETAILS" << endl
         << "0.EXIT";
    cout << "\nENTER YOUR CHOICE: ";
    cin >> choice;
  }
  return 0;
}
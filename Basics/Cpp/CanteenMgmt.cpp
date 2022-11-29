#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

class Product
{
private:
    int productNumber;
    string productName;
    float productRate;

public:
    Product() //Default constructor
    {
        productNumber = 0;
        productName = "";
        productRate = 0.0;
    }
    Product(int pNum, string pNam, float rate) : productNumber(pNum), productName(pNam), productRate(rate)  //Parameterised Constructor
    {
        ofstream outProduct;
        outProduct.open("Products.txt", ios::out | ios::app);
        outProduct
            << productNumber
            << ' '
            << productName
            << ' '
            << productRate
            << endl;
        cout << "\n\n\n\tPRODUCT CREATED SUCCESSFULLY";
        getch();
    }

    //Copy constructor
    Product(Product& P)                                  
    {
        //We have used this pointer here
        this->productNumber = P.productNumber;              
        this->productName = P.productName;
        this->productRate = P.productRate;
    }
    void display()
    {
        cout << "\n\tDETAILS OF COPIED PRODUCT-";
        cout << "\n\tPRODUCT NUMBER : " << productNumber;
        cout << "\n\tPRODUCT NAME : " << productName;
        cout << "\n\tRATE OF PRODUCT : " << productRate;
    }
    int getNumber()                                                                                        //Function
    {
        return productNumber;
    }
    string getName()
    {
        return productName;
    }
    float getRate()
    {
        return productRate;
    }
    void setNumber(int x)
    {
        productNumber = x;
    }
    void setName(string x)
    {
        productName = x;
    }
    //FUNCTION OVERLOADING
    void setRate(float x)           //If the rate of the product is in float value.
    {
        productRate = x;
    }
    void setRate(int x)             //If the rate of the product is in integer value.
    {
        productRate = x;
    }
};

class Bill
{
public:
    string date;
    float totalAmount;

public:
    Bill()
    {
        // current date/time based on current system

        time_t now = time(0);

        // converting now to string form
        char *dt = ctime(&now);

        date = dt;
        totalAmount = 0;
    }
};

class BillItems
{
private:
    Product product;
    int quantity;

public:
    void getItem(int code)
    {
        ifstream prod;
        prod.open("Products.txt", ios::in);
        int pn;
        string pp;
        float pr;
        while (1)
        {
            prod >> pn >> pp >> pr;
            if (pn == code)
            {
                product.setNumber(pn);
                product.setName(pp);
                product.setRate(pr);
                break;
            }
        }
    }

    //Quantity of the product
    void setQuantity(int x)     
    {
        quantity = x;
    }
    float getAmount()
    {
        int r;
        r = product.getRate();
        return r * quantity;
    }

     //Printing item details
    void printItemDet()            
    {
        cout
            << "\t" << setw(14) << product.getNumber()
            << "\t" << setw(12) << product.getName()
            << "\t" << setw(12) << product.getRate()
            << "\t" << setw(8) << quantity << "\t";
    }
};

class Invoice : public Bill
{
private:
    int numOfItems;
    BillItems item[50];
};


class CanteenManagementSystem
{
public:
    static void intro()
    {
        cout << "\n\n\n\tBILLING SYSTEM OF MITAOE CANTEEN" << endl;
        cout << "\n\t================================================================\n";
        cout << "\n\n\tMADE BY:";
        cout << "\n\n\tShashank Patil";
        cout << "\n\n\tAtharva Waghmare";
        cout << "\n\n\tKasturi Dive";
        cout << "\n\t================================================================\n";
        cout << "\n\n\n\t PLEASE NOTE: CANTEEN WILL BE CLOSED ON WEEKEND DAYS";
    }
    static void user()
    {
        int ch;
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t1. CUSTOMER";
        cout << "\n\n\t2. ADMINISTRATOR";
        cout << "\n\n\t3. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            customer();
            break;
        case 2:
            admin();
            break;
        case 3:
            exit(0);
        }
    }

    static void customer()
    {
        int n;
        BillItems item[20];
        system("cls");
        cout << "\n\n\tENTER THE NUMBER OF ITEMS: ";
        cin >> n;
        displayProduct(); // display all products
        int code;
        int qty;
        for (int i = 0; i < n; i++)
        {
            cout << "\n\tENTER ITEM CODE: ";
            cin >> code;
            item[i].getItem(code);
            cout << "\n\tENTER ITEM QUANTITY: ";
            cin >> qty;
            item[i].setQuantity(qty);
        }
        Bill fBill;
        for (int i = 0; i < n; i++)
        {
            fBill.totalAmount +=  item[i].getAmount(); 
        }
        // printing out the bill
        system("cls");
        cout << "\n\n\tINVOICE\t\t\tDate/Time:" << fBill.date << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\tProduct Number\tProduct Name\tProduct Rate\tQuantity\tAmount" << endl;
        for (int i = 0; i < n; i++)
        {
            item[i].printItemDet();
            cout << setw(6) << item[i].getAmount() << endl;
        }
         // For discount purpose
        float discountAmt = 0.0;
        float finalAmtTobePaid = fBill.totalAmount;

         //If Bill amount is greater than 500 Rs and less than 800 rs then 10% Discount on total bill amount
        if (fBill.totalAmount >= 500 && fBill.totalAmount <= 800)           
        {
            discountAmt = fBill.totalAmount * 10 / 100;
            finalAmtTobePaid = fBill.totalAmount - discountAmt;
            cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << fBill.totalAmount;
            cout << " \n\n\t\t\t\tCongratulations You got 10% Discount";
            cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << finalAmtTobePaid;
        }

        //If Bill amount is greater than 801 Rs and less than 999 rs then 12% Discount on total bill amount
        else if (fBill.totalAmount >= 801 && fBill.totalAmount <= 1000)      
        {
            discountAmt = fBill.totalAmount * 12 / 100;
            finalAmtTobePaid = fBill.totalAmount - discountAmt;
            cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << fBill.totalAmount;
            cout << " \n\n\t\t\t\tCongratulations You got 12% Discount";
            cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << finalAmtTobePaid;
        }

         //If Bill amount is greater than 1000 Rs then 15% Discount on total bill amount
        else if (fBill.totalAmount > 1000)                                 
        {
            discountAmt = fBill.totalAmount * 15 / 100;
            finalAmtTobePaid = fBill.totalAmount - discountAmt;
            cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << fBill.totalAmount;
            cout << " \n\n\t\t\t\tCongratulations You got 15% Discount";
            cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << finalAmtTobePaid;
        }
        else
        {
            cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << finalAmtTobePaid << endl;
        }

        cout << "\n\tThank You for Visiting!!" << endl;
        cout << "\n\tPress any key to continue...";
        getch();
    }
    static void admin()
    {
        while (1)
        {
            system("cls");
            int ch;
            cout << "\n\n\n\tADMIN MENU";
            cout << "\n\n\t1.CREATE PRODUCT";
            cout << "\n\n\t2.DISPLAY SAMPLE PRODUCT";
            cout << "\n\n\t3.DISPLAY ALL PRODUCTS";
            cout << "\n\n\t4.MODIFY PRODUCT";
            cout << "\n\n\t5.DELETE PRODUCT";
            cout << "\n\n\t6.BACK TO MAIN MENU";
            cout << "\n\n\tPlease Enter Your Choice (1-6) ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                createProduct();
                break;
            case 2:
                createProduct();
                break;
            case 3:
                displayProduct();
                break;
            case 4:
                modifyProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                user();
                break;
            default:
                break;
            }
        }
    }
    static void createProduct()
    {
        system("cls");
        int n;
        string p;
        float r;
        cout << "\n\n\tENTER THE DETAILS OF THE PRODUCT" << endl;
        cout << "\n\tENTER THE PRODUCT NUMBER: ";
        cin >> n;
        cout << "\n\tENTER THE PRODUCT NAME: ";
        cin >> p;
        cout << "\n\tENTER THE PRODUCT RATE: ";
        cin >> r;
        Product prod(n, p, r);
    }

    //Function overload
    static void createProduct(bool x)  
    {
        system("cls");
        int n;
        string p;
        float r;
        cout << "\n\n\tENTER THE DETAILS OF THE PRODUCT" << endl;
        cout << "\n\tENTER THE PRODUCT NUMBER" << endl;
        cin >> n;
        cout << "\n\tENTER THE PRODUCT NAME" << endl;
        cin >> p;
        cout << "\n\tENTER THE PRODUCT RATE" << endl;
        cin >> r;
        Product prod(n, p, r);

        if(x)
        {
            Product copyProd(prod);
            copyProd.display();
        }
    }
    static void displayProduct()
    {
        system("cls");
        ifstream displayProducts;
        displayProducts.open("Products.txt", ios::in);
        int n;
        string p;
        float r;
        cout << "\n\n\tDISPLAY ALL PRODUCTS"
             << "\n\t=================================================================";
        while (1)
        {
            displayProducts >> n;
            if (displayProducts.eof())
                break;
            displayProducts >> p >> r;
            // displaying on screen
            cout << "\n\tPRODUCT NUMBER : " << n;
            cout << "\n\tPRODUCT NAME : " << p;
            cout << "\n\tRATE OF PRODUCT : " << r;
            cout << "\n\t=================================================================";
        }
        cout << "\n\tPress any key";
        getch();
    }

    //For Modifying the product details.
    static void modifyProduct()  
    {
        system("cls");
        displayProduct(); // first display all products for the users to select the product
        ifstream prodIn;
        ofstream prodTmp;
        cout << "\n\t*****************************************************************";
        cout << "\n\tEnter the Product Number to Modify:\n";
        int modNum;
        cin >> modNum;
        prodIn.open("Products.txt", ios::in);
        prodTmp.open("temp.txt", ios::out);
        int n;
        string p;
        float r;
        while (1)
        {
            prodIn >> n;
            if (prodIn.eof())
                break;
            prodIn >> p >> r;
            if (n == modNum)
            {
                cout << "\n\tEnter new rate:";
                cin >> r;
            }
            prodTmp
                << n
                << ' '
                << p
                << ' '
                << r
                << endl;
        }
        prodIn.close();
        prodTmp.close();
        remove("Products.txt");
        rename("temp.txt", "Products.txt");
        cout << "\n\n\n\tPRODUCT RATE UPDATED SUCCESSFULLY";
        getch();
    }
    static void deleteProduct()
    {
        system("cls");
        displayProduct(); // first display all products for the users to select the product
        ifstream prodIn;
        ofstream prodTmp;
        cout << "\n\t*****************************************************************";
        cout << "\n\tEnter the Product Number to Delete:\n";
        int modNum;
        cin >> modNum;
        prodIn.open("Products.txt", ios::in);
        prodTmp.open("temp.txt", ios::out);
        int n;
        string p;
        float r;
        while (1)
        {
            prodIn >> n;
            if (prodIn.eof())
                break;
            prodIn >> p >> r;
            if (n != modNum)
            {
                prodTmp
                    << n
                    << ' '
                    << p
                    << ' '
                    << r
                    << endl;
            }
        }
        prodIn.close();
        prodTmp.close();
        remove("Products.txt");
        rename("temp.txt", "Products.txt");
        cout << "\n\n\n\tPRODUCT DELETED SUCCESSFULLY";
        getch();
    }
};

int main()
{
    CanteenManagementSystem::intro();
    getch();
    system("cls"); // function for clearing the screen in visual studio
    while (1)
    {
        CanteenManagementSystem::user();
    }
    return 0;
}
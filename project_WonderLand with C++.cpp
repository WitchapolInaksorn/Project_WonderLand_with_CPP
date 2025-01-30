#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
class Park
{
    public :    
        string name;
    string Getname()
    {
        cout << "\t\tEnter Your name : ";cin >> name;
        return name;
    }
    string Showname()
    {
        cout << endl;
        cout << "\t\t♥♥ SEE YOU LATER ♥♥ " << endl;
        cout << "\t\tTHANK YOU FOR USE PROGRAM NA KAB ";
        return name;
    }
};

class Poster : public Park
{
    public : 
        void Showposter()
        {
            ifstream myfile;
            string line;
            myfile.open ("poster.txt");
            while (getline(myfile,line))
            {
            cout << line << '\n';
            }
            myfile.close();
        }
};

class BoxOffice : public Poster
{
    public: 
        int select, quantity, total, money, change;
        int priceNormal = 500, pricePremium = 1000;

        void Getticket()
        {
            cout << "\t\t---------BOX OFFICE---------" << endl;
            cout << "\t\t[1] Buy a Ticket of Normal (" << priceNormal << " baht)" << endl;
            cout << "\t\t[2] Buy a Ticket of Premium (" << pricePremium << " baht)" << endl;
            cout << "\t\t[0] Go Back" << endl;

            select = 1;
            while (select != 0)
            {
                cout << "\t\tEnter your choice to select : ";
                cin >> select;

                switch(select)
                {
                    case 1: 
                        cout << "\t\tHow many Normal tickets would you like to buy? : ";
                        cin >> quantity;
                        total = quantity * priceNormal;
                        cout << "\t\tTotal for " << quantity << " Normal ticket(s) is " << total << " baht" << endl;
                        ProcessPayment();
                        return; 
                    case 2: 
                        cout << "\t\tHow many Premium tickets would you like to buy? : ";
                        cin >> quantity;
                        total = quantity * pricePremium;
                        cout << "\t\tTotal for " << quantity << " Premium ticket(s) is " << total << " baht" << endl;
                        ProcessPayment();
                        return; 
                    case 0:
                        cout << "\t\tReturning to main menu..." << endl;
                        break;
                    default:
                        cout << "\t\tInvalid choice, please select 1, 2, or 0." << endl;
                }
            }
        }

        void ProcessPayment()
        {
            while (true)
            {
                cout << "\t\tEnter your payment amount: ";
                cin >> money;

                if (money < total)
                {
                    cout << "\t\tInsufficient amount! You need " << total - money << " baht more." << endl;
                }
                else
                {
                    change = money - total;
                    cout << "\t\tPayment accepted!" << endl;
                    if (change > 0)
                    {
                        cout << "\t\tYour change is " << change << " baht." << endl;
                    }
                    cout << "\t\t-------SUCCESSFUL PAYMENT-------" << endl;
                    break;
                }
            }
        }
};

class Food : public BoxOffice
{
    public : 
        int select,count,amount1,amount2,amount3,amount4,amount5;
        int count1,count2,count3,count4,count5;
        int work,money,change;
        void sellfood()
        {
            cout << "\t\t----FOOD OF WONDER LAND----" << endl;
            cout << "\t\t----FOOD COURT----" << endl;
            cout << "\t\t[1] MAMA         : 25 baht" << endl;
            cout << "\t\t[2] CORN DOG     : 35 baht" << endl;
            cout << "\t\t[3] OMELET RICE  : 30 baht" << endl;
            cout << "\t\t[4] COLA         : 20 baht" << endl;
            cout << "\t\t[5] WATER        : 15 baht" << endl;
            cout << "\t\t[0] CHARGE MONEY" << endl;
            count = 0;
            count1 = 0;
            count2 = 0;
            count3 = 0;
            count4 = 0;
            count5 = 0;
            amount1 = 0;
            amount2 = 0;
            amount3 = 0;
            amount4 = 0;
            amount5 = 0;
            select = 1;
            while (select !=0)
            {
                cout << "\t\tEnter your food : ";
                cin >> select;
                switch(select)
                {
                case 1 : 
                    count += 25;
                    count1 += 25;
                    amount1 += 1;
                    break;
                case 2 : 
                    count += 35;
                    count2 += 35;
                    amount2 += 1;
                    break;
                case 3 :
                    count += 30;
                    count3 += 30;
                    amount3 += 1;
                    break;
                case 4 :
                    count += 20;
                    count4 += 20;
                    amount4 += 1;
                    break;
                case 5 : 
                    count += 15;
                    count5 += 15;
                    amount5 += 1;
                    break;
                case 0 : 
                    break;
                default : 
                    cout << "\t\tDON'T HAVE YOUR FOOD" << endl;
                }
            }
            cout << endl;
            cout << "\t\t-----------Bill-----------" <<endl;
            if(amount1 > 0)
            {
                cout << "\t\t" << amount1 << " MAMA           " << count1 << " baht" << endl;
            }
            if(amount2 > 0)
            {
                cout << "\t\t" << amount2 << " CORN DOG       " << count2 << " baht" << endl;
            }
            if(amount3 > 0)
            {
                cout << "\t\t" << amount3 << " OMELET RICE    " << count3 << " baht" << endl;
            }
            if(amount4 > 0)
            {
                cout << "\t\t" << amount4 << " COLA           " << count4 << " baht" << endl;
            }
            if(amount5 > 0)
            {
                cout << "\t\t" << amount5 << " WATER          " << count5 << " baht" << endl;
            }
            else 
            {
                NULL;   
            }
            cout << "\t\tTotal = " << count << endl;
            work = 1;
            while(work != 0)
            {
                cout << "\t\tEnter your money : ";
                cin >> money;
                change = money - count;
                if(money < count)
                {
                    cout << "\t\tYour money not enough!!";
                }
                else if(money > count)
                {
                    cout << "\t\tYour change = " << change << endl;
                    break;
                }
                else 
                {
                    break;
                }
                cout << endl;
            }
            cout << endl;
            cout << "\t\t-------SUCCESSFUL PAYMENT-------" << endl;
        }
        
        
};

class Souvenir : public Food
{
    public : 
        int select,choose,total,money,change,work;
        int choose1,choose2,choose3,choose4,choose5;
        int result1,result2,result3,result4,result5;
        
        void sellsouvenir()
{
    cout << "\t\t----SOUVENIR OF WONDER LAND----" << endl;
    cout << "\t\t[1] Shirt        : 450 baht" << endl;
    cout << "\t\t[2] Doll         : 400 baht" << endl;
    cout << "\t\t[3] Hat          : 350 baht" << endl;
    cout << "\t\t[4] Keychain     : 250 baht" << endl;
    cout << "\t\t[5] Shoulder bag : 500 baht" << endl;
    cout << "\t\t[0] CHARGE MONEY" << endl;
    
    select = 1;
    total = 0;
    choose1 = choose2 = choose3 = choose4 = choose5 = 0;
    result1 = result2 = result3 = result4 = result5 = 0;

    while (select != 0)
    {
        cout << "\t\tENTER YOUR SOUVENIR : ";
        cin >> select;
        
        if (select < 0 || select > 5)
        {
            cout << "\t\tDON'T HAVE YOUR SOUVENIR" << endl;
            continue;
        }
        
        if (select == 0)
            break;
        
        cout << "\t\tHOW MANY DO YOU WANT : ";
        cin >> choose;
        
        switch (select)
        {
            case 1: choose1 += choose; result1 = choose1 * 450; break;
            case 2: choose2 += choose; result2 = choose2 * 400; break;
            case 3: choose3 += choose; result3 = choose3 * 350; break;
            case 4: choose4 += choose; result4 = choose4 * 250; break;
            case 5: choose5 += choose; result5 = choose5 * 500; break;
        }
    }

    total = result1 + result2 + result3 + result4 + result5;

    cout << "\t\t-----------Bill-----------" << endl;
    if (choose1 > 0) cout << "\t\t" << choose1 << " Shirt        " << result1 << " baht" << endl;
    if (choose2 > 0) cout << "\t\t" << choose2 << " Doll         " << result2 << " baht" << endl;
    if (choose3 > 0) cout << "\t\t" << choose3 << " Hat          " << result3 << " baht" << endl;
    if (choose4 > 0) cout << "\t\t" << choose4 << " Keychain     " << result4 << " baht" << endl;
    if (choose5 > 0) cout << "\t\t" << choose5 << " Shoulder bag " << result5 << " baht" << endl;
    cout << "\t\tTotal = " << total << " baht" << endl;

    while (true)
    {
        cout << "\t\tEnter your money : ";
        cin >> money;
        
        if (money < total)
        {
            cout << "\t\tYour money is not enough! You need " << total - money << " baht more." << endl;
        }
        else
        {
            change = money - total;
            cout << "\t\tPayment accepted!" << endl;
            if (change > 0)
            {
                cout << "\t\tYour change is " << change << " baht." << endl;
            }
            cout << "\t\t-------SUCCESSFUL PAYMENT-------" << endl;
            break;
        }
    }
}

};


int main()
{
    int menu;
    Souvenir u1;
    u1.Getname();
    cout << "\t\t----Welcome To WONDERLAND----" << endl;
    menu = 1;
    while(menu != 0)
    {
        cout << endl;
        cout << "     |||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "     ||                                                 ||" << endl;
        cout << "     ||                                                 ||" << endl;
        cout << "     ||                   ----MENU----                  ||" << endl;
        cout << "     ||                [1] TICKET DETAIL                ||" << endl;
        cout << "     ||                [2] BUY A TICKET                 ||" << endl;
        cout << "     ||                [3] BUY A FOOD                   ||" << endl;
        cout << "     ||                [4] BUY A SOUVENIR               ||" << endl;
        cout << "     ||                [0] EXIT PROGRAM                 ||" << endl;
        cout << "     ||                                                 ||" << endl;
        cout << "     ||            # HAVE YOUR BEST TIME HERE :)        ||" << endl;
        cout << "     ||                                                 ||" << endl;
        cout << "     ||                                                 ||" << endl;
        cout << "     |||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;

        while (true) {
            cout << "\t\tWHAT MENU DO YOU WANT : ";
            cin >> menu;

            if (cin.fail()) { 
                cout << "\t\tInvalid input! Please enter a number from the menu options.\n" << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else if (menu < 0 || menu > 4) {
                cout << "\t\tInvalid choice! Please enter a valid menu option.\n" << endl;
            } else {
                break;
            }
        }

        switch(menu)
        {
            case 1:    
                u1.Showposter();
                break;
            case 2: 
                u1.Getticket();
                break;
            case 3: 
                u1.sellfood();
                break;
            case 4: 
                u1.sellsouvenir();
                break;
            case 0: 
                cout << u1.Showname() << " ☺";
                break;
        }
    }
}

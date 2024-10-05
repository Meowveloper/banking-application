#include <iostream>
#include <iomanip>
#include <limits>  

void showBalance (double balance);
double deposit ();
double withdraw (double balance);
void clearInput();

int main () 
{
    double balance = 0;
    int choice = 0;
    
    do
    {
        std::cout << "*****************" << '\n';
        std::cout << "Enter Your Choice" << '\n';
        std::cout << "*****************" << '\n';
        std::cout << "1. Show balance" << '\n';
        std::cout << "2. Deposit money" << '\n';
        std::cout << "3. Withdraw money" << '\n';
        std::cout << "4. Exit" << '\n';
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cout << "Invalid input" << '\n';
            clearInput();
            continue;
        } 

        switch (choice)
        {
            case 1: showBalance(balance); break;
        
            case 2:
                balance += deposit();
                showBalance(balance);
                break;

            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;

            case 4: std::cout << "Thanks for using our application" << '\n'; break;

            default: std::cout << "Invalid choice" << '\n'; break;
        }
    } while (choice != 4);
    
    return 0;
}

void showBalance (double balance)
{
    std::cout << "Your balance is : $" << std::setprecision(2) << std::fixed << balance << '\n'; // two decimal points...
}

double deposit ()
{
    double amount = 0;

    std::cout << "Enter the amount of money you want to deposit: ";
    std::cin >> amount;


    if (amount < 0 || std::cin.fail())
    {
        std::cout << "That's not a valid amount. You can enter 0 to make no deposit" << '\n';
        clearInput();
        return deposit();
    }
    else 
    {
        return amount;
    }
}

double withdraw (double balance) 
{
    double amount = 0;

    std::cout << "Enter amount you would like to withdraw: ";
    std::cin >> amount;


    if(amount > balance)
    {
        std::cout << "Insufficient balance" << '\n';
        return 0;
    }
    else if (amount < 0 || std::cin.fail()) 
    {
        std::cout << "Invalid amount" << '\n';
        clearInput();
        return withdraw(balance);
    }
    else 
    {
        return amount;
    }
}

void clearInput() 
{
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
}

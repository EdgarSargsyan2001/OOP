#include <iostream>
#include "bank.h"

void findCustomers(Bank &b)
{
    std::cout << "Enter Customer name ";
    std::string name;
    std::cin >> name;
    std::vector<Customer *> v = b.getCustomer(name);
    if (v.size() == 0)
    {
        std::cout << "Customer not found\n";
    }
    else
    {
        for (int i = 0; i < v.size(); ++i)
        {
            v[i]->printInfo();
        }
    }
}
void findCustomer(Bank &b)
{
    std::cout << "enter id ";
    int id;
    std::cin >> id;
    try
    {
        b.getCustomer(id).printInfo();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void transferMoney(Bank &b)
{
    std::cout << "enter the sender id ";
    int id1;
    std::cin >> id1;
    std::cout << "enter the recipient id ";
    int id2;
    std::cin >> id2;
    std::cout << "enter the mony ";
    int count;
    std::cin >> count;
    if (b.transferMoney(id1, id2, count))
    {
        std::cout << "transfer succeeded\n";
    }
    else
    {
        std::cout << "transmission failed\n";
    }
}

void commands(Bank &b)
{
    while (1)
    {
        std::cout << "\n:0: exit \n";
        std::cout << ":1: transfer Money \n";
        std::cout << ":2: find Customers  \n";
        std::cout << ":3: print Customer info with id \n";
        std::cout << ":4: print All Customer info \n";

        std::cout << "enter comand ";
        int n;
        std::cin >> n;
        std::cout << "\n";
        if (n == 0)
            break;
        switch (n)
        {
        case 1:
            transferMoney(b);
            break;
        case 2:
            findCustomers(b);
            break;
        case 3:
            findCustomer(b);
            break;
        case 4:
            b.printAllCustomerinfo();
            break;

        default:
            break;
        }
    }
}

int main()
{
    Bank ACBA(90000000);
    ACBA.setCustomer(Customer("Edgar", 22, 2000));
    ACBA.setCustomer(Customer("Narek", 18, 1500));
    ACBA.setCustomer(Customer("Jon", 33, 1225));
    ACBA.setCustomer(Customer("Ann", 19, 200));
    ACBA.setCustomer(Customer("Lilit", 22, 1800));
    ACBA.setCustomer(Customer("Edgar", 30, 20800));
    commands(ACBA);
    // std::cout << ACBA.getAllCustomerMony() << "\n";
}
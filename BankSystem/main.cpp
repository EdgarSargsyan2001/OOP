#include <iostream>
#include "bank.h"
#include <fstream>
#include <string>

std::vector<std::string> split(std::string str)
{
    std::vector<std::string> ans;
    std::string word;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ',')
        {
            ans.push_back(word);
            word.clear();
            continue;
        }
        word.push_back(str[i]);
    }
    ans.push_back(word);
    return ans;
}

bool initFromFile(Bank &b)
{
    std::fstream fs;
    fs.open("users.csv", std::ios::in);
    if (!fs.is_open())
    {
        std::cout << "ERROR: can not open input file\n";
        return false;
    }

    int line = 1;
    std::string custInfo;
    while (getline(fs, custInfo))
    {

        std::vector<std::string> info = split(custInfo);
        if (info.size() != 3)
        {
            std::cout << "line: " << line << " has been ignored\n";
            continue;
        }

        b.setCustomer(Customer(info[0], std::stoi(info[1]), std::stoi(info[2])));
        line++;
    }
    fs.close();
    return true;
}
bool saveInFile(Bank &b)
{
    std::fstream fs;
    fs.open("users.csv", std::ios::out);
    if (!fs.is_open())
    {
        std::cout << "ERROR: can not open output file\n";
        return false;
    }
    b.outAllCustomersInfoToFile(fs);
    fs.close();
    return true;
}

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
        std::cout << ":5: print All Customer History \n";

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
        case 5:
            b.printAllCustomerHistory();
            break;
        default:
            std::cout << "command not found :(\n";
            break;
        }
    }
}

int main()
{
    Bank ACBA(90000000);
    // ==== add customers from file ====
    if (!initFromFile(ACBA))
    {
        return 1;
    };

    commands(ACBA);

    // ===== update info in file ====
    if (!saveInFile(ACBA))
    {
        return 1;
    };
}
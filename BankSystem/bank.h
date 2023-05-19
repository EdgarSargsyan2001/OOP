#ifndef BANK_H
#define BANK_H
#include <string>
#include <iostream>
#include <vector>
#include "customer.h"

// ==================== Bank ========================
int Customer::st_id = 0;
class Bank
{
public:
    Bank(int);

    // setters
    void setCustomer(Customer);

    // getters
    Customer &getCustomer(int id);
    std::vector<Customer *> getCustomer(std::string name);
    int getCustomerCount();
    int getAllCustomerMony();

    //
    bool transferMoney(int id1, int id2, int count);

    //
    void printCustomerinfo(int id);
    void printAllCustomerinfo();

private:
    std::vector<Customer> _arr;
    int _bank_mony;
};

Bank::Bank(int m) : _bank_mony(m){};
// seters
void Bank::setCustomer(Customer A)
{
    _arr.push_back(A);
}

// getters
Customer &Bank::getCustomer(int id)
{
    for (int i = 0; i < _arr.size(); ++i)
    {
        if (_arr[i].getId() == id)
            return _arr[i];
    }
    throw std::out_of_range("id is broken:)\n");
}
std::vector<Customer *> Bank::getCustomer(std::string n)
{
    std::vector<Customer *> v;
    for (int i = 0; i < _arr.size(); ++i)
    {
        if (_arr[i].getName() == n)
            v.push_back(&_arr[i]);
    }
    return v;
}

int Bank::getCustomerCount()
{
    return _arr.size();
}
int Bank::getAllCustomerMony()
{
    int s = 0;
    for (int i = 0; i < _arr.size(); ++i)
    {
        s += _arr[i].getMony();
    }
    return s;
}
//
bool Bank::transferMoney(int id1, int id2, int count)
{
    return getCustomer(id1).transferMoney(getCustomer(id2), count);
}
void Bank::printCustomerinfo(int id)
{
    getCustomer(id).printInfo();
}
void Bank::printAllCustomerinfo()
{
    for (int i = 0; i < _arr.size(); ++i)
    {
        _arr[i].printInfo();
    }
}

#endif
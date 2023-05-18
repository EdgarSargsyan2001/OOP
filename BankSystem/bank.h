#ifndef BANK_H
#define BANK_H
#include <string>
#include <iostream>
#include <vector>

class Customer
{
    static int st_id;

public:
    // ctor
    Customer();
    Customer(std::string n, short a, int m);
    // seters
    void setName(std::string name);
    void setAge(short age);
    void setMony(int mony);

    // getters
    std::string getName();
    short getAge();
    int getMony();
    int getId();
    //
    void addMony(int m);
    void subMony(int m);

private:
    std::string _name;
    short _age;
    int _mony;
    int _id;
};

// ==================== Customer ========================

// ctor
Customer::Customer() : _name(""), _age(-1), _mony(0), _id(st_id++)
{
}
Customer::Customer(std::string n, short a, int m) : _name(n), _age(a), _mony(m), _id(st_id++){};

// seters
void Customer::setName(std::string name)
{
    _name = name;
}
void Customer::setAge(short age)
{
    if (age < 0)
        throw std::out_of_range("age cannot be a negative number");
    _age = age;
}
void Customer::setMony(int mony)
{
    if (mony < 0)
        throw std::out_of_range("the amount of money cannot be a negative number");
    _mony = mony;
}

// geters
std::string Customer::getName()
{
    return _name;
}
short Customer::getAge()
{
    return _age;
}
int Customer::getMony()
{
    return _mony;
}
int Customer::getId()
{
    return _id;
}

void Customer::addMony(int m)
{
    _mony += m;
}
void Customer::subMony(int m)
{
    _mony -= m;
}

// ==================== Bank ========================
int Customer::st_id = 0;
class Bank
{
public:
    Bank(int m) : _bank_mony(m){};
    // seters
    void setCustomer(Customer A)
    {
        _arr.push_back(A);
    }

    // getters
    Customer &getCustomer(int id)
    {
        for (int i = 0; i < _arr.size(); ++i)
        {
            if (_arr[i].getId() == id)
                return _arr[i];
        }
        throw std::out_of_range("id is broken:)\n");
    }
    Customer &getCustomer(std::string n)
    {
        for (int i = 0; i < _arr.size(); ++i)
        {
            if (_arr[i].getName() == n)
                return _arr[i];
        }
        throw std::out_of_range("id is broken:)\n");
    }
    int getCustomerId(std::string n)
    {
        for (int i = 0; i < _arr.size(); ++i)
        {
            if (_arr[i].getName() == n)
                return _arr[i].getId();
        }
        throw std::out_of_range("there is no one with that name\n ");
        return -1;
    }
    int getCustomerSize()
    {
        return _arr.size();
    }
    int getAllCustomerMony()
    {
        int s = 0;
        for (int i = 0; i < _arr.size(); ++i)
        {
            s += _arr[i].getMony();
        }
        return s;
    }
    //
    bool transferMoney(std::string n1, std::string n2, int count)
    {
        Customer &c1 = getCustomer(n1);
        if (c1.getMony() < count)
        {
            std::cout << "there is no such money\n";
            return false;
        };
        c1.subMony(count);
        getCustomer(n2).addMony(count);
        return true;
    }
    void printCustomerinfo(int id)
    {
        Customer c = getCustomer(id);
        std::cout << "Name: " << c.getName() << "\n";
        std::cout << "Age: " << c.getAge() << "\n";
        std::cout << "id: " << c.getId() << "\n";
        std::cout << "Mony: " << c.getMony() << "\n\n";
    }
    void printAllCustomerinfo()
    {
        for (int i = 0; i < _arr.size(); ++i)
        {
            std::cout << "Name: " << _arr[i].getName() << "\n";
            std::cout << "Age: " << _arr[i].getAge() << "\n";
            std::cout << "id: " << _arr[i].getId() << "\n";
            std::cout << "Mony: " << _arr[i].getMony() << "\n\n";
        }
    }

private:
    std::vector<Customer> _arr;
    int _bank_mony;
};

#endif
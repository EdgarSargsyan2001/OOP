
#ifndef CUSTMOER_H
#define CUSTMOER_H
#include <string>
#include <iostream>

// ==================== Customer ========================
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
    std::string getName() const;
    short getAge() const;
    int getMony() const;
    int getId() const;
    //
    void addMony(int m);
    void subMony(int m);
    bool transferMoney(Customer &reciver, int mony);
    //
    void printInfo() const;

private:
    std::string _name;
    short _age;
    int _mony;
    int _id;
};

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
std::string Customer::getName() const
{
    return _name;
}
short Customer::getAge() const
{
    return _age;
}
int Customer::getMony() const
{
    return _mony;
}
int Customer::getId() const
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
bool Customer::transferMoney(Customer &reciver, int mony)
{
    if (mony > _mony)
        return false;
    this->subMony(mony);
    reciver.addMony(mony);
    return true;
}

void Customer::printInfo() const
{
    std::cout << "Name: " << this->getName() << "\n";
    std::cout << "Age: " << this->getAge() << "\n";
    std::cout << "id: " << this->getId() << "\n";
    std::cout << "Mony: " << this->getMony() << "\n\n";
}

#endif
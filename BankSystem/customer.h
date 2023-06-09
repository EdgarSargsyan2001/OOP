
#ifndef CUSTMOER_H
#define CUSTMOER_H
#include <string>
#include <iostream>
#include <vector>

// ==================== Customer ========================
struct TransferH
{
    TransferH(std::string &n, int a, int b, bool g) : name(n), receiverid(a), count(b), getORset(g){};
    std::string name;
    int receiverid;
    int count;
    bool getORset;
};

class Customer
{
    static int st_id;

public:
    // ctor
    Customer(std::string n, short a, int m);

    // seters
    void setName(std::string name);
    void setAge(short age);
    void setMony(int mony);
    void setTransferHistory(std::string n, int receiverid, int count, bool gORs);

    // getters
    std::string getName() const;
    short getAge() const;
    int getMony() const;
    int getId() const;
    std::vector<TransferH> getTransferHistory() const;
    //
    void
    addMony(int m);
    void subMony(int m);
    bool transferMoney(Customer &reciver, int mony);
    //
    void printInfo() const;
    bool printTransferHistory() const;
    void outTransferMoneyInfoToFile(std::fstream &outFile) const;

private:
    std::string _name;
    int _mony;
    int _id;
    short _age;
    std::vector<TransferH> _transfer_history;
};

// ctor with parameters
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
void Customer::setTransferHistory(std::string n, int receiverid, int count, bool gORs)
{
    _transfer_history.push_back(TransferH(n, receiverid, count, gORs));
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
std::vector<TransferH> Customer::getTransferHistory() const
{
    return _transfer_history;
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
    if (mony > _mony || mony <= 0)
        return false;
    this->subMony(mony);
    reciver.addMony(mony);
    this->setTransferHistory(reciver.getName(), reciver.getId(), mony, 0);
    reciver.setTransferHistory(this->getName(), this->getId(), mony, 1);
    return true;
}

void Customer::printInfo() const
{
    std::cout << "Name: " << this->getName() << "\n";
    std::cout << "Age: " << this->getAge() << "\n";
    std::cout << "id: " << this->getId() << "\n";
    std::cout << "Mony: " << this->getMony() << "\n";
    std::cout << "Transfer history: \n";
    if (!printTransferHistory())
        std::cout << "\tthe customer has no transfer history \n";

    std::cout << std::endl;
}
bool Customer::printTransferHistory() const
{
    for (auto obj : _transfer_history)
    {
        std::cout << "\t";
        std::cout << this->getName();
        std::cout << " { id is " << this->getId() << " }";
        std::cout << (obj.getORset ? " receive " : " transfer ");
        std::cout << obj.count << (obj.getORset ? " from " : " to ") << obj.name;
        std::cout << " { id is " << obj.receiverid << " }"
                  << "\n";
    }

    return _transfer_history.size();
}
void Customer::outTransferMoneyInfoToFile(std::fstream &outFile) const
{
    for (auto obj : _transfer_history)
    {

        outFile << this->getName();
        outFile << " { id is " << this->getId() << " }";
        outFile << (obj.getORset ? " receive " : " transfer ");
        outFile << obj.count << (obj.getORset ? " from " : " to ") << obj.name;
        outFile << " { id is " << obj.receiverid << " }"
                << "\n";
    }
}
#endif
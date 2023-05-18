#include <iostream>
#include "bank.h"

int main()
{
    Bank ACBA(90000000);
    ACBA.setCustomer(Customer("Edgar", 21, 2000));
    ACBA.setCustomer(Customer("Narek", 18, 1500));
    ACBA.setCustomer(Customer("Jon", 33, 1225));
    ACBA.setCustomer(Customer("Ann", 19, 200));
    ACBA.setCustomer(Customer("Lilit", 22, 1800));

    // std::cout << ACBA.getAllCustomerMony() << "\n";
    ACBA.printCustomerinfo(ACBA.getCustomerId("Edgar"));
    if (ACBA.transferMoney("Lilit", "Edgar", 200))
    {
        ACBA.printCustomerinfo(ACBA.getCustomerId("Edgar"));
        ACBA.printCustomerinfo(ACBA.getCustomerId("Lilit"));
    }
}
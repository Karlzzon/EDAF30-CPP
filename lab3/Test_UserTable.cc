#include <string>
#include "User.h"
#include "UserTable.h"
#include <iostream>

using namespace std;

int main()
{
    UserTable validUsers("./users.txt");

    User testPerson{1234, "Test Testsson"};

    //validUsers.addUser(testPerson);
    cout << "Number of persons: " << validUsers.getNbrUsers() << endl;
   // validUsers.print(std::cout);
    cout << validUsers.find(21330) << "\n";
    cout << validUsers.find(21331) << "\n";
    cout << validUsers.find("Jens Holmgren") << "\n";
    cout << "Number of users: " << validUsers.getNbrUsers() << endl;
    cout << "User 99999: " << validUsers.find(99999) << endl;
    cout << "User Lucas Viklund: " << validUsers.find("Lucas Viklund") << endl;
    cout << "Running test function: " << testFindNbr(validUsers) << endl;

    return 0;
}

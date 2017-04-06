#include <iostream>

class Client2 {
    AbstractDatabase& myDatabase;
public:
    Client2(AbstractDatabase& db): myDatabase(db) {}
public:
    void transaction () {
        double data = myDatabase.getData();
        if (data != 0) std::cout << "Received data from database: " << data << std::endl;
    }
};
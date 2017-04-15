class Client1 {
    ConcreteDatabase myDatabase;
public:
    Client1(): myDatabase () {}
public:
    void transaction () {
        myDatabase.getData();
        if (data != 0) std::cout << "Received data from database: " << data << std::endl;
    }
};
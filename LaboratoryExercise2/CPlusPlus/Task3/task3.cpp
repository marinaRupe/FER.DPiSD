#include "mockDatabase.hpp"
#include "client2.hpp"

int testClient2() {
    AbstractDatabase* pdb = new MockDatabase();
    Client2 client(*pdb);
    client.transaction();
    return 0;
}

int task3Main() {
    testClient2();
    return 0;
}
#include "abstractDatabase.hpp"
class MockDatabase : public AbstractDatabase {
public:
    virtual double getData() { return 1000; }
};
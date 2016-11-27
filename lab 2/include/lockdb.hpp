#ifndef LOCKDB_HPP
#define LOCKDB_HPP

class Lockdb {
public:
    Lockdb();
    ~Lockdb();
    bool get_status();
private:
    bool status;
};

#endif

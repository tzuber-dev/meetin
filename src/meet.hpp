#include <string>

#include <iostream>
using namespace std;

class Median{
private:
    int* integers;
    int sizel;
    int capacity;
    void increasethearray();

public:
    Median();
    ~Median();

    void sumNumber(int val);
    bool loaddatafromfile(const std::string& filetype);
    double getmedian() const;
    int getsize() const;


};


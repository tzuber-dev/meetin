#include <iostream>

#include "src/meet.hpp"
#include <iomanip>
#include <string>



using namespace std;

int main() {

    string file;
    cout<<"Enter your chosen file name: ";
    getline(cin,file);

    Median currentdataset;

    if (!currentdataset.loaddatafromfile(file)) {
        std::cout<<"Error loading file"<<std::endl;
        return 1;
    }

    if (currentdataset.getsize() == 0) {
        std::cout<<"No data found"<<std::endl;
        return 1;
    };

    double themedian = currentdataset.getmedian();

    cout<<fixed<<setprecision(1)<<std::endl;
    cout<<"Median value is: "<<themedian<<endl;
}

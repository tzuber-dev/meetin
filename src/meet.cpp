#include <string>
#include"meet.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Median::Median() {
    capacity=10;
    sizel = 0;
    integers = new int[capacity];


}

Median::~Median() {
    delete[] integers;
}

void Median::increasethearray() {
    capacity =capacity*2;
    int* largearray = new int[capacity];

    for(int a=0;a<sizel;a++) {
        largearray[a]=integers[a];
    };
    delete[] integers;
    integers = largearray;
}


void Median::sumNumber(int val) {
    if (sizel==capacity) {
        increasethearray();
    }
    integers[sizel]=val;
    sizel++;
}

bool Median::loaddatafromfile(const std::string &filetype) {
    std::ifstream infile(filetype);
    if (!infile.is_open()) {
        return false;
    }
    std::string line;
    std::string datapiece;

    while (getline(infile, line)) {
        std::stringstream bb(line);

        while (getline(bb,datapiece,',')) {
            if (!datapiece.empty()) {
                sumNumber(std::stoi(datapiece));
            }
        }
    }

    infile.close();
    return true;
}


double Median::getmedian() const{
 if (sizel==0) {
     return 0.0;
 }
    if (sizel %2 ==1) {
        return integers[sizel/2];
    }else {
        int leftfrommiddle = integers[(sizel/2)-1];
        int rightfrommiddle = integers[(sizel/2)];

        return (leftfrommiddle+rightfrommiddle)/2;
    }
}

int Median::getsize() const {
    return sizel;
};
#ifndef ARITHMETICTESTER_H_INCLUDED
#define ARITHMETICTESTER_H_INCLUDED


#include "ArithmeticTesterBase.h"
#include <limits>
#include <chrono>
#include <cstdlib>
#include <array>
#include <ctime>
const int numTests = 1000000000;


template <class T, class ITERATOR>
void initializeToRandom(ITERATOR begin, ITERATOR end){
srand(time(0));
    for(ITERATOR it = begin; it != end; it++){

        (*it) = static_cast<T>(rand());

    }

}



template <class T>
class ArithmeticTester : public ArithmeticTesterBase{

public:

std::string typeStr;

long double additionTime;
long double subtractionTime;
long double multiplicationTime;
long double divisionTime;


ArithmeticTester(const std::string& types):typeStr(types){

}


virtual void logResults(std::ostream& str){


        str<<"TIME PER OPERATION OF TYPE "<<typeStr<<std::endl;
        str<<"ADDITION: "<<additionTime<<"\nSUBTRACTION: "<<subtractionTime<<
        "\nMULTIPLICATION: "<<multiplicationTime<<"\nDIVISION: "<<divisionTime<<'\n'<<std::endl;


}



virtual void multiplicationTest(){

    std::cout<<"Running multiplication test for "<<typeStr<<std::endl;


std::array<T,4> valuesToUse;
T total=0;

initializeToRandom<T, typename std::array<T,16>::iterator>(valuesToUse.begin(), valuesToUse.end());



auto beginTime = std::chrono::high_resolution_clock::now();

for(int i = 0; i < numTests;i++){


    total = valuesToUse[i & 3] * valuesToUse[(i+1)&3];

}


auto endTime = std::chrono::high_resolution_clock::now();


std::chrono::duration<long double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - beginTime);

multiplicationTime =time_span.count();

std::cout<<"Took "<<multiplicationTime<<std::endl;



std::cout<<"Total is "<<total<<std::endl;




}






virtual void divisionTest(){


    std::cout<<"Running division test for "<<typeStr<<std::endl;


std::array<T,4> valuesToUse;

T total =0;

initializeToRandom<T, typename std::array<T,16>::iterator>(valuesToUse.begin(), valuesToUse.end());


    auto beginTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < numTests;i++){


    total = valuesToUse[i & 3] / valuesToUse[(i+1)&3];

    }




auto endTime = std::chrono::high_resolution_clock::now();

std::chrono::duration<long double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - beginTime);

divisionTime =time_span.count();


std::cout<<"total is "<<total<<std::endl;


}





virtual void subtractionTest(){


std::array<T,4> valuesToUse;

initializeToRandom<T, typename std::array<T,16>::iterator>(valuesToUse.begin(), valuesToUse.end());


std::cout<<"Running subtraction test for "<<typeStr<<std::endl;

const T valueToSub = static_cast<T>(3);

T  total =1000000000;


auto beginTime = std::chrono::high_resolution_clock::now();

for(int i = 0; i < numTests;i++){

     total = valuesToUse[i & 3] - valuesToUse[(i+1)&3];

}

auto endTime = std::chrono::high_resolution_clock::now();

std::chrono::duration<long double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - beginTime);

subtractionTime =time_span.count();


std::cout<<"Total is "<<total<<std::endl;



}




void additionTest(){

std::array<T,4> valuesToUse;

initializeToRandom<T, typename std::array<T,16>::iterator>(valuesToUse.begin(), valuesToUse.end());


std::cout<<"Running addition test for "<<typeStr<<std::endl;
T total = 0;

auto beginTime = std::chrono::high_resolution_clock::now();

for(int i = 0; i < numTests;i++){

    total = valuesToUse[i & 3] + valuesToUse[(i+1)&3];

}

auto endTime = std::chrono::high_resolution_clock::now();

std::chrono::duration<long double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - beginTime);

additionTime =time_span.count();

std::cout<<"Total is "<<total<<std::endl;


}




};





#endif // ARITHMETICTESTER_H_INCLUDED

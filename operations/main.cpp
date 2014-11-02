#include <iostream>
#include <cstdint>
#include <fstream>
#include <memory>
#include <chrono>

#include "ArithmeticTester.h"
#include "runArithmeticTests.h"

using namespace std;
using namespace std::chrono;

void printTypeSizes(std::ostream& str);


//array versions too
//bool tests?
//ternary vs if tests?
//does compiler optimize out integer divisions?  cast to int then divide by 2 then cast back?
//i++, ++i, shift vs division, etc




///subtracing a negligible value from a huge value in float is fast







//try on 32 bit built and 64
#include <vector>

class base{
public:

    void operator()(){}
};


template <class dattype, typename container = std::vector<dattype> >
class thing: public base{
    using base::operator();
    container vec;

};

int main()
{

    thing<int > xxx;


    long double per = (long double)steady_clock::period::num / (long double)(steady_clock::period::den);

    cerr<<"steady clock per is "<<per<<std::endl;


    per = (long double)high_resolution_clock::period::num / (long double)(high_resolution_clock::period::den);

    cerr<<"high_resolution_clock clock per is "<<per<<std::endl;


    cout << "Hello world!" << endl;

    std::ofstream outFile("Results.txt");

    printTypeSizes(outFile);

    runArithmeticTests<ArithmeticTester>(outFile);

    return 0;
}

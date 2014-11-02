#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;


template <class ChronoClock>
void testClock(std::ostream& str){

    long double per = (long double)ChronoClock::period::num / (long double)(ChronoClock::period::den);

    str<<"clock period  is allegedly:: "<<per<<" second "<<std::endl;


    auto oldTime = ChronoClock::now();
    typename ChronoClock::time_point newTime;

    for(int i = 0; i < 1000000;i++){

        newTime = ChronoClock::now();

        if(oldTime!=newTime){

             duration<double> time_span = duration_cast<duration<double>>(newTime - oldTime);

             str << "diff is " << time_span.count() << " seconds.\n";

             oldTime=newTime;
        }

    }


}



int main()
{
    std::ofstream file("RESULTS.txt");
    std::ostream& str = file;


    str<<"TESTING CHRONO STEADY CLOCK"<<std::endl;
    testClock<steady_clock>(str);
    str<<"TESTING HIGH RESOLUTION CLOCK"<<std::endl;
    testClock<high_resolution_clock>(str);

    file.close();

    return 0;


}

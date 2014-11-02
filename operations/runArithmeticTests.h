#ifndef RUNARITHMETICTESTS_H_INCLUDED
#define RUNARITHMETICTESTS_H_INCLUDED




///requires that Tester extends ArithmeticTesterBase and is templated on various types
template <template <class B> class Tester>
void runArithmeticTests(std::ostream& str){

    typedef std::shared_ptr<ArithmeticTesterBase> testPtr;

    const   int TYPE_COUNT = 11;

    testPtr arithmeticTesters[TYPE_COUNT] = {

       testPtr( new Tester<std::uint8_t>("uint8")),
       testPtr( new Tester<std::uint16_t>("uint16")),
       testPtr( new Tester<std::uint32_t>("uint32")),
       testPtr( new Tester<std::uint64_t>("uint64") ),

       testPtr( new Tester<std::int8_t>("int8")),
       testPtr( new Tester<std::int16_t>("int16")),
       testPtr( new Tester<std::int32_t>("int32")),
       testPtr( new Tester<std::int64_t>("int64") ),

       testPtr(new Tester<float>("float")),
       testPtr(new Tester<double>("double")),
       testPtr(new Tester<long double>("long double"))

    };

    for(int i =0 ; i < TYPE_COUNT; i++){

        arithmeticTesters[i]->run();
        arithmeticTesters[i]->logResults(str);

    }


}



#endif // RUNARITHMETICTESTS_H_INCLUDED

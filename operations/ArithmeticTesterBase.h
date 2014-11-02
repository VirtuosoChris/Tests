#ifndef ARITHMETICTESTERBASE_H_INCLUDED
#define ARITHMETICTESTERBASE_H_INCLUDED


class ArithmeticTesterBase{
public:
    virtual void additionTest()=0;
    virtual void multiplicationTest()=0;
    virtual void divisionTest()=0;
    virtual void subtractionTest()=0;

    void run(){

        additionTest();
        multiplicationTest();
        divisionTest();
        subtractionTest();

    }

    virtual void logResults(std::ostream& str)=0;

};


#endif // ARITHMETICTESTERBASE_H_INCLUDED

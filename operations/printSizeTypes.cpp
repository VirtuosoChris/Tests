#include <iostream>


void printTypeSizes(std::ostream& str){


    str<<"Type sizes for this build configuration:::\n\nSize of size_t "<<sizeof(std::size_t)
    <<"\nSize of float "<<sizeof(float)
    <<"\nsize of double "<<sizeof(double)
    <<"\nsize of long double "<<sizeof(long double)
    <<"\n\nsize of char "<<sizeof(char)
    <<"\nsize of wchar_t "<<sizeof(wchar_t)

    <<"\n\nsize of uint8 "<<sizeof(std::uint8_t)<<
    "\nsize of uint16 "<<sizeof(std::uint16_t)<<
    "\nsize of uint32 "<<sizeof(std::uint32_t)<<
    "\nsize of uint64 "<<sizeof(std::uint64_t)<<

    "\n\nsize of int8 "<<sizeof(std::int8_t)<<
    "\nsize of int16 "<<sizeof(std::int16_t)<<
    "\nsize of int32 "<<sizeof(std::int32_t)<<
    "\nsize of int64 "<<sizeof(std::int64_t)<<

    "\n\nsize of uint "<<sizeof(unsigned int)<<
    "\nSize of int "<<sizeof(int)<<
    "\nsize of long "<<sizeof(long)<<std::endl;

}

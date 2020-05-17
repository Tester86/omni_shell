#include <iostream>
#include <exception>

using namespace std;

class index_error_exception : public exception{
    virtual const char* what() const throw(){
        return "IndexError: List index out of range";
    };
} IndexError;
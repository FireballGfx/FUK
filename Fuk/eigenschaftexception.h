#ifndef EIGENSCHAFTEXCEPTION_H
#define EIGENSCHAFTEXCEPTION_H

#include <iostream>
#include <exception>

class EigenschaftException : public std::exception
{
private:
    const char* message;
public:

    EigenschaftException(const char* message):message(message){
    }

    // ruft die Exception ab
    virtual const char* what() const throw(){
        return message;
    }
};

#endif // EIGENSCHAFTEXCEPTION_H

#ifndef BDAYEXCEPTION_H
#define BDAYEXCEPTION_H

#include <exception>
#include <qtconcurrentexception.h>

class BdayException : public QtConcurrent::Exception
{
public:
    void raise() const {qDebug() << "Exception: "; throw *this; }
};

BdayException wrongInput;
BdayException nonExistant;

#endif // BDAYEXCEPTION_H

#ifndef TYPES_H_
#define TYPES_H_

// #include <Arduino.h>
// #include <CircularBuffer.h>
#include <boost/circular_buffer.hpp>


#define maxSize 50
#define THRESHOLD 0.22
#define WINDOW 3


// #define TAB Serial.print(F("\t"))

typedef struct axes
{
    float x = 0.0; 
    float y = 0.0; 
    float z = 0.0;

    axes &operator=(axes a)
    {
        this->x = a.x;
        this->y = a.y;
        this->z = a.z;

        return *this;
    }

    axes &operator+=(axes a)
    {
        this->x += a.x;
        this->y += a.y;
        this->z += a.z;

        return *this;
    }
}axes;

typedef struct COEFFICIENTS
{
    double alpha[3];
    double beta[3];
}COEFFICIENTS;


typedef boost::circular_buffer<axes> CB;
// typedef char CB;
// typedef boost::circular_buffer<axes, std::allocator<axes>> CB;

#endif
//
// Created by a on 8/24/20.
//

#ifndef SMART_POINTERS_UTILS_H
#define SMART_POINTERS_UTILS_H

void printTest(bool result);


class Uncopyable{
protected:
    Uncopyable(){}
    ~Uncopyable(){}

private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator= (const Uncopyable&);
};

#endif //SMART_POINTERS_UTILS_H

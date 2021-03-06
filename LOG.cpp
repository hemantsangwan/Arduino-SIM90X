/*
 LOG.cpp - Library for standard logging convention.
 Created by Meir Michanie, June 9, 2010.
 Released into the public domain.
 Version 0.1
 */

#include "LOG.h"

LOG::LOG(int level)
        {
    setLevel(level);
}

void LOG::DATA(const char* string)
        {
    if (_level > 4) {
        debug.print(string);
    }
}

void LOG::DATA(int number)
        {
    if (_level > 4) {
        debug.print(number);
    }
}

void LOG::DEBUG(const char* string)
        {
    if (_level > 3) {
        debug.print("\n[DEBUG]: ");
        debug.println(string);
    }
}

void LOG::INFO(const char* string)
        {
    if (_level > 2) {
        debug.print("\n[INFO]: ");
        debug.println(string);
    }
}

void LOG::WARNING(const char* string)
        {
    if (_level > 1) {
        debug.print("\n[WARNING]: ");
        debug.println(string);
    }
}

void LOG::CRITICAL(const char* string)
        {
    if (_level > 0) {
        debug.print("\n[CRITICAL]: ");
        debug.println(string);
    }
}

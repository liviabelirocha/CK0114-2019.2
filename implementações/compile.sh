#!/bin/bash

g++ -Wall -Wextra -pedantic -std=c++17 -o main test.cpp

RET=$?

echo Retorno do g++: $RET

exit $RET
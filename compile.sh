#!/bin/bash

g++ -Wall -Wextra -pedantic -std=c++17 -o main.out aula30-1.cpp

RET=$?

echo Retorno do g++: $RET

exit $RET
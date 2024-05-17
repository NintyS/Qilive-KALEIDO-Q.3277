#!/bin/bash

echo "Compiling..."
g++ -c main.cpp
g++ main.o -o Test -lusb-1.0
echo "Running..."
sudo ./Test

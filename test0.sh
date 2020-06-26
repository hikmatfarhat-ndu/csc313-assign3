#!/bin/bash
rm -rf tests
mkdir tests
cd tests
cmake ..
make t0
./t0

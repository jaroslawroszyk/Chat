#!/bin/bash
pwd
ls
echo Target name
read target_name
cd build
cmake .. 
make
cd tests
./$target_name

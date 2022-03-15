#!/bin/bash
./make_src_examples.sh clean
./make_src_examples.sh
cd examples
if [ -z "$1" ]
then 
  ./test_complexe
  ./test_complexe2
  ./test_complexe3
  ./test_complexe4
else
  ./test_complexe > res/$1
  ./test_complexe2 >> res/$1
  ./test_complexe3 >> res/$1
  ./test_complexe4 >> res/$1
fi
cd ..
./make_src_examples.sh clean
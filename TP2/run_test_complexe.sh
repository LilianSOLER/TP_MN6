#!/bin/bash
./make_src_examples.sh clean
./make_src_examples.sh
cd examples
if [ -z "$1" ]
then 
  ./test_complexe
else
  ./test_complexe > res/$1
fi
cd ..
./make_src_examples.sh clean
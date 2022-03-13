#!/bin/bash

# function make_dir_option () {
#   if [ -z "$2" ]
#   then 
#     cd $1
#     make
#   else
#     cd $1
#     make $2
#   fi
# }

if [ -z "$1" ]
then 
  cd examples
  make
  cd ../src
  make
else
  cd examples
  make $1
  cd ../src
  make $1
fi

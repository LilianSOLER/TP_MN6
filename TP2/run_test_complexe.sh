#!/bin/bash
./make_src_examples.sh clean
./make_src_examples.sh
cd examples
./test_complexe
cd ..
./make_src_examples.sh clean
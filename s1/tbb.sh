#!/bin/bash
echo building TBB example with G++ + TBB lib ...
g++ tbb.cpp -o bin/tbb -ltbb
echo starting ...
bin/tbb
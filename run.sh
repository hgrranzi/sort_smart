#!/bin/bash

if (uname | grep "Linux")
then
	make -f Makefile_Linux
    make -f Makefile_Linux clean
else
    make -f Makefile_Mac
    make -f Makefile_Mac clean
fi
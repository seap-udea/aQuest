#!/bin/bash

bigkernels="de430"

#############################################################
# UNPACK KERNELS
#############################################################
for kernel in $bigkernels
do
    if [ ! -e "data/$kernel.bsp" ];then
	echo "Unpacking planetary kernel $kernel..."
	cd data
	cat $kernel.bsp.blo/* > $kernel.bsp
	cd -
    else
	echo "Kernel $kernel already unpacked..."
    fi
done

#############################################################
# CREATE MAKEFILE
#############################################################
if [ ! -e makefile ];then
    echo "Creating makefile..."
    cp makefile.in makefile
else
    echo "makefile already created..."
fi


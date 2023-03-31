#!/bin/bash

#Author: David Jepsson 920125-5271


preExt=$1
postExt=$2

for file in *."$preExt"; 
do 
    mv "$file" "${file%."$preExt"}.$postExt"; 
done
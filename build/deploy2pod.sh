#!/bin/bash

# Bash script for deploying built libraries and headers to Pod

if [ $# -lt 1 ]
then
	echo Usage: $0 path-to-pod-root 
	exit
else
	echo Checking if folder $1 actually exists...

	if [ ! -e "$1" ]; then
		echo Pod path $1 doesnot exist! Exiting... .
		exit
	fi
fi

##### Build XCode project if it doesn't exist
bash buildXCodeProject.sh 

##### Build iphoneos and iphonesimulator
xcodebuild -project ios/guidoar.xcodeproj  -target guidoar -configuration Release -sdk iphoneos CONFIGURATION_BUILD_DIR=ios/Release-iphoneos clean build 
xcodebuild -project ios/guidoar.xcodeproj  -target guidoar -configuration Release -arch x86_64 -arch i386 only_active_arch=no -sdk iphonesimulator CONFIGURATION_BUILD_DIR=ios/Release-iphonesimulator clean build 


##### Move to Pod location
OUT_LIB_NAME="/libGuidoARlib-iOS"

libname="/libguidoar.a"

# pod paths
podlibpath="$1/GuidoKit/Classes/Libs/guidoar$OUT_LIB_NAME"
podpublicheaderpath="$1/GuidoKit/Classes/Headers/Public"

##### Make Universal Lib and copy to Pod
# Check if Release-iphoneos and Release-iphonesimulator libraries exists
iphonebuildpath="$(pwd)/ios/Release-iphoneos$libname"
simulatorbuildpath="$(pwd)/ios/Release-iphonesimulator$libname"
universalpath="$(pwd)/ios$OUT_LIB_NAME"
if [ -f "$iphonebuildpath" ]
then
	echo iPhoneOS lib exists!
else
	echo Build the iPhoneOS library in $iphonebuildpath ! Exiting... .
	exit
fi

if [ -f $simulatorbuildpath ]
then
	echo iPhoneSimulator lib exists!
else
	echo Build the simulator library in ./Release-iphonesimulator ! Exiting... .
	exit
fi

# Lipo them together
lipo -create $iphonebuildpath $simulatorbuildpath -output $universalpath

if [ $? -eq 0 ]; then
	echo Lipo built the Universal library! Copying to Pod.
else
	echo Lipo failed! Exiting... .
	exit
fi

cp -v $universalpath $podlibpath
if [ $? -eq 0 ]; then
	echo Universal Library copied to Pod.
else
	echo Copy failed! Exiting... .
	exit
fi

##### Update src
localheaderpath="$(pwd)/../src/objc/libguidoar.h"
cp -v $localsrcpath $podsrcpath
if [ $? -eq 0 ]; then
	echo Public Header copied to Pod.
else
	echo Publib Header Copy failed! Exiting... .
	exit
fi



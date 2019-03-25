#!/bin/sh

if [ ! -d ./ios/guidoar.xcodeproj  ]; then
   if [ ! -d ios  ]; then
	mkdir ios
   fi
	cd ./ios
	cmake .. -DMIDIEXPORT=no -DIOS=yes -G Xcode
	cd ..
else
  echo "./build/ios/guidoar.xcodeproj already  exists"
fi

if [ ! -d ./macos/guidoar.xcodeproj  ]; then
	if [ ! -d macos  ]; then
		mkdir macos
	fi
	cd ./macos
	cmake .. -DMIDIEXPORT=no -DIOS=no -G Xcode
	cd ..
else
	echo "./build/macos/guidoar.xcodeproj already  exists"
fi

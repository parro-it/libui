#!/bin/bash

cd out
mkdir tmp
cp controlgallery cpp-multithread histogram tmp
cd tmp
tar -czvf ../../../artifacts/examples-static-$TRAVIS_OS_NAME-$BUILD_ARCH-$TRAVIS_TAG.tar.gz *
cd ..


rm -rf tmp
mkdir tmp
cp libui.a ../../*.h tmp
cd tmp
tar -czvf ../../../artifacts/libui-static-$TRAVIS_OS_NAME-$BUILD_ARCH-$TRAVIS_TAG.tar.gz *

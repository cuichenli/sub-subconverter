#!/bin/bash
set -xe

git submodule update --init --recursive


# setup libcron
pushd libcron
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../deps .
make libcron install -j3
popd

# setup quickjspp
pushd quickjspp
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../deps .
make install -j3
popd

# setup cmake dependencies
rm -rf build
conan install . --output-folder=build --build=missing
pushd build 
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build . || true

LINK_COMMAND=$(cat ./CMakeFiles/subconverter.dir/link.txt)
eval "${LINK_COMMAND} -l:quickjs/libquickjs.a" 
popd
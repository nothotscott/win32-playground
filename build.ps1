$BUILD = "build"

if (!(test-path $BUILD)) {
	md $BUILD
}
cd $BUILD
cmake -G Ninja ../
ninja all

cd ../
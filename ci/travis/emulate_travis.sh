restore_dir=$PWD
cd ../..
export TRAVIS_BUILD_DIR=$PWD
export TRAVIS=true
echo "TRAVIS_BUILD_DIR set to $TRAVIS_BUILD_DIR"
cd $restore_dir

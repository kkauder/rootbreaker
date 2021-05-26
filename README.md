# rootbreaker
Minimal-ish test to demonstrate dictionary issues in root 6.24

## Preparation
```sh
source $ROOTSYS/bin/thisroot.sh
export BASEDIR=`pwd`
export ROOT_INCLUDE_PATH=$BASEDIR/install/include
export ROOT_LIBRARY_PATH=$BASEDIR/install/lib
export DYLD_LIBRARY_PATH=$BASEDIR/install/lib:$DYLD_LIBRARY_PATH
export CMAKE_MODULE_PATH=$BASEDIR/install/cmake
export CMAKE_PREFIX_PATH=$BASEDIR/install/cmake:$CMAKE_PREFIX_PATH
## make sure we don't have any detritus
rm -r $BASEDIR/install
```

## Build the library
```sh
rm -r $BASEDIR/BuildTest/build
mkdir $BASEDIR/BuildTest/build ; cd $BASEDIR/BuildTest/build
cmake -DCMAKE_INSTALL_PREFIX=$BASEDIR/install ..
make -j 4 install
```

## Build and run the stand-alone tester
```sh
rm -r $BASEDIR/UseTest/build
mkdir $BASEDIR/UseTest/build ; cd $BASEDIR/UseTest/build
cmake  ..
make
./tester
```

#### Expected behavior:
The payload is
```c++
TClass branchClass(c->GetBranch("event")->GetClassName());
  if (branchClass.InheritsFrom("dicttest::EventDis")) {
    cout << "yarp" << endl;
  }
```
Since this code literally just used EventPythia to create the tree, expect `yarp`

#### Observed behavior:
```
Warning in <TClass::TClass>: no dictionary for class dicttest::EventPythia is available
Error in <TObjArray::At>: index 0 out of bounds (size: 1, this: 0x1360bd2d0)
Error in <TObjArray::At>: index 0 out of bounds (size: 1, this: 0x1360bd2d0)
norp
```

#### Interactive usage works:
```
% root -l
root [0] gSystem->Load("libeictest")
## paste contents of tester.cxx
yarp
```

## FYI: Root compile flags
```sh
git checkout v6-24-00
cmake -D unuran=on -D minuit2=on -D roofit=on \
      -D gdml=on \
      -Dfortran=ON \
      -Dbuiltin_vdt=ON \
      -Dbuiltin_glew=ON \
      -DCMAKE_INSTALL_PREFIX=${ROOTSYS} \
      ..
```

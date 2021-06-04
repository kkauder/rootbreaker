# rootbreaker
Minimal-ish test to demonstrate dictionary issues.
After some testing, it works in 6.20.04 and breaks in 6.20.06 and thereafter.

## Preparation
```sh
git clone https://github.com/kkauder/rootbreaker.git
cd rootbreaker
source $ROOTSYS/bin/thisroot.sh
export BASEDIR=`pwd`
export ROOT_INCLUDE_PATH=$BASEDIR/install/include
export ROOT_LIBRARY_PATH=$BASEDIR/install/lib
export DYLD_LIBRARY_PATH=$BASEDIR/install/lib:$DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$BASEDIR/install/lib:$LD_LIBRARY_PATH
export CMAKE_MODULE_PATH=$BASEDIR/install/cmake
export CMAKE_PREFIX_PATH=$BASEDIR/install/cmake:$CMAKE_PREFIX_PATH
```

## Build the library and tester
```sh
## make sure we don't have any detritus
rm -r $BASEDIR/install
rm -r $BASEDIR/build
mkdir $BASEDIR/build ; cd $BASEDIR/build
cmake -DCMAKE_INSTALL_PREFIX=$BASEDIR/install ..
make -j 4 install
```

## Run the tester
```sh
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

#### Observed behavior for root 6.20.06 and beyond:
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
git checkout v6-20-06
cmake -D unuran=on -D minuit2=on -D roofit=on \
      -D gdml=on \
      -Dfortran=ON \
      -Dbuiltin_vdt=ON \
      -Dbuiltin_glew=ON \
      -DCMAKE_INSTALL_PREFIX=${ROOTSYS} \
      ..
```

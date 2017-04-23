# matrix-hal-app-boilerplate

This repo provides boilerplate code for MATRIX Creator HAL-based applications to be built with cmake.
Authors of such applications must have completed the installation of the MATRIX Creator HAL, as described in detail in https://github.com/matrix-io/matrix-creator-hal.

In order to create a new MATRIX Creator HAL app, download and unzip the contents of this repo, and perform the following steps:

1) create and cd into folder `build`
2) create build environment with cmake
3) build with make

```
mkdir build &&
cd build &&
cmake .. &&
make &&
```

Now, feel free to write your own MATRIX Creator HAL-based app in `cpp/matrix-app.cpp`.
Use `make` to rebuild. Then, run app with

```
./matrix-app
```

## Have fun!

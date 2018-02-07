# ZebrafishTracker

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

## Example Usage

```shell
cd ~/git/ZebrafishTracker
./bin/ZebrafishTracker
```

```shell
./bin/ZebrafishTracker --help
  --help      Print usage and exit.
  --debug     Print debug.
  --mouse     Track mouse click location instead of blob.
  --paralyze  Disable stage so it does not move.
```

## Installation

### Setup Linear Motors

<https://github.com/janelia-experimental-technology/linear_motor_setup>

### Setup Jetson

<https://github.com/janelia-experimental-technology/nvidia_jetson_setup>

### Install Dependencies

```shell
sudo apt-get install cmake
sudo apt-get install libboost-all-dev
```

# Checkout Git Repositories

```shell
mkdir ~/git
cd ~/git
git clone https://github.com/janelia-experimental-technology/ZebrafishTracker.git
git clone https://github.com/janelia-experimental-technology/ZebrafishTrackerCalibration.git
```

### Compile

```shell
cd ~/git/ZebrafishTracker
mkdir build
cd build
cmake ..
make
```

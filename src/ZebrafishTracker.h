// ----------------------------------------------------------------------------
// ZebrafishTracker.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _ZEBRAFISH_TRACKER_H_
#define _ZEBRAFISH_TRACKER_H_
#include <iostream>
#include <signal.h>
#include <opencv2/core.hpp>
#include <opencv2/core/cuda.hpp>

// #if CUDA_FOUND
#include <cuda_runtime_api.h>
#include <cuda.h>
// #endif

#include "Configuration.h"
#include "Camera.h"
#include "ImageProcessor.h"
#include "StageController.h"
#include "Calibration.h"
#include "CoordinateConverter.h"


class ZebrafishTracker
{
public:
  ZebrafishTracker();

  void processCommandLineArgs(int argc, char * argv[]);
  void connectHardware();
  void disconnectHardware();
  void enableGpu();
  void allocateMemory();
  void findCalibration();
  void run();

private:
  Configuration configuration_;
  Camera camera_;
  ImageProcessor image_processor_;
  StageController stage_controller_;
  bool stage_homed_;
  bool stage_homing_;
  Calibration calibration_;
  CoordinateConverter coordinate_converter_;
  bool paralyzed_;
  bool blind_;
  bool recalibrate_;
  bool gpu_enabled_;

  volatile static sig_atomic_t run_enabled_;
  static void interruptSignalHandler(int sig);

  void connectCamera();
  void disconnectCamera();
  void connectStageController();
  void disconnectStageController();
};

#endif

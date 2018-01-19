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
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>

#include "Camera.h"
#include "BlobTracker.h"
#include "StageController.h"


class ZebrafishTracker
{
public:
  ZebrafishTracker();

  bool processCommandLineArgs(int argc, char * argv[]);
  bool importCalibrationData();
  bool connectHardware();
  bool disconnectHardware();
  void run();

private:
  const static bool SUCCESS = true;
  cv::Mat homography_image_to_stage_;
  Camera camera_;
  BlobTracker blob_tracker_;
  StageController stage_controller_;

  volatile static sig_atomic_t enabled_;
  static void interruptSignalHandler(int sig);

  bool connectCamera();
  bool disconnectCamera();
  bool connectStageController();
  bool disconnectStageController();
};

#endif

// ----------------------------------------------------------------------------
// Cameras.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _CAMERAS_H_
#define _CAMERAS_H_
#include <iostream>
#include <sstream>
#include <FlyCapture2.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class Cameras
{
public:
  Cameras();

  void printLibraryInfo();
  size_t countCameras();
  bool connectToCamera(size_t camera_index);
  void printCameraInfo();
  bool startCameraCapture();
  bool retrieveImage(cv::Mat & image);
  bool stopCameraCapture();
  bool disconnectCamera();
private:
  FlyCapture2::Error error_;
  FlyCapture2::BusManager bus_mgr_;
  size_t camera_index_;
  FlyCapture2::Camera camera_;
  FlyCapture2::CameraInfo camera_info_;
  static const size_t buffer_count_=300;
  FlyCapture2::Image raw_image_;
  FlyCapture2::Image rgb_image_;

  bool error();
  void printError();
};

#endif

// ----------------------------------------------------------------------------
// Camera.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <FlyCapture2.h>


class Camera
{
public:
  Camera();

  void printLibraryInfo();
  size_t count();
  bool setDesiredCameraIndex(const size_t camera_index);
  bool connect();
  void printCameraInfo();
  bool start();
  bool grabImage(cv::Mat & image);
  bool stop();
  bool disconnect();
  float getCameraTemperature();
private:
  FlyCapture2::Error error_;
  FlyCapture2::BusManager bus_mgr_;
  size_t camera_index_;
  FlyCapture2::PGRGuid guid_;
  FlyCapture2::Camera camera_;
  FlyCapture2::CameraInfo camera_info_;
  static const size_t buffer_count_=3;
  FlyCapture2::Image raw_image_;
  FlyCapture2::Image rgb_image_;

  struct Config
  {
    double frame_rate;
    bool auto_exposure;
    double exposure;
    bool auto_shutter;
    double shutter_speed;
    bool auto_gain;
    double gain;
    double brightness;
    bool auto_sharpness;
    double sharpness;
    bool auto_saturation;
    double saturation;
    double gamma;
  } config_;


  bool error();
  void printError();
  bool configure();
  bool setProperty(const FlyCapture2::PropertyType &type,
                   const bool &auto_set,
                   unsigned int &value_a,
                   unsigned int &value_b);
  bool setProperty(const FlyCapture2::PropertyType &type,
                   const bool &auto_set,
                   double &value);
};

#endif

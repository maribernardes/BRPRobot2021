/*=========================================================================
  Language:  C++
  Please see
    http://wiki.na-mic.org/Wiki/index.php/ProstateBRP_OpenIGTLink_Communication_June_2013
  for the detail of the protocol.

=========================================================================*/

#ifndef __RobotStatus_h
#define __RobotStatus_h

#include <string>
#include <map>
#include "Robot.hpp"
#include "igtlSocket.h"
#include "igtlMath.h"
#include "igtlMessageBase.h"
#include "RobotCommunicationBase.h"

class RobotStatus
{
public:
  RobotStatus();
  ~RobotStatus();

  int GetTargetFlag() { return FlagTarget; }
  int GetCalibrationFlag() { return this->FlagCalibration; };

  void SetCalibrationMatrix(igtl::Matrix4x4 &matrix);

  // Return 0 if a calibration matrix has not been set.
  int GetCalibrationMatrix(igtl::Matrix4x4 &matrix);

  void SetTargetMatrix(igtl::Matrix4x4 &matrix);

  // Return 0 if a target matrix has not been set.
  int GetTargetMatrix(igtl::Matrix4x4 &matrix);
  Robot robot;

protected:
  int FlagCalibration;
  int FlagTarget;
};

#endif //__RobotStatus_h

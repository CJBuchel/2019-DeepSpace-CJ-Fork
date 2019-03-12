#include "CurtinCtre.h"

#include <frc/RobotController.h>

using namespace curtinfrc;


// TALON

void Talon::StopMotor() {
  Disable();
}

void Talon::PIDWrite(double output) {
  Set(output);
}

double Talon::Get() const {
  return _value;
}

// void Talon::ModifyConfig(std::function<void(Talon::Configuration &)> func) {
//   Talon::Configuration config = SaveConfig();
//   func(config);
//   LoadConfig(config);
// }


// SRX

void TalonSrx::StopMotor() {
  Disable();
}

void TalonSrx::PIDWrite(double output) {
  Set(output);
}

double TalonSrx::Get() const {
  return _value;
}

int TalonSrx::GetEncoderRawTicks() {
  return GetSensorPosition();
}

double TalonSrx::GetEncoderTickVelocity() {
  return (double)GetSensorVelocity() * 10;
}

void TalonSrx::ModifyConfig(std::function<void(TalonSrx::Configuration &)> func) {
  TalonSrx::Configuration config = SaveConfig();
  func(config);
  LoadConfig(config);
}


// SPX

void VictorSpx::StopMotor() {
  Disable();
}

void VictorSpx::PIDWrite(double output) {
  Set(output);
}

double VictorSpx::Get() const {
  return _value;
}

void VictorSpx::ModifyConfig(std::function<void(VictorSpx::Configuration &)> func) {
  VictorSpx::Configuration config = SaveConfig();
  func(config);
  LoadConfig(config);
}

#include "BoxIntake.h"
#include "ControlMap.h"

void BoxIntake::IntakingPeriodic() {
  _config.motors.transmission->Set(1 * ControlMap::boxDeployedThrottle);
}

void BoxIntake::OuttakingPeriodic() {
  _config.motors.transmission->Set(-1 * ControlMap::boxDeployedThrottle);
}

void BoxIntake::DeployingPeriodic() {
  _config.motors.transmission->StopMotor();
}

void BoxIntake::StowingPeriodic() {
  _config.motors.transmission->Set(ControlMap::boxStowingThrottle);
}

void BoxIntake::StowedPeriodic() {
  _config.motors.transmission->Set(ControlMap::boxStowedThrottle);
}


void BoxIntakeManualStrategy::OnUpdate(double dt) {
  if (_contGroup.GetButton(ControlMap::boxIn)) {
    _boxIntake.SetIntaking();
  } else if (_contGroup.GetButton(ControlMap::boxOut)) {
    _boxIntake.SetOuttaking();
  } else if (_contGroup.GetButton(ControlMap::boxStow)) {
    _boxIntake.SetStowed();
  }
}

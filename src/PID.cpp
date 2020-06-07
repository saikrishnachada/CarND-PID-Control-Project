#include "PID.h"

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  // Previous cte.
  old_cte = 0.0;

}

void PID::UpdateError(double cte) {
  // Proportional error.
  p_error = cte;

  // Integral error.
  i_error += cte;

  // Diferential error.
  d_error = cte - old_cte;
  old_cte = cte;
}

double PID::TotalError() {
  return p_error * Kp + i_error * Ki + d_error * Kd;
}


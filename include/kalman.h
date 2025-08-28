
#pragma once

#include "Arduino.h"
#include "stdint.h"

namespace KalmanFilter
{
    struct Kalman
    {
        float zvb[3];   // [z, v, b] height, vertical velocity, accel bias
        float Q[3];     // diag process noise: [qz, qv, qb]
        float P[3][3];  // covariance
        float R_bps;    // baro variance
    };

    void init(Kalman &state, float z0, float v0, float b0,
                          float qz, float qv, float qb, float R_bps);

    void predict(Kalman &state, float a_meas_z, float dt_s);
    void update_bps(Kalman &state, float m_meas_z);
    void mx3_clone(float dst [3][3], float src [3][3]);
}
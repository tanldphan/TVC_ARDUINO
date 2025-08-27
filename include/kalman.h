
#pragma once

#include "Arduino.h"
#include "stdint.h"

namespace KalmanFilter
{
    struct Kalman
    {
        float x[3];      // [z, v, b] height, vertical velocity, accel bias
        float P[3][3];   // covariance
        float Q[3];      // diag process noise: [qz, qv, qb]
        float R_bps;    // baro variance
    };

    bool init(Kalman &kf, float z0, float v0, float b0,
            float qz, float qv, float qb, float R_bps);

    void predict(Kalman &kf, float a_meas_z, float dt_s);
    void update_bps(Kalman &kf, float m_meas_z);
    float convert(float *p, float *p0);
}
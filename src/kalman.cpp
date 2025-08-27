#include "kalman.h"
#include "bps.h"
#include "imu.h"
#include "bps.h"

float a = IMUmodule::imu.getAccelY_mss();

namespace KalmanFilter
{

    bool init(Kalman &kf, float z0, float v0, float b0,
            float qz, float qv, float qb, float R_bps)
    {
        return true;
    }

    void predict(Kalman &kf, float a_meas_mps2, float dt_s)
    {

    }
    void update_bps(Kalman &kf, float m_meas_z)
    {
        
    }
}
#include "kalman.h"
#include "bps.h"
#include "imu.h"
#include "bps.h"

namespace KalmanFilter
{
    void init(Kalman &state, float z0, float v0, float b0,
                             float qz, float qv, float qb, float R_bps)
    {
        // vertical state
        state.zvb[0] = z0;
        state.zvb[1] = v0;
        state.zvb[2] = b0;
        
        // process noise
        state.Q[0] = qz;
        state.Q[1] = qv;
        state.Q[2] = qb;

        // covariance P
        memset(state.P, 0, sizeof(state.P));
        state.P[0][0] = 10.0f;
        state.P[1][1] = 10.0f; 
        state.P[2][2] = 1.0f;

        // measurement noise
        state.R_bps = R_bps;
    }

    void predict(Kalman &state, float a_meas_mps2, float dt_s)
    {

    }

    void update_bps(Kalman &state, float m_meas_z)
    {
        
    }

    void mx3_clone(float dst [3][3], float src [3][3])
    {
        memcpy(dst, src, sizeof(float) * 9);
    }
}
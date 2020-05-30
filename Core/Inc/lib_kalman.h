/**
 * @file lib_kalman.h
 * @author 赵晨瑄 (chenxuan.zhao@icloud.com)
 * @brief 卡尔曼滤波
 * @version 0.1
 * @date 2020-05-27
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __LIB_KALMAN_H
#define __LIB_KALMAN_H

typedef struct __KalmanTypeDef {
  float estimate_covariance; /* 估计协方差 */
  float measure_covariance;  /* 测量协方差 */
  float estimate_value;      /* 估计值 */
} KalmanTypeDef;

#ifdef __cplusplus
extern "C" {
#endif

void Kalman_FilterInit(KalmanTypeDef *);
void Kalman_FilterUpdate(KalmanTypeDef *, float);

#ifdef __cplusplus
}
#endif

#endif /* __LIB_KALMAN_H */

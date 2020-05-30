/**
 * @file lib_kalman.c
 * @author 赵晨瑄 (chenxuan.zhao@icloud.com)
 * @brief 卡尔曼滤波
 * @version 0.1
 * @date 2020-05-27
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "lib_kalman.h"

#include <math.h>
#include <stdlib.h>

void Kalman_FilterInit(KalmanTypeDef *cfg) {
  cfg->estimate_value = 0;
  cfg->estimate_covariance = 0.1;
  cfg->measure_covariance = 0.02;
}

void Kalman_FilterUpdate(KalmanTypeDef *cfg, float measure) {
  float kalman_gain = 0;

  /* 计算卡尔曼增益 */
  kalman_gain = cfg->estimate_covariance *
                sqrt(1 / (pow(cfg->estimate_covariance, 2) +
                          pow(cfg->measure_covariance, 2) + 1));

  /* 计算本次滤波估计值 */
  cfg->estimate_value =
      cfg->estimate_value + kalman_gain * (measure - cfg->estimate_value);

  /* 更新估计协方差 */
  cfg->estimate_covariance = sqrt(1 - kalman_gain) * cfg->estimate_covariance;

  /* 更新测量方差 */
  cfg->measure_covariance = sqrt(1 - kalman_gain) * cfg->measure_covariance;
}

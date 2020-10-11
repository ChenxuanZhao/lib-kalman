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

void KalmanFilter_Init(KalmanTypeDef *cfg) {
    cfg->x = 0;
    cfg->p = 5;
    cfg->A = 1;
    cfg->H = 1;
    cfg->q = 0.25;
    cfg->r = 1;
}

float KalmanFilter_Update(KalmanTypeDef *cfg, float measure) {
    cfg->x = cfg->A * cfg->x;
    cfg->p = cfg->A * cfg->A * cfg->p + cfg->q;

    cfg->gain = cfg->p * cfg->H / (cfg->p * cfg->H * cfg->H + cfg->r);
    cfg->x = cfg->x + cfg->gain * (measure - cfg->H * cfg->x);
    cfg->p = (1 - cfg->gain * cfg->H) * cfg->p;

    return cfg->x;
}

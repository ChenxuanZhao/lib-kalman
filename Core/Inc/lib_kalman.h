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

#ifndef __LIB_KALMAN_H__
#define __LIB_KALMAN_H__

typedef struct __KalmanTypeDef {
    float x;
    float A;
    float H;
    float q;
    float r;
    float p;
    float gain;
} KalmanTypeDef;

#ifdef __cplusplus
extern "C" {
#endif

void KalmanFilter_Init(KalmanTypeDef *);
float KalmanFilter_Update(KalmanTypeDef *, float);

#ifdef __cplusplus
}
#endif

#endif /* __LIB_KALMAN_H__ */

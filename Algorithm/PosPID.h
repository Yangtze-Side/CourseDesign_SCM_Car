#ifndef __PID_H
#define __PID_H

#include "user_math.h"

/*------------------------------------------- PID ------------------------------------------*/

// 微分先行的位置式 PID
typedef struct PosPID_t {
    float e;            // 误差
    float e_last;       // 上次误差
    float e_int;        // 误差积分

    float Kp;           // 比例系数
    float Ki;           // 积分系数
    float Kd;           // 微分系数（微分项不除以时间因子）

    float e_int_max;    // 积分限幅（正数）
    float e_int_dis;    // 积分失能（正数）
    float delta_e_max;  // 误差限幅（正数）（当误差变化较大时认为是目标改变引起的）
    float u_max;        // 输出限幅（正数）

    float u;            // 输出
} PosPID_t;

void PosPID_Init(PosPID_t *pid, float kp, float ki, float kd, float intMax, float intDis, float DeMax, float uMax);
void PosPID_Update(PosPID_t *pid, float ek);
void PosPID_Clear(PosPID_t *pid);

#if 0

/*------------------------------------------- PI ------------------------------------------*/

// 位置式 PI
typedef struct PosPI_t {
    float e;            // 误差
    float e_int;        // 误差积分

    float Kp;           // 比例系数
    float Ki;           // 积分系数

    float e_int_max;    // 积分限幅（正数）
    float e_int_dis;    // 积分失能（正数）
    float u_max;        // 输出限幅（正数）

    float u;            // 输出
} PosPI_t;

void PosPI_Init(PosPI_t *pi, float kp, float ki, float intMax, float intDis, float uMax);
void PosPI_Update(PosPI_t *pi, float ek);
void PosPI_Clear(PosPI_t *pi);


/*------------------------------------------- PD ------------------------------------------*/

// 微分先行的位置式 PD
typedef struct PosPD_t {
    float e;            // 误差

    float Kp;           // 比例系数
    float Kd;           // 微分系数（微分项不除以时间因子）

    float u_max;        // 输出限幅（正数）

    float u;            // 输出
} PosPD_t;

void PosPD_Init(PosPD_t *pd, float kp, float kd, float uMax);
void PosPD_Update(PosPD_t *pd, float ek, float delta_e);

#endif

#endif // !__PID_H

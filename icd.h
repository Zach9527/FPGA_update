/*!
    \file  icd.h
    \brief 
*/

#ifndef __ICD_H
#define __ICD_H

#include <string.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"{
#endif

#define ICD_OK 0
#define ICD_ERR (-1)

#define ICD_MAX_LEN 1024

typedef struct {
	uint32_t head;//数据包头
	uint32_t cmd;//ICD命令
	uint32_t size;//数据长度
	
} XXXXX;

/*
 * 封装舵机控制命令数据包
 * long long sysTick:系统时间戳
 * int16_t *djCmd：四个电机控制数据
 * uint8_t *seq：帧序号
 * uint8_t *sendBuf：封装好的数据
 * int *sendBufSize：封装好的数据，最大100字节
 * uint8_t *sendDat：封装前的数据，没有包头和转译
 * 返回值：ICD_ERR/ICD_OK
 */

#ifdef __cplusplus
}
#endif

#endif /* __HEX_FILE_H */


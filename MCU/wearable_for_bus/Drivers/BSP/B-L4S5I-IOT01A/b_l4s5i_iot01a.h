/**
  ******************************************************************************
  * @file  : b_l4s5i_iot01a.h
  * @brief : header file for the BSP Common driver
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __B_L4S5I_IOT01A_H
#define __B_L4S5I_IOT01A_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "b_l4s5i_iot01a_conf.h"
#include "b_l4s5i_iot01a_errno.h"
#include "main.h"

#if (USE_BSP_COM_FEATURE > 0)
  #if (USE_COM_LOG > 0)
    #if defined(__ICCARM__) || defined(__CC_ARM) /* For IAR and MDK-ARM */
      #include <stdio.h>
    #endif
  #endif
#endif
/** @addtogroup BSP
 * @{
 */

/** @defgroup B_L4S5I_IOT01A
 * @{
 */

/** @defgroup B_L4S5I_IOT01A_LOW_LEVEL
 * @{
 */

/** @defgroup STM32L4XX_NUCLEO_LOW_LEVEL_Exported_Constants LOW LEVEL Exported Constants
  * @{
  */
/**
 * @brief STM32L4XX NUCLEO BSP Driver version number V1.0.0
 */
#define __B_L4S5I_IOT01A_BSP_VERSION_MAIN   (uint32_t)(0x01) /*!< [31:24] main version */
#define __B_L4S5I_IOT01A_BSP_VERSION_SUB1   (uint32_t)(0x00) /*!< [23:16] sub1 version */
#define __B_L4S5I_IOT01A_BSP_VERSION_SUB2   (uint32_t)(0x00) /*!< [15:8]  sub2 version */
#define __B_L4S5I_IOT01A_BSP_VERSION_RC     (uint32_t)(0x00) /*!< [7:0]  release candidate */
#define __B_L4S5I_IOT01A_BSP_VERSION        ((__B_L4S5I_IOT01A_BSP_VERSION_MAIN << 24)\
                                                    |(__B_L4S5I_IOT01A_BSP_VERSION_SUB1 << 16)\
                                                    |(__B_L4S5I_IOT01A_BSP_VERSION_SUB2 << 8 )\
                                                    |(__B_L4S5I_IOT01A_BSP_VERSION_RC))

/** @defgroup B_L4S5I_IOT01A_LOW_LEVEL_Exported_Types B_L4S5I_IOT01A LOW LEVEL Exported Types
 * @{
 */

 /**
  * @brief Define for B_L4S5I_IOT01A board
  */
#if !defined (USE_B_L4S5I_IOT01A)
 #define USE_B_L4S5I_IOT01A
#endif
#ifndef USE_BSP_COM_FEATURE
   #define USE_BSP_COM_FEATURE                  0U
#endif

/**
 * @}
 */

/** @defgroup B_L4S5I_IOT01A_LOW_LEVEL_COM B_L4S5I_IOT01A LOW LEVEL COM
 * @{
 */
/**
 * @brief Definition for COM portx, connected to USART1
 */

#define BUS_USART1_INSTANCE USART1
#define BUS_USART1_TX_GPIO_PIN GPIO_PIN_6
#define BUS_USART1_TX_GPIO_PORT GPIOB
#define BUS_USART1_TX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_USART1_TX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_USART1_TX_GPIO_AF GPIO_AF7_USART1
#define BUS_USART1_RX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_USART1_RX_GPIO_PORT GPIOB
#define BUS_USART1_RX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_USART1_RX_GPIO_PIN GPIO_PIN_7
#define BUS_USART1_RX_GPIO_AF GPIO_AF7_USART1

/**
 * @}
 */

/** @defgroup B_L4S5I_IOT01A_LOW_LEVEL_Exported_Types LOW LEVEL Exported Types
  * @{
  */
#ifndef USE_BSP_COM
  #define USE_BSP_COM                           0U
#endif

#ifndef USE_COM_LOG
  #define USE_COM_LOG                           1U
#endif

#if (USE_BSP_COM_FEATURE > 0)
typedef enum
{
  COM1 = 0U,
  COMn
}COM_TypeDef;

typedef enum
{
 COM_WORDLENGTH_8B     =   UART_WORDLENGTH_8B,
 COM_WORDLENGTH_9B     =   UART_WORDLENGTH_9B,
}COM_WordLengthTypeDef;

typedef enum
{
 COM_STOPBITS_1     =   UART_STOPBITS_1,
 COM_STOPBITS_2     =   UART_STOPBITS_2,
}COM_StopBitsTypeDef;

typedef enum
{
 COM_PARITY_NONE     =  UART_PARITY_NONE,
 COM_PARITY_EVEN     =  UART_PARITY_EVEN,
 COM_PARITY_ODD      =  UART_PARITY_ODD,
}COM_ParityTypeDef;

typedef enum
{
 COM_HWCONTROL_NONE    =  UART_HWCONTROL_NONE,
 COM_HWCONTROL_RTS     =  UART_HWCONTROL_RTS,
 COM_HWCONTROL_CTS     =  UART_HWCONTROL_CTS,
 COM_HWCONTROL_RTS_CTS =  UART_HWCONTROL_RTS_CTS,
}COM_HwFlowCtlTypeDef;

typedef struct
{
  uint32_t             BaudRate;
  COM_WordLengthTypeDef  WordLength;
  COM_StopBitsTypeDef  StopBits;
  COM_ParityTypeDef    Parity;
  COM_HwFlowCtlTypeDef HwFlowCtl;
}COM_InitTypeDef;
#endif

#define MX_UART_InitTypeDef          COM_InitTypeDef
#define MX_UART_StopBitsTypeDef      COM_StopBitsTypeDef
#define MX_UART_ParityTypeDef        COM_ParityTypeDef
#define MX_UART_HwFlowCtlTypeDef     COM_HwFlowCtlTypeDef
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1U)
typedef struct
{
  void (* pMspInitCb)(UART_HandleTypeDef *);
  void (* pMspDeInitCb)(UART_HandleTypeDef *);
} BSP_COM_Cb_t;
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS == 1U) */

/**
 * @}
 */

#define COMn                             1U
#define COM1_UART                        USART1

#define COM_POLL_TIMEOUT                 1000
extern UART_HandleTypeDef hcom_uart[COMn];
#define  huart1 hcom_uart[COM1]

/**
 * @}
 */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup B_L4S5I_IOT01A_LOW_LEVEL_Exported_Variables LOW LEVEL Exported Constants
  * @{
  */
/**
  * @}
  */

/** @defgroup B_L4S5I_IOT01A_LOW_LEVEL_Exported_Functions B_L4S5I_IOT01A LOW LEVEL Exported Functions
 * @{
 */

int32_t  BSP_GetVersion(void);
#if (USE_BSP_COM_FEATURE > 0)
int32_t  BSP_COM_Init(COM_TypeDef COM);
int32_t  BSP_COM_DeInit(COM_TypeDef COM);
#endif

#if (USE_COM_LOG > 0)
int32_t  BSP_COM_SelectLogPort(COM_TypeDef COM);
#endif

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1U)
int32_t BSP_COM_RegisterDefaultMspCallbacks(COM_TypeDef COM);
int32_t BSP_COM_RegisterMspCallbacks(COM_TypeDef COM , BSP_COM_Cb_t *Callback);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif /* __B_L4S5I_IOT01A__H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

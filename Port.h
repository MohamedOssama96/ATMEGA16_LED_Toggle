 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Mohamed Osama
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"
#include "Micro_Config.h"
#include "Std_Types.h"

#define INPUT     (0U)
#define OUTPUT    (1U)

/****************************************************************************************************************/
/* Description: Structure to describe each individual PIN contains:
 *	1. the PORT Which the pin belongs to. 0, 1, 2 or 3
 *	2. the number of the pin in the PORT.
 *  3. the direction of pin --> INPUT or OUTPUT
 */
typedef struct 
{
	uint8 port; 
	uint8 pin_num; 
	uint8 direction;
}Port_Config;
/***************************************************************************************************************/

/* configure the PIN to input or output pin */
void Port_SetDirection(const Port_Config *s_Config_Msg );

#endif /* PORT_H */


#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
/* None */

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Init Channel */
#define PORT_INIT_SID                   	(uint8)0x00

/* Service ID for PORT set pin direction */
#define PORT_SET_PIN_DIRECTION_SID      	(uint8)0x01

/* Service ID for PORT refresh port direction */
#define PORT_REFRESH_PORT_DIRECTION_SID 	(uint8)0x02

/* Service ID for PORT GetVersionInfo */
#define PORT_GET_VERSION_INFO_SID       	(uint8)0x03

/* Service ID for PORT set pin mode */
#define PORT_RSET_PIN_MODE_SID     			(uint8)0x04


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN					(uint8)0x0A

/* Port Pin is not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE   	(uint8)0x0B

/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG    				(uint8)0x0C

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE       	(uint8)0x0D

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE        	(uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT                   	(uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER 				(uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Type definition for Port_PinDirectionType used by the PORT APIs */
typedef enum {PORT_PIN_IN=0x00 , PORT_PIN_OUT=0x01} Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

typedef struct
{
	/* Member contains the ID of the Port that this Pin belongs to */
	Port_PortType Port_Num;
	/* Member contains the ID of the Pin in the port */
	Port_PinType Pin_Num;
	/* Member contains the direction of the Pin*/
	Port_PinDirectionType Pin_Dir;
} Port_ConfigPin;

/* Data Structure required for initializing the Port Driver */
typedef struct
{
	Port_ConfigPin Pins[PORT_CONFIGURED_PINS];
} Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for PORT read Channel API */
Port_PortLevelType Port_ReadPort(Port_PortType PortId);

/* Function for PORT write Channel API */
void Port_WritePort(Port_PortType PortId, Port_PortLevelType Level);

/* Function for PORT read Port API */
Port_LevelType Port_ReadChannel(Port_ChannelType ChannelId);

/* Function for PORT write Port API */
void Port_WriteChannel(Port_ChannelType ChannelId, Port_LevelType Level);

/* Function for PORT Initialization API */
void Port_Init(const Port_ConfigType * ConfigPtr);

#if (PORT_FLIP_CHANNEL_API == STD_ON)
/* Function for PORT flip channel API */
Port_LevelType Port_FlipChannel(Port_ChannelType ChannelId);
#endif

/* Function for PORT Get Version Info API */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */

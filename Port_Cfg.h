 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Port Module.
 *
 * Author: Mohamed Osama
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Number of the configured PORT Pins */
#define PORT_CONFIGURED_PINS             	 (2U)

/* Channel Index in the array of structures in PORT_PBcfg.c */
#define PortConf_LED_PIN_ID_INDEX        	 (uint8)0x00
#define PortConf_BUTTON_IN_ID_INDEX     	 (uint8)0x01

/* PORT Configured Port ID's  */
#define PortConf_LED_PORT_NUM                (Port_PortType)2 /* PORTC */
#define PortConf_BUTTON_PORT_NUM             (Port_PortType)3 /* PORTD */

/* PORT Configured Channel ID's */
#define PortConf_LED_PIN_NUM             	 (Port_ChannelType)5 /* Pin 5 in PORTC */
#define PortConf_BUTTON_PIN_NUM          	 (Port_ChannelType)2 /* Pin 2 in PORTD */
#endif /* PORT_CFG_H */

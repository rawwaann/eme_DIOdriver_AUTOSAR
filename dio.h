/*
 * dio.h
 *
 *  Created on: Oct 14, 2023
 *      Author: Lenovo
 */

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "hw_gpio.h"

typedef uint8 Dio_ChannelType ; /*Shall cover all available DIO channels*/
typedef uint8 Dio_PortType; /* Shall cover all available DIO Ports*/

typedef uint8 Dio_LevelType ; /*the type for the possible levels that a DIO channel can have (input or output). */

typedef uint8 Dio_PortLevelType ;   /*the type for the value of a DIO port*/


Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level);

#endif /* DIO_H_ */

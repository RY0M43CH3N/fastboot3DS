#pragma once

/*
 *   This file is part of fastboot 3DS
 *   Copyright (C) 2017 derrek, profi200
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "types.h"



void MCU_init(void);
void MCU_disableLEDs(void);
void MCU_powerOnLCDs(void);
void MCU_powerOffLCDs(void);
void MCU_triggerPowerOff(void);
void MCU_triggerReboot(void);
u8 MCU_readBatteryLevel(void);
bool MCU_readBatteryChargeState(void);
u8 MCU_readSystemModel(void);
void MCU_readRTC(void *rtc);

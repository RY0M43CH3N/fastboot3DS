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
#include "arm11/hardware/hardware.h"
#include "arm11/hardware/interrupt.h"
#include "arm11/hardware/hid.h"
#include "arm11/power.h"
#include "arm11/hardware/i2c.h"
#include "hardware/pxi.h"
#include "hardware/gfx.h"
#include "arm11/firm.h"
#include "arm11/menu.h"
#include "arm11/menu_fb3ds.h"
#include "arm11/console.h"
#include "arm11/fmt.h"
#include "fs.h"


volatile bool g_poweroffAllowed = false;
volatile bool g_startFirmLaunch = false;



int main(void)
{
	hardwareInit();

	GFX_init();
	
	// init menu console
	PrintConsole menu_con;
	consoleInit(SCREEN_SUB, &menu_con, false);
	
	// init description console
	PrintConsole desc_con;
	consoleInit(SCREEN_TOP, &desc_con, false);

	/*ee_puts("fs test...");
	s32 fs = fMount(FS_DRIVE_SDMC);
	if(fs < 0)
	{
		ee_printf("Failed to mount SD! %d\n", fs);
		return 1;
	}

	s32 f = fOpen("sdmc:/_testFile_.txt", FS_OPEN_CREATE_ALWAYS | FS_OPEN_WRITE);
	if(f < 0)
	{
		ee_printf("Failed to open file! %d\n", f);
		fUnmount(fs);
		return 1;
	}

	s32 res = fWrite(f, "It worked!!!", 13);
	if(res < 0)
	{
		ee_printf("Failed to write to file! %d\n", res);
		fClose(f);
		fUnmount(fs);
		return 1;
	}
	fClose(f);
	fUnmount(fs);*/

	// run menu
	menuProcess(&menu_con, &desc_con, menu_fb3ds);
	
	// power off
	if(g_poweroffAllowed) power_off();

	/*while(!g_startFirmLaunch)
	{
		waitForInterrupt();

		hidScanInput();
		const u32 kDown = hidKeysDown();
		const u32 kUp = hidKeysUp();

		if(hidGetPowerButton(true))
		{
			if(g_poweroffAllowed) power_off();
			PXI_trySendWord(PXI_RPL_POWER_PRESSED);
		}

		if(kDown & KEY_HOME) PXI_trySendWord(PXI_RPL_HOME_PRESSED);
		if(kDown & KEY_SHELL) i2cmcu_lcd_poweroff();
		if(kUp & KEY_SHELL)
		{
			i2cmcu_lcd_poweron();
			i2cmcu_lcd_backlight_poweron();
		}


		u8 hidstate = i2cmcu_readreg_hid_held();
		
		if(!(hidstate & MCU_HID_HOME_BUTTON_NOT_HELD))
			PXI_trySendWord(PXI_RPL_HOME_HELD);
	}

	GFX_deinit(); // TODO: Let ARM9 decide when to deinit gfx

	firm_launch();*/

	return 0;
}

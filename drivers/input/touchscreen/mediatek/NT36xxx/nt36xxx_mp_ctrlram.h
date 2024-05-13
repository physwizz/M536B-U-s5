/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
*/

#if NVT_TOUCH_MP

static uint32_t IC_X_CFG_SIZE = 18;
static uint32_t IC_Y_CFG_SIZE = 32;
static uint32_t IC_KEY_CFG_SIZE = 4;
static uint32_t X_Channel = 18;
static uint32_t Y_Channel = 32;
static uint32_t Key_Channel = TOUCH_KEY_NUM;
static uint8_t AIN_X[40] = {17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5,
		4, 3, 2, 1, 0};
static uint8_t AIN_Y[40] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
		19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4,
		3, 2, 1, 0};
#if TOUCH_KEY_NUM > 0
static uint8_t AIN_KEY[8] = {0, 1, 2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
#endif /* #if TOUCH_KEY_NUM > 0 */

static int32_t PS_Config_Lmt_Short_Rawdata_P = 20000;
static int32_t PS_Config_Lmt_Short_Rawdata_N = 11550;
static int32_t PS_Config_Lmt_Key_Short_Rawdata_P = 20000;
static int32_t PS_Config_Lmt_Key_Short_Rawdata_N = 11550;
static int32_t PS_Config_Lmt_Short_Diff_P = 6300;
static int32_t PS_Config_Lmt_Short_Diff_N;
static int32_t PS_Config_Lmt_Key_Short_Diff_P = 6300;
static int32_t PS_Config_Lmt_Key_Short_Diff_N;
static int32_t PS_Config_Lmt_Short_Base_P = 2000;
static int32_t PS_Config_Lmt_Short_Base_N = -2000;
static int32_t PS_Config_Lmt_Key_Short_Base_P = 2000;
static int32_t PS_Config_Lmt_Key_Short_Base_N = -2000;

static int32_t PS_Config_Lmt_Open_Rawdata_P[40 * 40] = {
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
	13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000, 13000,
#if TOUCH_KEY_NUM > 0
	13000, 13000, 13000,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_Open_Rawdata_N[40 * 40] = {
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
	6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500, 6500,
#if TOUCH_KEY_NUM > 0
	6500, 6500, 6500,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_Rawdata_P[40 * 40] = {
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
#if TOUCH_KEY_NUM > 0
	2000, 2000, 2000,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_Rawdata_N[40 * 40] = {
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
	400, 400, 400, 400, 400, 400, 400, 400, 400,
#if TOUCH_KEY_NUM > 0
	400, 400, 400,
#endif /* #if TOUCH_KEY_NUM > 0 */
};

static int32_t PS_Config_Lmt_FW_CC_P = 38;
static int32_t PS_Config_Lmt_FW_CC_N = 9;
static int32_t PS_Config_Lmt_Key_FW_CC_P = 38;
static int32_t PS_Config_Lmt_Key_FW_CC_N = 9;
static int32_t PS_Config_Lmt_FW_CC_I_P = 25;
static int32_t PS_Config_Lmt_FW_CC_I_N;
static int32_t PS_Config_Lmt_FW_CC_Q_P = 25;
static int32_t PS_Config_Lmt_FW_CC_Q_N;
static int32_t PS_Config_Lmt_Key_FW_CC_I_P = 25;
static int32_t PS_Config_Lmt_Key_FW_CC_I_N;
static int32_t PS_Config_Lmt_Key_FW_CC_Q_P = 25;
static int32_t PS_Config_Lmt_Key_FW_CC_Q_N;

static int32_t PS_Config_Lmt_FW_Diff_P = 35;
static int32_t PS_Config_Lmt_FW_Diff_N = -35;
static int32_t PS_Config_Lmt_Key_FW_Diff_P = 35;
static int32_t PS_Config_Lmt_Key_FW_Diff_N = -35;

static int32_t PS_Config_Diff_Test_Frame = 50;
extern void nvt_change_mode(uint8_t mode);
extern uint8_t nvt_get_fw_pipe(void);
extern void nvt_read_mdata(uint32_t xdata_addr, uint32_t xdata_btn_addr);
extern void nvt_get_mdata(int32_t *buf, uint8_t *m_x_num, uint8_t *m_y_num);


#endif /* #if NVT_TOUCH_MP */

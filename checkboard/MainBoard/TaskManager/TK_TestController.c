/****************************************************************************************************/
/*			@FileName		:	TK_TestController.c												  	*/
/*			@Author			:	zhengbaiqiu															*/
/*			@Version		:	v1.0																*/
/*			@Date			:	2019.11.12  														*/
/****************************************************************************************************/


/* Includes --------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stdlib.h"
#include "stdio.h"

/* Project ---------------------------------------------------------------------*/
#include "maindef.h"
#include "bsp.h"
#include "apiLib.h"
#include "TK_TestController.h"


/* Variable --------------------------------------------------------------------*/
/* Function --------------------------------------------------------------------*/
void TK_TestController( void *pvParameters );
void api_SendCMD_To_Display(u8 mode,u8 cmd,u8 status,u16 dat,u16 dat1,u8 flag,u16 waittime,u8 count);
u8 api_SendCMD_To_MainBoard(u8 seq,u8 mode,u8 cmd,u16 waittime,u8 type,u8 num);
u8 iiiiiiiii;

u8 str[20];


/*****************************************************************************
 * @name       :void TK_TestController( void *pvParameters )
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :时间控制任务
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
u8 iiiii;
void TK_TestController( void *pvParameters )
{
	//api_MachinePowerOn();
	for(;;)
	{
		IWDG_ReloadCounter();
		

// 		api_UART1_SendData(16,"Left_Avoid_Bump:");
// 		vTaskDelay(50);
// 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[2]);
// 		//api_ShortToStr(str,mMaininf.mWork.mWorkSensorOnAvl[4][0]);
// 		api_UART1_SendData(5,str);
// 		vTaskDelay(50);
// 		api_UART1_SendData(2,"\r\n");
// 		vTaskDelay(50);
// 		
// 		api_UART1_SendData(17,"Right_Avoid_Bump:");
// 		vTaskDelay(50);
// 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[3]);
// 		//api_ShortToStr(str,mMaininf.mWork.mWorkSensorOffAvl[4][0]);
// 		api_UART1_SendData(5,str);
// 		vTaskDelay(50);
// 		api_UART1_SendData(2,"\r\n");
// 		vTaskDelay(50);
// 		
// 		api_UART1_SendData(17,"Front_Avoid_Bump:");
// 		vTaskDelay(50);
// 		//api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[4]);
// 		api_ShortToStr(str,api_Get_FrontAvoidBump());
// 		api_UART1_SendData(5,str);
// 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// 		vTaskDelay(50);
// 		api_UART1_SendData(2,"\r\n");
// 		vTaskDelay(50);
// 		
// 		api_UART1_SendData(22,"Left_Side far:near:bat");
// 		vTaskDelay(50);
// 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[0]);
// 		api_ShortToStr(&str[5],mMaininf.mWork.mWorkSensorDataAvl[6]);
// 		api_ShortToStr(&str[10],mMaininf.mWork.mWorkSensorDataAvl[8]);
// 		api_UART1_SendData(15,str);
// 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// 		vTaskDelay(50);
// 		api_UART1_SendData(2,"\r\n");
// 		vTaskDelay(50);
// 		
// // 		api_UART1_SendData(15,"Left_Side_near:");
// // 		vTaskDelay(50);
// // 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[6]);
// // 		api_UART1_SendData(5,str);
// // 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// // 		vTaskDelay(50);
// // 		api_UART1_SendData(2,"\r\n");
// // 		vTaskDelay(50);
// 		
// 		api_UART1_SendData(23,"Right_Side far:near:bat");
// 		vTaskDelay(50);
// 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[1]);
// 		api_ShortToStr(&str[5],mMaininf.mWork.mWorkSensorDataAvl[7]);
// 		api_ShortToStr(&str[10],mMaininf.mWork.mWorkSensorDataAvl[9]);
// 		api_UART1_SendData(15,str);
// 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// 		vTaskDelay(50);
// 		api_UART1_SendData(2,"\r\n");
// 		vTaskDelay(50);
// 		
// // 		api_UART1_SendData(16,"Right_Side_near:");
// // 		vTaskDelay(50);
// // 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[7]);
// // 		api_UART1_SendData(5,str);
// // 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// // 		vTaskDelay(50);
// // 		api_UART1_SendData(2,"\r\n");
// // 		vTaskDelay(50);
// 		
// // 		api_UART1_SendData(10,"Left_Side:");
// // 		vTaskDelay(50);
// // 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[8]);
// // 		api_UART1_SendData(5,str);
// // 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// // 		vTaskDelay(50);
// // 		api_UART1_SendData(2,"\r\n");
// // 		vTaskDelay(50);
// 		
// // 		api_UART1_SendData(11,"Right_Side:");
// // 		vTaskDelay(50);
// // 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[9]);
// // 		api_UART1_SendData(5,str);
// // 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// // 		vTaskDelay(50);
// // 		api_UART1_SendData(2,"\r\n");
// // 		vTaskDelay(50);
// 		
// 		
// // 		api_Control_Motor(11,1);
// // 		api_Control_Motor(12,1);
// 		api_Control_Motor(13,1);
// 		api_Send_Signal(1,1);
// 		api_Send_Signal(2,1);
// 		api_Send_Signal(3,1);
// 		api_Receive_Signal(2,1);
		
		if(mMaininf.mUart1.mReceiveFlag == 1)   //调试
		{
			mMaininf.mUart1.mReceiveFlag = 0;
			api_UART2_Display_SendCMDData(2,1,1,0,0,0);
 			vTaskDelay(1000);
			mMaininf.mWork.mWorkChecking = 1;
			PAout(12) = 1;
			PAout(15) = 1;
			PEout(1) = 0;
			vTaskDelay(10000);
			api_SendCMD_To_MainBoard(0,1,1,100,1,5);
			mMaininf.mWork.mWorkStep = mMaininf.mUart1.ReceiveBuf[2];
		}
		
		if(mMaininf.mWork.mWorkKeyPressFlag == 1)
		{
			mMaininf.mWork.mWorkKeyPressFlag = 0;
			mMaininf.mWork.mWorkKeyPressFlag1 = 0;
			if(api_Test_ADC(&ADCValue[5],1240,620) == 1)//i9
			{
				api_Control_Motor(13,1);
				api_SendCMD_To_Display(2,2,1,0,0,0,1000,3);
			}
			if(api_Test_ADC(&ADCValue[5],2482,434) == 1)//i8
			{
				api_Control_Motor(11,1);
				api_Control_Motor(12,1);
				api_SendCMD_To_Display(2,1,1,0,0,0,1000,3);
			}
			mMaininf.mWork.mWorkChecking = 1;
			mMaininf.mWork.mWorkStep = TEST_START;
		}
		
		
		if(mMaininf.mWork.mWorkChecking == 1)
		{
			if(mMaininf.mWork.mWorkStep != mMaininf.mWork.mWorkStepOld)
			{
				mMaininf.mWork.mWorkStepOld = mMaininf.mWork.mWorkStep;
				
				switch(mMaininf.mWork.mWorkStep)
				{
					case TEST_START ://01
						api_SendCMD_To_Display(1,1,1,0,0,0,1000,3);
						mMaininf.mWork.mWorkStep = TEST_LEFT_GUIDE;
						break;
					case TEST_LEFT_GUIDE ://02
						Guide_EXTI_Control(0,1);
						api_Send_Signal(1,1);
						api_Receive_Signal(2,1);
						vTaskDelay(1000);
						if(api_GetGuideFlag(ENUM_GUIDE_LEFT) == 1)
						{
							api_SendCMD_To_Display(1,2,1,0,0,0,1000,3);
						}
						else
						{
							api_SendCMD_To_Display(1,2,0,0,0,0,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						Guide_EXTI_Control(0,0);
						mMaininf.mWork.mWorkStep = TEST_TOP_GUIDE;
						break;
					case TEST_TOP_GUIDE ://03
						Guide_EXTI_Control(3,1);
						mMaininf.mWork.mWorkTopGuideReceiveFlag = 1;
						vTaskDelay(300);
						//if(api_GetGuideFlag(ENUM_GUIDE_TOP) == 1)
						if(mMaininf.mWork.mWorkTopGuideFlag == 1)
						{
							api_SendCMD_To_Display(1,3,1,0,0,0,1000,3);
						}
						else
						{
							api_SendCMD_To_Display(1,3,0,0,0,0,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkTopGuideReceiveFlag = 0;
						Guide_EXTI_Control(3,0);
						mMaininf.mWork.mWorkStep = TEST_FRONT_GUIDE;
						break;
					case TEST_FRONT_GUIDE ://04
						Guide_EXTI_Control(2,1);
						mMaininf.mWork.mWorkFrontGuideReceiveFlag = 1;
						vTaskDelay(300);
						//if(api_GetGuideFlag(ENUM_GUIDE_FRONT) == 1)
						if(mMaininf.mWork.mWorkFrontGuideFlag == 1)
						{
							api_SendCMD_To_Display(1,4,1,0,0,0,1000,3);
						}
						else
						{
							api_SendCMD_To_Display(1,4,0,0,0,0,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkFrontGuideReceiveFlag = 0;
						Guide_EXTI_Control(2,0);
						mMaininf.mWork.mWorkStep = TEST_RIGHT_GUIDE;
						break;
					case TEST_RIGHT_GUIDE ://05
						Guide_EXTI_Control(1,1);
						vTaskDelay(1000);
						if(api_GetGuideFlag(ENUM_GUIDE_RIGHT) == 1)
						{
							api_SendCMD_To_Display(1,5,1,0,0,0,1000,3);
						}
						else
						{
							api_SendCMD_To_Display(1,5,0,0,0,0,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						Guide_EXTI_Control(1,0);
						api_Send_Signal(1,0);
						mMaininf.mWork.mWorkStep = TEST_LEFT_AVOID_BUMP;
						api_Receive_Signal(2,0);
						break;
					case TEST_LEFT_AVOID_BUMP ://06
						api_Send_Signal(2,1);
						vTaskDelay(500);
						
						mMaininf.mWork.mWorkLeftAlongSideDatFar = mMaininf.mWork.mWorkSensorDataAvl[8];
						mMaininf.mWork.mWorkRightAlongSideDatFar = mMaininf.mWork.mWorkSensorDataAvl[9];
						
						//if((mMaininf.mWork.mWorkSensorDataAvl[8] >= 700) && (mMaininf.mWork.mWorkSensorDataAvl[8] <= 2000))
						if((mMaininf.mWork.mWorkLeftAlongSideDatFar >= 700) && (mMaininf.mWork.mWorkLeftAlongSideDatFar <= 2000))
						{
							mMaininf.mWork.mWorkLeftSideErrorFlag = 1;
						}
						//if((mMaininf.mWork.mWorkSensorDataAvl[9] >= 700) && (mMaininf.mWork.mWorkSensorDataAvl[9] <= 2000))
						if((mMaininf.mWork.mWorkRightAlongSideDatFar >= 700) && (mMaininf.mWork.mWorkRightAlongSideDatFar <= 2000))
						{
							mMaininf.mWork.mWorkRightSideErrorFlag = 1;
						}
						api_Send_Signal(2,0);
						vTaskDelay(200);
						
						
						api_Send_Signal(3,1);
						vTaskDelay(500);
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(1,mMaininf.mWork.mWorkSensorDataAvl[2] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[2] & 0xff);
						vTaskDelay(200);
						#endif
						
						mMaininf.mWork.mWorkLeftAvoidBumpDatFar = mMaininf.mWork.mWorkSensorDataAvl[2];
						mMaininf.mWork.mWorkRightAvoidBumpDatFar = mMaininf.mWork.mWorkSensorDataAvl[3];
						
						
						if(mMaininf.mWork.mWorkLeftAvoidBumpDatFar < 800)
						{
							api_Control_Motor(0,1);
							vTaskDelay(2000);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(1,mMaininf.mWork.mWorkSensorDataAvl[2] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[2] & 0xff);
							vTaskDelay(200);
							#endif
							mMaininf.mWork.mWorkAvoidBumpDat = mMaininf.mWork.mWorkSensorDataAvl[2];
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1000)
							{
								api_SendCMD_To_Display(1,6,1,mMaininf.mWork.mWorkLeftAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,6,0,mMaininf.mWork.mWorkLeftAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,6,0,mMaininf.mWork.mWorkLeftAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP0;
						api_Control_Motor(0,0);
						vTaskDelay(2000);
						break;
					case TEST_FRONT_AVOID_BUMP0 ://07
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(2,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
					
						mMaininf.mWork.mWorkAmongAvoidBumpDatFar = api_Get_FrontAvoidBump();
						if(mMaininf.mWork.mWorkAmongAvoidBumpDatFar < 1000)
						{
							mMaininf.mWork.mWorkAmidAvoidBumpFlag = 1;
							api_Control_Motor(1,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(2,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 800)
							{
								api_SendCMD_To_Display(1,7,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,7,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,7,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP1;
						api_Control_Motor(1,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP1 ://08
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(3,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(2,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(3,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1200)
							{
								api_SendCMD_To_Display(1,8,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,8,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,8,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP2;
						api_Control_Motor(2,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP2 ://09
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(4,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(3,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(4,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1200)
							{
								api_SendCMD_To_Display(1,9,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,9,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,9,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP3;
						api_Control_Motor(3,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP3 ://10
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(5,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(4,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(5,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1200)
							{
								api_SendCMD_To_Display(1,10,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,10,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,10,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP4;
						api_Control_Motor(4,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP4 ://11
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(6,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(5,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(6,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1200)
							{
								api_SendCMD_To_Display(1,11,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,11,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,11,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP5;
						api_Control_Motor(5,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP5 ://12
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(7,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(6,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(7,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1200)
							{
								api_SendCMD_To_Display(1,12,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,12,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,12,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP6;
						api_Control_Motor(6,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP6 ://13
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(8,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(7,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(8,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1200)
							{
								api_SendCMD_To_Display(1,13,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,13,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,13,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP7;
						api_Control_Motor(7,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP7 ://14
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(8,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1200)
							{
								api_SendCMD_To_Display(1,14,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,14,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,14,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP8;
						api_Control_Motor(8,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP8 ://15
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(10,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(9,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(10,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 800)
							{
								api_SendCMD_To_Display(1,15,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,15,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,15,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_FRONT_AVOID_BUMP9;
						api_Control_Motor(9,0);
						//vTaskDelay(3000);
						break;
					case TEST_FRONT_AVOID_BUMP9 ://16
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(11,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
						vTaskDelay(200);
						#endif
						if(mMaininf.mWork.mWorkAmidAvoidBumpFlag == 1)
						{
							api_Control_Motor(10,1);
							vTaskDelay(1500);
							#ifdef zbq_Debug
							api_UART1_MainBoard_SendCMDData(11,mMaininf.mWork.mWorkSensorDataAvl[4] >> 8,
															mMaininf.mWork.mWorkSensorDataAvl[4] & 0xff);
							vTaskDelay(200);
							#endif
							
							mMaininf.mWork.mWorkAvoidBumpDat = api_Get_FrontAvoidBump();
							if(mMaininf.mWork.mWorkAvoidBumpDat > 800)
							{
								api_SendCMD_To_Display(1,16,1,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,16,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,16,0,mMaininf.mWork.mWorkAmongAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkAmidAvoidBumpFlag = 0;
						mMaininf.mWork.mWorkStep = TEST_RIGHT_AVOID_BUMP;
						api_Control_Motor(10,0);
						vTaskDelay(2000);
						break;
					case TEST_RIGHT_AVOID_BUMP ://17
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(12,mMaininf.mWork.mWorkSensorDataAvl[3] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[3] & 0xff);
						vTaskDelay(200);
						#endif
						api_Control_Motor(0,1);
						vTaskDelay(2000);
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(12,mMaininf.mWork.mWorkSensorDataAvl[3] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[3] & 0xff);
						vTaskDelay(200);
						#endif
						
						if(mMaininf.mWork.mWorkRightAvoidBumpDatFar < 800)
						{
							mMaininf.mWork.mWorkAvoidBumpDat = mMaininf.mWork.mWorkSensorDataAvl[3];
							if(mMaininf.mWork.mWorkAvoidBumpDat > 1000)
							{
								api_SendCMD_To_Display(1,17,1,mMaininf.mWork.mWorkRightAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,17,0,mMaininf.mWork.mWorkRightAvoidBumpDatFar,mMaininf.mWork.mWorkAvoidBumpDat,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,17,0,mMaininf.mWork.mWorkRightAvoidBumpDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_LEFT_ALONG_SIDE;
						//api_Control_Motor(0,0);
// 						//api_Send_Signal(3,0);
// 						vTaskDelay(2000);
						break;
					case TEST_LEFT_ALONG_SIDE ://18
						api_Send_Signal(2,1);
						vTaskDelay(200);
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(13,mMaininf.mWork.mWorkSensorOnOffAverage[0][1] >> 8,
														mMaininf.mWork.mWorkSensorOnOffAverage[0][1] & 0xff);
						vTaskDelay(200);
						#endif
					
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(13,mMaininf.mWork.mWorkSensorDataAvl[8] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[8] & 0xff);
						vTaskDelay(200);
						#endif
						
						if((mMaininf.mWork.mWorkLeftAlongSideDatFar >= 700) && (mMaininf.mWork.mWorkLeftAlongSideDatFar <= 2000))
						{
							mMaininf.mWork.mWorkLeftAlongSideDatNear = mMaininf.mWork.mWorkSensorDataAvl[8];
							
							if((mMaininf.mWork.mWorkLeftAlongSideDatNear >= 30) && 
								(mMaininf.mWork.mWorkLeftAlongSideDatNear <= 200))
							{
								api_SendCMD_To_Display(1,18,1,mMaininf.mWork.mWorkLeftAlongSideDatFar,mMaininf.mWork.mWorkLeftAlongSideDatNear,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,18,0,mMaininf.mWork.mWorkLeftAlongSideDatFar,mMaininf.mWork.mWorkLeftAlongSideDatNear,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,18,0,mMaininf.mWork.mWorkLeftAlongSideDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						mMaininf.mWork.mWorkStep = TEST_RIGHT_ALONG_SIDE;
						break;
					case TEST_RIGHT_ALONG_SIDE ://19
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(14,mMaininf.mWork.mWorkSensorOnOffAverage[1][1] >> 8,
														mMaininf.mWork.mWorkSensorOnOffAverage[1][1] & 0xff);
						vTaskDelay(200);
						#endif
					
						#ifdef zbq_Debug
						api_UART1_MainBoard_SendCMDData(14,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,
														mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
						vTaskDelay(200);
						#endif
					
					
						if((mMaininf.mWork.mWorkRightAlongSideDatFar >= 700) && (mMaininf.mWork.mWorkRightAlongSideDatFar <= 2000))
						{
							mMaininf.mWork.mWorkRightAlongSideDatNear = mMaininf.mWork.mWorkSensorDataAvl[9];
							
							if((mMaininf.mWork.mWorkRightAlongSideDatNear >= 30) && 
								(mMaininf.mWork.mWorkRightAlongSideDatNear <= 200))
							{
								api_SendCMD_To_Display(1,19,1,mMaininf.mWork.mWorkRightAlongSideDatFar,mMaininf.mWork.mWorkRightAlongSideDatNear,0,1000,3);
							}
							else
							{
								api_SendCMD_To_Display(1,19,0,mMaininf.mWork.mWorkRightAlongSideDatFar,mMaininf.mWork.mWorkRightAlongSideDatNear,2,1000,3);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
							}
						}
						else
						{
							api_SendCMD_To_Display(1,19,0,mMaininf.mWork.mWorkRightAlongSideDatFar,0,3,1000,3);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						api_Control_Motor(0,0);
						
						if(mMaininf.mWork.mWorkCheckErrorFlag == 0)
						{
							api_SendCMD_To_Display(1,0xfe,1,0,0,0,1000,3);
						}
						else
						{
							api_SendCMD_To_Display(1,0xfe,0,0,0,0,1000,3);
						}
						mMaininf.mWork.mWorkStep = TEST_LAST;
						break;
					
					
					case TEST_LAST ://test file
						api_Send_Signal(2,0);
						api_Send_Signal(3,0);
						api_Control_Motor(11,0);
						api_Control_Motor(12,0);
						api_Control_Motor(13,0);
						vTaskDelay(100);
						mMaininf.mWork.mWorkCheckStatus = 0;
						mMaininf.mWork.mWorkFileStep = 0;
						mMaininf.mWork.mWorkStep = 0;
						mMaininf.mWork.mWorkStepOld = 0;
						mMaininf.mWork.mWorkCheckErrorFlag = 0;
						mMaininf.mWork.mWorkChecking = 0;
						mMaininf.mWork.mWorkRightAvoidBumpErrorFlag = 0;
						mMaininf.mWork.mWorkLeftSideErrorFlag = 0;
						mMaininf.mWork.mWorkRightSideErrorFlag = 0;
					
						mMaininf.mWork.mWorkFrontGuideFlag = 0;
						mMaininf.mWork.mWorkTopGuideFlag = 0;
						mMaininf.mWork.mWorkFrontGuideCont = 0;
						mMaininf.mWork.mWorkTopGuideCont = 0;
						break;
					default :
						break;
				}
			}
		}
	
	}
}

/*****************************************************************************
 * @name       :void api_SendCMD_To_Display(u8 mode,u8 cmd,u8 status)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :send data
 * @parameters :time:超时时间 
 * @retvalue   :None
******************************************************************************/
void api_SendCMD_To_Display(u8 mode,u8 cmd,u8 status,u16 dat,u16 dat1,u8 flag,u16 waittime,u8 count)
{
	u8 mCont = 0;
	u8 mStatus = 0;
	
	do
	{
		if(++mCont > count)
		{
			return;
		}
		
		api_UART2_Display_SendCMDData(mode,cmd,status,dat,dat1,flag);
		
		mMaininf.mSystem.mDisplayStartTime = api_GetCurrentSystemTime();
		
		while(api_GetSystemTimePeriod(mMaininf.mSystem.mDisplayStartTime) < waittime)
		{
			if((mMaininf.mUart2.mReceiveFlag == 1) && (mMaininf.mUart2.ReceiveBuf[0] == mode) && 
				(mMaininf.mUart2.ReceiveBuf[1] == cmd) &&(mMaininf.mUart2.ReceiveBuf[2] == 1))
			{
				mStatus = 1;
				break;
			}
		}
		
		mMaininf.mUart2.mReceiveFlag = 0;
	}while(mStatus == 0);
	
}

/*****************************************************************************
 * @name       :void api_SendCMD_To_MainBoard(u8 seq,u8 mode,u8 cmd,u16 waittime)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :发送命令到主板
 * @parameters :testtype : 0:读取数据   1:检测发射    2:检测接收   waittime:单次检查时间  
				type:类型0：状态  1：数据     num:重发次数
 * @retvalue   :0:主板无数据返回     1：主板有数据返回
******************************************************************************/
u8 api_SendCMD_To_MainBoard(u8 seq,u8 mode,u8 cmd,u16 waittime,u8 type,u8 num)
{
	u8 mCont = 0;
	
	mMaininf.mUart1.ReceiveBuf[4] = 0;
	
	if(type == 0)
	{
		do{
			if(++mCont > num) return 0;//未接收到数据
			api_UART1_MainBoard_SendCMDData(seq,mode,cmd);
			vTaskDelay(waittime);
		}while((mMaininf.mUart1.mReceiveFlag == 0) || ((mMaininf.mUart1.mReceiveFlag == 1) && (mMaininf.mUart1.ReceiveBuf[4] == 0)));
		
	}
	else
	{
		do{
			if(++mCont > num) return 0;//未接收到数据
			api_UART1_MainBoard_SendCMDData(seq,mode,cmd);
			vTaskDelay(waittime);
		}while(mMaininf.mUart1.mReceiveFlag == 0);
		
	}
	
	mMaininf.mUart1.mReceiveFlag = 0;
	
	return 1;//接收到数据
}


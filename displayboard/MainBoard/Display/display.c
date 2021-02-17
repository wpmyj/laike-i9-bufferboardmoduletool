/****************************************************************************************************/
/*			@FileName		:	display.c															  	*/
/*			@Author			:	zhengbaiqiu															*/
/*			@Version		:	v1.0																*/
/*			@Date			:	2019.11.12  														*/
/****************************************************************************************************/


/* Includes --------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Project ---------------------------------------------------------------------*/
#include "maindef.h"
//#include "font.h"
#include "lcd_driver.h"	
#include "gui.h"	
#include "delay.h"
#include "display.h"
#include "apiLib.h"

/* Variable --------------------------------------------------------------------*/
extern u16 Touch_X;
extern u16 Touch_Y;

/* Function --------------------------------------------------------------------*/
void DrawTestPage(u8 *str);
void Test_Display(void);





/*****************************************************************************
 * @name       :void DrawTestPage(u8 *str)
 * @date       :2018-08-09 
 * @function   :Drawing test interface
 * @parameters :str:the start address of the Chinese and English strings
 * @retvalue   :None
******************************************************************************/ 
void DrawTestPage(u8 *str)
{
	//���ƹ̶���up
	//LCD_Clear(WHITE);
	LCD_Clear(GRAY0);
	LCD_Fill(0,0,lcddev.width,20,BLUE);
	//���ƹ̶���down
	LCD_Fill(0,20,lcddev.width,40,YELLOW);
//	LCD_Fill(0,230,lcddev.width,250,BLUE);
	LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
	POINT_COLOR=WHITE;
	//POINT_COLOR=GRAY0;
	Gui_StrCenter(0,2,WHITE,BLUE,str,16,1);//������ʾ
	Gui_StrCenters(0,22,BLACK,YELLOW,"�����",16,1);//������ʾ
	Gui_StrCenters(241,22,BLACK,YELLOW,"�����",16,1);//������ʾ
// 	Gui_StrCenters(0,232,WHITE,BLUE,"����״̬",16,1);//������ʾ
// 	Gui_StrCenters(241,232,WHITE,BLUE,"Ԥ��",16,1);//������ʾ
//	Gui_DrawLine(240,250,240,300,BLUE);
//	LCD_DrawLine(240,40,240,300);
	//Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"http://www.zbq.com",16,1);//������ʾ
	Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"�밴��ʾ����",16,1);//������ʾ
	//���Ʋ�������
	//LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
}

/*****************************************************************************
 * @name       :void Display_Avoid_Error(u8 pos,u16 y,u16 dat1,u16 dat2,u8 flag)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :��ʾ����ײ����
 * @parameters :pos:  1 : ��� 2���Ҳ�
 * @retvalue   :None
******************************************************************************/
void Display_Avoid_Error(u8 pos,u16 y,u16 dat1,u16 dat2,u8 flag)
{
	if(pos == 1)
	{
		if(flag == 0)
		{
			Gui_DrawFont_GBK16(84,y,BLACK,GRAY0,"Զ:");
			Gui_DrawFont_Num16(108,y,BLACK,GRAY0,dat1);
			Gui_DrawFont_GBK16(156,y,BLACK,GRAY0,"��:");
			Gui_DrawFont_Num16(180,y,BLACK,GRAY0,dat2);
		}
		else if(flag == 1)
		{
			Gui_DrawFont_GBK16(84,y,RED,GRAY0,"Զ:");
			Gui_DrawFont_Num16(108,y,RED,GRAY0,dat1);
			Gui_DrawFont_GBK16(156,y,BLACK,GRAY0,"��:");
			Gui_DrawFont_Num16(180,y,BLACK,GRAY0,dat2);
		}
		else if(flag == 2)
		{
			Gui_DrawFont_GBK16(84,y,BLACK,GRAY0,"Զ:");
			Gui_DrawFont_Num16(108,y,BLACK,GRAY0,dat1);
			Gui_DrawFont_GBK16(156,y,RED,GRAY0,"��:");
			Gui_DrawFont_Num16(180,y,RED,GRAY0,dat2);
		}
		else if(flag == 3)
		{
			Gui_DrawFont_GBK16(84,y,RED,GRAY0,"Զ:");
			Gui_DrawFont_Num16(108,y,RED,GRAY0,dat1);
			Gui_DrawFont_GBK16(156,y,RED,GRAY0,"��:");
			Gui_DrawFont_Num16(180,y,RED,GRAY0,dat2);
		}
	}
	else if(pos == 2)
	{
		if(flag == 0)
		{
			Gui_DrawFont_GBK16(326,y,BLACK,GRAY0,"Զ:");
			Gui_DrawFont_Num16(350,y,BLACK,GRAY0,dat1);
			Gui_DrawFont_GBK16(398,y,BLACK,GRAY0,"��:");
			Gui_DrawFont_Num16(422,y,BLACK,GRAY0,dat2);
		}
		else if(flag == 1)
		{
			Gui_DrawFont_GBK16(326,y,RED,GRAY0,"Զ:");
			Gui_DrawFont_Num16(350,y,RED,GRAY0,dat1);
			Gui_DrawFont_GBK16(398,y,BLACK,GRAY0,"��:");
			Gui_DrawFont_Num16(422,y,BLACK,GRAY0,dat2);
		}
		else if(flag == 2)
		{
			Gui_DrawFont_GBK16(326,y,BLACK,GRAY0,"Զ:");
			Gui_DrawFont_Num16(350,y,BLACK,GRAY0,dat1);
			Gui_DrawFont_GBK16(398,y,RED,GRAY0,"��:");
			Gui_DrawFont_Num16(422,y,RED,GRAY0,dat2);
		}
		else if(flag == 3)
		{
			Gui_DrawFont_GBK16(326,y,RED,GRAY0,"Զ:");
			Gui_DrawFont_Num16(350,y,RED,GRAY0,dat1);
			Gui_DrawFont_GBK16(398,y,RED,GRAY0,"��:");
			Gui_DrawFont_Num16(422,y,RED,GRAY0,dat2);
		}
	}
}

/*****************************************************************************
 * @name       :void Display_Test(u8 test_mode,u8 test_cmd,u8 test_status,u16 dat1,u16 dat2,u8 flag)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :display test
 * @parameters :test_cmd ��ȡ����������
 * @retvalue   :None
******************************************************************************/
void Display_Test(u8 test_mode,u8 test_cmd,u8 test_status,u16 dat1,u16 dat2,u8 flag)
{
	switch(test_cmd)
	{
		case TEST_START ://01
			if(test_status == 1)
			{
				//Gui_DrawFont_GBK24(300,245,GREEN,GRAY0,"�����...");
			}
			break;
		case TEST_LEFT_GUIDE ://02
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,44,BLACK,GRAY0,"������");
			}
			else
			{
				Gui_DrawFont_GBK24(0,44,RED,GRAY0,"������");
			}
			Gui_DrawFont_GBK24(0,68,BLACK,GRAY0,"...");
			break;
		case TEST_TOP_GUIDE ://03
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,68,BLACK,GRAY0,"������");
			}
			else
			{
				Gui_DrawFont_GBK24(0,68,RED,GRAY0,"������");
			}
			Gui_DrawFont_GBK24(0,92,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_GUIDE ://04
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,92,BLACK,GRAY0,"ǰ����");
			}
			else
			{
				Gui_DrawFont_GBK24(0,92,RED,GRAY0,"ǰ����");
			}
			Gui_DrawFont_GBK24(0,116,BLACK,GRAY0,"...");
			break;
		case TEST_RIGHT_GUIDE ://05
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,116,BLACK,GRAY0,"������");
			}
			else
			{
				Gui_DrawFont_GBK24(0,116,RED,GRAY0,"������");
			}
			Gui_DrawFont_GBK24(0,140,BLACK,GRAY0,"...");
			break;
		case TEST_LEFT_AVOID_BUMP ://06
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,140,BLACK,GRAY0,"����");
// 				Display_Avoid_Error(1,144,dat1,dat2,0);
			}
			else
			{
				Gui_DrawFont_GBK24(0,140,RED,GRAY0,"����");
// 				Display_Avoid_Error(1,144,dat1,dat2,flag);
			}
			Display_Avoid_Error(1,144,dat1,dat2,flag);
			
// 			Gui_DrawFont_GBK16(84,144,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(108,144,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(156,144,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(180,144,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(0,164,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP0 ://07
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,164,BLACK,GRAY0,"����0");
// 				Display_Avoid_Error(1,168,dat1,dat2,0);
			}
			else
			{
				Gui_DrawFont_GBK24(0,164,RED,GRAY0,"����0");
// 				Display_Avoid_Error(1,168,dat1,dat2,flag);
			}
			Display_Avoid_Error(1,168,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(84,168,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(108,168,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(156,168,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(180,168,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(0,188,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP1 ://08
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,188,BLACK,GRAY0,"����1");
			}
			else
			{
				Gui_DrawFont_GBK24(0,188,RED,GRAY0,"����1");
			}
			Display_Avoid_Error(1,192,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(84,192,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(108,192,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(156,192,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(180,192,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(0,212,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP2 ://09
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,212,BLACK,GRAY0,"����2");
			}
			else
			{
				Gui_DrawFont_GBK24(0,212,RED,GRAY0,"����2");
			}
			Display_Avoid_Error(1,216,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(84,216,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(108,216,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(156,216,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(180,216,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(0,236,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP3 ://10
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,236,BLACK,GRAY0,"����3");
			}
			else
			{
				Gui_DrawFont_GBK24(0,236,RED,GRAY0,"����3");
			}
			Display_Avoid_Error(1,240,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(84,240,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(108,240,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(156,240,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(180,240,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(0,260,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP4 ://11
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(0,260,BLACK,GRAY0,"����4");
			}
			else
			{
				Gui_DrawFont_GBK24(0,260,RED,GRAY0,"����4");
			}
			Display_Avoid_Error(1,264,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(84,264,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(108,264,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(156,264,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(180,264,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(242,44,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP5 ://12
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,44,BLACK,GRAY0,"����5");
			}
			else
			{
				Gui_DrawFont_GBK24(242,44,RED,GRAY0,"����5");
			}
			Display_Avoid_Error(2,48,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(326,48,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(350,48,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(398,48,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(422,48,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(242,68,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP6 ://13
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,68,BLACK,GRAY0,"����6");
			}
			else
			{
				Gui_DrawFont_GBK24(242,68,RED,GRAY0,"����6");
			}
			Display_Avoid_Error(2,72,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(326,72,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(350,72,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(398,72,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(422,72,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(242,92,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP7 ://14
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,92,BLACK,GRAY0,"����7");
			}
			else
			{
				Gui_DrawFont_GBK24(242,92,RED,GRAY0,"����7");
			}
			Display_Avoid_Error(2,96,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(326,96,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(350,96,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(398,96,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(422,96,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(242,116,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP8 ://15
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,116,BLACK,GRAY0,"����8");
			}
			else
			{
				Gui_DrawFont_GBK24(242,116,RED,GRAY0,"����8");
			}
			Display_Avoid_Error(2,120,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(326,120,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(350,120,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(398,120,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(422,120,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(242,140,BLACK,GRAY0,"...");
			break;
		case TEST_FRONT_AVOID_BUMP9 ://16
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,140,BLACK,GRAY0,"����9");
			}
			else
			{
				Gui_DrawFont_GBK24(242,140,RED,GRAY0,"����9");
			}
			Display_Avoid_Error(2,144,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(326,144,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(350,144,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(398,144,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(422,144,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(242,164,BLACK,GRAY0,"...");
			break;
		case TEST_RIGHT_AVOID_BUMP ://17
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,164,BLACK,GRAY0,"����");
			}
			else
			{
				Gui_DrawFont_GBK24(242,164,RED,GRAY0,"����");
			}
			Display_Avoid_Error(2,168,dat1,dat2,flag);
// 			Gui_DrawFont_GBK16(326,168,BLACK,GRAY0,"Զ:");
// 			Gui_DrawFont_Num16(350,168,BLACK,GRAY0,dat1);
// 			Gui_DrawFont_GBK16(398,168,BLACK,GRAY0,"��:");
// 			Gui_DrawFont_Num16(422,168,BLACK,GRAY0,dat2);
			Gui_DrawFont_GBK24(242,188,BLACK,GRAY0,"...");
			break;
		case TEST_LEFT_ALONG_SIDE ://18
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,188,BLACK,GRAY0,"���ر�");
			}
			else
			{
				Gui_DrawFont_GBK24(242,188,RED,GRAY0,"���ر�");
			}
			Display_Avoid_Error(2,192,dat1,dat2,flag);
			Gui_DrawFont_GBK24(242,212,BLACK,GRAY0,"...");
			break;
		case TEST_RIGHT_ALONG_SIDE ://19
			if(test_status == 1)
			{
				Gui_DrawFont_GBK24(242,212,BLACK,GRAY0,"���ر�");
			}
			else
			{
				Gui_DrawFont_GBK24(242,212,RED,GRAY0,"���ر�");
			}
			Display_Avoid_Error(2,216,dat1,dat2,flag);
			break;
		case 0xfe :
			if(test_status == 1)
			{
				DisplayButtonDown(316,242,404,290); //x1,y1,x2,y2
				Gui_DrawFont_GBK24(336,254,GREEN,GRAY0,"PASS");
			}
			else
			{
				DisplayButtonDown(316,242,404,290); //x1,y1,x2,y2
				Gui_DrawFont_GBK24(336,254,RED,GRAY0,"FAIL");
			}
			break;
		default :
			break;
	}
	Gui_DrawPoint(0,0,GRAY0);
}

/*****************************************************************************
 * @name       :void Test_Display(void)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Display(void)
{
//	if(mMaininf.mWork.mWorkInitFlag == 1)//��ʼ���ɹ�
	if(1)
	{
// 		if(mMaininf.mWork.mWorkChecking == 0)//δ�ڼ��״̬
// 		{
// 			if(mMaininf.mMode.mScreenPressFlag == 1)            //    ��Ļ����
// 			{
// 				mMaininf.mMode.mScreenPressFlag = 0;
// 				
// 				if((Touch_X >= 305) && (Touch_X <= 423) && (Touch_Y >= 215) && (Touch_Y <= 278))
// 				{
// 					LCD_Clear_Area(305,215,423,278,GRAY0);
// 					
// 					Gui_DrawFont_GBK24(140,130,BLUE,GRAY0,"�����..              ");
// 					
// 					api_SendCMDData(2,1,1);//��ʼ���
// 					mMaininf.mWork.mWorkChecking = 1;
// 				}
// 			}
// 		}
//		else
		if(1)
		{
			if(mMaininf.mUart1.mReceiveFlag == 1)            //    ���յ�����
			{
				mMaininf.mUart1.mReceiveFlag = 0;
				
				if((mMaininf.mUart1.ReceiveBuf[0] == 2) && (mMaininf.mUart1.ReceiveBuf[1] == 1) && 
				   (mMaininf.mUart1.ReceiveBuf[2] == 1))//���յ�����   i8
				{
					LCD_Fill(0,0,lcddev.width,20,BLUE);
					Gui_StrCenter(0,2,WHITE,BLUE,"I8����ײ�����װ",16,1);//������ʾ
					LCD_Clear_Area(0,44,230,295,GRAY0);
					LCD_Clear_Area(242,44,470,295,GRAY0);
					Gui_DrawFont_GBK24(0,44,BLACK,GRAY0,"...");
					api_SendCMDData(2,1,1);//��ʼ���
				}
				if((mMaininf.mUart1.ReceiveBuf[0] == 2) && (mMaininf.mUart1.ReceiveBuf[1] == 2) && 
				   (mMaininf.mUart1.ReceiveBuf[2] == 1))//���յ�����   i9
				{
					LCD_Fill(0,0,lcddev.width,20,BLUE);
					Gui_StrCenter(0,2,WHITE,BLUE,"I9����ײ�����װ",16,1);//������ʾ
					LCD_Clear_Area(0,44,230,295,GRAY0);
					LCD_Clear_Area(242,44,470,295,GRAY0);
					Gui_DrawFont_GBK24(0,44,BLACK,GRAY0,"...");
					api_SendCMDData(2,2,1);//��ʼ���
				}
				if(mMaininf.mUart1.ReceiveBuf[0] == 1)//���յ�ָ��
				{
					mMaininf.mWork.mWorkAvoidBumpDat1 = ((mMaininf.mUart1.ReceiveBuf[3] << 8) | mMaininf.mUart1.ReceiveBuf[4]);
					mMaininf.mWork.mWorkAvoidBumpDat2 = ((mMaininf.mUart1.ReceiveBuf[5] << 8) | mMaininf.mUart1.ReceiveBuf[6]);
					mMaininf.mWork.mWorkAvoidBumpErrorFlag = mMaininf.mUart1.ReceiveBuf[7];
					
					Display_Test(1,mMaininf.mUart1.ReceiveBuf[1],mMaininf.mUart1.ReceiveBuf[2],mMaininf.mWork.mWorkAvoidBumpDat1,mMaininf.mWork.mWorkAvoidBumpDat2,mMaininf.mWork.mWorkAvoidBumpErrorFlag);
					
					api_SendCMDData(1,mMaininf.mUart1.ReceiveBuf[1],1);//������Ϣ
					vTaskDelay(5);
					mMaininf.mWork.mWorkChecking = 0;

				}
			}
			
			//Display_Test(mMaininf.mWork.mWorkMODE,mMaininf.mWork.mWorkCMD,mMaininf.mWork.mWorkSTATUS);
		}
	}
	Gui_DrawPoint(0,0,GRAY0);
	
}























/****************************************************************************************************/
/*			@FileName		:	MAINDEF.h																																	  	*/
/*			@Author			:	zhengbaiqiu																																		*/
/*			@Version		:	v1.0																																					*/
/*			@Date				:	2019.11.12  																																	*/
/****************************************************************************************************/

#ifndef	__MAINDEF_H__
#define	__MAINDEF_H__

#include <stdlib.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stm32f10x.h"


/*		struct congig		*/



#ifdef __cplusplus
extern "C" {
#endif
	
	
#define m_Ok 1                         //真
#define m_NoOk 0                       //假
	
#define BURN_TIMEOUT 300               //烧录步骤500ms超时	
	
#define mePRINT_QUEUE_SIZE	(5)
#define meBURN_QUEUE_SIZE	(5)
#define mDELAY100msTick		( pdMS_TO_TICKS( ( TickType_t ) 100 ) )	
#define mDELAY200msTick		( pdMS_TO_TICKS( ( TickType_t ) 200 ) )	
#define mDELAY500msTick		( pdMS_TO_TICKS( ( TickType_t ) 500 ) )
	
	
/* Task priorities. */
//#define mainQUEUE_POLL_PRIORITY				( tskIDLE_PRIORITY + 2 )
//#define mainCHECK_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
//#define mainSEM_TEST_PRIORITY				( tskIDLE_PRIORITY + 1 )
//#define mainBLOCK_Q_PRIORITY				( tskIDLE_PRIORITY + 2 )
//#define mainCREATOR_TASK_PRIORITY           ( tskIDLE_PRIORITY + 3 )
//#define mainFLASH_TASK_PRIORITY				( tskIDLE_PRIORITY + 1 )
//#define mainCOM_TEST_PRIORITY				( tskIDLE_PRIORITY + 1 )
//#define mainINTEGER_TASK_PRIORITY           ( tskIDLE_PRIORITY )
#define mainTIMER_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
#define mainTEST_TASK_PRIORITY				( tskIDLE_PRIORITY + 1 )
// #define mainCHECKKEY_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
// #define mainCHECKSD_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
// #define mainPRINT_TASK_PRIORITY          (tskIDLE_PRIORITY + 2 )
// #define mainBURN_TASK_PRIORITY          (tskIDLE_PRIORITY + 2 )
// #define mainVERSIONCHECK_TASK_PRIORITY				( tskIDLE_PRIORITY + 2 )


/* Task Stack. */
#define mainTIMER_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
#define mainTEST_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainCHECKKEY_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainCHECKSD_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainVERSIONCHECK_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainPRINT_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainBURN_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 128 )



/*--------------------------------------------------------------------------

        自定义结构体

---------------------------------------------------------------------------*/	


/*   	 自定义			*/
#define SYSTEMTIMEMAX                86400000               /*   System timing maximum 24 hours  */

/* timeout time define */

#define TIMEOUT_0ms           (0)               /*   0ms超时      */
#define TIMEOUT_5ms           (5)               /*   5ms超时      */
#define TIMEOUT_10ms          (10)              /*   10ms超时     */
#define TIMEOUT_50ms          (50)              /*   50ms超时     */
#define TIMEOUT_100ms         (100)             /*   100ms超时    */
#define TIMEOUT_300ms         (300)             /*   300ms超时    */
#define TIMEOUT_500ms         (500)             /*   500ms超时    */
#define TIMEOUT_1000ms        (1000)            /*   1000ms超时   */
#define TIMEOUT_3500ms        (3500)            /*   3500ms超时   */
#define TIMEOUT_5000ms        (5000)            /*   5000ms超时   */

/*   	 结构体声明			*/
typedef enum {
	ST_MAIN_0xAA = 0x01,
	ST_MAIN_0xDD,
	ST_MAIN_SEQ,
	ST_MAIN_MODE,
	ST_MAIN_CMD,
	ST_MAIN_LEN,
	ST_MAIN_DATA,
	ST_MAIN_BCC,
} UART1_RECEIVE_STEP;

typedef enum {
	ST_0x55 = 0x01,
	ST_0xAA,
	ST_MODE,
	ST_CMD,
	ST_STA,
	ST_BCC
} UART5_RECEIVE_STEP;

typedef enum {
	ENUM_GUIDE_TOP = 0x00,
	ENUM_GUIDE_FRONT,
	ENUM_GUIDE_LEFT,
	ENUM_GUIDE_RIGHT,
	ENUM_GUIDE_BACK
} enum_GUIDE;

typedef enum {
	ENUM_GUIDE_A = 0xA3,
	ENUM_GUIDE_B,
	ENUM_GUIDE_C
} enum_GUIDE_SIGNAL;


typedef enum
{
	TEST_START = 0x01,                     //01开始检测
	TEST_LEFT_GUIDE,                       //02左引导
	TEST_TOP_GUIDE,                        //03上引导
	TEST_FRONT_GUIDE,                      //04前引导
	TEST_RIGHT_GUIDE,                      //05右引导
	TEST_LEFT_AVOID_BUMP,                  //06左免碰撞
	TEST_FRONT_AVOID_BUMP0,                //07中免碰撞0
	TEST_FRONT_AVOID_BUMP1,                //08
	TEST_FRONT_AVOID_BUMP2,                //09
	TEST_FRONT_AVOID_BUMP3,                //10
	TEST_FRONT_AVOID_BUMP4,                //11
	TEST_FRONT_AVOID_BUMP5,                //12
	TEST_FRONT_AVOID_BUMP6,                //13
	TEST_FRONT_AVOID_BUMP7,                //14
	TEST_FRONT_AVOID_BUMP8,                //15
	TEST_FRONT_AVOID_BUMP9,                //16
	TEST_RIGHT_AVOID_BUMP,                 //17右免碰撞
	TEST_LEFT_ALONG_SIDE,                  //18左沿边
	TEST_RIGHT_ALONG_SIDE,                 //19右沿边
	
	TEST_LAST                              //最后一步
	
}enum_TEST_CMD;


typedef struct _ST_SYSTEM_MANAGER{
	u32 mSystemTick ;                /*  1ms 模拟滴答计数器   */
	u32 mPowerOnStartTime ;
	
	u32 mGuideReceiveTime ;
	u32 mGuideCheckTime ;
	
	u32 mSystem200usTick;
	
	u32 mAvoidBumpStartTime;
	u32 mDisplayStartTime;
}_ST_SYSTEM_MANAGER;

typedef struct _ST_USART_MANAGER{
	u8 TxBuffer[64];
	u8 RxBuffer[64];
	u8 SendBuf[64];
	u8 ReceiveBuf[64];
	
	u16 mSendSize;
	u16 mSendCont;
	
	u8 mReceiveStep : 4;
	u8 mReceiveLen;
	u8 mReceiveBCC;
	u16 mReceiveSize;
	u16 mReceiveCont;
	u16 mReceiveTimeOut;
	
	u8 mReceiveFlag : 1;
	
}_ST_USART_MANAGER;

typedef struct{
    u8 Flag;
    u8 Status;
} _FS;

typedef struct{
    u8 mGuideReceiveFlag : 1;
    u8 mGuideNewReceiveStartFlag : 1;
	
	u8 mGuideStartDecodeFlag : 1;
	u8 mGuideReceiveOkFlag : 1;
	
	
	//时间相关
	u8 mTimeCont;
	u8 mTimeContLast;
	u8 mTimePeriod;
	//数据相关
	u8 mDecodeIndex;
	u8 mDecodeData;
	u8 mDecodeRecData;
	//数据清除相关
	u8 mSignalACountDownFlag : 1;
	u16 mSignalACountDownTime;
} _SENSORGUIDE;

typedef struct _ST_WORK_MANAGER{
	u8 mWorkInitFlag : 1;    //0:未初始化成功 1:初始化成功
	u8 mWorkChecking : 1;    //0:没有检测     1：正在检测中
	u8 mWorkCheckStatus : 2; //0:正在检测     1：检测成功     2：检测失败
	
	u8 mWorkStep;
	u8 mWorkStepOld;
	u8 mWorkFileStep;
	
	u8 mWorkTouchStep;
	
	u8 mWorkGuideSendFlag : 2;
	u8 mWorkGuideSendStep;
	u16 mWorkGuideSendCont;
	_FS mWorkGuide[1];
	
	_SENSORGUIDE mGuideReceive[5];
	
	u8 mWorkGuideReceiveFlag : 2;          //0:未开始接收   1：开始接收guide top  2:开始接收guide front
	u8 mWorkGuideFirstReceiveFlag : 1;     //0:第一次检测   1：不是第一次检测
	u8 mWorkGuideReceiveSuccessFlag : 1;   //0:未接收成功   1：接收成功
	
 	u8 mWorkKeyPressFlag : 1;
	u8 mWorkKeyPressFlag1 : 1;
	u8 mWorkKeyCont;
	
	u32 mWorkThingHight;
	
	u8 mWorkSensorSendStep;
	u8 mWorkSensorSendDropFlag : 1;
	u8 mWorkSensorSendAlongSideFlag : 1;
	u8 mWorkSensorSendAvoidBumpFlag : 1;
	
	u8 mWorkSensorAvoidBumpCont;
	u16 mWorkSensorOnOffAverage[15][2];//位置   0:开  1:关
	u16 mWorkSensorOnAvl[15][4];
	u16 mWorkSensorOffAvl[15][4];
	u16 mWorkSensorDataAvl[15];
	
	u8 mWorkCheckErrorFlag;
	
	u8 mWorkInitCont;
	u8 mWorkRightAvoidBumpErrorFlag : 1;
	u8 mWorkLeftSideErrorFlag : 1;
	u8 mWorkRightSideErrorFlag : 1;
	
	u8 mWorkCheckGuideReceiveFlag : 1;
	u8 mWorkAmidAvoidBumpFlag : 1;//中免碰撞检测标志位   0：不符合免碰撞初始条件   1：符合免碰撞初始条件
	
	
	u8 mWorkFrontGuideReceiveFlag : 1;
	u8 mWorkTopGuideReceiveFlag : 1;
	u8 mWorkFrontGuideFlag : 1;
	u8 mWorkTopGuideFlag : 1;
	
	u16 mWorkFrontGuideCont;
	u16 mWorkTopGuideCont;
	
	u16 mWorkAvoidBumpDat;
	u16 mWorkLeftAvoidBumpDatFar;
	u16 mWorkRightAvoidBumpDatFar;
	u16 mWorkAmongAvoidBumpDatFar;
	
	u16 mWorkLeftAlongSideDatFar;
	u16 mWorkLeftAlongSideDatNear;
	u16 mWorkRightAlongSideDatFar;
	u16 mWorkRightAlongSideDatNear;
}_ST_WORK_MANAGER;

// typedef struct _ST_WORK_MANAGER{
// 	u8 mWorkInitFlag : 1;    //0:未初始化成功 1:初始化成功
// 	u8 mWorkChecking : 1;    //0:没有检测     1：正在检测中
// 	u8 mWorkCheckStatus : 2; //0:正在检测     1：检测成功     2：检测失败
// 	
// 	u8 mWorkStep;
// 	u8 mWorkStepOld;
// 	u8 mWorkFileStep;
// 	
// 	u8 mWorkGuideSendFlag : 1;//0:不发射    1:发射
// 	u8 mWorkGuideSendStep;
// 	u16 mWorkGuideSendCont;
// 	_FS mWorkGuide[5];
// 	
// 	u8 mWorkKeyPressFlag : 1;
// 	u8 mWorkKeyPressFlag1 : 1;
// 	u8 mWorkKeyCont;
// 	
// 	u16 mWorkAlongSideReadVal;
// 	u16 mWorkAvoidBumpReadVal;
// 	u16 mWorkDropReadVal;
// 	u16 mWorkCodeReadVal;
// 	u16 mWorkDustReadVal;
// 	
// 	u8 mWorkCodeSendFlag : 1;      //0:不发    1:发
// 	u16 mWorkCodeSendCont;
// 	
// 	u8 mWorkDropSendFlag : 1;
// 	u16 mWorkDropSendCont;
// 	
// 	u8 mWorkBigUartFlag : 1;
// }_ST_WORK_MANAGER;


typedef struct _ST_MAINMANAGER{
	/*        文件内定义        */
	_ST_SYSTEM_MANAGER         mSystem;

	_ST_USART_MANAGER          mUart1;
	_ST_USART_MANAGER          mUart2;
//	_ST_USART_MANAGER          mUart4;
//	_ST_USART_MANAGER          mUart5;
	_ST_WORK_MANAGER           mWork;
}_ST_MAINMANAGER;
		
extern _ST_MAINMANAGER mMaininf;
extern __IO uint16_t ADCValue[8];
	
void prvSetupHardware(void);
void vCreateQueueAndSemphr(void);



	
	
#ifdef _cplusplus
extern }
#endif

#endif /*__MAINDEF_H__*/	


/****************************************************************************************************/
/*			@FileName		:	MAINDEF.h																																	  	*/
/*			@Author			:	zhengbaiqiu																																		*/
/*			@Version		:	v1.0																																					*/
/*			@Date				:	2019.11.12  																																	*/
/****************************************************************************************************/

#ifndef	__MAINDEF_H__
#define	__MAINDEF_H__

#include "stm32f10x.h"
#include <stdlib.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/*		struct congig		*/



#ifdef __cplusplus
extern "C" {
#endif
	
	
#define m_Ok 1                         //��
#define m_NoOk 0                       //��
	
#define BURN_TIMEOUT 300               //��¼����500ms��ʱ	
	
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
#define mainDISPLAY_TASK_PRIORITY				( tskIDLE_PRIORITY + 1 )
// #define mainCHECKKEY_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
// #define mainCHECKSD_TASK_PRIORITY				( tskIDLE_PRIORITY + 3 )
// #define mainPRINT_TASK_PRIORITY          (tskIDLE_PRIORITY + 2 )
// #define mainBURN_TASK_PRIORITY          (tskIDLE_PRIORITY + 2 )
// #define mainVERSIONCHECK_TASK_PRIORITY				( tskIDLE_PRIORITY + 2 )


/* Task Stack. */
#define mainTIMER_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
#define mainDISPLAY_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainCHECKKEY_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainCHECKSD_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainVERSIONCHECK_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainPRINT_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 64 )
// #define mainBURN_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 128 )



/*--------------------------------------------------------------------------

        �Զ���ṹ��

---------------------------------------------------------------------------*/	


/*   	 �Զ���			*/
#define SYSTEMTIMEMAX                86400000               /*   System timing maximum 24 hours  */

/* timeout time define */

#define TIMEOUT_0ms           (0)               /*   0ms��ʱ      */
#define TIMEOUT_5ms           (5)               /*   5ms��ʱ      */
#define TIMEOUT_10ms          (10)              /*   10ms��ʱ     */
#define TIMEOUT_50ms          (50)              /*   50ms��ʱ     */
#define TIMEOUT_100ms         (100)             /*   100ms��ʱ    */
#define TIMEOUT_300ms         (300)             /*   300ms��ʱ    */
#define TIMEOUT_500ms         (500)             /*   500ms��ʱ    */
#define TIMEOUT_1000ms        (1000)            /*   1000ms��ʱ   */
#define TIMEOUT_3500ms        (3500)            /*   3500ms��ʱ   */
#define TIMEOUT_5000ms        (5000)            /*   5000ms��ʱ   */

/*   	 �ṹ������			*/

typedef enum {
	ST_0x55 = 0x01,
	ST_0xAA,
	ST_MODE,
	ST_CMD,
	ST_STA,
	ST_DAT1,
	ST_DAT2,
	ST_DAT3,
	ST_DAT4,
	ST_DAT5,
	ST_BCC
} UART1_RECEIVE_STEP;


typedef enum
{
	TEST_START = 0x01,                     //01��ʼ���
	TEST_LEFT_GUIDE,                       //02������
	TEST_TOP_GUIDE,                        //03������
	TEST_FRONT_GUIDE,                      //04ǰ����
	TEST_RIGHT_GUIDE,                      //05������
	TEST_LEFT_AVOID_BUMP,                  //06������ײ
	TEST_FRONT_AVOID_BUMP0,                //07������ײ0
	TEST_FRONT_AVOID_BUMP1,                //08
	TEST_FRONT_AVOID_BUMP2,                //09
	TEST_FRONT_AVOID_BUMP3,                //10
	TEST_FRONT_AVOID_BUMP4,                //11
	TEST_FRONT_AVOID_BUMP5,                //12
	TEST_FRONT_AVOID_BUMP6,                //13
	TEST_FRONT_AVOID_BUMP7,                //14
	TEST_FRONT_AVOID_BUMP8,                //15
	TEST_FRONT_AVOID_BUMP9,                //16
	TEST_RIGHT_AVOID_BUMP,                 //17������ײ
	TEST_LEFT_ALONG_SIDE,                  //18���ر�
	TEST_RIGHT_ALONG_SIDE                  //19���ر�
	
}enum_TEST_CMD;

typedef struct _ST_SYSTEM_MANAGER{
	u32 mSystemTick ;                /*  1ms ģ��δ������   */
	u32 mPowerOnStartTime ;
	
	u32 mReadUartStatusStartTime ;
}_ST_SYSTEM_MANAGER;

typedef struct _ST_USART_MANAGER{
	u8 TxBuffer[64];
	u8 RxBuffer[64];
	u8 SendBuf[64];
	u8 ReceiveBuf[64];
	
	u16 mSendSize;
	u16 mSendCont;
	
	u8 mReceiveStep : 4;
	u8 mReceiveBCC;
	u16 mReceiveSize;
	u16 mReceiveCont;
	u16 mReceiveTimeOut;
	
	u8 mReceiveFlag : 1;
	
}_ST_USART_MANAGER;

typedef struct _ST_MODE_MANAGER{
	u8 mKeyPressFlag : 1;            //  0 : no press    1 : press  ��������
	u8 mScreenPressFlag : 1;         //  0 : no press    1 : press  ��Ļ����
	
	u8 mModePage;
}_ST_MODE_MANAGER;

typedef struct _ST_WORK_MANAGER{
	u8 mWorkMODE ;           //����ģʽ
 	u8 mWorkCMD ;            //����������
 	u8 mWorkSTATUS ;         //������״̬
	
	u8 mWorkInitFlag : 1;    //0:��ʼ��ʧ��   1����ʼ���ɹ�
	u8 mWorkChecking : 1;    //0:û�м��     1�����ڼ����
	u8 mWorkKeyCont ;
	
	u16 mWorkAvoidBumpDat1;
	u16 mWorkAvoidBumpDat2;
	u8 mWorkAvoidBumpErrorFlag;
}_ST_WORK_MANAGER;


typedef struct _ST_MAINMANAGER{
	/*        �ļ��ڶ���        */
	_ST_SYSTEM_MANAGER         mSystem;
	_ST_USART_MANAGER          mUart1;
//	_ST_USART_MANAGER          mUart2;
	
	_ST_MODE_MANAGER           mMode;
	_ST_WORK_MANAGER           mWork;

}_ST_MAINMANAGER;
		
extern _ST_MAINMANAGER mMaininf;
	
void prvSetupHardware(void);
void vCreateQueueAndSemphr(void);



	
	
#ifdef _cplusplus
extern }
#endif

#endif /*__MAINDEF_H__*/	


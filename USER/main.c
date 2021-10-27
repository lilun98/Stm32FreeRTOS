#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "can.h"
#include "FreeRTOS.h"
#include "task.h"


#define LED0  PDout(12)
#define LED1  PDout(13)


//typedef enum week
//{
//	Su, Mo, Tu, We, Th, Fr, Sa
//} WEEK;


//LED IO初始化
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;


  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIOD时钟
	
  //GPIOD12,D13初始化设置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;//对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIO
	
	GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13);//设置高，灯灭

}
void assert_failed(uint8_t* file, uint32_t line){
	printf("assert_failed in file %s at line %d.\r\n", file,line);
	while(1){
	
	}
}
//int main(void)
//{ 
//	
//	u8 canbuf[8];
//	volatile int a,b,c;
//	WEEK we = Su;
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
//	
//	
//	delay_init(168);		  //初始化延时函数
//	uart2_init(115200);
//	LED_Init();

//  /**下面是通过直接操作库函数的方式实现IO控制**/	
//	GPIO_ResetBits(GPIOD,GPIO_Pin_12);
//	GPIO_ResetBits(GPIOD,GPIO_Pin_13);
//	printf("nihao,6lowpan gateway");
//	
//	GPIO_ResetBits(GPIOD,0);
//	
////	CAN1_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN初始化,波特率500Kbps

//	printf("nihao,6lowpan gateway");

//	while(1)
//	{
//		GPIO_ResetBits(GPIOD,GPIO_Pin_12);  
//		GPIO_SetBits(GPIOD,GPIO_Pin_13);   
//		delay_ms(200);  		   
//		GPIO_SetBits(GPIOD,GPIO_Pin_12);	   
//		GPIO_ResetBits(GPIOD,GPIO_Pin_13); 
//		delay_ms(200);                     
//		printf("0123456789\r\n");
//		if((USART_RX_STA & 0x8000)==0x8000){
//			int len = USART_RX_STA&0x3FFF;
//			int i =0;
//			while(i < len){
//				while((USART2->SR&0X40)==0);//循环发送,直到发送完毕   
//				USART2->DR = USART_RX_BUF[i];   			
//				i++;
//			}
//			USART_RX_STA =0;
//		}
//	}
//}

//任务优先级
#define START_TASK_PRIO		1
//任务堆栈大小	
#define START_STK_SIZE 		128   
//实际大小为 START_STK_SIZE * StackType_t = 128 * 4 byte 
//任务句柄
TaskHandle_t StartTask_Handler;
//任务函数
void start_task(void *pvParameters);

//任务优先级
#define LED0_TASK_PRIO		2
//任务堆栈大小	
#define LED0_STK_SIZE 		50  
//任务句柄
TaskHandle_t LED0Task_Handler;
//任务函数
void led0_task(void *pvParameters);

//任务优先级
#define LED1_TASK_PRIO		3
//任务堆栈大小	
#define LED1_STK_SIZE 		50  
//任务句柄
TaskHandle_t LED1Task_Handler;
//任务函数
void led1_task(void *pvParameters);

//任务优先级
#define FLOAT_TASK_PRIO		4
//任务堆栈大小	
#define FLOAT_STK_SIZE 		128
//任务句柄
TaskHandle_t FLOATTask_Handler;
//任务函数
void float_task(void *pvParameters);

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4
	delay_init(168);		//初始化延时函数
	uart2_init(115200);     	//初始化串口
	LED_Init();		        //初始化LED端口
	
	//创建开始任务
    xTaskCreate((TaskFunction_t )start_task,            //任务函数
                (const char*    )"start_task",          //任务名称
                (uint16_t       )START_STK_SIZE,        //任务堆栈大小
                (void*          )NULL,                  //传递给任务函数的参数
                (UBaseType_t    )START_TASK_PRIO,       //任务优先级
                (TaskHandle_t*  )&StartTask_Handler);   //任务句柄              
    vTaskStartScheduler();          //开启任务调度
}
 
//开始任务任务函数
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //进入临界区
    //创建LED0任务
    xTaskCreate((TaskFunction_t )led0_task,     	
                (const char*    )"led0_task",   	
                (uint16_t       )LED0_STK_SIZE, 
                (void*          )NULL,				
                (UBaseType_t    )LED0_TASK_PRIO,	
                (TaskHandle_t*  )&LED0Task_Handler);   
    //创建LED1任务
    xTaskCreate((TaskFunction_t )led1_task,     
                (const char*    )"led1_task",   
                (uint16_t       )LED1_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )LED1_TASK_PRIO,
                (TaskHandle_t*  )&LED1Task_Handler);        
    //浮点测试任务
    xTaskCreate((TaskFunction_t )float_task,     
                (const char*    )"float_task",   
                (uint16_t       )FLOAT_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )FLOAT_TASK_PRIO,
                (TaskHandle_t*  )&FLOATTask_Handler);  
    vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}

//LED0任务函数 
void led0_task(void *pvParameters)
{
    while(1)
    {
        LED0=~LED0;
        vTaskDelay(500);
    }
}   

//LED1任务函数
void led1_task(void *pvParameters)
{
    while(1)
    {
        LED1=0;
        vTaskDelay(200);
        LED1=1;
        vTaskDelay(800);
    }
}

//浮点测试任务
void float_task(void *pvParameters)
{
	static float float_num=0.00;
    
	while(1)
	{
		float_num+=0.01f;
		printf("float_num的值为: %.4f\r\n",float_num);
        vTaskDelay(1000);
	}
}



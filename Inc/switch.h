#ifndef __COMMAND_H
#define __COMMAND_H
#define K_ON(port, pin) HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET)
#define K_OFF(port, pin) HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET)
typedef enum
{
	ACT_OFF = 0,
	ACT_ON,
	ACT_STOP
}SwActType_t;
typedef enum
{
	SW_FAN = 0,
	SW_SUNSHADE,
	SW_TOPFILM,
	SW_SIDEFILM,
	SW_LIGHT
}CommandType_t;
typedef enum
{
	RES_OK = 0,
	RES_FAILED,
	RES_KEEP
}CommandResType_t;
typedef struct
{
	CommandType_t	type;				//����
	SwActType_t	action;				//����
	CommandResType_t result;	//����ִ�н��
	SwActType_t status;				//״̬
	BOOL_t				command_new;//�������־
	GPIO_TypeDef *k1_port;
	uint16_t			k1_pin;
	GPIO_TypeDef *k2_port;
	uint16_t			k2_pin;
	char *				cmdbuf;			//�������
	uint8_t				cmdsize;		//���������С
}SW_Handle_t;//���ؾ��
/*ִ�п���������*/
BOOL_t Cmd_Exec(PtrQue_TypeDef * cq);
/*������г�ʼ��*/
void Command_Que_Init(PtrQue_TypeDef * cq);
/*���ƿ��ض���*/
void SW_Control(SW_Handle_t * sw);
void SW_OFF(SW_Handle_t * sw);
void SW_ON(SW_Handle_t * sw);
void SW_STOP(SW_Handle_t * sw);
#endif
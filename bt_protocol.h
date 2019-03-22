

#ifndef BT_PROTOCOL_H
#define BT_PROTOCOL_H




typedef struct 
{
	unsigned char packet_type;
	unsigned char opcode;
	unsigned char length;
	unsigned char payload[300];
}
HCI_PACKET;


typedef struct
{
	unsigned char bt_visiable:1;
	unsigned char bt_connectable:1;
	unsigned char ble_visible:1;
	unsigned char bt_connected:1;
	unsigned char ble_connected:1;
}
HCI_BT_STATUS;


typedef enum
{
	PAIR_MODE_PIN_CODE=0,
	PAIR_MODE_JUST_WORK=1,
}
PAIR_MODE;


#define  PACKET_TYPE_CMD              0x01
#define  PACKET_TYPE_EVENT            0x02

//�������
#define  HCI_CMD_SET_BT_ADDR			0x00  // ���� BT3.0 ��ַ
#define  HCI_CMD_SET_BLE_ADDR			0x01  // ���� BLE ��ַ
#define  HCI_CMD_SET_VISIBILITY			0x02  // ���ÿɷ��ֺ͹㲥
#define  HCI_CMD_SET_BT_NAME			0x03  // ���� BT3.0 ����
#define  HCI_CMD_SET_BLE_NAME			0x04  // ���� BLE ����
#define  HCI_CMD_SEND_SPP_DATA			0x05  // ���� BT3.0��SPP������
#define  HCI_CMD_SEND_BLE_DATA			0x09  // ���� BLE ����
#define  HCI_CMD_STATUS_REQUEST			0x0B  // ��������״̬
#define  HCI_CMD_SET_PAIRING_MODE		0x0C  // �������ģʽ
#define  HCI_CMD_SET_PINCODE			0x0D  // ���������
#define  HCI_CMD_SET_UART_FLOW			0x0E  // ���� UART ����
#define  HCI_CMD_SET_UART_BAUD			0x0F  // ���� UART ������
#define  HCI_CMD_VERSION_REQUEST		0x10  // ��ѯģ��̼��汾
#define  HCI_CMD_BT_DISCONNECT			0x11  // �Ͽ� BT3.0 ����
#define  HCI_CMD_BLE_DISCONNECT			0x12  // �Ͽ� BLE ����
#define  HCI_CMD_SET_COD				0x15  // ���� COD
#define  HCI_CMD_SET_NVRAM				0x26  // �·� NV ����
#define  HCI_CMD_ENTER_SLEEP_MODE		0x27  // ����˯��ģʽ
#define  HCI_CMD_SPP_DATA_COMPLETE		0x29  // SPP ���ݴ������
#define  HCI_CMD_SET_ADV_DATA			0x2A  // ���� ADV ����
#define  HCI_CMD_POWER_REQ				0x2B

// ��Ӧ�¼�
#define  HCI_EVENT_BT_CONNECTED        0x00   // BT3.0 ���ӽ���
#define  HCI_EVENT_BLE_CONNECTED       0x02   // BLE ���ӽ���
#define  HCI_EVENT_BT_DISCONNECTED     0x03   // BT3.0 ���ӶϿ�
#define  HCI_EVENT_BLE_DISCONNECTED    0x05   // BLE ���ӶϿ�
#define  HCI_EVENT_CMD_COMPLETE        0x06   // ���������
#define  HCI_EVENT_SPP_DATA_RECEIVED   0x07   // ���յ� BT3.0 ���ݣ�SPP��
#define  HCI_EVENT_BLE_DATA_RECEIVED   0x08   // ���յ� BLE ����
#define  HCI_EVENT_I_AM_READY          0x09   // ģ��׼����
#define  HCI_EVENT_STAUS_RESPONSE      0x0A   // ״̬�ظ�
#define  HCI_EVENT_NVRAM_CHANGED       0x0D   // �ϴ� NVRAM ����
#define  HCI_EVENT_UART_EXCEPTION      0x0F   // HCI ����ʽ����


int YC_HCI_CMD_SET_BT_ADDR(u8 *address);
int YC_HCI_CMD_SET_BLE_ADDR(u8 *address);
int YC_HCI_CMD_SET_VISIBILITY(u8 bt_visible, u8 ble_visible);
int YC_HCI_CMD_SET_BT_NAME(char *name);
int YC_HCI_CMD_SET_BLE_NAME(char *name);
int YC_HCI_CMD_STATUS_REQUEST(HCI_BT_STATUS *bt_status);
int YC_HCI_CMD_SET_PAIRING_MODE(PAIR_MODE pair_mode);
int YC_HCI_CMD_SET_PINCODE(char *pincode);
int YC_HCI_CMD_SET_UART_FLOW(u8 flow);
int YC_HCI_CMD_VERSION_REQUEST(u16 *version);
int YC_HCI_CMD_BT_DISCONNECT(void);
int YC_HCI_CMD_BLE_DISCONNECT(void);
int YC_HCI_CMD_SET_NVRAM(u8 *nvram);
int YC_HCI_CMD_ENTER_SLEEP_MODE(void);
int YC_HCI_CMD_EXIT_SLEEP_MODE(void);
int YC_HCI_CMD_SEND_SPP_DATA(u8 *data, u16 len);
int YC_HCI_CMD_SEND_BLE_DATA(u8 *data, u16 len);

void HCI_Get_Connect_Status(u8 *bt, u8 *ble);
int HCI_CHECK_EVENT(HCI_PACKET *response_packet, u8 cmd_opcode);


#endif



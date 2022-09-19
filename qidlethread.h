#ifndef QIDLETHREAD_H
#define QIDLETHREAD_H

#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QFile>

#define FPGA_FILE_MAX_SIZE (64*1024*1024)

#define ICD_MAX_SIZE 1024 //ICD最大长度为1K
#define ICD_DAT_MAX_SIZE 896 //ICD最大有效数据载荷896
#define ICD_FILEDAT_MAX_SIZE (ICD_DAT_MAX_SIZE-8) //ICD最大有效的文件数据载荷896

#define ICD_CMD_HEAD 0xAAAA5555 //包头
#define ICD_CMD_TAIL 0x5555AAAA //包尾
#define ICD_OPRET_OK 0x00000001 //操作OK
#define ICD_OPRET_UNEARSE 0x00000002 //未擦除

#define ICD_CMD_EARSE 0x00000001 //擦除指令
#define ICD_CMD_WRITE 0x00000002 //数据写入指令
#define ICD_CMD_READ 0x00000003 //数据读取指令
#define ICD_CMD_PARA_GET 0x00000004 //参数获取指令
#define ICD_CMD_PARA_SET 0x00000005 //参数设置取指令
#define ICD_CMD_STATE_GET 0x00000006 //状态获取

/*
 * ICD 通用包头协议
 */
#pragma pack(1)
typedef struct {
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数
    uint8_t dat[1];//数据段
    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
} ICD_COMMON_HEAD_T;

//擦除指令ICD定义
typedef struct {
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数
    uint32_t fpgaCs;//FPGA片选
    uint32_t addr;//擦除的地址
    uint32_t spaceSize;//擦除空间大小
    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
} ICD_EARSE_CMD_T;
#define ICD_EARSE_SIZE 12 //擦除指令数据段长度

//数据写指令ICD定义
typedef struct {
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数
    uint32_t fpgaCs;//FPGA片选
    uint32_t ackCnt;//在一个写流程中，第几次请求写操作
    uint8_t dat[ICD_FILEDAT_MAX_SIZE];//需要写入的数据
    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
} ICD_WRITE_CMD_T;

//操作状态响应ICD定义
typedef struct {
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数
    uint32_t opRet;//操作结果 0x0000_0001:表示擦除成功，其他:表示擦除失败
    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
} ICD_COMMON_RSP_T;
#define ICD_COMMON_RSP_SIZE 4 //操作结果响应数据包数据段长度

//数据读取指令ICD定义
typedef struct {
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数
    uint32_t fpgaCs;//FPGA片选
    uint32_t ackCnt;//在一个读取流程中，第几次请求读取操作
    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
} ICD_DAT_READ_CMD_T;
#define ICD_DAT_READ_SIZE 8 //数据读取指令数据段长度

//服务器参数获取指令ICD定义
typedef struct {
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数
    uint32_t rev;//保留字段
    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
} ICD_PARA_GET_CMD_T;
#define ICD_PARA_GET_SIZE 4 //服务器参数获取指令数据段长度

//服务器参数获取响应ICD定义   或者    服务器参数设置响应ICD定义
typedef struct {
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数
    uint8_t ip[4];//IP地址
    uint16_t port;//端口
    uint8_t mac[6];//MAC地址
    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
} ICD_PARA_T;
#define ICD_PARA_SIZE 12 //服务器参数数据段长度
typedef struct
{
    uint32_t head;//包头
    uint32_t cmd;//表示该条ICD为什么命令
    uint32_t size;//表示数据字段的字节个数

    uint8_t yy_h;
    uint8_t yy_l;
    uint8_t mm;
    uint8_t dd;
    uint8_t hh;
    uint8_t ss;
    uint8_t fpga1;//0x10
    uint8_t fpga2;//0x11
    uint8_t fpga3;//0x12

    uint8_t ctrl_h;//0x14
    uint8_t ctrl_l;//0x15
    uint8_t output_h;//0x16
    uint8_t output_l;//0x17
    uint8_t LTM4630_0_h;//0x20
    uint8_t LTM4630_0_l;//0x2
    uint8_t LTM4630_1_h;//0x22
    uint8_t LTM4630_1_l;//0x23
    uint8_t LTM4630_2_h;//0x24
    uint8_t LTM4630_2_l;//0x25
    //正面温度
    uint8_t Temp_TOP_h;//0x26
    uint8_t Temp_TOP_l;//0x27
    //背面温度
    uint8_t Temp_BOT_h;//0x28
    uint8_t Temp_BOT_l;//0x29
    //fpga
    uint8_t Temp_FPGA1_h;//0x2a
    uint8_t Temp_FPGA1_l;//0x2b
    uint8_t Temp_FPGA2_h;//0x2c
    uint8_t Temp_FPGA2_l;//0x2d
    uint8_t Temp_FPGA3_h;//0x2e
    uint8_t Temp_FPGA3_l;//0x2f
    //+1V0_FPGA1电压
    uint8_t FPGA1_1V0_h;//0x30
    uint8_t FPGA1_1V0_l;//0x31
    //+1V0_FPGA2_3电压
    uint8_t FPGA2_3_1V0_h;//0x32
    uint8_t FPGA2_3_1V0_l;//0x33
    //+1V0_FPGA1_MGTAVCC电压
    uint8_t FPGA1_1V0_MGTA_h;//0x34
    uint8_t FPGA1_1V0_MGTA_l;//0x35
    //+1V0_FPGA2_3_MGTAVCC电压
    uint8_t FPGA2_3_1V0_MGTA_h;//0x36
    uint8_t FPGA2_3_1V0_MGTA_l;//0x37
    //+1V2_FPGA1_MGTAVTT电压
    uint8_t FPGA1_1V2_MGTA_h;//0x38
    uint8_t FPGA1_1V2_MGTA_l;//0x39
    //+1V2_FPGA2_3_MGTAVTT电压
    uint8_t FPGA2_3_1V2_MGTA_h;//0x3a
    uint8_t FPGA2_3_1V2_MGTA_l;//0x3b
    //+1V8_FPGA1电压
    uint8_t FPGA1_1V8_h;//0x3c
    uint8_t FPGA1_1V8_l;//0x3d
    //+1V8电压
    uint8_t _1V8_h;//0x3e
    uint8_t _1V8_l;//0x3f
    uint8_t clkChoose;
    uint8_t clkConfig;
    uint8_t setupCtrl;

    uint32_t tail;//包尾
    uint32_t checkSum;//和校验
}ICD_STATE_PARA_RSP;
#define ICD_STATE_PARA_SIZE 48 //FPGA状态数据段长度
#pragma pack(0)
class QIdleThread : public QThread
{
    Q_OBJECT
public:
    explicit QIdleThread(QObject *parent = nullptr);
    ~QIdleThread();
protected:
    void run();
private:

public:
    void *fwd;
    QFile fpgaFile;
    QFile readFile;
    bool creatReadFile(void);

    uint32_t checkSum(uint8_t *dat, int size);
    bool checkDatIsOK(uint8_t *dat, int size);
    bool getIcdCmdDat(uint8_t *recvBuf, int recvSize, \
                      uint32_t *cmd, uint8_t *dat, uint32_t *datSize);
    void prgmUpgrade(void);
    void prgmRead(void);
    void prgmEarse(void);
    void paraGet(void);
    void paraSet(void);
    void stateGet(void);

public:
    int semTimeOut;//默认1000ms超时
    QMutex exitSem;//现成退出信号量
    QMutex tcpRecvSem;//TCP有数据
signals:
    void signalbut(void);
};

#endif // QIDLETHREAD_H

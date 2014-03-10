#ifndef __KSOTPTRADERAPI_H_INCLUDED_
#define __KSOTPTRADERAPI_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KSOTPUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_OTP_TRADER_API_EXPORT
#define OTP_TRADER_API_EXPORT __declspec(dllexport)
#else
#define OTP_TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#ifdef WIN32
#define OTP_TRADER_API_EXPORT 
#else
#define OTP_TRADER_API_EXPORT __attribute__((visibility("default")))
#endif

#endif

namespace KingstarAPI
{

class CKSOTPTraderSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用.
	virtual void OnFrontConnected(){};

	///当客户端与交易后台通信连接断开时，该方法被调用.
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	///        0x2004 服务器主动断开
	virtual void OnFrontDisconnected(int nReason){};

	///登录请求响应
	virtual void OnRspUserLogin(CKSOTPRspUserLoginField *pRspUserLogin, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///登出请求响应
	virtual void OnRspUserLogout(CKSOTPUserLogoutField *pUserLogout, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户口令更新请求响应
	virtual void OnRspUserPasswordUpdate(CKSOTPUserPasswordUpdateField *pUserPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///资金账户口令更新请求响应
	virtual void OnRspTradingAccountPasswordUpdate(CKSOTPTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单录入请求响应
	virtual void OnRspOrderInsert(CKSOTPInputOrderField *pInputOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单操作请求响应
	virtual void OnRspOrderAction(CKSOTPInputOrderActionField *pInputOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询报单响应
	virtual void OnRspQryOrder(CKSOTPOrderField *pOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询成交响应
	virtual void OnRspQryTrade(CKSOTPTradeField *pTrade, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询投资者持仓响应
	virtual void OnRspQryInvestorPosition(CKSOTPInvestorPositionField *pInvestorPosition, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询资金账户响应
	virtual void OnRspQryTradingAccount(CKSOTPTradingAccountField *pTradingAccount, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询投资者响应
	virtual void OnRspQryInvestor(CKSOTPInvestorField *pInvestor, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询合约账号响应
	virtual void OnRspQryTradingCode(CKSOTPTradingCodeField *pTradingCode, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询交易所响应
	virtual void OnRspQryExchange(CKSOTPExchangeField *pExchange, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询合约响应
	virtual void OnRspQryInstrument(CKSOTPInstrumentField *pInstrument, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionDetail(CKSOTPInvestorPositionDetailField *pInvestorPositionDetail, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询交易通知响应
	virtual void OnRspQryTradingNotice(CKSOTPTradingNoticeField *pTradingNotice, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///非交易报单录入请求响应
	virtual void OnRspNonTradingOrderInsert(CKSOTPInputNonTradingOrderField *pInputNonTradingOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///非交易报单操作请求响应
	virtual void OnRspNonTradingOrderAction(CKSOTPInputNonTradingOrderActionField *pInputNonTradingOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询非交易报单响应
	virtual void OnRspQryNonTradingOrder(CKSOTPNonTradingOrderField *pNonTradingOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询非交易报单量请求响应
	virtual void OnRspQryNonTradingOrderVolume(CKSOTPNonTradingOrderVolumeField *pNonTradingOrderVolume, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///请求查询标的券信息响应
	virtual void OnRspQryUnderlyingStockInfo(CKSOTPUnderlyingStockInfoField *pOTPUnderlyingStockInfo, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询个股期权手续费率请求响应
	virtual void OnRspQryOTPInsCommRate(CKSOTPOTPInsCommRateField *pOTPInsCommRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询个股期权保证金率请求响应
	virtual void OnRspQryOTPInsMarginRate(CKSOTPOTPInsMarginRateField *pOTPInsMarginRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询个股行权指派信息请求响应
	virtual void OnRspQryOTPAssignment(CKSOTPOTPAssignmentField *pOTPAssignment, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询行情响应
	virtual void OnRspQryDepthMarketData(CKSOTPDepthMarketDataField *pOTPDepthMarketData, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	///错误应答
	virtual void OnRspError(CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单通知
	virtual void OnRtnOrder(CKSOTPOrderField *pOrder) {};

	///成交通知
	virtual void OnRtnTrade(CKSOTPTradeField *pTrade) {};

	///非交易报单通知
	virtual void OnRtnNonTradingOrder(CKSOTPNonTradingOrderField *pNonTradingOrder) {};

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CKSOTPInstrumentStatusField *pInstrumentStatus) {};

	///交易通知
	virtual void OnRtnTradingNotice(CKSOTPTradingNoticeInfoField *pTradingNoticeInfo) {};
};

class OTP_TRADER_API_EXPORT CKSOTPTraderApi
{
public:
	///创建TraderApi
	///@return 创建出的UserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	static CKSOTPTraderApi *CreateOTPTraderApi(const char *pszFlowPath = "");

	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;

	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init() = 0;

	///获取当前交易日
	///@return 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;

	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址.
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”. 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址.”17001”代表服务器端口号.
	virtual void RegisterFront(char *pszFrontAddress) = 0;

	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CKSOTPTraderSpi *pSpi) = 0;

	///订阅私有流.
	///@param nResumeType 私有流重传方式  
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用.若不调用则不会收到私有流的数据.
	virtual void SubscribePrivateTopic(KSOTP_TE_RESUME_TYPE nResumeType) = 0;

	///订阅公共流.
	///@param nResumeType 公共流重传方式  
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用.若不调用则不会收到公共流的数据.
	virtual void SubscribePublicTopic(KSOTP_TE_RESUME_TYPE nResumeType) = 0;

	///用户登录请求
	virtual int ReqUserLogin(CKSOTPReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///登出请求
	virtual int ReqUserLogout(CKSOTPUserLogoutField *pUserLogout, int nRequestID) = 0;

	///用户口令更新请求
	virtual int ReqUserPasswordUpdate(CKSOTPUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///资金账户口令更新请求
	virtual int ReqTradingAccountPasswordUpdate(CKSOTPTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CKSOTPInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CKSOTPInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

	///请求查询报单
	virtual int ReqQryOrder(CKSOTPQryOrderField *pQryOrder, int nRequestID) = 0;

	///请求查询成交
	virtual int ReqQryTrade(CKSOTPQryTradeField *pQryTrade, int nRequestID) = 0;

	///请求查询投资者持仓
	virtual int ReqQryInvestorPosition(CKSOTPQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///请求查询资金账户
	virtual int ReqQryTradingAccount(CKSOTPQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

	///请求查询投资者
	virtual int ReqQryInvestor(CKSOTPQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///请求查询合约账号
	virtual int ReqQryTradingCode(CKSOTPQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///请求查询交易所
	virtual int ReqQryExchange(CKSOTPQryExchangeField *pQryExchange, int nRequestID) = 0;

	///请求查询合约
	virtual int ReqQryInstrument(CKSOTPQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///请求查询投资者持仓明细
	virtual int ReqQryInvestorPositionDetail(CKSOTPQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID) = 0;

	///请求查询交易通知
	virtual int ReqQryTradingNotice(CKSOTPQryTradingNoticeField *pQryTradingNotice, int nRequestID) = 0;

	///非交易报单录入请求
	virtual int ReqNonTradingOrderInsert(CKSOTPInputNonTradingOrderField *pInputNonTradingOrder, int nRequestID) = 0;

	///非交易报单操作请求（仅针对行权单）
	virtual int ReqNonTradingOrderAction(CKSOTPInputNonTradingOrderActionField *pInputNonTradingOrderAction, int nRequestID) = 0;

	///请求查询非交易报单
	virtual int ReqQryNonTradingOrder(CKSOTPQryNonTradingOrderField *pQryNonTradingOrder, int nRequestID) = 0;

	///查询非交易报单量请求
	virtual int ReqQryNonTradingOrderVolume(CKSOTPQryNonTradingOrderVolumeField *pQryNonTradingOrderVolume, int nRequestID) = 0;

	///查询标的券信息请求
	virtual int ReqQryUnderlyingStockInfo(CKSOTPQryUnderlyingStockInfoField *pQryOTPOrderParams, int nRequestID) = 0;

	///查询个股期权手续费率请求
	virtual int ReqQryOTPInsCommRate(CKSOTPQryOTPInsCommRateField *pQryOTPInsCommRate, int nRequestID) = 0;

	///查询个股期权保证金率请求
	virtual int ReqQryOTPInsMarginRate(CKSOTPQryOTPInsMarginRateField *pQryOTPInsMarginRate, int nRequestID) = 0;

	///查询个股行权指派信息
	virtual int ReqQryOTPAssignment(CKSOTPQryOTPAssignmentField *pQryOTPAssignment, int nRequestID) = 0;

	///请求查询行情 
	virtual int ReqQryDepthMarketData(CKSOTPQryDepthMarketDataField *pQryOTPDepthMarketData, int nRequestID) = 0;

protected:
	~CKSOTPTraderApi(){};
};

}	// end of namespace KingstarAPI
#endif
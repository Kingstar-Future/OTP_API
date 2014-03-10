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
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷���������.
	virtual void OnFrontConnected(){};

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷���������.
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	///        0x2004 �����������Ͽ�
	virtual void OnFrontDisconnected(int nReason){};

	///��¼������Ӧ
	virtual void OnRspUserLogin(CKSOTPRspUserLoginField *pRspUserLogin, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CKSOTPUserLogoutField *pUserLogout, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��������������Ӧ
	virtual void OnRspUserPasswordUpdate(CKSOTPUserPasswordUpdateField *pUserPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ʽ��˻��������������Ӧ
	virtual void OnRspTradingAccountPasswordUpdate(CKSOTPTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CKSOTPInputOrderField *pInputOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������Ӧ
	virtual void OnRspOrderAction(CKSOTPInputOrderActionField *pInputOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CKSOTPOrderField *pOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CKSOTPTradeField *pTrade, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CKSOTPInvestorPositionField *pInvestorPosition, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CKSOTPTradingAccountField *pTradingAccount, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CKSOTPInvestorField *pInvestor, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Լ�˺���Ӧ
	virtual void OnRspQryTradingCode(CKSOTPTradingCodeField *pTradingCode, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CKSOTPExchangeField *pExchange, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CKSOTPInstrumentField *pInstrument, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionDetail(CKSOTPInvestorPositionDetailField *pInvestorPositionDetail, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ����֪ͨ��Ӧ
	virtual void OnRspQryTradingNotice(CKSOTPTradingNoticeField *pTradingNotice, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǽ��ױ���¼��������Ӧ
	virtual void OnRspNonTradingOrderInsert(CKSOTPInputNonTradingOrderField *pInputNonTradingOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǽ��ױ�������������Ӧ
	virtual void OnRspNonTradingOrderAction(CKSOTPInputNonTradingOrderActionField *pInputNonTradingOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ǽ��ױ�����Ӧ
	virtual void OnRspQryNonTradingOrder(CKSOTPNonTradingOrderField *pNonTradingOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�ǽ��ױ�����������Ӧ
	virtual void OnRspQryNonTradingOrderVolume(CKSOTPNonTradingOrderVolumeField *pNonTradingOrderVolume, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�����ѯ���ȯ��Ϣ��Ӧ
	virtual void OnRspQryUnderlyingStockInfo(CKSOTPUnderlyingStockInfoField *pOTPUnderlyingStockInfo, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ѯ������Ȩ��������������Ӧ
	virtual void OnRspQryOTPInsCommRate(CKSOTPOTPInsCommRateField *pOTPInsCommRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ѯ������Ȩ��֤����������Ӧ
	virtual void OnRspQryOTPInsMarginRate(CKSOTPOTPInsMarginRateField *pOTPInsMarginRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ѯ������Ȩָ����Ϣ������Ӧ
	virtual void OnRspQryOTPAssignment(CKSOTPOTPAssignmentField *pOTPAssignment, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CKSOTPDepthMarketDataField *pOTPDepthMarketData, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	///����Ӧ��
	virtual void OnRspError(CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����֪ͨ
	virtual void OnRtnOrder(CKSOTPOrderField *pOrder) {};

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CKSOTPTradeField *pTrade) {};

	///�ǽ��ױ���֪ͨ
	virtual void OnRtnNonTradingOrder(CKSOTPNonTradingOrderField *pNonTradingOrder) {};

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CKSOTPInstrumentStatusField *pInstrumentStatus) {};

	///����֪ͨ
	virtual void OnRtnTradingNotice(CKSOTPTradingNoticeInfoField *pTradingNoticeInfo) {};
};

class OTP_TRADER_API_EXPORT CKSOTPTraderApi
{
public:
	///����TraderApi
	///@return ��������UserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	static CKSOTPTraderApi *CreateOTPTraderApi(const char *pszFlowPath = "");

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;

	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;

	///��ȡ��ǰ������
	///@return ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ.
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001��. 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ.��17001������������˿ں�.
	virtual void RegisterFront(char *pszFrontAddress) = 0;

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CKSOTPTraderSpi *pSpi) = 0;

	///����˽����.
	///@param nResumeType ˽�����ش���ʽ  
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ����.���������򲻻��յ�˽����������.
	virtual void SubscribePrivateTopic(KSOTP_TE_RESUME_TYPE nResumeType) = 0;

	///���Ĺ�����.
	///@param nResumeType �������ش���ʽ  
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ����.���������򲻻��յ�������������.
	virtual void SubscribePublicTopic(KSOTP_TE_RESUME_TYPE nResumeType) = 0;

	///�û���¼����
	virtual int ReqUserLogin(CKSOTPReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///�ǳ�����
	virtual int ReqUserLogout(CKSOTPUserLogoutField *pUserLogout, int nRequestID) = 0;

	///�û������������
	virtual int ReqUserPasswordUpdate(CKSOTPUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///�ʽ��˻������������
	virtual int ReqTradingAccountPasswordUpdate(CKSOTPTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CKSOTPInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CKSOTPInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryOrder(CKSOTPQryOrderField *pQryOrder, int nRequestID) = 0;

	///�����ѯ�ɽ�
	virtual int ReqQryTrade(CKSOTPQryTradeField *pQryTrade, int nRequestID) = 0;

	///�����ѯͶ���ֲ߳�
	virtual int ReqQryInvestorPosition(CKSOTPQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///�����ѯ�ʽ��˻�
	virtual int ReqQryTradingAccount(CKSOTPQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

	///�����ѯͶ����
	virtual int ReqQryInvestor(CKSOTPQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///�����ѯ��Լ�˺�
	virtual int ReqQryTradingCode(CKSOTPQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///�����ѯ������
	virtual int ReqQryExchange(CKSOTPQryExchangeField *pQryExchange, int nRequestID) = 0;

	///�����ѯ��Լ
	virtual int ReqQryInstrument(CKSOTPQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///�����ѯͶ���ֲ߳���ϸ
	virtual int ReqQryInvestorPositionDetail(CKSOTPQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID) = 0;

	///�����ѯ����֪ͨ
	virtual int ReqQryTradingNotice(CKSOTPQryTradingNoticeField *pQryTradingNotice, int nRequestID) = 0;

	///�ǽ��ױ���¼������
	virtual int ReqNonTradingOrderInsert(CKSOTPInputNonTradingOrderField *pInputNonTradingOrder, int nRequestID) = 0;

	///�ǽ��ױ����������󣨽������Ȩ����
	virtual int ReqNonTradingOrderAction(CKSOTPInputNonTradingOrderActionField *pInputNonTradingOrderAction, int nRequestID) = 0;

	///�����ѯ�ǽ��ױ���
	virtual int ReqQryNonTradingOrder(CKSOTPQryNonTradingOrderField *pQryNonTradingOrder, int nRequestID) = 0;

	///��ѯ�ǽ��ױ���������
	virtual int ReqQryNonTradingOrderVolume(CKSOTPQryNonTradingOrderVolumeField *pQryNonTradingOrderVolume, int nRequestID) = 0;

	///��ѯ���ȯ��Ϣ����
	virtual int ReqQryUnderlyingStockInfo(CKSOTPQryUnderlyingStockInfoField *pQryOTPOrderParams, int nRequestID) = 0;

	///��ѯ������Ȩ������������
	virtual int ReqQryOTPInsCommRate(CKSOTPQryOTPInsCommRateField *pQryOTPInsCommRate, int nRequestID) = 0;

	///��ѯ������Ȩ��֤��������
	virtual int ReqQryOTPInsMarginRate(CKSOTPQryOTPInsMarginRateField *pQryOTPInsMarginRate, int nRequestID) = 0;

	///��ѯ������Ȩָ����Ϣ
	virtual int ReqQryOTPAssignment(CKSOTPQryOTPAssignmentField *pQryOTPAssignment, int nRequestID) = 0;

	///�����ѯ���� 
	virtual int ReqQryDepthMarketData(CKSOTPQryDepthMarketDataField *pQryOTPDepthMarketData, int nRequestID) = 0;

protected:
	~CKSOTPTraderApi(){};
};

}	// end of namespace KingstarAPI
#endif
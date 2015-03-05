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

	///ִ������¼��������Ӧ
	virtual void OnRspExecOrderInsert(CKSOTPInputExecOrderField *pInputExecOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ӧ��
	virtual void OnRspLockInsert(CKSOTPInputLockField *pInputLock, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ִ���������������Ӧ
	virtual void OnRspExecOrderAction(CKSOTPInputExecOrderActionField *pInputExecOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯִ��������Ӧ
	virtual void OnRspQryExecOrder(CKSOTPExecOrderField *pExecOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ��������������Ӧ
	virtual void OnRspQryExecOrderVolume(CKSOTPExecOrderVolumeField *pExecOrderVolume, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ����Ӧ��
	virtual void OnRspQryLock(CKSOTPLockField *pLock, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ����֤ȯ��λӦ��
	virtual void OnRspQryLockPosition(CKSOTPLockPositionField *pLockPosition, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ���ȯ��Ϣ��Ӧ
	virtual void OnRspQryUnderlyingStockInfo(CKSOTPUnderlyingStockInfoField *pUnderlyingStockInfo, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ѯ������Ȩ��������������Ӧ
	virtual void OnRspQryOTPInsCommRate(CKSOTPOTPInsCommRateField *pOTPInsCommRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ѯ������Ȩ��Լ��֤����������Ӧ
	virtual void OnRspQryInstrumentMarginRate(CKSOTPInstrumentMarginRateField *pInstrumentMarginRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///��ѯ������Ȩָ����Ϣ������Ӧ
	virtual void OnRspQryOTPAssignment(CKSOTPOTPAssignmentField *pOTPAssignment, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CKSOTPDepthMarketDataField *pDepthMarketData, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���������ʽ�ת֤ȯӦ��
	virtual void OnRspFromBankToStockByStock(CKSOTPReqTransferField *pReqTransfer, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	///֤ȯ���������ʽ�ת֤ȯ֪ͨ
	virtual void OnRtnFromBankToStockByStock(CKSOTPRspTransferField *pRspTransfer) {};

	///֤ȯ����֤ȯ�ʽ�ת����Ӧ��
	virtual void OnRspFromStockToBankByStock(CKSOTPReqTransferField *pReqTransfer, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֤ȯ����֤ȯ�ʽ�ת����֪ͨ
	virtual void OnRtnFromStockToBankByStock(CKSOTPRspTransferField *pRspTransfer) {};

	///֤ȯ�����ѯ�������֪ͨ
	virtual void OnRtnQueryBankBalanceByStock(CKSOTPNotifyQueryAccountField *pNotifyQueryAccount) {};

	///�����ѯǩԼ������Ӧ
	virtual void OnRspQryContractBank(CKSOTPContractBankField *pContractBank, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///֤ȯ�����ѯ�������Ӧ��
	virtual void OnRspQueryBankAccountMoneyByStock(CKSOTPReqQueryAccountField *pReqQueryAccount, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯת����ˮ��Ӧ
	virtual void OnRspQryTransferSerial(CKSOTPTransferSerialField *pTransferSerial, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ������Ϣȷ����Ӧ
	virtual void OnRspQrySettlementInfoConfirm(CKSOTPSettlementInfoConfirmField *pSettlementInfoConfirm, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߽�����ȷ����Ӧ
	virtual void OnRspSettlementInfoConfirm(CKSOTPSettlementInfoConfirmField *pSettlementInfoConfirm, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ���߽�������Ӧ
	virtual void OnRspQrySettlementInfo(CKSOTPSettlementInfoField *pSettlementInfo, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�ͻ����׼�����Ӧ
	virtual void OnRspQryInvestorTradeLevel(CKSOTPInvestorTradeLevelField *pInvestorTradeLevel, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�����޹������Ӧ
	virtual void OnRspQryPurchaseLimitAmt(CKSOTPPurchaseLimitAmtField *pPurchaseLimitAmt, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ�����޲ֶ����Ӧ
	virtual void OnRspQryPositionLimitVol(CKSOTPPositionLimitVolField *pPositionLimitVol, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��ʷ������Ӧ
	virtual void OnRspQryHistoryOrder(CKSOTPHistoryOrderField *pHistoryOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��ʷ�ɽ���Ӧ
	virtual void OnRspQryHistoryTrade(CKSOTPHistoryTradeField *pHistoryTrade, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��ʷ��Ȩָ����ϸ��Ӧ
	virtual void OnRspQryHistoryAssignment(CKSOTPHistoryAssignmentField *pHistoryAssignment, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Ȩ������ϸ��Ӧ
	virtual void OnRspQryDelivDetail(CKSOTPDelivDetailField *pDelivDetail, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�Զ���Ȩִ�в�����Ӧ
	virtual void OnRspAutoExecOrderAction(CKSOTPAutoExecOrderActionField *pAutoExecOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ӧ��
	virtual void OnRspError(CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����֪ͨ
	virtual void OnRtnOrder(CKSOTPOrderField *pOrder) {};

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CKSOTPTradeField *pTrade) {};

	///ִ������֪ͨ
	virtual void OnRtnExecOrder(CKSOTPExecOrderField *pExecOrder) {};

	///����֪ͨ
	virtual void OnRtnLock(CKSOTPLockField *pLock) {};

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

	///ִ������¼������
	virtual int ReqExecOrderInsert(CKSOTPInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///ִ�������������
	virtual int ReqExecOrderAction(CKSOTPInputExecOrderActionField *pInputExecOrderAction, int nRequestID) = 0;

	///��������
	virtual int ReqLockInsert(CKSOTPInputLockField *pInputLock, int nRequestID) = 0;

	///�����ѯִ������
	virtual int ReqQryExecOrder(CKSOTPQryExecOrderField *pQryExecOrder, int nRequestID) = 0;

	///��ѯ������������
	virtual int ReqQryExecOrderVolume(CKSOTPQryExecOrderVolumeField *pQryExecOrderVolume, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryLock(CKSOTPQryLockField *pQryLock, int nRequestID) = 0;

	///�����ѯ����֤ȯ��λ
	virtual int ReqQryLockPosition(CKSOTPQryLockPositionField *pQryLockPosition, int nRequestID) = 0;

	///��ѯ���ȯ��Ϣ����
	virtual int ReqQryUnderlyingStockInfo(CKSOTPQryUnderlyingStockInfoField *pQryOTPOrderParams, int nRequestID) = 0;

	///��ѯ������Ȩ������������
	virtual int ReqQryOTPInsCommRate(CKSOTPQryOTPInsCommRateField *pQryOTPInsCommRate, int nRequestID) = 0;

	///��ѯ������Ȩ��Լ��֤��������
	virtual int ReqQryInstrumentMarginRate(CKSOTPQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID) = 0;

	///��ѯ������Ȩָ����Ϣ
	virtual int ReqQryOTPAssignment(CKSOTPQryOTPAssignmentField *pQryOTPAssignment, int nRequestID) = 0;

	///�����ѯ���� 
	virtual int ReqQryDepthMarketData(CKSOTPQryDepthMarketDataField *pQryOTPDepthMarketData, int nRequestID) = 0;

	///�����ʽ�ת��������
	virtual int ReqFromBankToStockByStock(CKSOTPReqTransferField *pReqTransfer, int nRequestID) = 0;

	///֤ȯ�ʽ�ת��������
	virtual int ReqFromStockToBankByStock(CKSOTPReqTransferField *pReqTransfer, int nRequestID) = 0;

	///�����ѯǩԼ����
	virtual int ReqQryContractBank(CKSOTPQryContractBankField *pQryContractBank, int nRequestID) = 0;

	///��ѯ�����������
	virtual int ReqQueryBankAccountMoneyByStock(CKSOTPReqQueryAccountField *pReqQueryAccount, int nRequestID) = 0;

	///�����ѯת����ˮ
	virtual int ReqQryTransferSerial(CKSOTPQryTransferSerialField *pQryTransferSerial, int nRequestID) = 0;

	///�����ѯ������Ϣȷ��
	virtual int ReqQrySettlementInfoConfirm(CKSOTPQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID) = 0;

	///Ͷ���߽�����ȷ��
	virtual int ReqSettlementInfoConfirm(CKSOTPSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID) = 0;

	///�����ѯͶ���߽�����
	virtual int ReqQrySettlementInfo(CKSOTPQrySettlementInfoField *pQrySettlementInfo, int nRequestID) = 0;

	///��ѯ�ͻ����׼���
	virtual int ReqQryInvestorTradeLevel(CKSOTPQryInvestorTradeLevelField *pQryInvestorTradeLevel, int nRequestID) = 0;

	///��ѯ�����޹����
	virtual int ReqQryPurchaseLimitAmt(CKSOTPQryPurchaseLimitAmtField *pQryPurchaseLimitAmt, int nRequestID) = 0;

	///��ѯ�����޲ֶ��
	virtual int ReqQryPositionLimitVol(CKSOTPQryPositionLimitVolField *pQryPositionLimitVol, int nRequestID) = 0;

	///�����ѯ��ʷ����
	virtual int ReqQryHistoryOrder(CKSOTPQryHistoryOrderField *pQryHistoryOrder, int nRequestID) = 0;

	///�����ѯ��ʷ�ɽ�
	virtual int ReqQryHistoryTrade(CKSOTPQryHistoryTradeField *pQryHistoryTrade, int nRequestID) = 0;

	///�����ѯ��ʷ��Ȩָ����ϸ
	virtual int ReqQryHistoryAssignment(CKSOTPQryHistoryAssignmentField *pQryHistoryAssignment, int nRequestID) = 0;

	///�����ѯ��Ȩ������ϸ
	virtual int ReqQryDelivDetail(CKSOTPQryDelivDetailField *pQryDelivDetail, int nRequestID) = 0;

	///�Զ���Ȩִ�в���
	virtual int ReqAutoExecOrderAction(CKSOTPAutoExecOrderActionField *pAutoExecOrderAction, int nRequestID) = 0;

protected:
	~CKSOTPTraderApi(){};
};

}	// end of namespace KingstarAPI
#endif
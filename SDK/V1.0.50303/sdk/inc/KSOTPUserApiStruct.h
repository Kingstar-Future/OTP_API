#ifndef __KSOTPUSERAPISTRUCT_H_INCLUDED_
#define __KSOTPUSERAPISTRUCT_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KSOTPUserApiDataType.h"

namespace KingstarAPI
{
///��Ӧ��Ϣ
struct CKSOTPRspInfoField
{
	///�������
	TKSOTPErrorIDType	ErrorID;
	///������Ϣ
	TKSOTPErrorMsgType	ErrorMsg;
};

///�û���¼����
struct CKSOTPReqUserLoginField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����
	TKSOTPPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TKSOTPProductInfoType	UserProductInfo;
	///Mac��ַ
	TKSOTPMacAddressType	MacAddress;
	///�ն�IP��ַ
	TKSOTPIPAddressType	ClientIPAddress;
};

///�û���¼Ӧ��
struct CKSOTPRspUserLoginField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///������
	TKSOTPDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TKSOTPTimeType	LoginTime;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����ϵͳ����
	TKSOTPSystemNameType	SystemName;
	///ǰ�ñ��
	TKSOTPFrontIDType	FrontID;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///��󱨵�����
	TKSOTPOrderRefType	MaxOrderRef;
	///��֤��ʱ��
	TKSOTPTimeType	SSETime;
};

///�û��ǳ�����
struct CKSOTPUserLogoutField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///�û�����
	TKSOTPUserIDType	UserID;
};

///�û�������
struct CKSOTPUserPasswordUpdateField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///�û�����
	TKSOTPUserIDType	UserID;
	///ԭ���Ŀ���
	TKSOTPPasswordType	OldPassword;
	///�µĿ���
	TKSOTPPasswordType	NewPassword;
};

///�ʽ��˻���������
struct CKSOTPTradingAccountPasswordUpdateField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///ԭ���Ŀ���
	TKSOTPPasswordType	OldPassword;
	///�µĿ���
	TKSOTPPasswordType	NewPassword;
};

///���뱨��
struct CKSOTPInputOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��������
	TKSOTPOrderRefType	OrderRef;
	///�û�����
	TKSOTPUserIDType	UserID;
	///�����۸�����
	TKSOTPOrderPriceTypeType	OrderPriceType;
	///��������
	TKSOTPDirectionType	Direction;
	///��ƽ��־
	TKSOTPOffsetFlagType	OffsetFlag;
	///���ұ�־
	TKSOTPHedgeFlagType	HedgeFlag;
	///�۸�
	TKSOTPPriceType	LimitPrice;
	///����
	TKSOTPVolumeType	VolumeTotalOriginal;
	///��Ч������
	TKSOTPTimeConditionType	TimeCondition;
	///GTD����
	TKSOTPDateType	GTDDate;
	///�ɽ�������
	TKSOTPVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TKSOTPVolumeType	MinVolume;
	///��������
	TKSOTPContingentConditionType	ContingentCondition;
	///ֹ���
	TKSOTPPriceType	StopPrice;
	///ǿƽԭ��
	TKSOTPForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TKSOTPBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///������
	TKSOTPRequestIDType	RequestID;
	///�û�ǿ����־
	TKSOTPBoolType	UserForceClose;
	///��������־
	TKSOTPBoolType	IsSwapOrder;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///���뱨������
struct CKSOTPInputOrderActionField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��������
	TKSOTPOrderRefType	OrderRef;
	///������
	TKSOTPRequestIDType	RequestID;
	///ǰ�ñ��
	TKSOTPFrontIDType	FrontID;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///�������
	TKSOTPOrderSysIDType	OrderSysID;
	///������־
	TKSOTPActionFlagType	ActionFlag;
	///�۸�
	TKSOTPPriceType	LimitPrice;
	///�����仯
	TKSOTPVolumeType	VolumeChange;
	///�û�����
	TKSOTPUserIDType	UserID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
};

///��ѯ����
struct CKSOTPQryOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///�������
	TKSOTPOrderSysIDType	OrderSysID;
};

///��ѯ�ɽ�
struct CKSOTPQryTradeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��ʼʱ��
	TKSOTPTimeType	TradeTimeStart;
	///����ʱ��
	TKSOTPTimeType	TradeTimeEnd;
};

///��ѯͶ���ֲ߳�
struct CKSOTPQryInvestorPositionField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///Ͷ���ֲ߳�
struct CKSOTPInvestorPositionField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TKSOTPPosiDirectionType	PosiDirection;
	///���ұ�־
	TKSOTPHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TKSOTPPositionDateType	PositionDate;
	///���ճֲ�
	TKSOTPVolumeType	YdPosition;
	///���ճֲ�
	TKSOTPVolumeType	Position;
	///��ͷ����
	TKSOTPVolumeType	LongFrozen;
	///��ͷ����
	TKSOTPVolumeType	ShortFrozen;
	///���ֶ�����
	TKSOTPMoneyType	LongFrozenAmount;
	///���ֶ�����
	TKSOTPMoneyType	ShortFrozenAmount;
	///������
	TKSOTPVolumeType	OpenVolume;
	///���ֽ��
	TKSOTPMoneyType	OpenAmount;
	///ƽ�ֽ��
	TKSOTPMoneyType	CloseAmount;
	///�ֲֳɱ�
	TKSOTPMoneyType	PositionCost;
	///ռ�õı�֤��
	TKSOTPMoneyType	UseMargin;
	///����ı�֤��
	TKSOTPMoneyType	FrozenMargin;
	///������ʽ�
	TKSOTPMoneyType	FrozenCash;
	///�����������
	TKSOTPMoneyType	FrozenCommission;
	///�ʽ���
	TKSOTPMoneyType	CashIn;
	///������
	TKSOTPMoneyType	Commission;
	///ƽ��ӯ��
	TKSOTPMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TKSOTPMoneyType	PositionProfit;
	///�ϴν����
	TKSOTPPriceType	PreSettlementPrice;
	///���ν����
	TKSOTPPriceType	SettlementPrice;
	///������
	TKSOTPDateType	TradingDay;
	///������
	TKSOTPSettlementIDType	SettlementID;
	///���ֳɱ�
	TKSOTPMoneyType	OpenCost;
	///��������֤��
	TKSOTPMoneyType	ExchangeMargin;
	///���ն���ƽ��ӯ��
	TKSOTPMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TKSOTPMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TKSOTPVolumeType	TodayPosition;
	///��֤����
	TKSOTPRatioType	MarginRateByMoney;
	///��֤����(������)
	TKSOTPRatioType	MarginRateByVolume;
	///ִ�ж���
	TKSOTPVolumeType	StrikeFrozen;
	///ִ�ж�����
	TKSOTPMoneyType	StrikeFrozenAmount;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///��ѯ�ʽ��˻�
struct CKSOTPQryTradingAccountField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
};

///�ʽ��˻�
struct CKSOTPTradingAccountField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///�ϴν���׼����
	TKSOTPMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TKSOTPMoneyType	PreMargin;
	///�����
	TKSOTPMoneyType	Deposit;
	///������
	TKSOTPMoneyType	Withdraw;
	///����ı�֤��
	TKSOTPMoneyType	FrozenMargin;
	///������ʽ�
	TKSOTPMoneyType	FrozenCash;
	///�����������
	TKSOTPMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TKSOTPMoneyType	CurrMargin;
	///�ʽ���
	TKSOTPMoneyType	CashIn;
	///������
	TKSOTPMoneyType	Commission;
	///ƽ��ӯ��
	TKSOTPMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TKSOTPMoneyType	PositionProfit;
	///֤ȯ����׼����
	TKSOTPMoneyType	Balance;
	///�����ʽ�
	TKSOTPMoneyType	Available;
	///��ȡ�ʽ�
	TKSOTPMoneyType	WithdrawQuota;
	///����׼����
	TKSOTPMoneyType	Reserve;
	///������
	TKSOTPDateType	TradingDay;
	///������
	TKSOTPSettlementIDType	SettlementID;
	///���ö��
	TKSOTPMoneyType	Credit;
	///��Ѻ���
	TKSOTPMoneyType	Mortgage;
	///��������֤��
	TKSOTPMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TKSOTPMoneyType	DeliveryMargin;
	///���������֤��
	TKSOTPMoneyType	ExchangeDeliveryMargin;
};

///��ѯͶ����
struct CKSOTPQryInvestorField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
};

///Ͷ����
struct CKSOTPInvestorField
{
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ��������
	TKSOTPPartyNameType	InvestorName;
	///֤������
	TKSOTPIdCardTypeType	IdentifiedCardType;
	///֤������
	TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TKSOTPBoolType	IsActive;
	///��ϵ�绰
	TKSOTPTelephoneType	Telephone;
	///ͨѶ��ַ
	TKSOTPAddressType	Address;
	///��������
	TKSOTPDateType	OpenDate;
	///�ֻ�
	TKSOTPMobileType	Mobile;
};

///��ѯ��Լ�˺�
struct CKSOTPQryTradingCodeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///���ױ���
struct CKSOTPTradingCodeField
{
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Լ�˺�
	TKSOTPClientIDType	ClientID;
	///�Ƿ��Ծ
	TKSOTPBoolType	IsActive;
	///���ױ�������
	TKSOTPClientIDTypeType	ClientIDType;
};

///��ѯ������
struct CKSOTPQryExchangeField
{
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///������
struct CKSOTPExchangeField
{
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///����������
	TKSOTPExchangeNameType	ExchangeName;
};

///��ѯ��Լ
struct CKSOTPQryInstrumentField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///��Լ
struct CKSOTPInstrumentField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Լ����
	TKSOTPInstrumentNameType	InstrumentName;
	///��Լ�ڽ������Ĵ���
	TKSOTPExchangeInstIDType	ExchangeInstID;
	///Ʒ�ִ���
	TKSOTPInstrumentIDType	ProductID;
	///��Ʒ����
	TKSOTPProductClassType	ProductClass;
	///�������
	TKSOTPYearType	DeliveryYear;
	///������
	TKSOTPMonthType	DeliveryMonth;
	///�м۵�����µ���
	TKSOTPVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TKSOTPVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TKSOTPVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TKSOTPVolumeType	MinLimitOrderVolume;
	///��Լ��������
	TKSOTPVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TKSOTPPriceType	PriceTick;
	///������
	TKSOTPDateType	CreateDate;
	///������
	TKSOTPDateType	OpenDate;
	///������
	TKSOTPDateType	ExpireDate;
	///��ʼ������
	TKSOTPDateType	StartDelivDate;
	///����������
	TKSOTPDateType	EndDelivDate;
	///��Լ��������״̬
	TKSOTPInstLifePhaseType	InstLifePhase;
	///��ǰ�Ƿ���
	TKSOTPBoolType	IsTrading;
	///�ֲ�����
	TKSOTPPositionTypeType	PositionType;
	///�ֲ���������
	TKSOTPPositionDateTypeType	PositionDateType;
	///��ͷ��֤����
	TKSOTPRatioType	LongMarginRatio;
	///��ͷ��֤����
	TKSOTPRatioType	ShortMarginRatio;
	///������Ʒ����
	TKSOTPInstrumentIDType	UnderlyingInstrID;
	///ִ�м�
	TKSOTPPriceType	StrikePrice;
	///��Ȩ����
	TKSOTPOptionsTypeType	OptionsType;
	///��Լϵ��
	TKSOTPInstrumentIDType	InstrumentIdSerial;
	///��Լ������Ʒ����
	TKSOTPUnderlyingMultipleType	UnderlyingMultiple;
};

///��ѯͶ���ֲ߳���ϸ
struct CKSOTPQryInvestorPositionDetailField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///Ͷ���ֲ߳���ϸ
struct CKSOTPInvestorPositionDetailField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///���ұ�־
	TKSOTPHedgeFlagType	HedgeFlag;
	///����
	TKSOTPDirectionType	Direction;
	///��������
	TKSOTPDateType	OpenDate;
	///�ɽ����
	TKSOTPTradeIDType	TradeID;
	///����
	TKSOTPVolumeType	Volume;
	///���ּ�
	TKSOTPPriceType	OpenPrice;
	///������
	TKSOTPDateType	TradingDay;
	///������
	TKSOTPSettlementIDType	SettlementID;
	///�ɽ�����
	TKSOTPTradeTypeType	TradeType;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///���ն���ƽ��ӯ��
	TKSOTPMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TKSOTPMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TKSOTPMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TKSOTPMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TKSOTPMoneyType	Margin;
	///��������֤��
	TKSOTPMoneyType	ExchMargin;
	///��֤����
	TKSOTPRatioType	MarginRateByMoney;
	///��֤����(������)
	TKSOTPRatioType	MarginRateByVolume;
	///������
	TKSOTPPriceType	LastSettlementPrice;
	///�����
	TKSOTPPriceType	SettlementPrice;
};

///��ѯ�����¼�֪ͨ
struct CKSOTPQryTradingNoticeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
};

///�û��¼�֪ͨ
struct CKSOTPTradingNoticeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����ϵ�к�
	TKSOTPSequenceSeriesType	SequenceSeries;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����ʱ��
	TKSOTPTimeType	SendTime;
	///���к�
	TKSOTPSequenceNoType	SequenceNo;
	///��Ϣ����
	TKSOTPContentType	FieldContent;
};

///�û��¼�֪ͨ��Ϣ
struct CKSOTPTradingNoticeInfoField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����ʱ��
	TKSOTPTimeType	SendTime;
	///��Ϣ����
	TKSOTPContentType	FieldContent;
	///����ϵ�к�
	TKSOTPSequenceSeriesType	SequenceSeries;
	///���к�
	TKSOTPSequenceNoType	SequenceNo;
};

///�����ִ������
struct CKSOTPInputExecOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///ִ����������
	TKSOTPOrderRefType	ExecOrderRef;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����
	TKSOTPVolumeType	Volume;
	///������
	TKSOTPRequestIDType	RequestID;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TKSOTPOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TKSOTPHedgeFlagType	HedgeFlag;
	///ִ������
	TKSOTPActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TKSOTPPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TKSOTPExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TKSOTPExecOrderCloseFlagType	CloseFlag;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///����ִ���������
struct CKSOTPInputExecOrderActionField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///ִ�������������
	TKSOTPOrderActionRefType	ExecOrderActionRef;
	///ִ����������
	TKSOTPOrderRefType	ExecOrderRef;
	///������
	TKSOTPRequestIDType	RequestID;
	///ǰ�ñ��
	TKSOTPFrontIDType	FrontID;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///ִ������������
	TKSOTPExecOrderSysIDType	ExecOrderSysID;
	///������־
	TKSOTPActionFlagType	ActionFlag;
	///�û�����
	TKSOTPUserIDType	UserID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
};

///¼������
struct CKSOTPInputLockField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��������
	TKSOTPOrderRefType	LockRef;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����
	TKSOTPVolumeType	Volume;
	///������
	TKSOTPRequestIDType	RequestID;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///��������
	TKSOTPLockTypeType	LockType;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///����
struct CKSOTPLockField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��������
	TKSOTPOrderRefType	LockRef;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����
	TKSOTPVolumeType	Volume;
	///������
	TKSOTPRequestIDType	RequestID;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///��������
	TKSOTPLockTypeType	LockType;
	///�����������
	TKSOTPOrderLocalIDType	LockLocalID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Ա����
	TKSOTPParticipantIDType	ParticipantID;
	///�ͻ�����
	TKSOTPClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TKSOTPExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TKSOTPTraderIDType	TraderID;
	///��װ���
	TKSOTPInstallIDType	InstallID;
	///ִ�������ύ״̬
	TKSOTPOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TKSOTPSequenceNoType	NotifySequence;
	///������
	TKSOTPDateType	TradingDay;
	///������
	TKSOTPSettlementIDType	SettlementID;
	///�������
	TKSOTPOrderSysIDType	LockSysID;
	///��������
	TKSOTPDateType	InsertDate;
	///����ʱ��
	TKSOTPTimeType	InsertTime;
	///����ʱ��
	TKSOTPTimeType	CancelTime;
	///����״̬
	TKSOTPOrderActionStatusType	LockStatus;
	///�����Ա���
	TKSOTPParticipantIDType	ClearingPartID;
	///���
	TKSOTPSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TKSOTPFrontIDType	FrontID;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TKSOTPProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TKSOTPErrorMsgType	StatusMsg;
	///�����û�����
	TKSOTPUserIDType	ActiveUserID;
	///���͹�˾�������
	TKSOTPSequenceNoType	BrokerLockSeq;
	///Ӫҵ�����
	TKSOTPBranchIDType	BranchID;
};

///��ѯ����
struct CKSOTPQryLockField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///�������
	TKSOTPOrderSysIDType	LockSysID;
};

///ִ�������ѯ
struct CKSOTPQryExecOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///ִ��������
	TKSOTPExecOrderSysIDType	ExecOrderSysID;
};

///�����ѯ��������
struct CKSOTPQryExecOrderVolumeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///Ͷ���ױ���־
	TKSOTPHedgeFlagType	HedgeFlag;
	///������־
	TKSOTPDirectionType	Direction;
};

///�����ѯ��������
struct CKSOTPExecOrderVolumeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///Ͷ���ױ���־
	TKSOTPHedgeFlagType	HedgeFlag;
	///������ִ����
	TKSOTPVolumeType	ExecVolume;
	///�����������
	TKSOTPVolumeType	ActionVolume;
	///������ִ����
	TKSOTPVolumeType	ExecedVolume;
	///����������� 
	TKSOTPVolumeType	ActionedVolume;
	///������־
	TKSOTPDirectionType	Direction;
};

///��ѯ����֤ȯ��λ
struct CKSOTPQryLockPositionField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///����֤ȯ��λ
struct CKSOTPLockPositionField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///����
	TKSOTPVolumeType	Volume;
	///����������
	TKSOTPVolumeType	FrozenVolume;
};

///�����ѯ���ȯ��Ϣ����
struct CKSOTPQryUnderlyingStockInfoField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TKSOTPInstrumentIDType	ProductID;
};

///�����ѯ���ȯ��Ϣ����
struct CKSOTPUnderlyingStockInfoField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TKSOTPInstrumentIDType	ProductID;
	///������
	TKSOTPPriceType	PreClosePrice;
	///��ȫϵ��
	TKSOTPRatioType	GuarantRatio;
};

///�����ѯ������Ȩ������������
struct CKSOTPQryOTPInsCommRateField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///�����ѯ������Ȩ��Լ��������
struct CKSOTPOTPInsCommRateField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TKSOTPInvestorRangeType	InvestorRange;
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///������������
	TKSOTPRatioType	OpenRatioByMoney;
	///����������
	TKSOTPRatioType	OpenRatioByVolume;
	///ƽ����������
	TKSOTPRatioType	CloseRatioByMoney;
	///ƽ��������
	TKSOTPRatioType	CloseRatioByVolume;
	///ƽ����������
	TKSOTPRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TKSOTPRatioType	CloseTodayRatioByVolume;
	///ִ����������
	TKSOTPRatioType	StrikeRatioByMoney;
	///ִ��������
	TKSOTPRatioType	StrikeRatioByVolume;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///�����ѯ������Ȩ��Լ��֤��������
struct CKSOTPQryInstrumentMarginRateField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TKSOTPHedgeFlagType	HedgeFlag;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///�����ѯ������Ȩ��Լ��֤����
struct CKSOTPInstrumentMarginRateField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TKSOTPInvestorRangeType	InvestorRange;
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TKSOTPHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TKSOTPRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TKSOTPMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TKSOTPRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TKSOTPMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TKSOTPBoolType	IsRelative;
};

///���������Ȩָ����Ϣ
struct CKSOTPQryOTPAssignmentField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����
	TKSOTPDirectionType	Direction;
};

///���������Ȩָ����Ϣ
struct CKSOTPOTPAssignmentField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����
	TKSOTPDirectionType	Direction;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Լ����
	TKSOTPInstrumentNameType	InstrumentName;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///Ͷ���ױ���־
	TKSOTPHedgeFlagType	HedgeFlag;
	///���ճֲ�
	TKSOTPVolumeType	YdPosition;
	///��Ȩָ�ɺ�Լ����
	TKSOTPVolumeType AssInsVo;
	///��Ȩ���֤ȯ����
	TKSOTPVolumeType AssProVol;
	///��Ȩָ��Ӧ�����
	TKSOTPMoneyType  FeePay;
	///��ȨC/P��־
	TKSOTPOptionsTypeType OptionsType;
	///��Ȩ������
	TKSOTPDateType DeliveryDay;
	///���ɺ�Լ��ʶ��
	TKSOTPInstrumentIDType StockID;
};

///��ѯ����
struct CKSOTPQryDepthMarketDataField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///�������
struct CKSOTPDepthMarketDataField
{
	///������
	TKSOTPDateType	TradingDay;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TKSOTPExchangeInstIDType	ExchangeInstID;
	///���¼�
	TKSOTPPriceType	LastPrice;
	///�ϴν����
	TKSOTPPriceType	PreSettlementPrice;
	///������
	TKSOTPPriceType	PreClosePrice;
	///��ֲ���
	TKSOTPLargeVolumeType	PreOpenInterest;
	///����
	TKSOTPPriceType	OpenPrice;
	///��߼�
	TKSOTPPriceType	HighestPrice;
	///��ͼ�
	TKSOTPPriceType	LowestPrice;
	///����
	TKSOTPVolumeType	Volume;
	///�ɽ����
	TKSOTPMoneyType	Turnover;
	///�ֲ���
	TKSOTPLargeVolumeType	OpenInterest;
	///������
	TKSOTPPriceType	ClosePrice;
	///���ν����
	TKSOTPPriceType	SettlementPrice;
	///��ͣ���
	TKSOTPPriceType	UpperLimitPrice;
	///��ͣ���
	TKSOTPPriceType	LowerLimitPrice;
	///����ʵ��
	TKSOTPRatioType	PreDelta;
	///����ʵ��
	TKSOTPRatioType	CurrDelta;
	///����޸�ʱ��
	TKSOTPTimeType	UpdateTime;
	///����޸ĺ���
	TKSOTPMillisecType	UpdateMillisec;
	///�����һ
	TKSOTPPriceType	BidPrice1;
	///������һ
	TKSOTPVolumeType	BidVolume1;
	///������һ
	TKSOTPPriceType	AskPrice1;
	///������һ
	TKSOTPVolumeType	AskVolume1;
	///����۶�
	TKSOTPPriceType	BidPrice2;
	///��������
	TKSOTPVolumeType	BidVolume2;
	///�����۶�
	TKSOTPPriceType	AskPrice2;
	///��������
	TKSOTPVolumeType	AskVolume2;
	///�������
	TKSOTPPriceType	BidPrice3;
	///��������
	TKSOTPVolumeType	BidVolume3;
	///��������
	TKSOTPPriceType	AskPrice3;
	///��������
	TKSOTPVolumeType	AskVolume3;
	///�������
	TKSOTPPriceType	BidPrice4;
	///��������
	TKSOTPVolumeType	BidVolume4;
	///��������
	TKSOTPPriceType	AskPrice4;
	///��������
	TKSOTPVolumeType	AskVolume4;
	///�������
	TKSOTPPriceType	BidPrice5;
	///��������
	TKSOTPVolumeType	BidVolume5;
	///��������
	TKSOTPPriceType	AskPrice5;
	///��������
	TKSOTPVolumeType	AskVolume5;
	///���վ���
	TKSOTPPriceType	AveragePrice;
	///ҵ������
	TKSOTPDateType	ActionDay;
};

///���������̵�ѯ������
struct CKSOTPForQuoteRspField
{
	///������
	TKSOTPDateType	TradingDay;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///ѯ�۱��
	TKSOTPOrderSysIDType	ForQuoteSysID;
	///ѯ��ʱ��
	TKSOTPTimeType	ForQuoteTime;
	///ҵ������
	TKSOTPDateType	ActionDay;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
};

///����
struct CKSOTPOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��������
	TKSOTPOrderRefType	OrderRef;
	///�û�����
	TKSOTPUserIDType	UserID;
	///�����۸�����
	TKSOTPOrderPriceTypeType	OrderPriceType;
	///��������
	TKSOTPDirectionType	Direction;
	///��ƽ��־
	TKSOTPOffsetFlagType	OffsetFlag;
	///�۸�
	TKSOTPPriceType	LimitPrice;
	///���ұ�־
	TKSOTPHedgeFlagType	HedgeFlag;
	///����
	TKSOTPVolumeType	VolumeTotalOriginal;
	///��Ч������
	TKSOTPTimeConditionType	TimeCondition;
	///GTD����
	TKSOTPDateType	GTDDate;
	///�ɽ�������
	TKSOTPVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TKSOTPVolumeType	MinVolume;
	///��������
	TKSOTPContingentConditionType	ContingentCondition;
	///ֹ���
	TKSOTPPriceType	StopPrice;
	///ǿƽԭ��
	TKSOTPForceCloseReasonType	ForceCloseReason;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///������
	TKSOTPRequestIDType	RequestID;
	///���ر������
	TKSOTPOrderLocalIDType	OrderLocalID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Ա����
	TKSOTPParticipantIDType	ParticipantID;
	///��Լ�˺�
	TKSOTPClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TKSOTPExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TKSOTPTraderIDType	TraderID;
	///�����ύ״̬
	TKSOTPOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TKSOTPSequenceNoType	NotifySequence;
	///������
	TKSOTPDateType	TradingDay;
	///������
	TKSOTPSettlementIDType	SettlementID;
	///�������
	TKSOTPOrderSysIDType	OrderSysID;
	///������Դ
	TKSOTPOrderSourceType	OrderSource;
	///����״̬
	TKSOTPOrderStatusType	OrderStatus;
	///��������
	TKSOTPOrderTypeType	OrderType;
	///��ɽ�����
	TKSOTPVolumeType	VolumeTraded;
	///ʣ������
	TKSOTPVolumeType	VolumeTotal;
	///��������
	TKSOTPDateType	InsertDate;
	///ί��ʱ��
	TKSOTPTimeType	InsertTime;
	///����ʱ��
	TKSOTPTimeType	ActiveTime;
	///����޸�ʱ��
	TKSOTPTimeType	UpdateTime;
	///����ʱ��
	TKSOTPTimeType	CancelTime;
	///���
	TKSOTPSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TKSOTPFrontIDType	FrontID;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TKSOTPProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TKSOTPErrorMsgType	StatusMsg;
	///�û�ǿ����־
	TKSOTPBoolType	UserForceClose;
	///�����û�����
	TKSOTPUserIDType	ActiveUserID;
	///���͹�˾�������
	TKSOTPSequenceNoType	BrokerOrderSeq;
};

///�ɽ�
struct CKSOTPTradeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��������
	TKSOTPOrderRefType	OrderRef;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///�ɽ����
	TKSOTPTradeIDType	TradeID;
	///��������
	TKSOTPDirectionType	Direction;
	///�������
	TKSOTPOrderSysIDType	OrderSysID;
	///��Ա����
	TKSOTPParticipantIDType	ParticipantID;
	///��Լ�˺�
	TKSOTPClientIDType	ClientID;
	///���׽�ɫ
	TKSOTPTradingRoleType	TradingRole;
	///��Լ�ڽ������Ĵ���
	TKSOTPExchangeInstIDType	ExchangeInstID;
	///��ƽ��־
	TKSOTPOffsetFlagType	OffsetFlag;
	///���ұ�־
	TKSOTPHedgeFlagType	HedgeFlag;
	///�۸�
	TKSOTPPriceType	Price;
	///����
	TKSOTPVolumeType	Volume;
	///�ɽ�ʱ��
	TKSOTPDateType	TradeDate;
	///�ɽ�ʱ��
	TKSOTPTimeType	TradeTime;
	///�ɽ�����
	TKSOTPTradeTypeType	TradeType;
	///�ɽ�����Դ
	TKSOTPPriceSourceType	PriceSource;
	///����������Ա����
	TKSOTPTraderIDType	TraderID;
	///���ر������
	TKSOTPOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TKSOTPParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///���
	TKSOTPSequenceNoType	SequenceNo;
	///������
	TKSOTPDateType	TradingDay;
	///���͹�˾�������
	TKSOTPSequenceNoType	BrokerOrderSeq;
	///�ɽ���Դ
	TKSOTPTradeSourceType	TradeSource;
};

///ִ������
struct CKSOTPExecOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///ִ����������
	TKSOTPOrderRefType	ExecOrderRef;
	///�û�����
	TKSOTPUserIDType	UserID;
	///����
	TKSOTPVolumeType	Volume;
	///������
	TKSOTPRequestIDType	RequestID;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TKSOTPOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TKSOTPHedgeFlagType	HedgeFlag;
	///ִ������
	TKSOTPActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TKSOTPPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TKSOTPExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TKSOTPExecOrderCloseFlagType	CloseFlag;
	///����ִ��������
	TKSOTPOrderLocalIDType	ExecOrderLocalID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Ա����
	TKSOTPParticipantIDType	ParticipantID;
	///�ͻ�����
	TKSOTPClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TKSOTPExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TKSOTPTraderIDType	TraderID;
	///��װ���
	TKSOTPInstallIDType	InstallID;
	///ִ�������ύ״̬
	TKSOTPOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TKSOTPSequenceNoType	NotifySequence;
	///������
	TKSOTPDateType	TradingDay;
	///������
	TKSOTPSettlementIDType	SettlementID;
	///ִ��������
	TKSOTPExecOrderSysIDType	ExecOrderSysID;
	///��������
	TKSOTPDateType	InsertDate;
	///����ʱ��
	TKSOTPTimeType	InsertTime;
	///����ʱ��
	TKSOTPTimeType	CancelTime;
	///ִ�н��
	TKSOTPExecResultType	ExecResult;
	///�����Ա���
	TKSOTPParticipantIDType	ClearingPartID;
	///���
	TKSOTPSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TKSOTPFrontIDType	FrontID;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TKSOTPProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TKSOTPErrorMsgType	StatusMsg;
	///�����û�����
	TKSOTPUserIDType	ActiveUserID;
	///���͹�˾�������
	TKSOTPSequenceNoType	BrokerExecOrderSeq;
	///Ӫҵ�����
	TKSOTPBranchIDType	BranchID;
};

///��Լ״̬
struct CKSOTPInstrumentStatusField
{
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TKSOTPExchangeInstIDType	ExchangeInstID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TKSOTPInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	TKSOTPTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	TKSOTPTimeType	EnterTime;
	///���뱾״̬ԭ��
	TKSOTPInstStatusEnterReasonType	EnterReason;
};

///ת������
struct CKSOTPReqTransferField
{
	///ҵ������
	TKSOTPTradeCodeType	TradeCode;
	///���д���
	TKSOTPBankIDType	BankID;
	///���з�֧��������
	TKSOTPBankBrchIDType	BankBranchID;
	///���̴���
	TKSOTPBrokerIDType	BrokerID;
	///���̷�֧��������
	TKSOTPFutureBranchIDType	BrokerBranchID;
	///��������
	TKSOTPTradeDateType	TradeDate;
	///����ʱ��
	TKSOTPTradeTimeType	TradeTime;
	///������ˮ��
	TKSOTPBankSerialType	BankSerial;
	///����ϵͳ���� 
	TKSOTPTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TKSOTPSerialType	PlateSerial;
	///����Ƭ��־
	TKSOTPLastFragmentType	LastFragment;
	///�Ự��
	TKSOTPSessionIDType	SessionID;
	///�ͻ�����
	TKSOTPIndividualNameType	CustomerName;
	///֤������
	TKSOTPIdCardTypeType	IdCardType;
	///֤������
	TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TKSOTPCustTypeType	CustType;
	///�����ʺ�
	TKSOTPBankAccountType	BankAccount;
	///��������
	TKSOTPPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///֤ȯ����
	TKSOTPPasswordType	Password;
	///��װ���
	TKSOTPInstallIDType	InstallID;
	///֤ȯ��˾��ˮ��
	TKSOTPFutureSerialType	FutureSerial;
	///�û���ʶ
	TKSOTPUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TKSOTPYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TKSOTPTradeAmountType	TradeAmount;
	///֤ȯ��ȡ���
	TKSOTPTradeAmountType	FutureFetchAmount;
	///����֧����־
	TKSOTPFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TKSOTPCustFeeType	CustFee;
	///Ӧ��֤ȯ��˾����
	TKSOTPFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TKSOTPAddInfoType	Message;
	///ժҪ
	TKSOTPDigestType	Digest;
	///�����ʺ�����
	TKSOTPBankAccTypeType	BankAccType;
	///������־
	TKSOTPDeviceIDType	DeviceID;
	///֤ȯ��λ�ʺ�����
	TKSOTPBankAccTypeType	BankSecuAccType;
	///֤ȯ��˾���б���
	TKSOTPBankCodingForFutureType	BrokerIDByBank;
	///֤ȯ��λ�ʺ�
	TKSOTPBankAccountType	BankSecuAcc;
	///���������־
	TKSOTPPwdFlagType	BankPwdFlag;
	///֤ȯ�ʽ�����˶Ա�־
	TKSOTPPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TKSOTPOperNoType	OperNo;
	///������
	TKSOTPRequestIDType	RequestID;
	///����ID
	TKSOTPTIDType	TID;
	///ת�˽���״̬
	TKSOTPTransferStatusType	TransferStatus;
};

///�����ʽ�ת֤ȯ��Ӧ
struct CKSOTPRspTransferField
{
	///ҵ������
	TKSOTPTradeCodeType	TradeCode;
	///���д���
	TKSOTPBankIDType	BankID;
	///���з�֧��������
	TKSOTPBankBrchIDType	BankBranchID;
	///���̴���
	TKSOTPBrokerIDType	BrokerID;
	///���̷�֧��������
	TKSOTPFutureBranchIDType	BrokerBranchID;
	///��������
	TKSOTPTradeDateType	TradeDate;
	///����ʱ��
	TKSOTPTradeTimeType	TradeTime;
	///������ˮ��
	TKSOTPBankSerialType	BankSerial;
	///����ϵͳ���� 
	TKSOTPTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TKSOTPSerialType	PlateSerial;
	///����Ƭ��־
	TKSOTPLastFragmentType	LastFragment;
	///�Ự��
	TKSOTPSessionIDType	SessionID;
	///�ͻ�����
	TKSOTPIndividualNameType	CustomerName;
	///֤������
	TKSOTPIdCardTypeType	IdCardType;
	///֤������
	TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TKSOTPCustTypeType	CustType;
	///�����ʺ�
	TKSOTPBankAccountType	BankAccount;
	///��������
	TKSOTPPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///֤ȯ����
	TKSOTPPasswordType	Password;
	///��װ���
	TKSOTPInstallIDType	InstallID;
	///֤ȯ��˾��ˮ��
	TKSOTPFutureSerialType	FutureSerial;
	///�û���ʶ
	TKSOTPUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TKSOTPYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TKSOTPTradeAmountType	TradeAmount;
	///֤ȯ��ȡ���
	TKSOTPTradeAmountType	FutureFetchAmount;
	///����֧����־
	TKSOTPFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TKSOTPCustFeeType	CustFee;
	///Ӧ��֤ȯ��˾����
	TKSOTPFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TKSOTPAddInfoType	Message;
	///ժҪ
	TKSOTPDigestType	Digest;
	///�����ʺ�����
	TKSOTPBankAccTypeType	BankAccType;
	///������־
	TKSOTPDeviceIDType	DeviceID;
	///֤ȯ��λ�ʺ�����
	TKSOTPBankAccTypeType	BankSecuAccType;
	///֤ȯ��˾���б���
	TKSOTPBankCodingForFutureType	BrokerIDByBank;
	///֤ȯ��λ�ʺ�
	TKSOTPBankAccountType	BankSecuAcc;
	///���������־
	TKSOTPPwdFlagType	BankPwdFlag;
	///֤ȯ�ʽ�����˶Ա�־
	TKSOTPPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TKSOTPOperNoType	OperNo;
	///������
	TKSOTPRequestIDType	RequestID;
	///����ID
	TKSOTPTIDType	TID;
	///ת�˽���״̬
	TKSOTPTransferStatusType	TransferStatus;
	///�������
	TKSOTPErrorIDType	ErrorID;
	///������Ϣ
	TKSOTPErrorMsgType	ErrorMsg;
};

///��ѯǩԼ��������
struct CKSOTPQryContractBankField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///���д���
	TKSOTPBankIDType	BankID;
	///���з����Ĵ���
	TKSOTPBankBrchIDType	BankBrchID;
};

///��ѯǩԼ������Ӧ
struct CKSOTPContractBankField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///���д���
	TKSOTPBankIDType	BankID;
	///���з����Ĵ���
	TKSOTPBankBrchIDType	BankBrchID;
	///��������
	TKSOTPBankNameType	BankName;
};

///��ѯ�˻���Ϣ����
struct CKSOTPReqQueryAccountField
{
	///ҵ������
	TKSOTPTradeCodeType	TradeCode;
	///���д���
	TKSOTPBankIDType	BankID;
	///���з�֧��������
	TKSOTPBankBrchIDType	BankBranchID;
	///���̴���
	TKSOTPBrokerIDType	BrokerID;
	///���̷�֧��������
	TKSOTPFutureBranchIDType	BrokerBranchID;
	///��������
	TKSOTPTradeDateType	TradeDate;
	///����ʱ��
	TKSOTPTradeTimeType	TradeTime;
	///������ˮ��
	TKSOTPBankSerialType	BankSerial;
	///����ϵͳ���� 
	TKSOTPTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TKSOTPSerialType	PlateSerial;
	///����Ƭ��־
	TKSOTPLastFragmentType	LastFragment;
	///�Ự��
	TKSOTPSessionIDType	SessionID;
	///�ͻ�����
	TKSOTPIndividualNameType	CustomerName;
	///֤������
	TKSOTPIdCardTypeType	IdCardType;
	///֤������
	TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TKSOTPCustTypeType	CustType;
	///�����ʺ�
	TKSOTPBankAccountType	BankAccount;
	///��������
	TKSOTPPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///֤ȯ����
	TKSOTPPasswordType	Password;
	///֤ȯ��˾��ˮ��
	TKSOTPFutureSerialType	FutureSerial;
	///��װ���
	TKSOTPInstallIDType	InstallID;
	///�û���ʶ
	TKSOTPUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TKSOTPYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///ժҪ
	TKSOTPDigestType	Digest;
	///�����ʺ�����
	TKSOTPBankAccTypeType	BankAccType;
	///������־
	TKSOTPDeviceIDType	DeviceID;
	///֤ȯ��λ�ʺ�����
	TKSOTPBankAccTypeType	BankSecuAccType;
	///֤ȯ��˾���б���
	TKSOTPBankCodingForFutureType	BrokerIDByBank;
	///֤ȯ��λ�ʺ�
	TKSOTPBankAccountType	BankSecuAcc;
	///���������־
	TKSOTPPwdFlagType	BankPwdFlag;
	///֤ȯ�ʽ�����˶Ա�־
	TKSOTPPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TKSOTPOperNoType	OperNo;
	///������
	TKSOTPRequestIDType	RequestID;
	///����ID
	TKSOTPTIDType	TID;
};

///��ѯ�˻���Ϣ��Ӧ
struct CKSOTPRspQueryAccountField
{
	///ҵ������
	TKSOTPTradeCodeType	TradeCode;
	///���д���
	TKSOTPBankIDType	BankID;
	///���з�֧��������
	TKSOTPBankBrchIDType	BankBranchID;
	///���̴���
	TKSOTPBrokerIDType	BrokerID;
	///���̷�֧��������
	TKSOTPFutureBranchIDType	BrokerBranchID;
	///��������
	TKSOTPTradeDateType	TradeDate;
	///����ʱ��
	TKSOTPTradeTimeType	TradeTime;
	///������ˮ��
	TKSOTPBankSerialType	BankSerial;
	///����ϵͳ���� 
	TKSOTPTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TKSOTPSerialType	PlateSerial;
	///����Ƭ��־
	TKSOTPLastFragmentType	LastFragment;
	///�Ự��
	TKSOTPSessionIDType	SessionID;
	///�ͻ�����
	TKSOTPIndividualNameType	CustomerName;
	///֤������
	TKSOTPIdCardTypeType	IdCardType;
	///֤������
	TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TKSOTPCustTypeType	CustType;
	///�����ʺ�
	TKSOTPBankAccountType	BankAccount;
	///��������
	TKSOTPPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///֤ȯ����
	TKSOTPPasswordType	Password;
	///֤ȯ��˾��ˮ��
	TKSOTPFutureSerialType	FutureSerial;
	///��װ���
	TKSOTPInstallIDType	InstallID;
	///�û���ʶ
	TKSOTPUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TKSOTPYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///ժҪ
	TKSOTPDigestType	Digest;
	///�����ʺ�����
	TKSOTPBankAccTypeType	BankAccType;
	///������־
	TKSOTPDeviceIDType	DeviceID;
	///֤ȯ��λ�ʺ�����
	TKSOTPBankAccTypeType	BankSecuAccType;
	///֤ȯ��˾���б���
	TKSOTPBankCodingForFutureType	BrokerIDByBank;
	///֤ȯ��λ�ʺ�
	TKSOTPBankAccountType	BankSecuAcc;
	///���������־
	TKSOTPPwdFlagType	BankPwdFlag;
	///֤ȯ�ʽ�����˶Ա�־
	TKSOTPPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TKSOTPOperNoType	OperNo;
	///������
	TKSOTPRequestIDType	RequestID;
	///����ID
	TKSOTPTIDType	TID;
	///���п��ý��
	TKSOTPTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TKSOTPTradeAmountType	BankFetchAmount;
};

///�����ѯת����ˮ
struct CKSOTPQryTransferSerialField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///���б���
	TKSOTPBankIDType	BankID;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
};

///��ѯ�˻���Ϣ֪ͨ
struct CKSOTPNotifyQueryAccountField
{
	///ҵ������
	TKSOTPTradeCodeType	TradeCode;
	///���д���
	TKSOTPBankIDType	BankID;
	///���з�֧��������
	TKSOTPBankBrchIDType	BankBranchID;
	///���̴���
	TKSOTPBrokerIDType	BrokerID;
	///���̷�֧��������
	TKSOTPFutureBranchIDType	BrokerBranchID;
	///��������
	TKSOTPTradeDateType	TradeDate;
	///����ʱ��
	TKSOTPTradeTimeType	TradeTime;
	///������ˮ��
	TKSOTPBankSerialType	BankSerial;
	///����ϵͳ���� 
	TKSOTPTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TKSOTPSerialType	PlateSerial;
	///����Ƭ��־
	TKSOTPLastFragmentType	LastFragment;
	///�Ự��
	TKSOTPSessionIDType	SessionID;
	///�ͻ�����
	TKSOTPIndividualNameType	CustomerName;
	///֤������
	TKSOTPIdCardTypeType	IdCardType;
	///֤������
	TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TKSOTPCustTypeType	CustType;
	///�����ʺ�
	TKSOTPBankAccountType	BankAccount;
	///��������
	TKSOTPPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///֤ȯ����
	TKSOTPPasswordType	Password;
	///֤ȯ��˾��ˮ��
	TKSOTPFutureSerialType	FutureSerial;
	///��װ���
	TKSOTPInstallIDType	InstallID;
	///�û���ʶ
	TKSOTPUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TKSOTPYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///ժҪ
	TKSOTPDigestType	Digest;
	///�����ʺ�����
	TKSOTPBankAccTypeType	BankAccType;
	///������־
	TKSOTPDeviceIDType	DeviceID;
	///֤ȯ��λ�ʺ�����
	TKSOTPBankAccTypeType	BankSecuAccType;
	///֤ȯ��˾���б���
	TKSOTPBankCodingForFutureType	BrokerIDByBank;
	///֤ȯ��λ�ʺ�
	TKSOTPBankAccountType	BankSecuAcc;
	///���������־
	TKSOTPPwdFlagType	BankPwdFlag;
	///֤ȯ�ʽ�����˶Ա�־
	TKSOTPPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TKSOTPOperNoType	OperNo;
	///������
	TKSOTPRequestIDType	RequestID;
	///����ID
	TKSOTPTIDType	TID;
	///���п��ý��
	TKSOTPTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TKSOTPTradeAmountType	BankFetchAmount;
	///�������
	TKSOTPErrorIDType	ErrorID;
	///������Ϣ
	TKSOTPErrorMsgType	ErrorMsg;
};

///����ת�˽�����ˮ��
struct CKSOTPTransferSerialField
{
	///ƽ̨��ˮ��
	TKSOTPPlateSerialType	PlateSerial;
	///���׷�������
	TKSOTPTradeDateType	TradeDate;
	///��������
	TKSOTPDateType	TradingDay;
	///����ʱ��
	TKSOTPTradeTimeType	TradeTime;
	///���״���
	TKSOTPTradeCodeType	TradeCode;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///���б���
	TKSOTPBankIDType	BankID;
	///���з�֧��������
	TKSOTPBankBrchIDType	BankBranchID;
	///�����ʺ�����
	TKSOTPBankAccTypeType	BankAccType;
	///�����ʺ�
	TKSOTPBankAccountType	BankAccount;
	///������ˮ��
	TKSOTPBankSerialType	BankSerial;
	///֤ȯ��˾����
	TKSOTPBrokerIDType	BrokerID;
	///���̷�֧��������
	TKSOTPFutureBranchIDType	BrokerBranchID;
	///֤ȯ��˾�ʺ�����
	TKSOTPFutureAccTypeType	FutureAccType;
	///Ͷ�����ʺ�
	TKSOTPAccountIDType	AccountID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///֤ȯ��˾��ˮ��
	TKSOTPFutureSerialType	FutureSerial;
	///֤������
	TKSOTPIdCardTypeType	IdCardType;
	///֤������
	TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///���׽��
	TKSOTPTradeAmountType	TradeAmount;
	///Ӧ�տͻ�����
	TKSOTPCustFeeType	CustFee;
	///Ӧ��֤ȯ��˾����
	TKSOTPFutureFeeType	BrokerFee;
	///��Ч��־
	TKSOTPAvailabilityFlagType	AvailabilityFlag;
	///����Ա
	TKSOTPOperatorCodeType	OperatorCode;
	///�������ʺ�
	TKSOTPBankAccountType	BankNewAccount;
	///�������
	TKSOTPErrorIDType	ErrorID;
	///������Ϣ
	TKSOTPErrorMsgType	ErrorMsg;
};

///ָ���ĺ�Լ
struct CKSOTPSpecificInstrumentField
{
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
};

///��ѯ�ͻ����׼���
struct CKSOTPQryInvestorTradeLevelField
{
	///���͹�˾����
	TKSOTPBrokerIDType BrokerID;
	///����������
	TKSOTPExchangeIDType ExchangeID;
	///��Ʒ����
	TKSOTPInstrumentIDType ProductID;
};

///�ͻ����׼���
struct CKSOTPInvestorTradeLevelField
{
	///���͹�˾����
	TKSOTPBrokerIDType BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType ExchangeID;
	///��Ʒ����
	TKSOTPInstrumentIDType ProductID;
	///���׼���
	TKSOTPTradeLevelType TradeLevel;
};

///��ѯ�����޹����
struct CKSOTPQryPurchaseLimitAmtField
{
	///���͹�˾����
	TKSOTPBrokerIDType BrokerID;
	///����������
	TKSOTPExchangeIDType ExchangeID;
};

///�����޹����
struct CKSOTPPurchaseLimitAmtField
{
	///���͹�˾����
	TKSOTPBrokerIDType BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType ExchangeID;
	///�޹����
	TKSOTPMoneyType	PurLimitAmt;
};

///��ѯ�����޲ֶ��
struct CKSOTPQryPositionLimitVolField
{
	///���͹�˾����
	TKSOTPBrokerIDType BrokerID;
	///����������
	TKSOTPExchangeIDType ExchangeID;
	///��Ʒ����
	TKSOTPInstrumentIDType ProductID;
	///�����Ա�־
	TKSOTPProtectFlagType ProtectFlag;
	///��ȨC/P��־
	TKSOTPOptionsTypeType OptionsType;
	///���Ʒ�Χ
	TKSOTPControlRangeType ControlRange;
};

///��ѯ�����޲ֶ��
struct CKSOTPPositionLimitVolField
{
	///���͹�˾����
	TKSOTPBrokerIDType BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType ExchangeID;
	///��Ʒ����
	TKSOTPInstrumentIDType ProductID;
	///�����Ա�־
	TKSOTPProtectFlagType ProtectFlag;
	///��ȨC/P��־
	TKSOTPOptionsTypeType OptionsType;
	///���Ʒ�Χ
	TKSOTPControlRangeType ControlRange;
	///�޲ֶ��
	TKSOTPVolumeType	PosiLimitVol;
};

///��ѯͶ���߽�����
struct CKSOTPQrySettlementInfoField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///������
	TKSOTPDateType	TradingDay;
};

///��ѯ������Ϣȷ����
struct CKSOTPQrySettlementInfoConfirmField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
};

///Ͷ���߽�����ȷ����Ϣ
struct CKSOTPSettlementInfoConfirmField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///ȷ������
	TKSOTPDateType	ConfirmDate;
	///ȷ��ʱ��
	TKSOTPTimeType	ConfirmTime;
};

///Ͷ���߽�����
struct CKSOTPSettlementInfoField
{
	///������
	TKSOTPDateType	TradingDay;
	///������
	TKSOTPSettlementIDType	SettlementID;
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///���
	TKSOTPSequenceNoType	SequenceNo;
	///��Ϣ����
	TKSOTPContentType	Content;
};

///��ѯ��ʷ����
struct CKSOTPQryHistoryOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///���ر������
	TKSOTPOrderLocalIDType	OrderLocalID;
	///Ʒ�ִ���
	TKSOTPInstrumentIDType	ProductID;
	///��ʼ����
	TKSOTPDateType	OrderDataStart;
	///��������
	TKSOTPDateType	OrderDataEnd;
};

///��ѯ��ʷ�ɽ�
struct CKSOTPQryHistoryTradeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///Ʒ�ִ���
	TKSOTPInstrumentIDType	ProductID;
	///��ʼ����
	TKSOTPDateType	TradeDataStart;
	///��������
	TKSOTPDateType	TradeDataEnd;
};

///��ѯ��ʷ��Ȩָ����ϸ
struct CKSOTPQryHistoryAssignmentField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///Ͷ�����
	TKSOTPHedgeFlagType	HedgeFlag;
	///��Ȩ����
	TKSOTPOptionsTypeType	OptionsType;
	///������
	TKSOTPDateType	DeliveryMonth;
	///�ֲַ���
	TKSOTPPosiDirectionType PosiDirection;
};

///��ѯ��Ȩ������ϸ
struct CKSOTPQryDelivDetailField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///������
	TKSOTPDateType	DeliveryMonth;
	///���ɽ��ղ�ѯ����
	TKSOTPDelivModeType	DelivMode;
};

///�Զ���Ȩִ�в���
struct CKSOTPAutoExecOrderActionField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///�Զ���Ȩ��ֵ(0-���Զ���Ȩ,��0-��������ֵ���Զ���Ȩ(20����20%))
	TKSOTPVolumeType RangeVol;
};

///��ʷ��Ȩָ����ϸ
struct CKSOTPHistoryAssignmentField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///��������
	TKSOTPTradeDateType	TradingDay;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///�ͻ�����
	TKSOTPClientIDType	ClientID;
	///���֤ȯ����
	TKSOTPInstrumentIDType	StockInstr;
	///Ͷ�����
	TKSOTPHedgeFlagType	HedgeFlag;
	///��Ȩ����
	TKSOTPOptionsTypeType	OptionsType;
	///�ֲַ���
	TKSOTPPosiDirectionType PosiDirection;
	///ִ�м�
	TKSOTPPriceType	StrikePrice;
	///��Ȩָ������
	TKSOTPVolumeType ExecVol;
	///���֤ȯӦ�ո�����
	TKSOTPVolumeType IOVol;
	///Ӧ�ո����
	TKSOTPMoneyType	IOAmt;
	///��Ȩ������
	TKSOTPDateType	DelivDate;
};

///��Ȩ������ϸ
struct CKSOTPDelivDetailField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///���֤ȯ����
	TKSOTPInstrumentIDType	StockInstr;
	///Ӧ��/Ӧ��/��ȯ֤ȯ����
	TKSOTPVolumeType IOVol;
	///ʵ�ո�����
	TKSOTPVolumeType IOVolInFact;
	///�����
	TKSOTPPriceType	SettlementPrice;
	///��ȯ��ֵ/������
	TKSOTPMoneyType	SettlementAmt;
	///��Ȩ������
	TKSOTPDateType	DelivDate;
	///ҵ����������
	TKSOTPFunctionNameType	FunctionName;
};

///��ʷ����
struct CKSOTPHistoryOrderField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///�ͻ�����
	TKSOTPIndividualNameType	CustomerName;
	///��Լ����
	TKSOTPInstrumentIDType	InstrumentID;
	///���ر������
	TKSOTPOrderLocalIDType	OrderLocalID;
	///�걨ʱ��
	TKSOTPTimeType	InsertTime;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///�ɽ��۸�
	TKSOTPPriceType	TradePrice;
	///�ɽ����
	TKSOTPMoneyType	TradeAmount;
	///�ɽ�����
	TKSOTPVolumeType	VolumeTraded;
	///����ⶳ���
	TKSOTPMoneyType	FrozenAmount;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///���
	TKSOTPSequenceNoType	SequenceNo;
	///��������
	TKSOTPDirectionType	Direction;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///�û��˲�Ʒ��Ϣ
	TKSOTPProductInfoType	UserProductInfo;
	///������
	TKSOTPRequestIDType	RequestID;
	///��������
	TKSOTPOrderRefType	OrderRef;
	///ǰ�ñ��
	TKSOTPFrontIDType	FrontID;
	///�Ự���
	TKSOTPSessionIDType	SessionID;
	///ί�м۸�
	TKSOTPPriceType	OrderPrice;
	///ί����Դ
	TKSOTPOrderSourceType	OrderSource;
	///ί������
	TKSOTPDateType	InsertDate;
	///ί��ʱ��
	TKSOTPTimeType	OrderTime;
	///ί������
	TKSOTPVolumeType	VolumeTotalOriginal;
	///ί��״̬
	TKSOTPOrderStatusType	OrderStatus;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///��Ʒ����
	TKSOTPProductNameType	ProductName;
	///��Ʒ����
	TKSOTPProductClassType	ProductClass;
	///Ͷ��������ƽ��־
	TKSOTPOffsetFlagType	OffsetFlag;
	///ҵ����������
	TKSOTPFunctionNameType	FunctionName;
};

///��ʷ�ɽ�
struct CKSOTPHistoryTradeField
{
	///���͹�˾����
	TKSOTPBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TKSOTPInvestorIDType	InvestorID;
	///�ͻ�����
	TKSOTPIndividualNameType	CustomerName;
	///���ر������
	TKSOTPOrderLocalIDType	OrderLocalID;
	///���ִ���
	TKSOTPCurrencyIDType	CurrencyID;
	///����������
	TKSOTPExchangeIDType	ExchangeID;
	///��Ʒ����
	TKSOTPInstrumentIDType	ProductID;
	///��Ʒ����
	TKSOTPProductNameType	ProductName;
	///�ɽ�����
	TKSOTPVolumeType	VolumeTraded;
	///�ɽ����
	TKSOTPMoneyType	TradeAmount;
	///�ɽ�����
	TKSOTPDateType	TradeDate;
	///�ɽ�ʱ��
	TKSOTPTimeType	TradeTime;
	///Ͷ��������ƽ��־
	TKSOTPOffsetFlagType	OffsetFlag;
	///ҵ��Ԫ
	TKSOTPBusinessUnitType	BusinessUnit;
	///������
	TKSOTPMoneyType	Commission;
	///��ע
	TKSOTPMemoType	Memo;
	///����ʱ��
	TKSOTPTimeType	TraderOfferTime;
	///�ɽ��۸�
	TKSOTPPriceType	TradePrice;	
	///��Ȩ���ױ���
	TKSOTPClientIDType	ClientID;
	///��Ȩ����
	TKSOTPOptionsTypeType	OptionsType;
	///���ұ�־
	TKSOTPHedgeFlagType	HedgeFlag;
	///Ȩ��������
	TKSOTPVolumeType RoyaltyVolume;
	///���������
	TKSOTPVolumeType ObligationVolume;
	///Ȩ���ֽ��
	TKSOTPMoneyType	RoyaltyAmount;
	///����ֽ��
	TKSOTPMoneyType	ObligationAmount;
	///�ɽ����
	TKSOTPTradeIDType	TradeID;
	///ҵ����������
	TKSOTPFunctionNameType	FunctionName;
};
}	// end of namespace KingstarAPI

#endif

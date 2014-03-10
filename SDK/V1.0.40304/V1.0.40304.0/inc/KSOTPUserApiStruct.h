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
		///ҵ��Ԫ
		TKSOTPBusinessUnitType	BusinessUnit;
		///������
		TKSOTPRequestIDType	RequestID;
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

	///��Լ�˺�
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
		///��Լ�˺�����
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

	///����ķǽ��ױ���
	struct CKSOTPInputNonTradingOrderField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
		///Ʒ�ִ���
		TKSOTPInstrumentIDType	ProductID;
		///�ǽ��ױ�������
		TKSOTPOrderRefType	OTPOrderRef;
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
		///���ұ�־
		TKSOTPHedgeFlagType	HedgeFlag;
		///�������ͱ�־
		TKSOTPApplyFlagType	ApplyFlag;
	};

	///����ǽ��ױ�������
	struct CKSOTPInputNonTradingOrderActionField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///�ǽ��ױ�������
		TKSOTPOrderRefType	OTPOrderRef;
		///������
		TKSOTPRequestIDType	RequestID;
		///ǰ�ñ��
		TKSOTPFrontIDType	FrontID;
		///�Ự���
		TKSOTPSessionIDType	SessionID;
		///����������
		TKSOTPExchangeIDType	ExchangeID;
		///�ǽ��ױ����������
		TKSOTPOTPOrderSysIDType	OTPOrderSysID;
		///������־
		TKSOTPActionFlagType	ActionFlag;
		///�û�����
		TKSOTPUserIDType	UserID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///����ǽ��ױ�����ѯ
	struct CKSOTPQryNonTradingOrderField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
		///Ʒ�ִ���
		TKSOTPInstrumentIDType	ProductID;
		///����������
		TKSOTPExchangeIDType	ExchangeID;
		///�ǽ��ױ������
		TKSOTPOTPOrderSysIDType	OTPOrderSysID;
	};

	///�����ѯ�ǽ��ױ���������
	struct CKSOTPQryNonTradingOrderVolumeField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
		///���ұ�־
		TKSOTPHedgeFlagType	HedgeFlag;
		///Ʒ�ִ���
		TKSOTPInstrumentIDType	ProductID;
		///�������ͱ�־
		TKSOTPApplyFlagType	ApplyFlag;
	};

	///�����ѯ�ǽ��ױ�����
	struct CKSOTPNonTradingOrderVolumeField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
		///���ұ�־
		TKSOTPHedgeFlagType	HedgeFlag;
		///��������
		TKSOTPVolumeType	OTPVolume;
		///��������
		TKSOTPVolumeType	OTPedVolume;
		///�������ͱ�־
		TKSOTPApplyFlagType	ApplyFlag;
	};

	///�����ѯ���ȯ��Ϣ����
	struct CKSOTPQryUnderlyingStockInfoField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
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
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///����������
		TKSOTPExchangeIDType	ExchangeID;
		///Ʒ�ִ���
		TKSOTPInstrumentIDType	ProductID;
		///������
		TKSOTPPriceType	PreClosePrice;
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
	};

	///�����ѯ������Ȩ��Լ��������
	struct CKSOTPOTPInsCommRateField
	{
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
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
		///ִ����������
		TKSOTPRatioType	StrikeRatioByMoney;
		///ִ��������
		TKSOTPRatioType	StrikeRatioByVolume;
	};

	///�����ѯ������Ȩ��֤��������
	struct CKSOTPQryOTPInsMarginRateField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///�����ѯ������Ȩ��֤����
	struct CKSOTPOTPInsMarginRateField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
		///��֤����
		TKSOTPRatioType	MarginRateByMoney;
		///��ǰ��֤����
		TKSOTPMoneyType	CurrMargin;
	};

	///���������Ȩָ����Ϣ
	struct CKSOTPQryOTPAssignmentField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
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

	///�ǽ��ױ���
	struct CKSOTPNonTradingOrderField
	{
		///���͹�˾����
		TKSOTPBrokerIDType	BrokerID;
		///Ͷ���ߴ���
		TKSOTPInvestorIDType	InvestorID;
		///��Լ����
		TKSOTPInstrumentIDType	InstrumentID;
		///Ʒ�ִ���
		TKSOTPInstrumentIDType	ProductID;
		///�ǽ��ױ�������
		TKSOTPOrderRefType	OTPOrderRef;
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
		///���ұ�־
		TKSOTPHedgeFlagType	HedgeFlag;
		///���طǽ��ױ������
		TKSOTPOrderLocalIDType	OTPOrderLocalID;
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
		///�ǽ��ױ����ύ״̬
		TKSOTPOrderSubmitStatusType	OrderSubmitStatus;
		///������ʾ���
		TKSOTPSequenceNoType	NotifySequence;
		///������
		TKSOTPDateType	TradingDay;
		///������
		TKSOTPSettlementIDType	SettlementID;
		///�ǽ��ױ������
		TKSOTPOTPOrderSysIDType	OTPOrderSysID;
		///��������
		TKSOTPDateType	InsertDate;
		///����ʱ��
		TKSOTPTimeType	InsertTime;
		///����ʱ��
		TKSOTPTimeType	CancelTime;
		///�ǽ���ί�е�״̬
		TKSOTPOTPOrderStatusType	OTPOrderStatus;
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
		TKSOTPSequenceNoType	BrokerOTPOrderSeq;
		///�������ͱ�־
		TKSOTPApplyFlagType	ApplyFlag;
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

}	// end of namespace KingstarAPI

#endif

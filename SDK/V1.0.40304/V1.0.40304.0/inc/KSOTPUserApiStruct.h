#ifndef __KSOTPUSERAPISTRUCT_H_INCLUDED_
#define __KSOTPUSERAPISTRUCT_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KSOTPUserApiDataType.h"

namespace KingstarAPI
{
	///响应信息
	struct CKSOTPRspInfoField
	{
		///错误代码
		TKSOTPErrorIDType	ErrorID;
		///错误信息
		TKSOTPErrorMsgType	ErrorMsg;
	};

	///用户登录请求
	struct CKSOTPReqUserLoginField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///用户代码
		TKSOTPUserIDType	UserID;
		///密码
		TKSOTPPasswordType	Password;
		///用户端产品信息
		TKSOTPProductInfoType	UserProductInfo;
		///Mac地址
		TKSOTPMacAddressType	MacAddress;
		///终端IP地址
		TKSOTPIPAddressType	ClientIPAddress;
	};

	///用户登录应答
	struct CKSOTPRspUserLoginField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///交易日
		TKSOTPDateType	TradingDay;
		///登录成功时间
		TKSOTPTimeType	LoginTime;
		///用户代码
		TKSOTPUserIDType	UserID;
		///交易系统名称
		TKSOTPSystemNameType	SystemName;
		///前置编号
		TKSOTPFrontIDType	FrontID;
		///会话编号
		TKSOTPSessionIDType	SessionID;
		///最大报单引用
		TKSOTPOrderRefType	MaxOrderRef;
		///上证所时间
		TKSOTPTimeType	SSETime;
	};

	///用户登出请求
	struct CKSOTPUserLogoutField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///用户代码
		TKSOTPUserIDType	UserID;
	};

	///用户口令变更
	struct CKSOTPUserPasswordUpdateField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///用户代码
		TKSOTPUserIDType	UserID;
		///原来的口令
		TKSOTPPasswordType	OldPassword;
		///新的口令
		TKSOTPPasswordType	NewPassword;
	};

	///资金账户口令变更域
	struct CKSOTPTradingAccountPasswordUpdateField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者帐号
		TKSOTPAccountIDType	AccountID;
		///原来的口令
		TKSOTPPasswordType	OldPassword;
		///新的口令
		TKSOTPPasswordType	NewPassword;
	};

	///输入报单
	struct CKSOTPInputOrderField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///报单引用
		TKSOTPOrderRefType	OrderRef;
		///用户代码
		TKSOTPUserIDType	UserID;
		///报单价格条件
		TKSOTPOrderPriceTypeType	OrderPriceType;
		///买卖方向
		TKSOTPDirectionType	Direction;
		///开平标志
		TKSOTPOffsetFlagType	OffsetFlag;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///价格
		TKSOTPPriceType	LimitPrice;
		///数量
		TKSOTPVolumeType	VolumeTotalOriginal;
		///有效期类型
		TKSOTPTimeConditionType	TimeCondition;
		///GTD日期
		TKSOTPDateType	GTDDate;
		///成交量类型
		TKSOTPVolumeConditionType	VolumeCondition;
		///最小成交量
		TKSOTPVolumeType	MinVolume;
		///触发条件
		TKSOTPContingentConditionType	ContingentCondition;
		///止损价
		TKSOTPPriceType	StopPrice;
		///业务单元
		TKSOTPBusinessUnitType	BusinessUnit;
		///请求编号
		TKSOTPRequestIDType	RequestID;
	};

	///输入报单操作
	struct CKSOTPInputOrderActionField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///报单引用
		TKSOTPOrderRefType	OrderRef;
		///请求编号
		TKSOTPRequestIDType	RequestID;
		///前置编号
		TKSOTPFrontIDType	FrontID;
		///会话编号
		TKSOTPSessionIDType	SessionID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///报单编号
		TKSOTPOrderSysIDType	OrderSysID;
		///操作标志
		TKSOTPActionFlagType	ActionFlag;
		///价格
		TKSOTPPriceType	LimitPrice;
		///数量变化
		TKSOTPVolumeType	VolumeChange;
		///用户代码
		TKSOTPUserIDType	UserID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///查询报单
	struct CKSOTPQryOrderField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///报单编号
		TKSOTPOrderSysIDType	OrderSysID;
	};

	///查询成交
	struct CKSOTPQryTradeField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///开始时间
		TKSOTPTimeType	TradeTimeStart;
		///结束时间
		TKSOTPTimeType	TradeTimeEnd;
	};

	///查询投资者持仓
	struct CKSOTPQryInvestorPositionField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///投资者持仓
	struct CKSOTPInvestorPositionField
	{
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///持仓多空方向
		TKSOTPPosiDirectionType	PosiDirection;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///持仓日期
		TKSOTPPositionDateType	PositionDate;
		///上日持仓
		TKSOTPVolumeType	YdPosition;
		///今日持仓
		TKSOTPVolumeType	Position;
		///多头冻结
		TKSOTPVolumeType	LongFrozen;
		///空头冻结
		TKSOTPVolumeType	ShortFrozen;
		///开仓冻结金额
		TKSOTPMoneyType	LongFrozenAmount;
		///开仓冻结金额
		TKSOTPMoneyType	ShortFrozenAmount;
		///开仓量
		TKSOTPVolumeType	OpenVolume;
		///开仓金额
		TKSOTPMoneyType	OpenAmount;
		///平仓金额
		TKSOTPMoneyType	CloseAmount;
		///持仓成本
		TKSOTPMoneyType	PositionCost;
		///占用的保证金
		TKSOTPMoneyType	UseMargin;
		///冻结的保证金
		TKSOTPMoneyType	FrozenMargin;
		///冻结的资金
		TKSOTPMoneyType	FrozenCash;
		///冻结的手续费
		TKSOTPMoneyType	FrozenCommission;
		///资金差额
		TKSOTPMoneyType	CashIn;
		///手续费
		TKSOTPMoneyType	Commission;
		///平仓盈亏
		TKSOTPMoneyType	CloseProfit;
		///持仓盈亏
		TKSOTPMoneyType	PositionProfit;
		///上次结算价
		TKSOTPPriceType	PreSettlementPrice;
		///本次结算价
		TKSOTPPriceType	SettlementPrice;
		///交易日
		TKSOTPDateType	TradingDay;
		///结算编号
		TKSOTPSettlementIDType	SettlementID;
		///开仓成本
		TKSOTPMoneyType	OpenCost;
		///交易所保证金
		TKSOTPMoneyType	ExchangeMargin;
		///逐日盯市平仓盈亏
		TKSOTPMoneyType	CloseProfitByDate;
		///逐笔对冲平仓盈亏
		TKSOTPMoneyType	CloseProfitByTrade;
		///今日持仓
		TKSOTPVolumeType	TodayPosition;
		///保证金率
		TKSOTPRatioType	MarginRateByMoney;
		///保证金率(按手数)
		TKSOTPRatioType	MarginRateByVolume;
		///执行冻结
		TKSOTPVolumeType	StrikeFrozen;
		///执行冻结金额
		TKSOTPMoneyType	StrikeFrozenAmount;
	};

	///查询资金账户
	struct CKSOTPQryTradingAccountField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
	};

	///资金账户
	struct CKSOTPTradingAccountField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者帐号
		TKSOTPAccountIDType	AccountID;
		///上次结算准备金
		TKSOTPMoneyType	PreBalance;
		///上次占用的保证金
		TKSOTPMoneyType	PreMargin;
		///入金金额
		TKSOTPMoneyType	Deposit;
		///出金金额
		TKSOTPMoneyType	Withdraw;
		///冻结的保证金
		TKSOTPMoneyType	FrozenMargin;
		///冻结的资金
		TKSOTPMoneyType	FrozenCash;
		///冻结的手续费
		TKSOTPMoneyType	FrozenCommission;
		///当前保证金总额
		TKSOTPMoneyType	CurrMargin;
		///资金差额
		TKSOTPMoneyType	CashIn;
		///手续费
		TKSOTPMoneyType	Commission;
		///平仓盈亏
		TKSOTPMoneyType	CloseProfit;
		///持仓盈亏
		TKSOTPMoneyType	PositionProfit;
		///证券结算准备金
		TKSOTPMoneyType	Balance;
		///可用资金
		TKSOTPMoneyType	Available;
		///可取资金
		TKSOTPMoneyType	WithdrawQuota;
		///基本准备金
		TKSOTPMoneyType	Reserve;
		///交易日
		TKSOTPDateType	TradingDay;
		///结算编号
		TKSOTPSettlementIDType	SettlementID;
		///信用额度
		TKSOTPMoneyType	Credit;
		///质押金额
		TKSOTPMoneyType	Mortgage;
		///交易所保证金
		TKSOTPMoneyType	ExchangeMargin;
		///投资者交割保证金
		TKSOTPMoneyType	DeliveryMargin;
		///交易所交割保证金
		TKSOTPMoneyType	ExchangeDeliveryMargin;
	};

	///查询投资者
	struct CKSOTPQryInvestorField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
	};

	///投资者
	struct CKSOTPInvestorField
	{
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者名称
		TKSOTPPartyNameType	InvestorName;
		///证件类型
		TKSOTPIdCardTypeType	IdentifiedCardType;
		///证件号码
		TKSOTPIdentifiedCardNoType	IdentifiedCardNo;
		///是否活跃
		TKSOTPBoolType	IsActive;
		///联系电话
		TKSOTPTelephoneType	Telephone;
		///通讯地址
		TKSOTPAddressType	Address;
		///开户日期
		TKSOTPDateType	OpenDate;
		///手机
		TKSOTPMobileType	Mobile;
	};

	///查询合约账号
	struct CKSOTPQryTradingCodeField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
	};

	///合约账号
	struct CKSOTPTradingCodeField
	{
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///合约账号
		TKSOTPClientIDType	ClientID;
		///是否活跃
		TKSOTPBoolType	IsActive;
		///合约账号类型
		TKSOTPClientIDTypeType	ClientIDType;
	};

	///查询交易所
	struct CKSOTPQryExchangeField
	{
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
	};

	///交易所
	struct CKSOTPExchangeField
	{
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///交易所名称
		TKSOTPExchangeNameType	ExchangeName;
	};

	///查询合约
	struct CKSOTPQryInstrumentField
	{
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
	};

	///合约
	struct CKSOTPInstrumentField
	{
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///合约名称
		TKSOTPInstrumentNameType	InstrumentName;
		///合约在交易所的代码
		TKSOTPExchangeInstIDType	ExchangeInstID;
		///品种代码
		TKSOTPInstrumentIDType	ProductID;
		///产品类型
		TKSOTPProductClassType	ProductClass;
		///交割年份
		TKSOTPYearType	DeliveryYear;
		///交割月
		TKSOTPMonthType	DeliveryMonth;
		///市价单最大下单量
		TKSOTPVolumeType	MaxMarketOrderVolume;
		///市价单最小下单量
		TKSOTPVolumeType	MinMarketOrderVolume;
		///限价单最大下单量
		TKSOTPVolumeType	MaxLimitOrderVolume;
		///限价单最小下单量
		TKSOTPVolumeType	MinLimitOrderVolume;
		///合约数量乘数
		TKSOTPVolumeMultipleType	VolumeMultiple;
		///最小变动价位
		TKSOTPPriceType	PriceTick;
		///创建日
		TKSOTPDateType	CreateDate;
		///上市日
		TKSOTPDateType	OpenDate;
		///到期日
		TKSOTPDateType	ExpireDate;
		///开始交割日
		TKSOTPDateType	StartDelivDate;
		///结束交割日
		TKSOTPDateType	EndDelivDate;
		///合约生命周期状态
		TKSOTPInstLifePhaseType	InstLifePhase;
		///当前是否交易
		TKSOTPBoolType	IsTrading;
		///持仓类型
		TKSOTPPositionTypeType	PositionType;
		///持仓日期类型
		TKSOTPPositionDateTypeType	PositionDateType;
		///多头保证金率
		TKSOTPRatioType	LongMarginRatio;
		///空头保证金率
		TKSOTPRatioType	ShortMarginRatio;
		///基础商品代码
		TKSOTPInstrumentIDType	UnderlyingInstrID;
		///执行价
		TKSOTPPriceType	StrikePrice;
		///期权类型
		TKSOTPOptionsTypeType	OptionsType;
		///合约系列
		TKSOTPInstrumentIDType	InstrumentIdSerial;
	};

	///查询投资者持仓明细
	struct CKSOTPQryInvestorPositionDetailField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///投资者持仓明细
	struct CKSOTPInvestorPositionDetailField
	{
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///买卖
		TKSOTPDirectionType	Direction;
		///开仓日期
		TKSOTPDateType	OpenDate;
		///成交编号
		TKSOTPTradeIDType	TradeID;
		///数量
		TKSOTPVolumeType	Volume;
		///开仓价
		TKSOTPPriceType	OpenPrice;
		///交易日
		TKSOTPDateType	TradingDay;
		///结算编号
		TKSOTPSettlementIDType	SettlementID;
		///成交类型
		TKSOTPTradeTypeType	TradeType;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///逐日盯市平仓盈亏
		TKSOTPMoneyType	CloseProfitByDate;
		///逐笔对冲平仓盈亏
		TKSOTPMoneyType	CloseProfitByTrade;
		///逐日盯市持仓盈亏
		TKSOTPMoneyType	PositionProfitByDate;
		///逐笔对冲持仓盈亏
		TKSOTPMoneyType	PositionProfitByTrade;
		///投资者保证金
		TKSOTPMoneyType	Margin;
		///交易所保证金
		TKSOTPMoneyType	ExchMargin;
		///保证金率
		TKSOTPRatioType	MarginRateByMoney;
		///保证金率(按手数)
		TKSOTPRatioType	MarginRateByVolume;
		///昨结算价
		TKSOTPPriceType	LastSettlementPrice;
		///结算价
		TKSOTPPriceType	SettlementPrice;
	};

	///查询交易事件通知
	struct CKSOTPQryTradingNoticeField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
	};

	///用户事件通知
	struct CKSOTPTradingNoticeField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///序列系列号
		TKSOTPSequenceSeriesType	SequenceSeries;
		///用户代码
		TKSOTPUserIDType	UserID;
		///发送时间
		TKSOTPTimeType	SendTime;
		///序列号
		TKSOTPSequenceNoType	SequenceNo;
		///消息正文
		TKSOTPContentType	FieldContent;
	};

	///用户事件通知信息
	struct CKSOTPTradingNoticeInfoField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///发送时间
		TKSOTPTimeType	SendTime;
		///消息正文
		TKSOTPContentType	FieldContent;
		///序列系列号
		TKSOTPSequenceSeriesType	SequenceSeries;
		///序列号
		TKSOTPSequenceNoType	SequenceNo;
	};

	///输入的非交易报单
	struct CKSOTPInputNonTradingOrderField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///品种代码
		TKSOTPInstrumentIDType	ProductID;
		///非交易报单引用
		TKSOTPOrderRefType	OTPOrderRef;
		///用户代码
		TKSOTPUserIDType	UserID;
		///数量
		TKSOTPVolumeType	Volume;
		///请求编号
		TKSOTPRequestIDType	RequestID;
		///业务单元
		TKSOTPBusinessUnitType	BusinessUnit;
		///开平标志
		TKSOTPOffsetFlagType	OffsetFlag;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///申请类型标志
		TKSOTPApplyFlagType	ApplyFlag;
	};

	///输入非交易报单操作
	struct CKSOTPInputNonTradingOrderActionField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///非交易报单引用
		TKSOTPOrderRefType	OTPOrderRef;
		///请求编号
		TKSOTPRequestIDType	RequestID;
		///前置编号
		TKSOTPFrontIDType	FrontID;
		///会话编号
		TKSOTPSessionIDType	SessionID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///非交易报单操作编号
		TKSOTPOTPOrderSysIDType	OTPOrderSysID;
		///操作标志
		TKSOTPActionFlagType	ActionFlag;
		///用户代码
		TKSOTPUserIDType	UserID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///输入非交易报单查询
	struct CKSOTPQryNonTradingOrderField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///品种代码
		TKSOTPInstrumentIDType	ProductID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///非交易报单编号
		TKSOTPOTPOrderSysIDType	OTPOrderSysID;
	};

	///输入查询非交易报单量请求
	struct CKSOTPQryNonTradingOrderVolumeField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///品种代码
		TKSOTPInstrumentIDType	ProductID;
		///申请类型标志
		TKSOTPApplyFlagType	ApplyFlag;
	};

	///输出查询非交易报单量
	struct CKSOTPNonTradingOrderVolumeField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///可申请量
		TKSOTPVolumeType	OTPVolume;
		///已申请量
		TKSOTPVolumeType	OTPedVolume;
		///申请类型标志
		TKSOTPApplyFlagType	ApplyFlag;
	};

	///输入查询标的券信息请求
	struct CKSOTPQryUnderlyingStockInfoField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///品种代码
		TKSOTPInstrumentIDType	ProductID;
	};

	///输出查询标的券信息请求
	struct CKSOTPUnderlyingStockInfoField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///品种代码
		TKSOTPInstrumentIDType	ProductID;
		///昨收盘
		TKSOTPPriceType	PreClosePrice;
	};

	///输入查询个股期权手续费率请求
	struct CKSOTPQryOTPInsCommRateField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///输出查询个股期权合约手续费率
	struct CKSOTPOTPInsCommRateField
	{
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///开仓手续费率
		TKSOTPRatioType	OpenRatioByMoney;
		///开仓手续费
		TKSOTPRatioType	OpenRatioByVolume;
		///平仓手续费率
		TKSOTPRatioType	CloseRatioByMoney;
		///平仓手续费
		TKSOTPRatioType	CloseRatioByVolume;
		///执行手续费率
		TKSOTPRatioType	StrikeRatioByMoney;
		///执行手续费
		TKSOTPRatioType	StrikeRatioByVolume;
	};

	///输入查询个股期权保证金率请求
	struct CKSOTPQryOTPInsMarginRateField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///输出查询个股期权保证金率
	struct CKSOTPOTPInsMarginRateField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///保证金率
		TKSOTPRatioType	MarginRateByMoney;
		///当前保证金金额
		TKSOTPMoneyType	CurrMargin;
	};

	///输入个股行权指派信息
	struct CKSOTPQryOTPAssignmentField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///买卖
		TKSOTPDirectionType	Direction;
	};

	///输出个股行权指派信息
	struct CKSOTPOTPAssignmentField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///买卖
		TKSOTPDirectionType	Direction;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///合约名称
		TKSOTPInstrumentNameType	InstrumentName;
		///产品代码
		TKSOTPInstrumentIDType	ProductID;
		///投机套保标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///上日持仓
		TKSOTPVolumeType	YdPosition;
		///行权指派合约数量
		TKSOTPVolumeType AssInsVo;
		///行权标的证券数量
		TKSOTPVolumeType AssProVol;
		///行权指派应付金额
		TKSOTPMoneyType  FeePay;
		///期权C/P标志
		TKSOTPOptionsTypeType OptionsType;
		///行权交收日
		TKSOTPDateType DeliveryDay;
		///个股合约标识码
		TKSOTPInstrumentIDType StockID;
	};

	///查询行情
	struct CKSOTPQryDepthMarketDataField
	{
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
	};

	///深度行情
	struct CKSOTPDepthMarketDataField
	{
		///交易日
		TKSOTPDateType	TradingDay;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///合约在交易所的代码
		TKSOTPExchangeInstIDType	ExchangeInstID;
		///最新价
		TKSOTPPriceType	LastPrice;
		///上次结算价
		TKSOTPPriceType	PreSettlementPrice;
		///昨收盘
		TKSOTPPriceType	PreClosePrice;
		///昨持仓量
		TKSOTPLargeVolumeType	PreOpenInterest;
		///今开盘
		TKSOTPPriceType	OpenPrice;
		///最高价
		TKSOTPPriceType	HighestPrice;
		///最低价
		TKSOTPPriceType	LowestPrice;
		///数量
		TKSOTPVolumeType	Volume;
		///成交金额
		TKSOTPMoneyType	Turnover;
		///持仓量
		TKSOTPLargeVolumeType	OpenInterest;
		///今收盘
		TKSOTPPriceType	ClosePrice;
		///本次结算价
		TKSOTPPriceType	SettlementPrice;
		///涨停板价
		TKSOTPPriceType	UpperLimitPrice;
		///跌停板价
		TKSOTPPriceType	LowerLimitPrice;
		///昨虚实度
		TKSOTPRatioType	PreDelta;
		///今虚实度
		TKSOTPRatioType	CurrDelta;
		///最后修改时间
		TKSOTPTimeType	UpdateTime;
		///最后修改毫秒
		TKSOTPMillisecType	UpdateMillisec;
		///申买价一
		TKSOTPPriceType	BidPrice1;
		///申买量一
		TKSOTPVolumeType	BidVolume1;
		///申卖价一
		TKSOTPPriceType	AskPrice1;
		///申卖量一
		TKSOTPVolumeType	AskVolume1;
		///申买价二
		TKSOTPPriceType	BidPrice2;
		///申买量二
		TKSOTPVolumeType	BidVolume2;
		///申卖价二
		TKSOTPPriceType	AskPrice2;
		///申卖量二
		TKSOTPVolumeType	AskVolume2;
		///申买价三
		TKSOTPPriceType	BidPrice3;
		///申买量三
		TKSOTPVolumeType	BidVolume3;
		///申卖价三
		TKSOTPPriceType	AskPrice3;
		///申卖量三
		TKSOTPVolumeType	AskVolume3;
		///申买价四
		TKSOTPPriceType	BidPrice4;
		///申买量四
		TKSOTPVolumeType	BidVolume4;
		///申卖价四
		TKSOTPPriceType	AskPrice4;
		///申卖量四
		TKSOTPVolumeType	AskVolume4;
		///申买价五
		TKSOTPPriceType	BidPrice5;
		///申买量五
		TKSOTPVolumeType	BidVolume5;
		///申卖价五
		TKSOTPPriceType	AskPrice5;
		///申卖量五
		TKSOTPVolumeType	AskVolume5;
		///当日均价
		TKSOTPPriceType	AveragePrice;
	};

	///报单
	struct CKSOTPOrderField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///报单引用
		TKSOTPOrderRefType	OrderRef;
		///用户代码
		TKSOTPUserIDType	UserID;
		///报单价格条件
		TKSOTPOrderPriceTypeType	OrderPriceType;
		///买卖方向
		TKSOTPDirectionType	Direction;
		///开平标志
		TKSOTPOffsetFlagType	OffsetFlag;
		///价格
		TKSOTPPriceType	LimitPrice;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///数量
		TKSOTPVolumeType	VolumeTotalOriginal;
		///有效期类型
		TKSOTPTimeConditionType	TimeCondition;
		///GTD日期
		TKSOTPDateType	GTDDate;
		///成交量类型
		TKSOTPVolumeConditionType	VolumeCondition;
		///最小成交量
		TKSOTPVolumeType	MinVolume;
		///触发条件
		TKSOTPContingentConditionType	ContingentCondition;
		///止损价
		TKSOTPPriceType	StopPrice;
		///强平原因
		TKSOTPForceCloseReasonType	ForceCloseReason;
		///业务单元
		TKSOTPBusinessUnitType	BusinessUnit;
		///请求编号
		TKSOTPRequestIDType	RequestID;
		///本地报单编号
		TKSOTPOrderLocalIDType	OrderLocalID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///会员代码
		TKSOTPParticipantIDType	ParticipantID;
		///合约账号
		TKSOTPClientIDType	ClientID;
		///合约在交易所的代码
		TKSOTPExchangeInstIDType	ExchangeInstID;
		///交易所交易员代码
		TKSOTPTraderIDType	TraderID;
		///报单提交状态
		TKSOTPOrderSubmitStatusType	OrderSubmitStatus;
		///报单提示序号
		TKSOTPSequenceNoType	NotifySequence;
		///交易日
		TKSOTPDateType	TradingDay;
		///结算编号
		TKSOTPSettlementIDType	SettlementID;
		///报单编号
		TKSOTPOrderSysIDType	OrderSysID;
		///报单来源
		TKSOTPOrderSourceType	OrderSource;
		///报单状态
		TKSOTPOrderStatusType	OrderStatus;
		///报单类型
		TKSOTPOrderTypeType	OrderType;
		///今成交数量
		TKSOTPVolumeType	VolumeTraded;
		///剩余数量
		TKSOTPVolumeType	VolumeTotal;
		///报单日期
		TKSOTPDateType	InsertDate;
		///委托时间
		TKSOTPTimeType	InsertTime;
		///激活时间
		TKSOTPTimeType	ActiveTime;
		///最后修改时间
		TKSOTPTimeType	UpdateTime;
		///撤销时间
		TKSOTPTimeType	CancelTime;
		///序号
		TKSOTPSequenceNoType	SequenceNo;
		///前置编号
		TKSOTPFrontIDType	FrontID;
		///会话编号
		TKSOTPSessionIDType	SessionID;
		///用户端产品信息
		TKSOTPProductInfoType	UserProductInfo;
		///状态信息
		TKSOTPErrorMsgType	StatusMsg;
		///用户强评标志
		TKSOTPBoolType	UserForceClose;
		///操作用户代码
		TKSOTPUserIDType	ActiveUserID;
		///经纪公司报单编号
		TKSOTPSequenceNoType	BrokerOrderSeq;
	};

	///成交
	struct CKSOTPTradeField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///报单引用
		TKSOTPOrderRefType	OrderRef;
		///用户代码
		TKSOTPUserIDType	UserID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///成交编号
		TKSOTPTradeIDType	TradeID;
		///买卖方向
		TKSOTPDirectionType	Direction;
		///报单编号
		TKSOTPOrderSysIDType	OrderSysID;
		///会员代码
		TKSOTPParticipantIDType	ParticipantID;
		///合约账号
		TKSOTPClientIDType	ClientID;
		///交易角色
		TKSOTPTradingRoleType	TradingRole;
		///合约在交易所的代码
		TKSOTPExchangeInstIDType	ExchangeInstID;
		///开平标志
		TKSOTPOffsetFlagType	OffsetFlag;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///价格
		TKSOTPPriceType	Price;
		///数量
		TKSOTPVolumeType	Volume;
		///成交时期
		TKSOTPDateType	TradeDate;
		///成交时间
		TKSOTPTimeType	TradeTime;
		///成交类型
		TKSOTPTradeTypeType	TradeType;
		///成交价来源
		TKSOTPPriceSourceType	PriceSource;
		///交易所交易员代码
		TKSOTPTraderIDType	TraderID;
		///本地报单编号
		TKSOTPOrderLocalIDType	OrderLocalID;
		///结算会员编号
		TKSOTPParticipantIDType	ClearingPartID;
		///业务单元
		TKSOTPBusinessUnitType	BusinessUnit;
		///序号
		TKSOTPSequenceNoType	SequenceNo;
		///交易日
		TKSOTPDateType	TradingDay;
		///经纪公司报单编号
		TKSOTPSequenceNoType	BrokerOrderSeq;
		///成交来源
		TKSOTPTradeSourceType	TradeSource;
	};

	///非交易报单
	struct CKSOTPNonTradingOrderField
	{
		///经纪公司代码
		TKSOTPBrokerIDType	BrokerID;
		///投资者代码
		TKSOTPInvestorIDType	InvestorID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///品种代码
		TKSOTPInstrumentIDType	ProductID;
		///非交易报单引用
		TKSOTPOrderRefType	OTPOrderRef;
		///用户代码
		TKSOTPUserIDType	UserID;
		///数量
		TKSOTPVolumeType	Volume;
		///请求编号
		TKSOTPRequestIDType	RequestID;
		///业务单元
		TKSOTPBusinessUnitType	BusinessUnit;
		///开平标志
		TKSOTPOffsetFlagType	OffsetFlag;
		///备兑标志
		TKSOTPHedgeFlagType	HedgeFlag;
		///本地非交易报单编号
		TKSOTPOrderLocalIDType	OTPOrderLocalID;
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///会员代码
		TKSOTPParticipantIDType	ParticipantID;
		///合约账号
		TKSOTPClientIDType	ClientID;
		///合约在交易所的代码
		TKSOTPExchangeInstIDType	ExchangeInstID;
		///交易所交易员代码
		TKSOTPTraderIDType	TraderID;
		///非交易报单提交状态
		TKSOTPOrderSubmitStatusType	OrderSubmitStatus;
		///报单提示序号
		TKSOTPSequenceNoType	NotifySequence;
		///交易日
		TKSOTPDateType	TradingDay;
		///结算编号
		TKSOTPSettlementIDType	SettlementID;
		///非交易报单编号
		TKSOTPOTPOrderSysIDType	OTPOrderSysID;
		///报单日期
		TKSOTPDateType	InsertDate;
		///插入时间
		TKSOTPTimeType	InsertTime;
		///撤销时间
		TKSOTPTimeType	CancelTime;
		///非交易委托单状态
		TKSOTPOTPOrderStatusType	OTPOrderStatus;
		///结算会员编号
		TKSOTPParticipantIDType	ClearingPartID;
		///序号
		TKSOTPSequenceNoType	SequenceNo;
		///前置编号
		TKSOTPFrontIDType	FrontID;
		///会话编号
		TKSOTPSessionIDType	SessionID;
		///用户端产品信息
		TKSOTPProductInfoType	UserProductInfo;
		///状态信息
		TKSOTPErrorMsgType	StatusMsg;
		///操作用户代码
		TKSOTPUserIDType	ActiveUserID;
		///经纪公司报单编号
		TKSOTPSequenceNoType	BrokerOTPOrderSeq;
		///申请类型标志
		TKSOTPApplyFlagType	ApplyFlag;
	};

	///合约状态
	struct CKSOTPInstrumentStatusField
	{
		///交易所代码
		TKSOTPExchangeIDType	ExchangeID;
		///合约在交易所的代码
		TKSOTPExchangeInstIDType	ExchangeInstID;
		///合约代码
		TKSOTPInstrumentIDType	InstrumentID;
		///合约交易状态
		TKSOTPInstrumentStatusType	InstrumentStatus;
		///交易阶段编号
		TKSOTPTradingSegmentSNType	TradingSegmentSN;
		///进入本状态时间
		TKSOTPTimeType	EnterTime;
		///进入本状态原因
		TKSOTPInstStatusEnterReasonType	EnterReason;
	};

}	// end of namespace KingstarAPI

#endif

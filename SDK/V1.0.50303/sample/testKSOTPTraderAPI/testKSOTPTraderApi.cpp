// 个股期权OTP_API使用范例

#include "stdio.h"
#include <iostream>
#include "KSOTPTraderApi.h"

#ifdef WIN32
#include "windows.h"
#else
#include<unistd.h>
#include<string.h>
#endif

using namespace std;
using namespace KingstarAPI;

// CKSOTPTraderSpi派生类
class CSimpleHandler : public CKSOTPTraderSpi
{

public:
	// constructor，which need a valid pointer to a CKSOTPTraderApi instance 
	CSimpleHandler (CKSOTPTraderApi * pUserApi)
	{
		m_pUserApi = pUserApi;
		m_nRequestID = 0;
		memset(m_chBrokerID, 0, sizeof(m_chBrokerID));
		memset(m_chUserID, 0, sizeof(m_chUserID));
		memset(m_chPassword, 0, sizeof(m_chPassword));
		memset(m_chExchangeID, 0, sizeof(m_chExchangeID));
		memset(m_chContract, 0, sizeof(m_chContract));
		memset(m_chProductID, 0, sizeof(m_chProductID));
	}

	// destructor
	~CSimpleHandler () {}

	// After making a succeed connection with the server, the client should send the login request to the server.
	virtual void OnFrontConnected ()
	{
		cout<<"OnFrontConnected:" << endl;
		CKSOTPReqUserLoginField reqUserLogin = { 0 };

		// broker id 
		strcpy (reqUserLogin.BrokerID, m_chBrokerID);
		// user id
		strcpy (reqUserLogin.UserID, m_chUserID);
		// password
		strcpy (reqUserLogin.Password, m_chPassword);

		// send the login request
		m_pUserApi->ReqUserLogin (&reqUserLogin, m_nRequestID++);
	}

	// When the connection between client and the server disconnected,the follwing function will be called.
	virtual void OnFrontDisconnected (int nReason)
	{
		//  In this  case,  API will reconnect, the  client  application can ignore this.
		cout<<"OnFrontDisconnected:" << endl;
	}

	// After receiving the login request from  the client，the server will send the following response to notify the client whether the login success or not.
	virtual void OnRspUserLogin (CKSOTPRspUserLoginField * pRspUserLogin, CKSOTPRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pRspUserLogin != NULL)
		{
			cout << "OnRspUserLogin:"
				<< "经济公司代码:" << pRspUserLogin->BrokerID
				<< "交易日:" << pRspUserLogin->TradingDay
				<< "登陆成功时间:" << pRspUserLogin->LoginTime
				<< "用户代码:" << pRspUserLogin->UserID
				<< "交易系统名称" << pRspUserLogin->SystemName
				<< "前置机号:" << pRspUserLogin->FrontID 
				<< "会话编号:" << pRspUserLogin->SessionID
				<< "最大报单引用:" << pRspUserLogin->MaxOrderRef
				<< "上证所时间:" << pRspUserLogin->SSETime << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;
		if (pRspInfo->ErrorID != 0)
		{
			// in case any login failure, the client should handle this error.
			cout<<"Failed to login:"
				<<"errorcode="<<pRspInfo->ErrorID
				<<"errormsg="<<pRspInfo->ErrorMsg
				<<"requestid="<<nRequestID
				<<"chain="<<bIsLast<<endl;	
			exit (-1);
		}
		if (bIsLast == true)
		{
			//get trading day
			cout << "TradingDay:" << m_pUserApi->GetTradingDay()<<endl;
			//query Investor request
			CKSOTPQryInvestorField Investor = {0};
			// broker id 
			strcpy(Investor.BrokerID, m_chBrokerID);
			// investor id 
			strcpy(Investor.InvestorID, m_chUserID);

			m_pUserApi->ReqQryInvestor(&Investor, m_nRequestID++ );
		}
	}

	// investor response
	virtual void OnRspQryInvestor(CKSOTPInvestorField *pInvestor, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pInvestor)
		{
			cout << "OnRspQryInvestor:"
				<< "投资者代码:" << pInvestor->InvestorID
				<< "经纪公司代码:" << pInvestor->BrokerID
				<< "投资者名称:" << pInvestor->InvestorName
				<< "证件类型:" << pInvestor->IdentifiedCardType
				<< "证件号码:" << pInvestor->IdentifiedCardNo
				<< "是否活跃:" << pInvestor->IsActive
				<< "联系电话:" << pInvestor->Telephone
				<< "通讯地址:" << pInvestor->Address
				<< "手机:" << pInvestor->Mobile
				<< "开户日期:" << pInvestor->OpenDate << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// trade account request.
			CKSOTPQryTradingAccountField TradingAccount = {0};

			// broker id 
			strcpy(TradingAccount.BrokerID, m_chBrokerID);
			// investor id
			strcpy(TradingAccount.InvestorID, m_chUserID);

			m_pUserApi->ReqQryTradingAccount(&TradingAccount, m_nRequestID++ );
		}
	}

	// trade account response
	virtual void OnRspQryTradingAccount(CKSOTPTradingAccountField *pTradingAccount, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pTradingAccount)
		{
			cout << "OnRspQryTradingAccount:"
				<< "经纪公司代码:" << pTradingAccount->BrokerID
				<< "账号:" << pTradingAccount->AccountID
				<< "上次结算准备金:" << pTradingAccount->PreBalance
				<< "上次占用的保证金:" << pTradingAccount->PreMargin
				<< "入金金额:" << pTradingAccount->Deposit
				<< "出金金额:" << pTradingAccount->Withdraw
				<< "冻结的保证金:" << pTradingAccount->FrozenMargin
				<< "冻结的资金:" << pTradingAccount->FrozenCash
				<< "冻结的手续费:" << pTradingAccount->FrozenCommission
				<< "当前保证金总额:" << pTradingAccount->CurrMargin
				<< "资金差额:" << pTradingAccount->CashIn
				<< "手续费:" << pTradingAccount->Commission
				<< "平仓盈亏:" << pTradingAccount->CloseProfit
				<< "持仓盈亏:" << pTradingAccount->PositionProfit
				<< "证券结算准备金:" << pTradingAccount->Balance
				<< "可用资金:" << pTradingAccount->Available
				<< "可取资金:" << pTradingAccount->WithdrawQuota
				<< "基本准备金:" << pTradingAccount->Reserve
				<< "交易日:" << pTradingAccount->TradingDay
				<< "结算编号:" << pTradingAccount->SettlementID
				<< "信用额度:" << pTradingAccount->Credit
				<< "质押金额:" << pTradingAccount->Mortgage
				<< "交易所保证金:" << pTradingAccount->ExchangeMargin
				<< "投资者交割保证金:" << pTradingAccount->DeliveryMargin
				<< "交易所交割保证金:" << pTradingAccount->ExchangeDeliveryMargin
				<< "期权平仓盈亏:" << pTradingAccount->CloseProfit<< endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// qryexchange
			CKSOTPQryExchangeField QryExchange = {0};
			// exchange id
			strcpy(QryExchange.ExchangeID, m_chExchangeID);

			m_pUserApi->ReqQryExchange(&QryExchange, m_nRequestID++ );
		}
	}

	// rspqryexchange response
	virtual void OnRspQryExchange(CKSOTPExchangeField *pExchange, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pExchange)
		{
			cout << "OnRspQryExchange:"
				<< "交易所代码:" << pExchange->ExchangeID
				<< "交易所名称:" << pExchange->ExchangeName<< endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// rspqryinstrument
			CKSOTPQryInstrumentField QryInstrument = {0};
			// exchange id
			strcpy(QryInstrument.ExchangeID, m_chExchangeID);

			m_pUserApi->ReqQryInstrument(&QryInstrument, m_nRequestID++ );
		}
	}

	// instrument response
	virtual void OnRspQryInstrument(CKSOTPInstrumentField *pInstrument, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pInstrument)
		{
			cout << "OnRspQryInstrument:"
				<< "交易所代码:" << pInstrument->ExchangeID
				<< "合约代码:" << pInstrument->InstrumentID
				<< "合约名称:" << pInstrument->InstrumentName
				<< "合约数量乘数:" << pInstrument->VolumeMultiple
				<< "到期日:" << pInstrument->ExpireDate
				<< "产品代码:" << pInstrument->ProductID
				<< "最小变动价位:" << pInstrument->PriceTick << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// investor position detail
			CKSOTPQryInvestorPositionDetailField InvestorPositionDetail = {0};
			// broker id 
			strcpy(InvestorPositionDetail.BrokerID, m_chBrokerID);
			// investor id
			strcpy(InvestorPositionDetail.InvestorID, m_chUserID);
			//	instrument id
			strcpy(InvestorPositionDetail.InstrumentID, m_chContract);

			m_pUserApi->ReqQryInvestorPositionDetail(&InvestorPositionDetail, m_nRequestID++ );
		}
	}

	// investor position detail response
	virtual void OnRspQryInvestorPositionDetail(CKSOTPInvestorPositionDetailField *pInvestorPositionDetail, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pInvestorPositionDetail)
		{
			cout <<  "OnRspQryInvestorPositionDetail:"
				<<"交易日:"  <<  pInvestorPositionDetail->TradingDay                                       
				<< "开仓日期:" << pInvestorPositionDetail->OpenDate
				<< "成交编号:" << pInvestorPositionDetail->TradeID
				<< "投资者代码:" << pInvestorPositionDetail->InvestorID
				<< "交易所代码:" << pInvestorPositionDetail->ExchangeID
				<< "买卖标志:" << pInvestorPositionDetail->Direction
				<< "投保标志:" << pInvestorPositionDetail->HedgeFlag
				<< "数量:" << pInvestorPositionDetail->Volume
				<< "开仓价格:" << pInvestorPositionDetail->OpenPrice
				<< "投资者保证金:" << pInvestorPositionDetail->Margin
				<< "交易所保证金:" << pInvestorPositionDetail->ExchMargin << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// send order insertion request.
			CKSOTPInputOrderField ord = {0};
			// broker id 
			strcpy(ord.BrokerID, m_chBrokerID); 
			// investor id
			strcpy(ord.InvestorID, m_chUserID); 
			// instrument id
			strcpy(ord.InstrumentID, m_chContract);
			///order reference 
			strcpy(ord.OrderRef, "9");  
			// user id 
			strcpy(ord.UserID, m_chUserID); 
			// order price type 
			ord.OrderPriceType = KS_OTP_OPT_LimitPrice; 
			// direction 
			ord.Direction = KS_OTP_D_Buy; 
			// order’s offset flag 
			ord.OffsetFlag = KS_OTP_OF_Open;
			// order’s hedge flag 
			ord.HedgeFlag = KS_OTP_HF_Speculation;
			// price 
			ord.LimitPrice = 0.25; 
			// volume 
			ord.VolumeTotalOriginal = 1; 
			// valid date 
			ord.TimeCondition = KS_OTP_TC_GFD; 
			// GTD date
			strcpy(ord.GTDDate, ""); 
			// volume condition 
			ord.VolumeCondition = KS_OTP_VC_AV; 
			// min volume 
			ord.MinVolume = 0; 
			// trigger condition 
			ord.ContingentCondition = KS_OTP_CC_Immediately; 
			// stop price 
			ord.StopPrice = 0; 
			// request id
			ord.RequestID = m_nRequestID;

			m_pUserApi->ReqOrderInsert(&ord, m_nRequestID++ );
		}	

		if (bIsLast == true)
		{
			// qryorder
			CKSOTPQryOrderField QryOrder = {0};
			// broker id 
			strcpy(QryOrder.BrokerID, m_chBrokerID);
			// investor id
			strcpy(QryOrder.InvestorID, m_chUserID);

			m_pUserApi->ReqQryOrder(&QryOrder, m_nRequestID++ );
		}
	}

	// order insertion response 
	virtual void OnRspOrderInsert(CKSOTPInputOrderField *pInputOrder, CKSOTPRspInfoField *pRspInfo, int  nRequestID, bool bIsLast) 
	{
		if (NULL != pInputOrder)
		{
			cout << "OnRspOrderInsert:"                                 			
				<< "报单引用:" << pInputOrder->OrderRef << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;
	}

	// order insert return 
	virtual void OnRtnOrder (CKSOTPOrderField * pOrder)
	{
		cout << "OnRtnOrder:"
			<< "序号:" << pOrder->SequenceNo
			<< "客户号:" << pOrder->InvestorID
			<< "委托号:" << pOrder->OrderSysID
			<< "交易所代码:" << pOrder->ExchangeID
			<< "合约号:" << pOrder->InstrumentID
			<< "报单状态:" << pOrder->OrderStatus
			<< "状态信息:" << pOrder->StatusMsg
			<< "委托数量:" << pOrder->VolumeTotalOriginal
			<< "成交数量:" << pOrder->VolumeTraded
			<< "未成交数量:" << pOrder->VolumeTotal
			<< "交割期:" << pOrder->TradingDay
			<< "委托时间:" << pOrder->InsertTime
			<< "撤单时间:" << pOrder->CancelTime
			<< "报单类型:" << pOrder->OrderType
			<< "报单来源:" << pOrder->OrderSource
			<< "报单价格条件:" << pOrder->OrderPriceType
			<< "有效期类型:" << pOrder->TimeCondition
			<< "止损价:" << pOrder->StopPrice
			<< "激活时间:" << pOrder->ActiveTime
			<< "报单引用:" << pOrder->OrderRef
			<< "前置机号:" << pOrder->FrontID
			<< "会话编号:" << pOrder->SessionID << endl;
	}

	// trade return
	virtual void OnRtnTrade (CKSOTPTradeField * pTrade)
	{
		cout << "OnRtnTrade:"
			<< "序号:" << pTrade->SequenceNo
			<< "客户号:" << pTrade->InvestorID
			<< "交易所代码:" << pTrade->ExchangeID
			<< "委托单号:" << pTrade->OrderSysID
			<< "合约编码:" << pTrade->InstrumentID
			<< "买卖标记:" << pTrade->Direction
			<< "开平仓标记:" << pTrade->OffsetFlag
			<< "投保标记:" << pTrade->HedgeFlag
			<< "成交数量" << pTrade->Volume
			<< "成交价格" << pTrade->Price
			<< "成交号" << pTrade->TradeID
			<< "交割期" << pTrade->TradingDay
			<< "成交时间" << pTrade->TradeTime
			<< "报单引用" << pTrade->OrderRef << endl;
	}

	// qryorder response
	virtual void OnRspQryOrder(CKSOTPOrderField *pOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if(pOrder != NULL)
		{
			cout <<  "OnRspQryOrder:"
				<<"报单编号:"  <<  pOrder->OrderSysID << endl;    
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{	
			// qrytrade
			CKSOTPQryTradeField QryTrade = {0};
			// broker id 
			strcpy(QryTrade.BrokerID, m_chBrokerID); 
			// investor id
			strcpy(QryTrade.InvestorID, m_chUserID);
			// start time
			strcpy(QryTrade.TradeTimeStart, "20131201");
			// end time
			strcpy(QryTrade.TradeTimeEnd, "20131231");
			// exchange id
			strcpy(QryTrade.ExchangeID, m_chExchangeID);
			// instrument id
			strcpy(QryTrade.InstrumentID, m_chContract);

			m_pUserApi->ReqQryTrade(&QryTrade, m_nRequestID++ );
		}

		if(pOrder != NULL)
		{
			// order insertion success, then send order action request.
			if (pOrder->OrderStatus == KS_OTP_OST_NoTradeQueueing && atoi(pOrder->OrderSysID) != 0)
			{
				// delete ord
				CKSOTPInputOrderActionField ord = {0};
				// broker id 
				strcpy(ord.BrokerID, m_chBrokerID); 
				// investor id
				strcpy(ord.InvestorID, m_chUserID);
				// order action refernce
				strcpy(ord.OrderRef, "000000000001");

				/// order reference 
				strcpy(ord.OrderRef, pOrder->OrderRef);		// *必传1
				// front id
				ord.FrontID = pOrder->FrontID;				// *必传2
				// session id
				ord.SessionID = pOrder->SessionID;			// *必传3
				// exchange id
				strcpy(ord.ExchangeID, pOrder->ExchangeID);	// *必传4
				// action order id
				strcpy(ord.OrderSysID,pOrder->OrderSysID);	// *有即传

				//  action order num(unavailable yet)
				ord.VolumeChange=0;
				// instrument id 
				strcpy(ord.InstrumentID, pOrder->InstrumentID); 
				// user id 
				strcpy(ord.UserID, m_chUserID); 

				m_pUserApi->ReqOrderAction(&ord, m_nRequestID++ ); 
			}
		}
	}

	// order action result  response
	virtual void OnRspOrderAction(CKSOTPInputOrderActionField *pInputOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pInputOrderAction)
		{
			cout << "OnRspOrderAction:"                                            
				<< "客户号:" << pInputOrderAction->InvestorID
				<< "委托号:" << pInputOrderAction->OrderSysID
				<< "交易所代码:" << pInputOrderAction->ExchangeID
				<< "合约号:" << pInputOrderAction->InstrumentID
				<< "委托价格:" << pInputOrderAction->LimitPrice << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;
	}

	// qrytrade response
	virtual void OnRspQryTrade(CKSOTPTradeField *pTrade, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if(pTrade != NULL)
		{
			cout << "OnRspQryTrade:"                                          
				<< "客户号:" << pTrade->InvestorID
				<< "交易所代码:" << pTrade->ExchangeID
				<< "报单编号:" << pTrade->OrderSysID
				<< "合约代码:" << pTrade->InstrumentID
				<< "买卖标记:" << pTrade->Direction
				<< "开平标志:" << pTrade->OffsetFlag
				<< "投保标记:" << pTrade->HedgeFlag
				<< "成交数量:" << pTrade->Volume
				<< "成交价格:" << pTrade->Price
				<< "成交号:" << pTrade->TradeID
				<< "日期:" << pTrade->TradeDate
				<< "交易日:" <<pTrade->TradingDay
				<< "成交时间:" << pTrade->TradeTime
				<< "序号:" << pTrade->SequenceNo << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// qry position
			CKSOTPQryInvestorPositionField QryInvestorPosition = {0};
			// broker id 
			strcpy(QryInvestorPosition.BrokerID, m_chBrokerID); 
			// investor id 
			strcpy(QryInvestorPosition.InvestorID, m_chUserID);
			// instrument id
			strcpy(QryInvestorPosition.InstrumentID, m_chContract);

			m_pUserApi->ReqQryInvestorPosition(&QryInvestorPosition, m_nRequestID++ );;
		}
	}

	// qryInvestor position response
	virtual void OnRspQryInvestorPosition(CKSOTPInvestorPositionField *pInvestorPosition, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if(pInvestorPosition != NULL)
		{
			cout << "OnRspQryInvestorPosition:"                                           
				<< "客户号:" << pInvestorPosition->InvestorID
				<< "今日总持仓:" << pInvestorPosition->Position
				<< "今日现持仓:" << pInvestorPosition->TodayPosition
				<< "持仓成本:" << pInvestorPosition->PositionCost
				<< "开仓成本:" << pInvestorPosition->OpenCost
				<< "合约代码:" << pInvestorPosition->InstrumentID
				<< "投机套保标志:" << pInvestorPosition->HedgeFlag
				<< "持仓盈亏:" << pInvestorPosition->PositionProfit
				<< "持仓多空方向:" << pInvestorPosition->PosiDirection
				<< "交易日:" << pInvestorPosition->TradingDay
				<< "占用的保证金:" << pInvestorPosition->UseMargin <<endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// password update
			CKSOTPUserPasswordUpdateField UserPasswordUpdate = {0};
			// broker id
			strcpy(UserPasswordUpdate.BrokerID,m_chBrokerID);
			// user id
			strcpy(UserPasswordUpdate.UserID, m_chUserID);
			// old password
			strcpy(UserPasswordUpdate.OldPassword, "123456");
			// new password
			strcpy(UserPasswordUpdate.NewPassword, "123456");

			m_pUserApi->ReqUserPasswordUpdate(&UserPasswordUpdate, m_nRequestID++ );
		}
	}

	// password update response
	virtual void OnRspUserPasswordUpdate(CKSOTPUserPasswordUpdateField *pUserPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pUserPasswordUpdate)
		{
			cout << "OnRspUserPasswordUpdate:"                                          
				<< "客户号:" << pUserPasswordUpdate->UserID
				<< "旧口令:" << pUserPasswordUpdate->OldPassword
				<< "新口令:" << pUserPasswordUpdate->NewPassword <<endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;
		if (bIsLast == true)
		{
			// password update
			CKSOTPTradingAccountPasswordUpdateField TradingAccountPasswordUpdate = {0};
			// broker id
			strcpy(TradingAccountPasswordUpdate.BrokerID,m_chBrokerID);
			// user id
			strcpy(TradingAccountPasswordUpdate.AccountID, m_chUserID);
			// old password
			strcpy(TradingAccountPasswordUpdate.OldPassword, "123456");
			// new password
			strcpy(TradingAccountPasswordUpdate.NewPassword, "123456");

			m_pUserApi->ReqTradingAccountPasswordUpdate(&TradingAccountPasswordUpdate, m_nRequestID++ );
		}
	}

	// trading account password update response
	virtual void OnRspTradingAccountPasswordUpdate(CKSOTPTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pTradingAccountPasswordUpdate)
		{
			cout << "OnRspTradingAccountPasswordUpdate:"                                          
				<< "客户号:" << pTradingAccountPasswordUpdate->AccountID
				<< "旧口令:" << pTradingAccountPasswordUpdate->OldPassword
				<< "新口令:" << pTradingAccountPasswordUpdate->NewPassword <<endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// password update
			CKSOTPQryTradingCodeField TradingCode = {0};
			// broker id 
			strcpy(TradingCode.BrokerID, m_chBrokerID); 
			// investor id
			strcpy(TradingCode.InvestorID, m_chUserID);
			// exchange id
			strcpy(TradingCode.ExchangeID, m_chExchangeID);

			m_pUserApi->ReqQryTradingCode(&TradingCode, m_nRequestID++ );
		}
	}

	// tradingcode response
	virtual void OnRspQryTradingCode(CKSOTPTradingCodeField *pTradingCode, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pTradingCode)
		{
			cout << "OnRspQryTradingCode:"                                 			
				<< "投资者代码:" << pTradingCode->InvestorID
				<< "经纪公司代码:" << pTradingCode->BrokerID
				<< "交易所代码:" << pTradingCode->ExchangeID
				<< "合约账号:" << pTradingCode->ClientID
				<< "是否活跃:" << pTradingCode->IsActive
				<< "合约账号类型:" << pTradingCode->ClientIDType <<endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// send order insertion request.
			CKSOTPInputExecOrderField ord = {0};
			// broker id 
			strcpy(ord.BrokerID, m_chBrokerID); 
			// investor id
			strcpy(ord.InvestorID, m_chUserID); 
			// instrument id 
			strcpy(ord.InstrumentID, m_chContract);
			//order reference 
			strcpy(ord.ExecOrderRef, "9");  
			// user id 
			strcpy(ord.UserID, m_chUserID); 
			// volume 
			ord.Volume = 1; 
			// request id
			ord.RequestID = m_nRequestID;
			// order’s offset flag 
			ord.OffsetFlag = KS_OTP_OF_Open;
			// order’s hedge flag 
			ord.HedgeFlag = KS_OTP_HF_Speculation;
			m_pUserApi->ReqExecOrderInsert(&ord, m_nRequestID++ );
		}
	}

	// nontrading orderInsert response
	virtual void OnRspExecOrderInsert(CKSOTPExecOrderField *pInputOTPOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pInputOTPOrder != NULL)
		{
			cout << "非交易报单录入请求响应:"
				<< "经济公司代码:" << pInputOTPOrder->BrokerID
				<< "客户号:" << pInputOTPOrder->InvestorID
				<< "合约编码:" << pInputOTPOrder->InstrumentID
				<< "非交易报单引用:" << pInputOTPOrder->ExecOrderRef
				<< "用户代码:" << pInputOTPOrder->UserID
				<< "数量:" << pInputOTPOrder->Volume
				<< "请求编号:" << pInputOTPOrder->RequestID
				<< "业务单元:" << pInputOTPOrder->BusinessUnit
				<< "开平标志:" << pInputOTPOrder->OffsetFlag
				<< "备兑标志:" << pInputOTPOrder->HedgeFlag<< endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;
	}

	// nontrading order return
	virtual void OnRtnExecOrder(CKSOTPExecOrderField *pNonTradingOrder)
	{
		cout << "OnRtnNonTradingOrder:"
			<< "经济公司代码:" << pNonTradingOrder->BrokerID
			<< "客户号:" << pNonTradingOrder->InvestorID
			<< "合约编码:" << pNonTradingOrder->InstrumentID
			<< "执行宣告引用:" << pNonTradingOrder->ExecOrderRef
			<< "用户代码:" << pNonTradingOrder->UserID
			<< "数量:" << pNonTradingOrder->Volume
			<< "请求编号:" << pNonTradingOrder->RequestID
			<< "业务单元:" << pNonTradingOrder->BusinessUnit
			<< "开平标志:" << pNonTradingOrder->OffsetFlag
			<< "备兑标志:" << pNonTradingOrder->HedgeFlag
			<< "本地执行宣告编号:" << pNonTradingOrder->ExecOrderLocalID
			<< "交易所代码:" << pNonTradingOrder->ExchangeID
			<< "会员代码:" << pNonTradingOrder->ParticipantID
			<< "合约账号:" << pNonTradingOrder->ClientID
			<< "合约在交易所的代码:" << pNonTradingOrder->ExchangeInstID
			<< "交易所交易员代码:" << pNonTradingOrder->TraderID
			<< "执行宣告提交状态:" << pNonTradingOrder->OrderSubmitStatus
			<< "报单提示序号:" << pNonTradingOrder->NotifySequence
			<< "交易日:" << pNonTradingOrder->TradingDay
			<< "结算编号:" << pNonTradingOrder->SettlementID
			<< "执行宣告编号:" << pNonTradingOrder->ExecOrderSysID
			<< "报单日期:" << pNonTradingOrder->InsertDate
			<< "插入时间:" << pNonTradingOrder->InsertTime	
			<< "撤销时间:" << pNonTradingOrder->CancelTime
			<< "结算会员编号:" << pNonTradingOrder->ClearingPartID
			<< "序号:" << pNonTradingOrder->SequenceNo
			<< "前置编号:" << pNonTradingOrder->FrontID
			<< "会话编号:" << pNonTradingOrder->SessionID
			<< "用户端产品信息:" << pNonTradingOrder->UserProductInfo
			<< "状态信息:" << pNonTradingOrder->StatusMsg
			<< "操作用户代码:" << pNonTradingOrder->ActiveUserID
			<< "经纪公司报单编号:" << pNonTradingOrder->BrokerExecOrderSeq << endl;

		// send order insertion request
		CKSOTPQryExecOrderField ord = {0};
		// broker id 
		strcpy(ord.BrokerID, m_chBrokerID); 
		// investor id 
		strcpy(ord.InvestorID, m_chUserID); 
		// instrument id
		strcpy(ord.InstrumentID, m_chContract);
		//order reference
		strcpy(ord.ExecOrderSysID, "");  
		// exchange id 
		strcpy(ord.ExchangeID, m_chExchangeID); 

		m_pUserApi->ReqQryExecOrder(&ord, m_nRequestID++ );
	}

	// the error notification caused by client request
	virtual void OnRspError (CKSOTPRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		cout << "OnRspError" 
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		// the client should handle the error
	}

	// instrument status return
	virtual void OnRtnInstrumentStatus (CKSOTPInstrumentStatusField *pInstrumentStatus)
	{
		cout << "OnRtnInstrumentStatus" 
			<< "ExchangeID:" << pInstrumentStatus->ExchangeID
			<< "InstrumentStatus:" << pInstrumentStatus->InstrumentStatus
			<< "EnterReason:" << pInstrumentStatus->EnterReason << endl;
	}

	// trading notice return
	virtual void OnRtnTradingNotice(CKSOTPTradingNoticeInfoField *pTradingNoticeInfo)
	{
		cout << "OnRtnTradingNotice:"
			<< "经济公司代码:" << pTradingNoticeInfo->BrokerID
			<< "客户号:" << pTradingNoticeInfo->InvestorID
			<< "发送时间:" << pTradingNoticeInfo->SendTime
			<< "消息正文:" << pTradingNoticeInfo->FieldContent
			<< "序列系列号:" << pTradingNoticeInfo->SequenceSeries
			<< "序列号:" << pTradingNoticeInfo->SequenceNo << endl;
	}

	// nontrading order response
	virtual void OnRspQryExecOrder(CKSOTPExecOrderField *pOTPOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pOTPOrder != NULL)
		{
			cout << "请求查询非交易报单响应:"
				<< "经济公司代码:" << pOTPOrder->BrokerID
				<< "客户号:" << pOTPOrder->InvestorID
				<< "合约编码:" << pOTPOrder->InstrumentID
				<< "执行宣告引用:" << pOTPOrder->ExecOrderRef
				<< "用户代码:" << pOTPOrder->UserID
				<< "数量:" << pOTPOrder->Volume
				<< "请求编号:" << pOTPOrder->RequestID
				<< "业务单元:" << pOTPOrder->BusinessUnit
				<< "开平标志:" << pOTPOrder->OffsetFlag
				<< "备兑标志:" << pOTPOrder->HedgeFlag
				<< "执行宣告报单编号:" << pOTPOrder->ExecOrderLocalID
				<< "交易所代码:" << pOTPOrder->ExchangeID
				<< "会员代码:" << pOTPOrder->ParticipantID
				<< "合约账号:" << pOTPOrder->ClientID
				<< "合约在交易所的代码:" << pOTPOrder->ExchangeInstID
				<< "交易所交易员代码:" << pOTPOrder->TraderID
				<< "非交易报单提交状态:" << pOTPOrder->OrderSubmitStatus
				<< "报单提示序号:" << pOTPOrder->NotifySequence
				<< "交易日:" << pOTPOrder->TradingDay
				<< "结算编号:" << pOTPOrder->SettlementID
				<< "执行宣告编号:" << pOTPOrder->ExecOrderSysID
				<< "报单日期:" << pOTPOrder->InsertDate
				<< "插入时间:" << pOTPOrder->InsertTime	
				<< "撤销时间:" << pOTPOrder->CancelTime
				<< "结算会员编号:" << pOTPOrder->ClearingPartID
				<< "序号:" << pOTPOrder->SequenceNo
				<< "前置编号:" << pOTPOrder->FrontID
				<< "会话编号:" << pOTPOrder->SessionID
				<< "用户端产品信息:" << pOTPOrder->UserProductInfo
				<< "状态信息:" << pOTPOrder->StatusMsg
				<< "操作用户代码:" << pOTPOrder->ActiveUserID
				<< "经纪公司报单编号:" << pOTPOrder->BrokerExecOrderSeq << endl;
			if (bIsLast == true)
			{
				// send order insertion request.
				CKSOTPInputExecOrderActionField ord = {0};
				// broker id 
				strcpy(ord.BrokerID, m_chBrokerID); 
				// investor ID 
				strcpy(ord.InvestorID, m_chUserID); 
				// instrument ID 
				strcpy(ord.InstrumentID, m_chContract);
				//order reference 
				strcpy(ord.ExecOrderRef, "9");  
				// user id 
				strcpy(ord.UserID, m_chUserID); 
				// action flag 
				ord.ActionFlag = KS_OTP_AF_Delete; 
				// front id
				ord.FrontID = pOTPOrder->FrontID; 
				// session id
				ord.SessionID = pOTPOrder->SessionID; 
				// exchange id
				strcpy(ord.ExchangeID, pOTPOrder->ExchangeID); 
				// otporder sysid
				strcpy(ord.ExecOrderSysID,pOTPOrder->ExecOrderSysID); 
				// request id
				ord.RequestID = m_nRequestID;

				m_pUserApi->ReqExecOrderAction(&ord, m_nRequestID++ );
			}
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;		
	}

	// nontrading order action response
	virtual void OnRspExecOrderAction(CKSOTPInputExecOrderActionField *pInputOTPOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	{
		if (pInputOTPOrderAction != NULL)
		{
			cout << "执行宣告操作请求响应:"
				<< "经济公司代码:" << pInputOTPOrderAction->BrokerID
				<< "客户号:" << pInputOTPOrderAction->InvestorID
				<< "执行宣告引用:" << pInputOTPOrderAction->ExecOrderRef
				<< "请求编号:" << pInputOTPOrderAction->RequestID
				<< "前置编号:" << pInputOTPOrderAction->FrontID
				<< "会话编号:" << pInputOTPOrderAction->SessionID
				<< "交易所代码:" << pInputOTPOrderAction->ExchangeID
				<< "合约编码:" << pInputOTPOrderAction->InstrumentID
				<< "撤销用户:" << pInputOTPOrderAction->UserID
				<< "执行宣告操作编号:" << pInputOTPOrderAction->ExecOrderSysID
				<< "操作标志:" << pInputOTPOrderAction->ActionFlag
				<< "用户代码用户代码:" << pInputOTPOrderAction->UserID << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// send order insertion request.
			CKSOTPQryExecOrderVolumeField ord = {0};
			// broker id 
			strcpy(ord.BrokerID, m_chBrokerID); 
			// investor id
			strcpy(ord.InvestorID, m_chUserID); 
			// instrument id
			strcpy(ord.InstrumentID, m_chContract);  
			// hedge flag
			ord.HedgeFlag = KS_OTP_HF_Covered; 

			m_pUserApi->ReqQryExecOrderVolume(&ord, m_nRequestID++ );
		}
	}

	// nontrading order volume response
	virtual void OnRspQryExecOrderVolume(CKSOTPExecOrderVolumeField *pOTPOrderVolume, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pOTPOrderVolume != NULL)
		{
			cout << "查询非交易报单量响应:"
				<< "经济公司代码:" << pOTPOrderVolume->BrokerID
				<< "客户号:" << pOTPOrderVolume->InvestorID
				<< "合约编码:" << pOTPOrderVolume->InstrumentID
				<< "备兑标志:" << pOTPOrderVolume->HedgeFlag
				<< "可申请执行量:" << pOTPOrderVolume->ExecVolume
				<< "已申请执行量:" << pOTPOrderVolume->ExecedVolume << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// send order insertion request.
			CKSOTPQryOTPInsCommRateField ord = {0};
			// broker id 
			strcpy(ord.BrokerID, m_chBrokerID); 
			// investor id
			strcpy(ord.InvestorID, m_chUserID); 
			// instrument id
			strcpy(ord.InstrumentID, m_chContract); 

			m_pUserApi->ReqQryOTPInsCommRate(&ord, m_nRequestID++ );
		}
	}

	//  instrument commission rate response
	virtual void OnRspQryOTPInsCommRate(CKSOTPOTPInsCommRateField *pOTPInsMarginRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pOTPInsMarginRate != NULL)
		{
			cout << "请求查询个股期权手续费率响应:"
				<< "合约编码:" << pOTPInsMarginRate->InstrumentID
				<< "营业部代码:" << pOTPInsMarginRate->BrokerID
				<< "投资者代码:" << pOTPInsMarginRate->InvestorID
				<< "开仓手续费率:" << pOTPInsMarginRate->OpenRatioByMoney
				<< "开仓手续费:" << pOTPInsMarginRate->OpenRatioByVolume
				<< "平仓手续费率:" << pOTPInsMarginRate->CloseRatioByMoney
				<< "平仓手续费:" << pOTPInsMarginRate->CloseRatioByVolume
				<< "执行手续费率:" << pOTPInsMarginRate->StrikeRatioByMoney
				<< "执行手续费:" << pOTPInsMarginRate->StrikeRatioByVolume<< endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;
		if (bIsLast == true)
		{
			// send order insertion request.
			CKSOTPQryInstrumentMarginRateField ord = {0};
			// broker id 
			strcpy(ord.BrokerID, m_chBrokerID); 
			// investor ID 
			strcpy(ord.InvestorID, m_chUserID); 
			// instrument ID 
			strcpy(ord.InstrumentID, m_chContract);  

			m_pUserApi->ReqQryInstrumentMarginRate(&ord, m_nRequestID++ );
		}
	}

	// instrument marginrate response
	virtual void OnRspQryInstrumentMarginRate(CKSOTPInstrumentMarginRateField *pInstrumentMarginRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pInstrumentMarginRate != NULL)
		{
			cout << "查询个股期权保证金率请求响应:"
				<< "合约编码:" << pInstrumentMarginRate->InstrumentID
				<< "营业部代码:" << pInstrumentMarginRate->BrokerID
				<< "投资者代码:" << pInstrumentMarginRate->InvestorID << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		if (bIsLast == true)
		{
			// send order insertion request.
			CKSOTPQryUnderlyingStockInfoField ord = {0};
			// broker id 
			strcpy(ord.BrokerID, m_chBrokerID); 
			// exchange id 
			strcpy(ord.ExchangeID, m_chExchangeID); 
			// product id
			strcpy(ord.ProductID, ""); 

			m_pUserApi->ReqQryUnderlyingStockInfo(&ord, m_nRequestID++ );
		}
	}

	// underlying stock information response
	virtual void OnRspQryUnderlyingStockInfo(CKSOTPUnderlyingStockInfoField *pUnderlyingStockInfo, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pUnderlyingStockInfo != NULL)
		{
			cout << "查询标的券信息响应:"
				<< "经济公司代码:" << pUnderlyingStockInfo->BrokerID
				<< "交易所代码:" << pUnderlyingStockInfo->ExchangeID
				<< "产品代码:" << pUnderlyingStockInfo->ProductID
				<< "昨收盘:" << pUnderlyingStockInfo->PreClosePrice << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;
	}

	// logout response
	virtual void OnRspUserLogout(CKSOTPUserLogoutField *pUserLogout, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (NULL != pUserLogout)
		{
			cout << "OnRspUserLogout:"                                 			
				<< "投资者代码:" << pUserLogout->UserID << endl;
		}
		cout << endl
			<< "ErrorCode=" << pRspInfo->ErrorID
			<< "ErrorMsg=" << pRspInfo->ErrorMsg
			<< "RequestID=" << nRequestID
			<< "Chain=" << bIsLast << endl;

		// inform the main thread order transaction is over 
		//SetEvent(m_hEvent); 
	}

public:
	// broker id
	TKSOTPBrokerIDType m_chBrokerID;
	// user id
	TKSOTPUserIDType m_chUserID;
	// user password
	TKSOTPPasswordType m_chPassword;
	// exchange id
	TKSOTPExchangeIDType m_chExchangeID;
	// contract
	TKSOTPInstrumentIDType m_chContract;
	TKSOTPInstrumentIDType m_chProductID;
	// request id
	int m_nRequestID;
	// finish event
	//HANDLE m_hEvent;

private:
	// a pointer of CKSOTPTraderApi instance
	CKSOTPTraderApi * m_pUserApi;
};


int main ()
{
	// create a CKSOTPTraderApi instance
	CKSOTPTraderApi *pUserApi = CKSOTPTraderApi::CreateOTPTraderApi ();

	// create an event handler instance
	CSimpleHandler *pSpi = new CSimpleHandler (pUserApi);

	// create a manual reset event with no signal
	//pSpi ->m_hEvent = CreateEvent(NULL, true, false, NULL);

	// set spi's broker, user, password
	strncpy (pSpi ->m_chBrokerID, "31000853", sizeof(pSpi ->m_chBrokerID)-1);
	strncpy (pSpi ->m_chUserID, "80002", sizeof(pSpi ->m_chUserID)-1);
	strncpy (pSpi ->m_chPassword, "123456", sizeof(pSpi ->m_chPassword)-1);
	strncpy (pSpi ->m_chContract, "90000001", sizeof(pSpi ->m_chContract)-1);
	strncpy (pSpi ->m_chExchangeID, "SSE", sizeof(pSpi ->m_chExchangeID)-1);
	strncpy (pSpi ->m_chProductID, "510050", sizeof(pSpi ->m_chProductID)-1);

	// register an event handler instance
	pUserApi->RegisterSpi (pSpi);

	// subscribe private topic
	pUserApi->SubscribePrivateTopic (KSOTP_TERT_QUICK);
	pUserApi->SubscribePublicTopic (KSOTP_TERT_QUICK);

	// register the front address and port
	pUserApi->RegisterFront ("tcp://10.253.117.107:13153");

	// make the connection between client and server
	pUserApi->Init ();

	// waiting for quit event
	//WaitForSingleObject(pSpi ->m_hEvent, INFINITE);

	cout << "press return to release..." << endl;
	getchar();

	// release the API instance
	pUserApi->Release();

	cout << "press return to quit..." << endl;
	getchar();

	return 0;
}

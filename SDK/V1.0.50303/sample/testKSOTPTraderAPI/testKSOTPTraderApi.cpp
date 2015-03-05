// ������ȨOTP_APIʹ�÷���

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

// CKSOTPTraderSpi������
class CSimpleHandler : public CKSOTPTraderSpi
{

public:
	// constructor��which need a valid pointer to a CKSOTPTraderApi instance 
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

	// After receiving the login request from  the client��the server will send the following response to notify the client whether the login success or not.
	virtual void OnRspUserLogin (CKSOTPRspUserLoginField * pRspUserLogin, CKSOTPRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pRspUserLogin != NULL)
		{
			cout << "OnRspUserLogin:"
				<< "���ù�˾����:" << pRspUserLogin->BrokerID
				<< "������:" << pRspUserLogin->TradingDay
				<< "��½�ɹ�ʱ��:" << pRspUserLogin->LoginTime
				<< "�û�����:" << pRspUserLogin->UserID
				<< "����ϵͳ����" << pRspUserLogin->SystemName
				<< "ǰ�û���:" << pRspUserLogin->FrontID 
				<< "�Ự���:" << pRspUserLogin->SessionID
				<< "��󱨵�����:" << pRspUserLogin->MaxOrderRef
				<< "��֤��ʱ��:" << pRspUserLogin->SSETime << endl;
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
				<< "Ͷ���ߴ���:" << pInvestor->InvestorID
				<< "���͹�˾����:" << pInvestor->BrokerID
				<< "Ͷ��������:" << pInvestor->InvestorName
				<< "֤������:" << pInvestor->IdentifiedCardType
				<< "֤������:" << pInvestor->IdentifiedCardNo
				<< "�Ƿ��Ծ:" << pInvestor->IsActive
				<< "��ϵ�绰:" << pInvestor->Telephone
				<< "ͨѶ��ַ:" << pInvestor->Address
				<< "�ֻ�:" << pInvestor->Mobile
				<< "��������:" << pInvestor->OpenDate << endl;
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
				<< "���͹�˾����:" << pTradingAccount->BrokerID
				<< "�˺�:" << pTradingAccount->AccountID
				<< "�ϴν���׼����:" << pTradingAccount->PreBalance
				<< "�ϴ�ռ�õı�֤��:" << pTradingAccount->PreMargin
				<< "�����:" << pTradingAccount->Deposit
				<< "������:" << pTradingAccount->Withdraw
				<< "����ı�֤��:" << pTradingAccount->FrozenMargin
				<< "������ʽ�:" << pTradingAccount->FrozenCash
				<< "�����������:" << pTradingAccount->FrozenCommission
				<< "��ǰ��֤���ܶ�:" << pTradingAccount->CurrMargin
				<< "�ʽ���:" << pTradingAccount->CashIn
				<< "������:" << pTradingAccount->Commission
				<< "ƽ��ӯ��:" << pTradingAccount->CloseProfit
				<< "�ֲ�ӯ��:" << pTradingAccount->PositionProfit
				<< "֤ȯ����׼����:" << pTradingAccount->Balance
				<< "�����ʽ�:" << pTradingAccount->Available
				<< "��ȡ�ʽ�:" << pTradingAccount->WithdrawQuota
				<< "����׼����:" << pTradingAccount->Reserve
				<< "������:" << pTradingAccount->TradingDay
				<< "������:" << pTradingAccount->SettlementID
				<< "���ö��:" << pTradingAccount->Credit
				<< "��Ѻ���:" << pTradingAccount->Mortgage
				<< "��������֤��:" << pTradingAccount->ExchangeMargin
				<< "Ͷ���߽��֤��:" << pTradingAccount->DeliveryMargin
				<< "���������֤��:" << pTradingAccount->ExchangeDeliveryMargin
				<< "��Ȩƽ��ӯ��:" << pTradingAccount->CloseProfit<< endl;
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
				<< "����������:" << pExchange->ExchangeID
				<< "����������:" << pExchange->ExchangeName<< endl;
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
				<< "����������:" << pInstrument->ExchangeID
				<< "��Լ����:" << pInstrument->InstrumentID
				<< "��Լ����:" << pInstrument->InstrumentName
				<< "��Լ��������:" << pInstrument->VolumeMultiple
				<< "������:" << pInstrument->ExpireDate
				<< "��Ʒ����:" << pInstrument->ProductID
				<< "��С�䶯��λ:" << pInstrument->PriceTick << endl;
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
				<<"������:"  <<  pInvestorPositionDetail->TradingDay                                       
				<< "��������:" << pInvestorPositionDetail->OpenDate
				<< "�ɽ����:" << pInvestorPositionDetail->TradeID
				<< "Ͷ���ߴ���:" << pInvestorPositionDetail->InvestorID
				<< "����������:" << pInvestorPositionDetail->ExchangeID
				<< "������־:" << pInvestorPositionDetail->Direction
				<< "Ͷ����־:" << pInvestorPositionDetail->HedgeFlag
				<< "����:" << pInvestorPositionDetail->Volume
				<< "���ּ۸�:" << pInvestorPositionDetail->OpenPrice
				<< "Ͷ���߱�֤��:" << pInvestorPositionDetail->Margin
				<< "��������֤��:" << pInvestorPositionDetail->ExchMargin << endl;
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
			// order��s offset flag 
			ord.OffsetFlag = KS_OTP_OF_Open;
			// order��s hedge flag 
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
				<< "��������:" << pInputOrder->OrderRef << endl;
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
			<< "���:" << pOrder->SequenceNo
			<< "�ͻ���:" << pOrder->InvestorID
			<< "ί�к�:" << pOrder->OrderSysID
			<< "����������:" << pOrder->ExchangeID
			<< "��Լ��:" << pOrder->InstrumentID
			<< "����״̬:" << pOrder->OrderStatus
			<< "״̬��Ϣ:" << pOrder->StatusMsg
			<< "ί������:" << pOrder->VolumeTotalOriginal
			<< "�ɽ�����:" << pOrder->VolumeTraded
			<< "δ�ɽ�����:" << pOrder->VolumeTotal
			<< "������:" << pOrder->TradingDay
			<< "ί��ʱ��:" << pOrder->InsertTime
			<< "����ʱ��:" << pOrder->CancelTime
			<< "��������:" << pOrder->OrderType
			<< "������Դ:" << pOrder->OrderSource
			<< "�����۸�����:" << pOrder->OrderPriceType
			<< "��Ч������:" << pOrder->TimeCondition
			<< "ֹ���:" << pOrder->StopPrice
			<< "����ʱ��:" << pOrder->ActiveTime
			<< "��������:" << pOrder->OrderRef
			<< "ǰ�û���:" << pOrder->FrontID
			<< "�Ự���:" << pOrder->SessionID << endl;
	}

	// trade return
	virtual void OnRtnTrade (CKSOTPTradeField * pTrade)
	{
		cout << "OnRtnTrade:"
			<< "���:" << pTrade->SequenceNo
			<< "�ͻ���:" << pTrade->InvestorID
			<< "����������:" << pTrade->ExchangeID
			<< "ί�е���:" << pTrade->OrderSysID
			<< "��Լ����:" << pTrade->InstrumentID
			<< "�������:" << pTrade->Direction
			<< "��ƽ�ֱ��:" << pTrade->OffsetFlag
			<< "Ͷ�����:" << pTrade->HedgeFlag
			<< "�ɽ�����" << pTrade->Volume
			<< "�ɽ��۸�" << pTrade->Price
			<< "�ɽ���" << pTrade->TradeID
			<< "������" << pTrade->TradingDay
			<< "�ɽ�ʱ��" << pTrade->TradeTime
			<< "��������" << pTrade->OrderRef << endl;
	}

	// qryorder response
	virtual void OnRspQryOrder(CKSOTPOrderField *pOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if(pOrder != NULL)
		{
			cout <<  "OnRspQryOrder:"
				<<"�������:"  <<  pOrder->OrderSysID << endl;    
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
				strcpy(ord.OrderRef, pOrder->OrderRef);		// *�ش�1
				// front id
				ord.FrontID = pOrder->FrontID;				// *�ش�2
				// session id
				ord.SessionID = pOrder->SessionID;			// *�ش�3
				// exchange id
				strcpy(ord.ExchangeID, pOrder->ExchangeID);	// *�ش�4
				// action order id
				strcpy(ord.OrderSysID,pOrder->OrderSysID);	// *�м���

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
				<< "�ͻ���:" << pInputOrderAction->InvestorID
				<< "ί�к�:" << pInputOrderAction->OrderSysID
				<< "����������:" << pInputOrderAction->ExchangeID
				<< "��Լ��:" << pInputOrderAction->InstrumentID
				<< "ί�м۸�:" << pInputOrderAction->LimitPrice << endl;
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
				<< "�ͻ���:" << pTrade->InvestorID
				<< "����������:" << pTrade->ExchangeID
				<< "�������:" << pTrade->OrderSysID
				<< "��Լ����:" << pTrade->InstrumentID
				<< "�������:" << pTrade->Direction
				<< "��ƽ��־:" << pTrade->OffsetFlag
				<< "Ͷ�����:" << pTrade->HedgeFlag
				<< "�ɽ�����:" << pTrade->Volume
				<< "�ɽ��۸�:" << pTrade->Price
				<< "�ɽ���:" << pTrade->TradeID
				<< "����:" << pTrade->TradeDate
				<< "������:" <<pTrade->TradingDay
				<< "�ɽ�ʱ��:" << pTrade->TradeTime
				<< "���:" << pTrade->SequenceNo << endl;
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
				<< "�ͻ���:" << pInvestorPosition->InvestorID
				<< "�����ֲܳ�:" << pInvestorPosition->Position
				<< "�����ֲֳ�:" << pInvestorPosition->TodayPosition
				<< "�ֲֳɱ�:" << pInvestorPosition->PositionCost
				<< "���ֳɱ�:" << pInvestorPosition->OpenCost
				<< "��Լ����:" << pInvestorPosition->InstrumentID
				<< "Ͷ���ױ���־:" << pInvestorPosition->HedgeFlag
				<< "�ֲ�ӯ��:" << pInvestorPosition->PositionProfit
				<< "�ֲֶ�շ���:" << pInvestorPosition->PosiDirection
				<< "������:" << pInvestorPosition->TradingDay
				<< "ռ�õı�֤��:" << pInvestorPosition->UseMargin <<endl;
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
				<< "�ͻ���:" << pUserPasswordUpdate->UserID
				<< "�ɿ���:" << pUserPasswordUpdate->OldPassword
				<< "�¿���:" << pUserPasswordUpdate->NewPassword <<endl;
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
				<< "�ͻ���:" << pTradingAccountPasswordUpdate->AccountID
				<< "�ɿ���:" << pTradingAccountPasswordUpdate->OldPassword
				<< "�¿���:" << pTradingAccountPasswordUpdate->NewPassword <<endl;
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
				<< "Ͷ���ߴ���:" << pTradingCode->InvestorID
				<< "���͹�˾����:" << pTradingCode->BrokerID
				<< "����������:" << pTradingCode->ExchangeID
				<< "��Լ�˺�:" << pTradingCode->ClientID
				<< "�Ƿ��Ծ:" << pTradingCode->IsActive
				<< "��Լ�˺�����:" << pTradingCode->ClientIDType <<endl;
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
			// order��s offset flag 
			ord.OffsetFlag = KS_OTP_OF_Open;
			// order��s hedge flag 
			ord.HedgeFlag = KS_OTP_HF_Speculation;
			m_pUserApi->ReqExecOrderInsert(&ord, m_nRequestID++ );
		}
	}

	// nontrading orderInsert response
	virtual void OnRspExecOrderInsert(CKSOTPExecOrderField *pInputOTPOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pInputOTPOrder != NULL)
		{
			cout << "�ǽ��ױ���¼��������Ӧ:"
				<< "���ù�˾����:" << pInputOTPOrder->BrokerID
				<< "�ͻ���:" << pInputOTPOrder->InvestorID
				<< "��Լ����:" << pInputOTPOrder->InstrumentID
				<< "�ǽ��ױ�������:" << pInputOTPOrder->ExecOrderRef
				<< "�û�����:" << pInputOTPOrder->UserID
				<< "����:" << pInputOTPOrder->Volume
				<< "������:" << pInputOTPOrder->RequestID
				<< "ҵ��Ԫ:" << pInputOTPOrder->BusinessUnit
				<< "��ƽ��־:" << pInputOTPOrder->OffsetFlag
				<< "���ұ�־:" << pInputOTPOrder->HedgeFlag<< endl;
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
			<< "���ù�˾����:" << pNonTradingOrder->BrokerID
			<< "�ͻ���:" << pNonTradingOrder->InvestorID
			<< "��Լ����:" << pNonTradingOrder->InstrumentID
			<< "ִ����������:" << pNonTradingOrder->ExecOrderRef
			<< "�û�����:" << pNonTradingOrder->UserID
			<< "����:" << pNonTradingOrder->Volume
			<< "������:" << pNonTradingOrder->RequestID
			<< "ҵ��Ԫ:" << pNonTradingOrder->BusinessUnit
			<< "��ƽ��־:" << pNonTradingOrder->OffsetFlag
			<< "���ұ�־:" << pNonTradingOrder->HedgeFlag
			<< "����ִ��������:" << pNonTradingOrder->ExecOrderLocalID
			<< "����������:" << pNonTradingOrder->ExchangeID
			<< "��Ա����:" << pNonTradingOrder->ParticipantID
			<< "��Լ�˺�:" << pNonTradingOrder->ClientID
			<< "��Լ�ڽ������Ĵ���:" << pNonTradingOrder->ExchangeInstID
			<< "����������Ա����:" << pNonTradingOrder->TraderID
			<< "ִ�������ύ״̬:" << pNonTradingOrder->OrderSubmitStatus
			<< "������ʾ���:" << pNonTradingOrder->NotifySequence
			<< "������:" << pNonTradingOrder->TradingDay
			<< "������:" << pNonTradingOrder->SettlementID
			<< "ִ��������:" << pNonTradingOrder->ExecOrderSysID
			<< "��������:" << pNonTradingOrder->InsertDate
			<< "����ʱ��:" << pNonTradingOrder->InsertTime	
			<< "����ʱ��:" << pNonTradingOrder->CancelTime
			<< "�����Ա���:" << pNonTradingOrder->ClearingPartID
			<< "���:" << pNonTradingOrder->SequenceNo
			<< "ǰ�ñ��:" << pNonTradingOrder->FrontID
			<< "�Ự���:" << pNonTradingOrder->SessionID
			<< "�û��˲�Ʒ��Ϣ:" << pNonTradingOrder->UserProductInfo
			<< "״̬��Ϣ:" << pNonTradingOrder->StatusMsg
			<< "�����û�����:" << pNonTradingOrder->ActiveUserID
			<< "���͹�˾�������:" << pNonTradingOrder->BrokerExecOrderSeq << endl;

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
			<< "���ù�˾����:" << pTradingNoticeInfo->BrokerID
			<< "�ͻ���:" << pTradingNoticeInfo->InvestorID
			<< "����ʱ��:" << pTradingNoticeInfo->SendTime
			<< "��Ϣ����:" << pTradingNoticeInfo->FieldContent
			<< "����ϵ�к�:" << pTradingNoticeInfo->SequenceSeries
			<< "���к�:" << pTradingNoticeInfo->SequenceNo << endl;
	}

	// nontrading order response
	virtual void OnRspQryExecOrder(CKSOTPExecOrderField *pOTPOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (pOTPOrder != NULL)
		{
			cout << "�����ѯ�ǽ��ױ�����Ӧ:"
				<< "���ù�˾����:" << pOTPOrder->BrokerID
				<< "�ͻ���:" << pOTPOrder->InvestorID
				<< "��Լ����:" << pOTPOrder->InstrumentID
				<< "ִ����������:" << pOTPOrder->ExecOrderRef
				<< "�û�����:" << pOTPOrder->UserID
				<< "����:" << pOTPOrder->Volume
				<< "������:" << pOTPOrder->RequestID
				<< "ҵ��Ԫ:" << pOTPOrder->BusinessUnit
				<< "��ƽ��־:" << pOTPOrder->OffsetFlag
				<< "���ұ�־:" << pOTPOrder->HedgeFlag
				<< "ִ�����汨�����:" << pOTPOrder->ExecOrderLocalID
				<< "����������:" << pOTPOrder->ExchangeID
				<< "��Ա����:" << pOTPOrder->ParticipantID
				<< "��Լ�˺�:" << pOTPOrder->ClientID
				<< "��Լ�ڽ������Ĵ���:" << pOTPOrder->ExchangeInstID
				<< "����������Ա����:" << pOTPOrder->TraderID
				<< "�ǽ��ױ����ύ״̬:" << pOTPOrder->OrderSubmitStatus
				<< "������ʾ���:" << pOTPOrder->NotifySequence
				<< "������:" << pOTPOrder->TradingDay
				<< "������:" << pOTPOrder->SettlementID
				<< "ִ��������:" << pOTPOrder->ExecOrderSysID
				<< "��������:" << pOTPOrder->InsertDate
				<< "����ʱ��:" << pOTPOrder->InsertTime	
				<< "����ʱ��:" << pOTPOrder->CancelTime
				<< "�����Ա���:" << pOTPOrder->ClearingPartID
				<< "���:" << pOTPOrder->SequenceNo
				<< "ǰ�ñ��:" << pOTPOrder->FrontID
				<< "�Ự���:" << pOTPOrder->SessionID
				<< "�û��˲�Ʒ��Ϣ:" << pOTPOrder->UserProductInfo
				<< "״̬��Ϣ:" << pOTPOrder->StatusMsg
				<< "�����û�����:" << pOTPOrder->ActiveUserID
				<< "���͹�˾�������:" << pOTPOrder->BrokerExecOrderSeq << endl;
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
			cout << "ִ���������������Ӧ:"
				<< "���ù�˾����:" << pInputOTPOrderAction->BrokerID
				<< "�ͻ���:" << pInputOTPOrderAction->InvestorID
				<< "ִ����������:" << pInputOTPOrderAction->ExecOrderRef
				<< "������:" << pInputOTPOrderAction->RequestID
				<< "ǰ�ñ��:" << pInputOTPOrderAction->FrontID
				<< "�Ự���:" << pInputOTPOrderAction->SessionID
				<< "����������:" << pInputOTPOrderAction->ExchangeID
				<< "��Լ����:" << pInputOTPOrderAction->InstrumentID
				<< "�����û�:" << pInputOTPOrderAction->UserID
				<< "ִ������������:" << pInputOTPOrderAction->ExecOrderSysID
				<< "������־:" << pInputOTPOrderAction->ActionFlag
				<< "�û������û�����:" << pInputOTPOrderAction->UserID << endl;
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
			cout << "��ѯ�ǽ��ױ�������Ӧ:"
				<< "���ù�˾����:" << pOTPOrderVolume->BrokerID
				<< "�ͻ���:" << pOTPOrderVolume->InvestorID
				<< "��Լ����:" << pOTPOrderVolume->InstrumentID
				<< "���ұ�־:" << pOTPOrderVolume->HedgeFlag
				<< "������ִ����:" << pOTPOrderVolume->ExecVolume
				<< "������ִ����:" << pOTPOrderVolume->ExecedVolume << endl;
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
			cout << "�����ѯ������Ȩ����������Ӧ:"
				<< "��Լ����:" << pOTPInsMarginRate->InstrumentID
				<< "Ӫҵ������:" << pOTPInsMarginRate->BrokerID
				<< "Ͷ���ߴ���:" << pOTPInsMarginRate->InvestorID
				<< "������������:" << pOTPInsMarginRate->OpenRatioByMoney
				<< "����������:" << pOTPInsMarginRate->OpenRatioByVolume
				<< "ƽ����������:" << pOTPInsMarginRate->CloseRatioByMoney
				<< "ƽ��������:" << pOTPInsMarginRate->CloseRatioByVolume
				<< "ִ����������:" << pOTPInsMarginRate->StrikeRatioByMoney
				<< "ִ��������:" << pOTPInsMarginRate->StrikeRatioByVolume<< endl;
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
			cout << "��ѯ������Ȩ��֤����������Ӧ:"
				<< "��Լ����:" << pInstrumentMarginRate->InstrumentID
				<< "Ӫҵ������:" << pInstrumentMarginRate->BrokerID
				<< "Ͷ���ߴ���:" << pInstrumentMarginRate->InvestorID << endl;
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
			cout << "��ѯ���ȯ��Ϣ��Ӧ:"
				<< "���ù�˾����:" << pUnderlyingStockInfo->BrokerID
				<< "����������:" << pUnderlyingStockInfo->ExchangeID
				<< "��Ʒ����:" << pUnderlyingStockInfo->ProductID
				<< "������:" << pUnderlyingStockInfo->PreClosePrice << endl;
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
				<< "Ͷ���ߴ���:" << pUserLogout->UserID << endl;
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

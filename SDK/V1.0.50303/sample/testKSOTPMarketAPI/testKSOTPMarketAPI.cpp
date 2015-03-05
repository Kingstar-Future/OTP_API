// testKSMarketDataAPI.cpp : Defines the entry point for the console application.
//



#include "stdio.h"
#include <iostream>
#include "KSOTPMdApi.h"


#ifdef WIN32
#include "windows.h"
#pragma comment(lib, "../../sdk/win32/ksotpmarketdataapi.lib")
#pragma message("Automatically linking with ksotpmarketdataapi.lib")
#else
#include<unistd.h>
#include<string.h>
#endif

using namespace std;
using namespace KingstarAPI;


// CKSOTPMdSpi派生类
class CSimpleHandler : public CKSOTPMdSpi
{

public:
	// constructor，which need a valid pointer to a CKSOTPMdApi instance 
	CSimpleHandler (CKSOTPMdApi * pUserApi)
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
	// get trading day
		printf("获取当前交易日 = %s\n",m_pUserApi->GetTradingDay());

		// 行情订阅列表
		char *ppInstrumentID[] = {"90000021"};
		// 行情订阅个数
		int iInstrumentID = 1;
        // 	订阅
		m_pUserApi->SubscribeMarketData(ppInstrumentID, iInstrumentID);
        // 释放内存
        //delete ppInstrumentID[0];
	}

	///RspSubMarketData return
	virtual void OnRspSubMarketData(CKSOTPSpecificInstrumentField *pSpecificInstrument, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		printf("OnRspSubMarketData:%s\n", pSpecificInstrument->InstrumentID);
		printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);

		if (bIsLast == true)
		{
			// 行情退订列表
			char *ppInstrumentID[] = {"90000021"};			
			// 行情退订个数
			int iInstrumentID = 1;
			m_pUserApi->UnSubscribeMarketData(ppInstrumentID,iInstrumentID);
		}

	}


	///OnRspUnSubMarketData return
	virtual void OnRspUnSubMarketData(CKSOTPSpecificInstrumentField *pSpecificInstrument, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		printf("OnRspUnSubMarketData:\n");
		printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);

		// logout
		CKSOTPUserLogoutField UserLogout;
		memset(&UserLogout, 0, sizeof(UserLogout));
		// broker id 
		strcpy(UserLogout.BrokerID, m_chBrokerID); 
		// investor ID 
		strcpy(UserLogout.UserID, m_chUserID);
		
		m_pUserApi->ReqUserLogout(&UserLogout,3);
	}

	///OnRtnDepthMarketData
	virtual void OnRtnDepthMarketData(CKSOTPDepthMarketDataField *pDepthMarketData)
	{
        printf("OnRtnDepthMarketData:");
        if(pDepthMarketData != NULL)
        {
            printf("%s|%s|%.04f|%.04f|%.04f|%.04f|%.04f|%d|%.04f|%.04f|%.04f|%d|%d|%.04f|%.04f|%.04f|%.04f|%.04f|%s|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|",
                pDepthMarketData->ExchangeID,					// 交易所代码
                pDepthMarketData->InstrumentID,					// 合约代码
                pDepthMarketData->PreClosePrice,				// 昨收盘
                pDepthMarketData->OpenPrice,					// 今开盘
                pDepthMarketData->HighestPrice,					// 最高价
                pDepthMarketData->LowestPrice,					// 最低价
                pDepthMarketData->LastPrice,					// 最新价
                pDepthMarketData->Volume,						// 数量
                pDepthMarketData->Turnover,						// 成交金额
                pDepthMarketData->BidPrice1,					// 申买价一
                pDepthMarketData->AskPrice1,					// 申卖价一
                pDepthMarketData->BidVolume1,					// 申买量一
                pDepthMarketData->AskVolume1,					// 申卖量一
                pDepthMarketData->UpperLimitPrice,				// 涨停板价
                pDepthMarketData->LowerLimitPrice,				// 跌停板价
                pDepthMarketData->PreSettlementPrice,			// 上次结算价
                pDepthMarketData->SettlementPrice,				// 本次结算价
                pDepthMarketData->OpenInterest,					// 持仓量
                pDepthMarketData->TradingDay,					// 交易日
                pDepthMarketData->BidVolume2,					// 申买量二
                pDepthMarketData->BidPrice2,					// 申买价二
                pDepthMarketData->BidVolume3,					// 申买量三
                pDepthMarketData->BidPrice3,					// 申买价三
                pDepthMarketData->BidVolume4,					// 申买量四
                pDepthMarketData->BidPrice4,					// 申买价四
                pDepthMarketData->BidVolume5,					// 申买量五
                pDepthMarketData->BidPrice5,					// 申买价五
                pDepthMarketData->AskVolume2,					// 申卖量二
                pDepthMarketData->AskPrice2,					// 申卖价二
                pDepthMarketData->AskVolume3,					// 申卖量三
                pDepthMarketData->AskPrice3,					// 申卖价三
                pDepthMarketData->AskVolume4,					// 申卖量四
                pDepthMarketData->AskPrice4,					// 申卖价四
                pDepthMarketData->AskVolume5,					// 申卖量五
                pDepthMarketData->AskPrice5						// 申卖价五
                );
        }
        printf("\n");
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

private:
	// a pointer of CKSOTPMdApi instance
	CKSOTPMdApi * m_pUserApi;
};


int main ()
{
	// create a CKSOTPMdApi instance
	CKSOTPMdApi *pUserApi = CKSOTPMdApi::CreateOTPMdApi ("log");

	// create an event handler instance
	CSimpleHandler *pSpi = new CSimpleHandler (pUserApi);

	// set spi's broker, user, password
	strncpy (pSpi ->m_chBrokerID, "", sizeof(pSpi ->m_chBrokerID)-1);
	strncpy (pSpi ->m_chContract, "90000021", sizeof(pSpi ->m_chContract)-1);
	strncpy (pSpi ->m_chExchangeID, "SSE", sizeof(pSpi ->m_chExchangeID)-1);
	strncpy (pSpi ->m_chProductID, "510050", sizeof(pSpi ->m_chProductID)-1);
		strncpy (pSpi ->m_chUserID, "80008", sizeof(pSpi ->m_chUserID)-1);
	strncpy (pSpi ->m_chPassword, "123456", sizeof(pSpi ->m_chPassword)-1);

	// register an event handler instance
	pUserApi->RegisterSpi (pSpi);

	// register the front address and port
	//pUserApi->RegisterFront ("tcp://10.253.43.40:17993");
	pUserApi->RegisterFront ("tcp://10.253.117.107:13163");

	// make the connection between client and server
	pUserApi->Init ();

	cout << "press return to release..." << endl;
	getchar();

	// release the API instance
	pUserApi->Release();

	cout << "press return to quit..." << endl;
	getchar();

	return 0;
}
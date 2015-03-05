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


// CKSOTPMdSpi������
class CSimpleHandler : public CKSOTPMdSpi
{

public:
	// constructor��which need a valid pointer to a CKSOTPMdApi instance 
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
	// get trading day
		printf("��ȡ��ǰ������ = %s\n",m_pUserApi->GetTradingDay());

		// ���鶩���б�
		char *ppInstrumentID[] = {"90000021"};
		// ���鶩�ĸ���
		int iInstrumentID = 1;
        // 	����
		m_pUserApi->SubscribeMarketData(ppInstrumentID, iInstrumentID);
        // �ͷ��ڴ�
        //delete ppInstrumentID[0];
	}

	///RspSubMarketData return
	virtual void OnRspSubMarketData(CKSOTPSpecificInstrumentField *pSpecificInstrument, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		printf("OnRspSubMarketData:%s\n", pSpecificInstrument->InstrumentID);
		printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);

		if (bIsLast == true)
		{
			// �����˶��б�
			char *ppInstrumentID[] = {"90000021"};			
			// �����˶�����
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
                pDepthMarketData->ExchangeID,					// ����������
                pDepthMarketData->InstrumentID,					// ��Լ����
                pDepthMarketData->PreClosePrice,				// ������
                pDepthMarketData->OpenPrice,					// ����
                pDepthMarketData->HighestPrice,					// ��߼�
                pDepthMarketData->LowestPrice,					// ��ͼ�
                pDepthMarketData->LastPrice,					// ���¼�
                pDepthMarketData->Volume,						// ����
                pDepthMarketData->Turnover,						// �ɽ����
                pDepthMarketData->BidPrice1,					// �����һ
                pDepthMarketData->AskPrice1,					// ������һ
                pDepthMarketData->BidVolume1,					// ������һ
                pDepthMarketData->AskVolume1,					// ������һ
                pDepthMarketData->UpperLimitPrice,				// ��ͣ���
                pDepthMarketData->LowerLimitPrice,				// ��ͣ���
                pDepthMarketData->PreSettlementPrice,			// �ϴν����
                pDepthMarketData->SettlementPrice,				// ���ν����
                pDepthMarketData->OpenInterest,					// �ֲ���
                pDepthMarketData->TradingDay,					// ������
                pDepthMarketData->BidVolume2,					// ��������
                pDepthMarketData->BidPrice2,					// ����۶�
                pDepthMarketData->BidVolume3,					// ��������
                pDepthMarketData->BidPrice3,					// �������
                pDepthMarketData->BidVolume4,					// ��������
                pDepthMarketData->BidPrice4,					// �������
                pDepthMarketData->BidVolume5,					// ��������
                pDepthMarketData->BidPrice5,					// �������
                pDepthMarketData->AskVolume2,					// ��������
                pDepthMarketData->AskPrice2,					// �����۶�
                pDepthMarketData->AskVolume3,					// ��������
                pDepthMarketData->AskPrice3,					// ��������
                pDepthMarketData->AskVolume4,					// ��������
                pDepthMarketData->AskPrice4,					// ��������
                pDepthMarketData->AskVolume5,					// ��������
                pDepthMarketData->AskPrice5						// ��������
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
				<< "Ͷ���ߴ���:" << pUserLogout->UserID << endl;
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
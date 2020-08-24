//---------------------------------------------------------------------------

#pragma hdrstop

#include "UdpSocketThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)





__fastcall CUdpSocketThread::CUdpSocketThread(SOCKET *p_sock) {
	m_eThreadWork = THREAD_STOP;
	Priority = tpTimeCritical;
	m_sock = p_sock;
	isTryingToConnect = true;
	isConnected = false;
	//memset(&recvData, 0, sizeof(recvData));
}
//---------------------------------------------------------------------------

__fastcall CUdpSocketThread::~CUdpSocketThread() {
	UnicodeString tempStr = L"Thread Terminated (from Thread Destroyer)";
	SendMessage(FormMain->Handle, MSG_LOG_FROM_THREAD, (unsigned int)&tempStr, 0x10);
}
//---------------------------------------------------------------------------

void __fastcall CUdpSocketThread::Execute() {

	// Common
	UnicodeString t_Str = L"";
	AnsiString t_AnsiStr = "";
	int t_errno = 0;
	int t_ConnectTryingCount = 1;
	int t_ReceivedSize = 0;

	struct sockaddr_in	t_sockaddr_in;
	struct sockaddr_in t_from_addr;
	int t_fromaddrsize = sizeof(t_from_addr);
	memset(&t_sockaddr_in, 0, sizeof(t_sockaddr_in));
	t_sockaddr_in.sin_family = AF_INET;
	t_sockaddr_in.sin_addr.s_addr = inet_addr(IP_LOCAL);
	t_sockaddr_in.sin_port = htons(UDP_SERVER_PORT);

	t_Str = L"Thread Start";
	SendMessage(FormMain->Handle, MSG_LOG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
	m_eThreadWork = THREAD_RUNNING;

	BYTE t_Buffer[1500] = {0, };

	if(bind(*m_sock, (struct sockaddr*)&t_sockaddr_in, sizeof(t_sockaddr_in)) < 0) {
		t_Str = L"Bind Error";
		SendMessage(FormMain->Handle, MSG_LOG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
		return;
	}

	while(!Terminated) {
		// For Thread Stop & Resume
		if(m_eThreadWork != THREAD_RUNNING) {
			if(m_eThreadWork == THREAD_TERMINATED) return;
			WaitForSingleObject((void*)this->Handle, 500);
			continue;
		}

		t_ReceivedSize = recvfrom(*m_sock, t_Buffer, 1500, 0, (struct sockaddr*)&t_from_addr, &t_fromaddrsize);
		t_Str.sprintf(L"[RECV] Size : %d", t_ReceivedSize);
		SendMessage(FormMain->Handle, MSG_LOG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
	}

	return;
}














void __fastcall CUdpSocketThread::Stop() {
	m_eThreadWork = THREAD_STOP;
}
//---------------------------------------------------------------------------

void __fastcall CUdpSocketThread::Resume() {
	m_eThreadWork = THREAD_RUNNING;
}
//---------------------------------------------------------------------------

void __fastcall CUdpSocketThread::DoTerminate() {
	m_eThreadWork = THREAD_TERMINATED;
}
//---------------------------------------------------------------------------

ThreadWorkingType __fastcall CUdpSocketThread::GetThreadStatus() {
	return m_eThreadWork;
}
//---------------------------------------------------------------------------
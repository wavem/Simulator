//---------------------------------------------------------------------------

#pragma hdrstop

#include "UdpSocketThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
















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
#include "StdAfx.h"
#include "GetMsgInfo.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

GetMsgInfo::GetMsgInfo(void)
{
	printf("GetMsgInfo\n");
}


GetMsgInfo::~GetMsgInfo(void)
{
	printf("~GetMsgInfo\n");
}

void GetMsgInfo::Test()
{
	printf("test\n");
	GetCpuType();
}

void GetMsgInfo::GetCpuType()
{
	//获得CPU型号
    SYSTEM_INFO systemInfo;
	GetSystemInfo (&systemInfo);
	cout << "处理器掩码: " << systemInfo.dwActiveProcessorMask << endl
		 << "处理器个数: " << systemInfo.dwNumberOfProcessors << endl
		 << "处理器分页大小: " << systemInfo.dwPageSize << endl
		 << "处理器类型: " << systemInfo.dwProcessorType << endl
		 << "最大寻址单元: " << systemInfo.lpMaximumApplicationAddress << endl
		 << "最小寻址单元: " << systemInfo.lpMinimumApplicationAddress << endl
		 << "处理器等级: " << systemInfo.wProcessorLevel << endl
		 << "处理器版本: " << systemInfo.wProcessorRevision << endl;
	cout << "---------------------------------------------------"<<endl;

	MEMORYSTATUS memory;
	memory.dwLength =sizeof(memory); //初始化
	GlobalMemoryStatus(&memory);
	cout << "您的物理内存是(Mb):"<<(int)(memory.dwTotalPhys /1024/1024)<<endl;
	cout << "其中可用内存是(Kb):"<<(int)( memory.dwAvailPhys /1024)<<endl;

}


// KeyClick.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKeyClickApp: 
// �йش����ʵ�֣������ KeyClick.cpp
//

class CKeyClickApp : public CWinApp
{
public:
	CKeyClickApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CKeyClickApp theApp;

struct DoMainStruct
{
	WORD VirtualKeyCode = 0, fsModifiers = 0;//����
	CListBox cListBox;
}Domain;


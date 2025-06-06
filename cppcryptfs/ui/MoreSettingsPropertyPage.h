#pragma once

/*
cppcryptfs : user-mode cryptographic virtual overlay filesystem.

Copyright (C) 2016-2025 Bailey Brown (github.com/bailey27/cppcryptfs)

cppcryptfs is based on the design of gocryptfs (github.com/rfjakob/gocryptfs)

The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "CryptPropertyPage.h"
#include "CryptSetting.h"
#include <memory>
#include <unordered_map>

// CMoreSettingsPropertyPage dialog

class CMoreSettingsPropertyPage : public CCryptPropertyPage
{
	DECLARE_DYNAMIC(CMoreSettingsPropertyPage)

public:
	CMoreSettingsPropertyPage();   // standard constructor
	virtual ~CMoreSettingsPropertyPage();

	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MORESETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	std::unordered_map<int, std::unique_ptr<CryptSetting>> m_controls;
	void SetControlChanged(int id);
	void SetControls(CryptSetting::SetType set_type);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedExfat();
	virtual BOOL OnInitDialog();


	
public:
	afx_msg void OnClickedDefaults();
	afx_msg void OnClickedRecommended();
	afx_msg void OnClickedFat32();
	afx_msg void OnClickedNtfs();
	afx_msg void OnClickedNotntfs();
	afx_msg void OnClickedNosparsefiles();
};

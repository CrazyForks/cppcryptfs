/*
cppcryptfs : user-mode cryptographic virtual overlay filesystem.

Copyright (C) 2016-2021 Bailey Brown (github.com/bailey27/cppcryptfs)

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

#include "stdafx.h"
#include "CryptSetting.h"


CryptSetting::CryptSetting(CCryptPropertyPage& dlg, int id, const WCHAR* section, const WCHAR* setting, int default, int recommended)
	: m_dlg(dlg), m_id(id), m_section(section), m_setting(setting), m_default(default), m_recommended(recommended)
{
	m_current = theApp.GetProfileInt(section, setting, default);
}

void CryptCheckBoxSetting::Set(SetType set_type, bool save)
{
	auto val = m_current;

	switch (set_type) {
	case SetType::Current:
		val = m_current;
		break;
	case SetType::Default:
		val = m_default;
		break;
	case SetType::Recommended:
		val = m_recommended;
		break;
	case SetType::Changed:
		val = !m_current;
		break;
	}

	m_current = val;

	m_dlg.CheckDlgButton(m_id, val ? 1 : 0);

	if (save)
		theApp.WriteProfileInt(m_section, m_setting, val);
	
}
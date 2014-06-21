#include "wx_pch.h"
#include "NewPanel.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(NewPanel)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(NewPanel)
//*)

//(*IdInit(NewPanel)
//*)

BEGIN_EVENT_TABLE(NewPanel,wxPanel)
	//(*EventTable(NewPanel)
	//*)
END_EVENT_TABLE()

NewPanel::NewPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(NewPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

NewPanel::~NewPanel()
{
	//(*Destroy(NewPanel)
	//*)
}


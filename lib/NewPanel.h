#ifndef NEWPANEL_H
#define NEWPANEL_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(NewPanel)
	#include <wx/panel.h>
	//*)
#endif
//(*Headers(NewPanel)
//*)

class NewPanel: public wxPanel
{
	public:

		NewPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~NewPanel();

		//(*Declarations(NewPanel)
		//*)

	protected:

		//(*Identifiers(NewPanel)
		//*)

	private:

		//(*Handlers(NewPanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

#ifndef NEWPLANETDIALOG_H
#define NEWPLANETDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(NewPlanetDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/choice.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(NewPlanetDialog)
//*)

#include <wx/cmndata.h>
#include <wx/colordlg.h>

class NewPlanetDialog: public wxDialog
{
	public:

		NewPlanetDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~NewPlanetDialog();

		//(*Declarations(NewPlanetDialog)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxTextCtrl* VzTextCtrl;
		wxTextCtrl* NameTxtCtrl;
		wxChoice* ColourChoice;
		wxTextCtrl* ZTextCtrl;
		wxTextCtrl* VxTextCtrl;
		wxChoice* SizeChoice;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxButton* Button1;
		wxTextCtrl* XTextCtrl;
		wxStaticText* StaticText6;
		wxTextCtrl* YTextCtrl;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxTextCtrl* MassTextCtrl;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* VyTextCtrl;
		wxStaticText* StaticText15;
		wxStaticText* StaticText12;
		wxStaticText* StaticText17;
		wxStaticText* StaticText4;
		wxStaticText* StaticText16;
		//*)

		void SetColourData(wxColourData* CustomColourData);

		// Colour Dialog Data
		wxColourData* ColourDlgData;
		wxColourDialog* ColourDlg;

	protected:

		//(*Identifiers(NewPlanetDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT13;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT14;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT16;
		static const long ID_TEXTCTRL8;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT11;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT12;
		//*)

	private:

		//(*Handlers(NewPlanetDialog)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnColourChoiceSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

#ifndef IMPORTPLANETDIALOG_H
#define IMPORTPLANETDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(ImportPlanetDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/choice.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(ImportPlanetDialog)
//*)

#include <wx/cmndata.h>
#include <wx/colordlg.h>



class ImportPlanetDialog: public wxDialog
{
	public:

		ImportPlanetDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ImportPlanetDialog();

		//(*Declarations(ImportPlanetDialog)
		wxTextCtrl* NameTextCtrl;
		wxTextCtrl* EphemeridesTextCtrl;
		wxChoice* ColourChoice;
		wxChoice* SizeChoice;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxTextCtrl* MassTextCtrl;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText4;
		//*)

        void SetColourData(wxColourData* CustomColourData);

		// Colour Dialog Data
		wxColourData* ColourDlgData;
		wxColourDialog* ColourDlg;

		// Planet parameters
        double x, y, z, vX, vY, vZ, mass;

	protected:

		//(*Identifiers(ImportPlanetDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT3;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ImportPlanetDialog)
		void OnInit(wxInitDialogEvent& event);
		void OnColourChoiceSelect(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

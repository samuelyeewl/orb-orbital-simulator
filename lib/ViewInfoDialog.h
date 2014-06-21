#ifndef VIEWINFODIALOG_H
#define VIEWINFODIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(ViewInfoDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/checkbox.h>
	#include <wx/panel.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/timer.h>
	//*)
#endif
//(*Headers(ViewInfoDialog)
//*)

#include "Planet.h"

class ViewInfoDialog: public wxDialog
{
	public:

		ViewInfoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ViewInfoDialog();

		//(*Declarations(ViewInfoDialog)
		wxStaticText* StaticText10;
		wxCheckBox* SpeedCheckBox;
		wxStaticText* StaticText9;
		wxStaticText* StaticText20;
		wxStaticText* AccelStaticText;
		wxStaticText* StaticText2;
		wxStaticText* GPEStaticText;
		wxStaticText* StaticText14;
		wxStaticText* StaticText6;
		wxStaticText* AccelZStaticText;
		wxStaticText* DistanceStaticText;
		wxStaticText* StaticText19;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxStaticText* StaticText18;
		wxStaticText* MassStaticText;
		wxStaticText* RevStaticText;
		wxCheckBox* vZCheckBox;
		wxPanel* Panel1;
		wxCheckBox* vYCheckBox;
		wxStaticText* StaticText1;
		wxStaticText* AccelXStaticText;
		wxStaticText* StaticText3;
		wxCheckBox* vXCheckBox;
		wxCheckBox* XCheckBox;
		wxStaticText* StaticText21;
		wxCheckBox* KECheckBox;
		wxCheckBox* DistanceCheckBox;
		wxButton* ExportButton;
		wxStaticText* NameStaticText;
		wxCheckBox* TECheckBox;
		wxStaticText* BlankStaticText2;
		wxStaticText* SpeedStaticText;
		wxCheckBox* ZCheckBox;
		wxStaticText* vYStaticText;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* vZStaticText;
		wxCheckBox* GPECheckBox;
		wxStaticText* TEStaticText;
		wxStaticText* AccelYStaticText;
		wxStaticText* StaticText15;
		wxStaticText* StaticText12;
		wxStaticText* XStaticText;
		wxTimer InfoCalcTimer;
		wxPanel* ColourPanel;
		wxButton* ShowMoreButton;
		wxStaticText* ZStaticText;
		wxCheckBox* YCheckBox;
		wxStaticText* StaticText17;
		wxStaticText* StaticText4;
		wxCheckBox* AccelZCheckBox;
		wxStaticText* PeriodStaticText;
		wxStaticText* BlankStaticText;
		wxCheckBox* AccelXCheckBox;
		wxStaticText* vXStaticText;
		wxStaticText* StaticText16;
		wxStaticText* KEStaticText;
		wxButton* OpenGraphButton;
		wxStaticText* YStaticText;
		wxCheckBox* AccelYCheckBox;
		wxCheckBox* AccelCheckBox;
		//*)

        wxBoxSizer* BoxSizer4;
        wxStaticBoxSizer* StaticBoxSizer2;
        wxFlexGridSizer* FlexGridSizer3;
        wxFlexGridSizer* FlexGridSizer2;
        wxBoxSizer* BoxSizer2;
        wxStaticBoxSizer* StaticBoxSizer3;
        wxBoxSizer* BoxSizer1;
        wxStaticBoxSizer* StaticBoxSizer1;
        wxFlexGridSizer* FlexGridSizer1;
        wxBoxSizer* BoxSizer3;

        /** \brief Sets the planet whose info is being viewed. Must be called to initialize dialog properly
         * \param Pointer to planet. If NULL, dialog will close.
         */
		void SetPlanet(Planet* PlanetPtr);

        /** \brief Hides the Advanced Panel
         * \return Returns true if successful
         */
        bool HideAdvancedPanel();

        /** \brief Shows the Advanced Panel
         * \return Returns true if successful
         */
        bool ShowAdvancedPanel();



	protected:

		//(*Identifiers(ViewInfoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_PANEL2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_CHECKBOX3;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT17;
		static const long ID_CHECKBOX4;
		static const long ID_STATICTEXT18;
		static const long ID_STATICTEXT19;
		static const long ID_CHECKBOX5;
		static const long ID_STATICTEXT20;
		static const long ID_STATICTEXT21;
		static const long ID_CHECKBOX6;
		static const long ID_STATICTEXT22;
		static const long ID_STATICTEXT23;
		static const long ID_CHECKBOX7;
		static const long ID_STATICTEXT24;
		static const long ID_STATICTEXT25;
		static const long ID_CHECKBOX8;
		static const long ID_STATICTEXT26;
		static const long ID_STATICTEXT27;
		static const long ID_CHECKBOX9;
		static const long ID_STATICTEXT28;
		static const long ID_STATICTEXT29;
		static const long ID_CHECKBOX10;
		static const long ID_STATICTEXT30;
		static const long ID_STATICTEXT31;
		static const long ID_CHECKBOX11;
		static const long ID_STATICTEXT32;
		static const long ID_STATICTEXT33;
		static const long ID_CHECKBOX12;
		static const long ID_STATICTEXT34;
		static const long ID_STATICTEXT35;
		static const long ID_CHECKBOX13;
		static const long ID_STATICTEXT36;
		static const long ID_STATICTEXT37;
		static const long ID_CHECKBOX14;
		static const long ID_STATICTEXT38;
		static const long ID_STATICTEXT39;
		static const long ID_CHECKBOX15;
		static const long ID_STATICTEXT40;
		static const long ID_STATICTEXT41;
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(ViewInfoDialog)
		void OnKeyDown(wxKeyEvent& event);
		void OnInfoCalcTimerTrigger(wxTimerEvent& event);
		void OnShowMoreButtonClick(wxCommandEvent& event);
		//*)

        /** \brief Recursively sets keydown events to parent control
         */
        void connectKeyDownEvent(wxWindow* pclComponent);

        /** \brief Initializes features of dialog
         */
		void InitializeDialog();

		/**< Pointer to planet being examined */
		Planet* MyPlanet;

		/**< Whether the advanced information is shown */
		bool AdvancedShown;

		DECLARE_EVENT_TABLE()
};

#endif

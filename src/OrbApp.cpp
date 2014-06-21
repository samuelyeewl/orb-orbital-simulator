/***************************************************************
 * Name:      OrbApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Samuel Yee (samuelyeewl@gmail.com)
 * Created:   2011-11-10
 * Copyright: Samuel Yee ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "OrbApp.h"

//(*AppHeaders
#include "OrbMain.h"
#include <wx/image.h>
//*)

#include <wx/cmdline.h>

IMPLEMENT_APP(OrbApp);

bool OrbApp::OnInit()
{
    OrbFrame* Frame;
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Frame = new OrbFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)

    // Process command line arguments
    wxCmdLineEntryDesc CmdEntryDesc[] = {
        { wxCMD_LINE_PARAM,
            NULL, NULL, "File to be opened",
            wxCMD_LINE_VAL_STRING,
            wxCMD_LINE_PARAM_OPTIONAL
        },

        { wxCMD_LINE_NONE }
    };

    wxCmdLineParser parser(CmdEntryDesc, argc, argv);

    parser.Parse();
    if (parser.GetParamCount() == 0) {

    } else {
        wxString Filename = parser.GetParam(0);
        Frame->OpenOrbFile(Filename);
    }
    // End of processing arguments

    return wxsOK;

}

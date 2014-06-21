#include "wx_pch.h"
#include "GraphPane.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(GraphPane)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(GraphPane)
//*)

#include <vector>
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>

//(*IdInit(GraphPane)
//*)

BEGIN_EVENT_TABLE(GraphPane,wxPanel)
	//(*EventTable(GraphPane)
	//*)

	EVT_PAINT(GraphPane::OnPaintEvent)
	EVT_ERASE_BACKGROUND(GraphPane::OnEraseEvent)
	EVT_SIZE(GraphPane::OnResizeEvent)
END_EVENT_TABLE()

GraphPane::GraphPane(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, wxWindow* parentFrame)
{
	//(*Initialize(GraphPane)
	Create(parent, id, wxDefaultPosition, wxSize(500,500), wxTAB_TRAVERSAL, _T("id"));
	SetMinSize(wxSize(500,500));
	SetBackgroundColour(wxColour(255,255,255));
	//*)

	BlackBG = false;
	NewPoints = 0;
}

GraphPane::~GraphPane()
{
	//(*Destroy(GraphPane)
	//*)
}

void GraphPane::SetGraphInfoAddress(std::vector<GraphInfo*>* GraphAddress)
{
    GraphInfoVector = GraphAddress;
}

void GraphPane::InvertColours()
{
    BlackBG = (BlackBG ? false : true);
}

void GraphPane::OnResizeEvent(wxSizeEvent& evt)
{
    this->Refresh();
    evt.Skip();
}

void GraphPane::OnPaintEvent(wxPaintEvent& evt)
{
    wxBufferedPaintDC dc(this);
    FullRefresh(dc);
}

void GraphPane::CalculateScale(double MaxXExtent, double MaxYExtent)
{
    wxCoord width, height;
    this->GetSize(&width, &height);

    CalculateScale(MaxXExtent, MaxYExtent, width, height);
}

void GraphPane::CalculateScale(double MaxXExtent, double MaxYExtent, wxCoord width, wxCoord height)
{
    double tempfactor;

    if (MaxXExtent != 0) {
        ScalingFactor = width / MaxXExtent;
    }
    if (MaxYExtent != 0) {
        tempfactor = height / MaxYExtent;
        if (tempfactor < ScalingFactor) {
            ScalingFactor = tempfactor;
        }
    }
}

void GraphPane::FullRefresh(wxDC& dc)
{
    // Erase Background
    wxCoord width, height;
    this->GetSize(&width, &height);

    dc.SetPen((BlackBG ? *wxBLACK_PEN : *wxWHITE_PEN));
    dc.SetBrush(BlackBG ? *wxBLACK_BRUSH : *wxWHITE_BRUSH);
    dc.DrawRectangle(0, 0, width, height);

    // Set the origin at the centre
    dc.SetDeviceOrigin(wxCoord(width/2), wxCoord(height/2));


    wxPen pen((BlackBG ? *wxWHITE : *wxBLACK), 1);
    wxBrush brush((BlackBG ? *wxBLACK_BRUSH : *wxWHITE_BRUSH));
    dc.SetPen(pen);

    if (GraphInfoVector != NULL && !(GraphInfoVector->empty())) {

        // Declare iterators for each set of coordinates --> Loop through all trails/sets of coordinates
        std::vector<GraphInfo*>::const_iterator CoordSetIt;

        // Declare iterators for each trail
        std::deque<double>::const_iterator XCoordIt;
        std::deque<double>::const_iterator YCoordIt;

        //Begin iterating
        CoordSetIt = GraphInfoVector->begin();

        while (CoordSetIt != GraphInfoVector->end()) {
            // Set Colour
            if ((*CoordSetIt)->TrailColour == *wxBLACK && BlackBG) {
                    pen = wxPen(*wxWHITE, 1);
            } else {
                    pen = wxPen((*CoordSetIt)->TrailColour, 1);
            }
            dc.SetPen(pen);

            // Iterate through all coordinates
            if ((*CoordSetIt)->XCoordinate.size() > unsigned(NewPoints)) {
                XCoordIt = (*CoordSetIt)->XCoordinate.begin() + NewPoints - 1;
                YCoordIt = (*CoordSetIt)->YCoordinate.begin() + NewPoints - 1;
            }
            else {
                XCoordIt = (*CoordSetIt)->XCoordinate.begin();
                YCoordIt = (*CoordSetIt)->YCoordinate.begin();
            }


            while (XCoordIt != (*CoordSetIt)->XCoordinate.end()) {
                dc.DrawPoint(wxCoord((*XCoordIt) * ScalingFactor), wxCoord((*YCoordIt) * ScalingFactor* (-1)));
                XCoordIt++;
                YCoordIt++;
            }


            // If terminator size > 0, draw circle terminator at last coordinate.
            if ((*CoordSetIt)->TermSize > 0) {
                XCoordIt--;
                YCoordIt--;

                if ((*CoordSetIt)->TrailColour == *wxBLACK && BlackBG) {
                    brush.SetColour(*wxWHITE);
                } else {
                    brush.SetColour((*CoordSetIt)->TrailColour);
                }
                dc.SetBrush(brush);
                dc.DrawEllipse(wxCoord((*XCoordIt) * ScalingFactor - (*CoordSetIt)->TermSize),
                               wxCoord((*YCoordIt) * ScalingFactor* (-1) - (*CoordSetIt)->TermSize),
                               (*CoordSetIt)->TermSize * 2, (*CoordSetIt)->TermSize * 2);
            }

            ++CoordSetIt;
        }
    }
}

void GraphPane::PartialRefresh()
{
    wxClientDC dc(this);

    wxCoord width, height;
    this->GetSize(&width, &height);

    // Set the origin at the centre
    dc.SetDeviceOrigin(wxCoord(width/2), wxCoord(height/2));

    if (GraphInfoVector != NULL & !GraphInfoVector->empty()) {
        // Declare iterators for each set of coordinates --> Loop through all trails/sets of coordinates
        std::vector<GraphInfo*>::const_iterator CoordSetIt;

        // Declare iterators for each trail
        std::deque<double>::const_iterator XCoordIt;
        std::deque<double>::const_iterator YCoordIt;

        //Begin iterating
        CoordSetIt = GraphInfoVector->begin();

        wxPen BGPen = wxPen(BlackBG ? *wxBLACK : *wxWHITE, 1);
        wxBrush BGBrush = wxBrush(BlackBG ? *wxBLACK : *wxWHITE);

        while (CoordSetIt != GraphInfoVector->end()) {
            dc.SetPen(BGPen);
            // Erase terminator circle
            if ((*CoordSetIt)->XCoordinate.size() > unsigned(NewPoints) + 1) {
                XCoordIt = (*CoordSetIt)->XCoordinate.end() - NewPoints - 1;
                YCoordIt = (*CoordSetIt)->YCoordinate.end() - NewPoints - 1;
            } else {
                XCoordIt = (*CoordSetIt)->XCoordinate.begin();
                YCoordIt = (*CoordSetIt)->YCoordinate.begin();
            }
            dc.SetBrush(BGBrush);
            if ((*CoordSetIt)->TermSize > 0) {
                dc.DrawEllipse(wxCoord((*XCoordIt) * ScalingFactor - (*CoordSetIt)->TermSize), wxCoord((*YCoordIt) * ScalingFactor* (-1) - (*CoordSetIt)->TermSize),
                                   (*CoordSetIt)->TermSize * 2, (*CoordSetIt)->TermSize * 2);
            }

            // Draw back points
            if ((*CoordSetIt)->XCoordinate.size() > unsigned(NewPoints) + (*CoordSetIt)->TermSize + 1) {
                XCoordIt -= (*CoordSetIt)->TermSize;
                YCoordIt -= (*CoordSetIt)->TermSize;
            } else {
                XCoordIt = (*CoordSetIt)->XCoordinate.begin();
                YCoordIt = (*CoordSetIt)->YCoordinate.begin();
            }

            if ((*CoordSetIt)->TrailColour == *wxBLACK && BlackBG) {
                dc.SetBrush(wxBrush(*wxBLACK));
                dc.SetPen(wxPen(*wxBLACK, 1));
            } else {
                dc.SetBrush(wxBrush((*CoordSetIt)->TrailColour));
                dc.SetPen(wxPen((*CoordSetIt)->TrailColour, 1));
            }

            while (XCoordIt != (*CoordSetIt)->XCoordinate.end()) {
                dc.DrawPoint(wxCoord((*XCoordIt) * ScalingFactor), wxCoord((*YCoordIt) * ScalingFactor* (-1)));
                ++XCoordIt;
                ++YCoordIt;
            }

            --XCoordIt;
            --YCoordIt;

            // Draw terminator circle
            if ((*CoordSetIt)->TermSize > 0) {
                dc.DrawEllipse(wxCoord((*XCoordIt) * ScalingFactor - (*CoordSetIt)->TermSize),
                               wxCoord((*YCoordIt) * ScalingFactor* (-1) - (*CoordSetIt)->TermSize),
                               (*CoordSetIt)->TermSize * 2, (*CoordSetIt)->TermSize * 2);
            }

            ++CoordSetIt;
        }
    }
}

void GraphPane::OnEraseEvent(wxEraseEvent& evt)
{
    // Do nothing
}

void GraphPane::SetNewPointNum(int Num)
{
    NewPoints = Num;
}

double GraphPane::GetXExtent()
{
    wxCoord width, height;
    this->GetSize(&width, &height);

    return double(width / ScalingFactor);
}

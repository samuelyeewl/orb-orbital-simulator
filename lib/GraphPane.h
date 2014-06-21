/** \file GraphPane.h
 *
 *  \brief A class based on wxPanel that makes it easier to draw dynamic graphs.
 *
 *  GraphPane.h defines structs like GraphInfo and LineInfo to store information on coordinates and graphs to be drawn.
 *  The panel uses a pointer to a std::vector of these structs to access the coordinates. This must be passed to the pointer through the appropriate Set functions
 *
 *  Features:
 *  - Allows automatic or manual scaling
 *  - Able to use colours and add terminator styles to graphs and lines
 */


#ifndef GRAPHPANE_H
#define GRAPHPANE_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(GraphPane)
	#include <wx/panel.h>
	//*)
#endif
//(*Headers(GraphPane)
//*)

#include <wx/colour.h>
#include <vector>
#include <deque>

/**< A struct type containing the coordinates of the graph to be drawn, colour and terminator size. */
struct GraphInfo {
    std::deque<double> XCoordinate;        /**< Double-ended queue of doubles storing the x coordinates */
    std::deque<double> YCoordinate;        /**< Double-ended queue of doubles storing the y coordinates */
    std::deque<double> ZCoordinate;        /**< Double-ended queue of doubles storing the z coordinates */
    wxColour TrailColour;                   /**< Colour of points in this graph */
    int TermSize;                           /**< Size of terminating circle (drawn at last coordinate). 0 for no circle. */
};

/** \brief This classes allows the easy drawing of graphs
 * GraphPane inherits wxPanel
 */
class GraphPane: public wxPanel
{
	public:

		GraphPane(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, wxWindow* parentFrame=NULL);
		virtual ~GraphPane();

		//(*Declarations(GraphPane)
		//*)

		/** \brief Sets the address of the coordinates of graphs to be drawn.
         *  \param Address of std::vector of pointers to GraphInfo structs
         */
        void SetGraphInfoAddress(std::vector<GraphInfo*>* GraphAddress);

        /** \brief Inverts background colour
         * Toggles background colour between black and white. Toggles the colour of graphs drawn in black or white.
         */
		void InvertColours();

        /** \brief Calls a partial refresh of the GraphPane.
         * Does not clear panel. Instead, erases the last x points and draws x new points, where x is set by SetNewPointNum
         */
		void PartialRefresh();

		// Calculate Scale
		// Overloaded version removes function call to get size of wxDC.
		void CalculateScale(double MaxXExtent, double MaxYExtent);
		void CalculateScale(double MaxXExtent, double MaxYExtent, wxCoord width, wxCoord height);

		// Set New Points
		void SetNewPointNum(int Num);

        /** \brief Gets the true maximum extent in SI units
         * \return Returns the horizontal size of the displayed panel in metres.
         */
        double GetXExtent();


	protected:

		//(*Identifiers(GraphPane)
		//*)

	private:
        /**< Pointer to std::vector of pointers to GraphInfo structs */
        std::vector<GraphInfo*>* GraphInfoVector;

        // Full Refresh: redraws everything.
        void FullRefresh(wxDC& dc);

        bool BlackBG;

        double ScalingFactor;

        int NewPoints;


		//(*Handlers(GraphPane)
		//*)

		void GraphPane::OnPaintEvent(wxPaintEvent& evt);
		void GraphPane::OnEraseEvent(wxEraseEvent& evt);
		void GraphPane::OnResizeEvent(wxSizeEvent& evt);

		DECLARE_EVENT_TABLE()
};

#endif

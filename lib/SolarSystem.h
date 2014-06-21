#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "Planet.h"
#include <wx/colour.h>
#include <wx/string.h>
#include <wx/frame.h>
#include <wx/textfile.h>
#include <vector>
#include <map>

enum FrameType {
    ORIGINAL, COMORIGIN, PLANETORIGIN, CUSTOMORIGIN
};

const double PI = 3.1415926536;

class SolarSystem
{
    public:
        // Functions
        SolarSystem();
        virtual ~SolarSystem();

        /*
            Create a new planet and add it to the system.
            Receives xInit, yInit, zInit in Mm, vXInit, vYInit, vZInit in km/s, mass in 10^20 kg
            Returns a pointer to the planet created.
            Overloaded version takes in Planet ID.
        */
        Planet* CreateNewPlanet(double xInit, double yInit, double zInit,
                                double vXInit, double vYInit, double vZInit,
                                double mass, wxColour* colour, int TerminatorSize, wxString PlanetName);

        Planet* CreateNewPlanet(double xInit, double yInit, double zInit,
                                double vXInit, double vYInit, double vZInit,
                                double mass, wxColour* colour, int TerminatorSize, wxString PlanetName,
                                int PlanetID);

        /*
            Edit the planet with the given PlanetID.
            UpdateCoordinates should be called immediately after.
            Returns true if successful.
        */
        bool EditPlanet(int PlanetID,
                        double xInit, double yInit, double zInit,
                        double vXInit, double vYInit, double vZInit,
                        double mass, wxColour* colour, int TerminatorSize, wxString PlanetName);

        /*
            Delete the planet with the given PlanetID.
            UpdateCoordinates should be called immediately after.
            Returns true if successful
        */
        bool DeletePlanet(int PlanetID);

        /*
            Update the Coordinate List.
            Returns 0 if successful, 1 if not.
        */
        int UpdateCoordinates(std::vector<GraphInfo*>* MainCoordinates);

        /*
            Sets the trail length
        */
        void SetTrailLength(int length);

        /*
            Returns the trail length
        */
        int GetTrailLength();

        /*
            Set step size in seconds
        */
        void SetStepSize(int StepS);

        /*
            Check if SolarSystem is empty
            Returns true if empty, false if not.
        */
        bool IsEmpty();

        /*
            Returns the number of planets
        */
        int NumPlanets();

        /*
            Updates system to next time step
        */
        void NextStep();

        /*
            Get Max Elements
            Places the maximum X and Y coordinates in the addresses provided
        */
        void GetMaxElements(double* MaxX, double* MaxY);


        /*
            Reset planets to intial coordinates
        */
        void ResetCoordinates();

        /*
            Delete all planets
            UpdateCoordinates should be called immediately after.
        */
        void ResetSystem();

        /*
            Change frame of reference
            Overloaded version accepts custom origin and planet origin
        */
        void ChangeReferenceFrame(FrameType Choice);
        void ChangeReferenceFrame(FrameType Choice, double x, double y, double z);
        void ChangeReferenceFrame(FrameType Choice, int PlanetId);

        /*
            Change origin speed
            Overloaded version accepts origin speed
            Should only be called after a call to ChangeReferenceFrame
        */
        void ChangeOriginSpeed(bool Moving);
        void ChangeOriginSpeed(bool Moving, double vX, double vY, double vZ);

        /*
            Change rotation
            Overloaded version accepts new rotation angular frequency in radians per second
            Should only be called after a call to ChangeReferenceFrame
        */
        void ChangeRotation(bool Rotating);
        void ChangeRotation(bool Rotating, double Freq);

        /*
            Gets the time elapsed
        */
        double GetTimeElapsed();

        /*
            Save System to file
            Returns true if successful
        */
        bool SaveSystemToFile(wxTextFile* SaveFile);

        // Variables
        std::map<int, Planet*> PlanetList;

        double MaxXCoord;
        double MaxYCoord;

        // Frame of reference
        FrameType FrameChoice;

        bool TranslatingOrigin;
        double OriginvX, OriginvY, OriginvZ;

        bool Rotation;
        double RotationFrequency;

        // Custom origin
        double CustomX, CustomY, CustomZ;
        int CustomPlanetOriginId;


    protected:


    private:
        // Functions
        int NewPlanetID(void);

        /*
            Calculates the centre of mass of the system
            Returns in the three integers passed.
        */
        void CalcCOM(double* COMX, double* COMY, double* COMZ);

        /*
            Writes the current coordinates of all planets according to the given frame.
            Overloaded version does so for only one planet as specified.
        */
        void WriteCurrentCoords();
        void WriteCurrentCoords(int ID);



        int IDCounter;
        unsigned int TrailLength, StepLength;

        // Gravitational Acceleration
        double GConstant;

        // Internal time counter
        double ElapsedTime;

        // Number of extra steps to keep
        int ExtraSteps;
};

#endif // SOLARSYSTEM_H

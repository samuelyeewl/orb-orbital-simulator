#ifndef PLANET_H
#define PLANET_H

#include <wx/colour.h>
#include <deque>
#include <bitset>

#include "GraphPane.h"

#define PERIODNOTSET -5

// Conversion factors
#define METRE_PER_AU 149597870700.0
#define MPS_PER_AUDAY 1731456.836805560

// ExtraInfo struct contains data for export or graph display
struct ExtraData {
    std::bitset<16> ExtraInfoStored;
    std::deque<double> DistanceCOMVec;
    std::deque<double> CurrentXVec;
    std::deque<double> CurrentYVec;
    std::deque<double> CurrentZVec;
    std::deque<double> SpeedVec;
    std::deque<double> CurrentvXVec;
    std::deque<double> CurrentvYVec;
    std::deque<double> CurrentvZVec;
    std::deque<double> AccelVec;
    std::deque<double> AccelXVec;
    std::deque<double> AccelYVec;
    std::deque<double> AccelZVec;
    std::deque<double> GPEVec;
    std::deque<double> KEVec;
    std::deque<double> TEVec;
};

// ExtraInfoStored
#define STOREDISTANCECOM    0
#define STORECURRENTX       1
#define STORECURRENTY       2
#define STORECURRENTZ       3
#define STORESPEED          4
#define STORECURRENTVX      5
#define STORECURRENTVY      6
#define STORECURRENTVZ      7
#define STOREACCEL          8
#define STOREACCELX         9
#define STOREACCELY         10
#define STOREACCELZ         11
#define STOREGPE            12
#define STOREKE             13
#define STORETE             14

/*
    The planet class stores information for each of the planets
*/

class Planet
{
    public:
        Planet(double xInit, double yInit, double zInit,
               double vXInit, double vYInit, double vZInit,
               double m, wxColour* colour, int TerminatorSize, wxString PlanetName);
        virtual ~Planet();

        GraphInfo PlanetInfo;

        double InitialX, InitialY, InitialZ;
        double InitialvX, InitialvY, InitialvZ;
        double CurrentX, CurrentY, CurrentZ;
        double CurrentvX, CurrentvY, CurrentvZ;
        double Mass;
        wxString PName;
        int PlanetId;

        // Orbital Parameters
        // OrbitalPeriod: PERIODNOTSET is -1 * no. of steps to wait before calculating direction of motion.
        //                == PERIODNOTSET if InitialAngle not set
        //                < -1 if direction not set
        //                -1 when it is time to set the direction
        //                0 during the first revolution
        double OrbitalPeriod;
        double InitialAngle;
        bool Clockwise;
        bool FirstSignFlip, SecondSignFlip;
        int Revolution;
        double PreviousRevStart;

        // ViewInfo: true will set the calculation of the following data:
        bool ViewInfo;
        double DistanceCOM;
        double AccelX;
        double AccelY;
        double AccelZ;
        double GPE;
        double KE;
        double TE;

        // ExtraData bitfield true (ViewInfo must also be true) will start storing the extra data in ExtraInfo
        int ExtraInfoLength;
        ExtraData ExtraInfo;

        void SetPlanetId(int PID);

    protected:


    private:


};



#endif // PLANET_H

#include "Planet.h"


/* Constructor */
Planet::Planet(double xInit, double yInit, double zInit, double vXInit, double vYInit, double vZInit, double m, wxColour* colour, int TerminatorSize, wxString PlanetName)
            : InitialX(xInit), InitialY(yInit), InitialZ(zInit), InitialvX(vXInit), InitialvY(vYInit), InitialvZ(vZInit),
            CurrentX(xInit), CurrentY(yInit), CurrentZ(zInit), CurrentvX(vXInit), CurrentvY(vYInit), CurrentvZ(vZInit), Mass(m), PName(PlanetName)
{
    PlanetInfo.TrailColour = *colour;
    PlanetInfo.TermSize = TerminatorSize;

    OrbitalPeriod = PERIODNOTSET;
    Clockwise = false;
    FirstSignFlip = false;
    SecondSignFlip = false;
    Revolution = 0;
    PreviousRevStart = 0;

    ViewInfo = false;
    DistanceCOM = 0;
    AccelX = 0;
    AccelY = 0;
    AccelZ = 0;
    GPE = 0;
    KE = 0;
    TE = 0;

    ExtraInfo.ExtraInfoStored = 0ul;
    ExtraInfoLength = 0;
}

Planet::~Planet()
{
    //dtor
}

void Planet::SetPlanetId(int PID)
{
    PlanetId = PID;
}

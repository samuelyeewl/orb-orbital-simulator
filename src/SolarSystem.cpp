#include "SolarSystem.h"
#include <cmath>
#include <algorithm>

/////////////////////////////////////////
//          PUBLIC FUNCTIONS           //
/////////////////////////////////////////

/*
    Constructor
    Does nothing at the moment.
*/

SolarSystem::SolarSystem()
{
    IDCounter = 1;
    TrailLength = 3981;
    StepLength = 10000;
    GConstant = 6.673e-11;
    MaxXCoord = 0;
    MaxYCoord = 0;
    ElapsedTime = 0;

    FrameChoice = COMORIGIN;
    CustomX = 0;
    CustomY = 0;
    CustomZ = 0;
    CustomPlanetOriginId = 0;

    TranslatingOrigin = false;
    OriginvX = 0;
    OriginvY = 0;
    OriginvZ = 0;

    Rotation = false;
    RotationFrequency = 0;
}

SolarSystem::~SolarSystem()
{
    //dtor
}

/*
    Create a new planet and add it to the system.
    Returns the PlanetID.
*/
Planet* SolarSystem::CreateNewPlanet(double xInit, double yInit, double zInit,
                                    double vXInit, double vYInit, double vZInit,
                                    double mass, wxColour* colour, int TerminatorSize, wxString PlanetName)
{
    Planet* NewPlanet = new Planet(xInit, yInit, zInit, vXInit, vYInit, vZInit, mass, colour, TerminatorSize, PlanetName);
    int PlanetID = NewPlanetID();
    PlanetList.insert(std::make_pair(PlanetID, NewPlanet));
    NewPlanet->SetPlanetId(PlanetID);

    WriteCurrentCoords(PlanetID);

    return NewPlanet;
}

Planet* SolarSystem::CreateNewPlanet(double xInit, double yInit, double zInit,
                                    double vXInit, double vYInit, double vZInit,
                                    double mass, wxColour* colour, int TerminatorSize, wxString PlanetName,
                                    int PlanetID)
{
    Planet* NewPlanet = new Planet(xInit, yInit, zInit, vXInit, vYInit, vZInit, mass, colour, TerminatorSize, PlanetName);
    PlanetList.insert(std::make_pair(PlanetID, NewPlanet));
    NewPlanet->SetPlanetId(PlanetID);

    WriteCurrentCoords(PlanetID);

    return NewPlanet;
}

/*
    Delete the planet with the given PlanetID.
    UpdateCoordinates should be called immediately after.
    Returns true if successful
*/
bool SolarSystem::DeletePlanet(int PlanetID)
{
    delete (Planet*)PlanetList[PlanetID];
    PlanetList.erase(PlanetID);

    return true;
}

/*
    Edit the planet with the given PlanetID.
    UpdateCoordinates should be called immediately after.
    Returns true if successful.
*/
bool SolarSystem::EditPlanet(int PlanetID,
                            double xInit, double yInit, double zInit,
                            double vXInit, double vYInit, double vZInit,
                            double mass, wxColour* colour, int TerminatorSize, wxString PlanetName)
{
    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.find(PlanetID);

    if (PlanetIt != PlanetList.end()) {
        (*PlanetIt).second->PlanetInfo.TrailColour = *colour;
        (*PlanetIt).second->PlanetInfo.TermSize = TerminatorSize;

        (*PlanetIt).second->InitialX = xInit;
        (*PlanetIt).second->InitialY = yInit;
        (*PlanetIt).second->InitialZ = zInit;
        (*PlanetIt).second->InitialvX = vXInit;
        (*PlanetIt).second->InitialvY = vYInit;
        (*PlanetIt).second->InitialvZ = vZInit;

        (*PlanetIt).second->CurrentX = xInit;
        (*PlanetIt).second->CurrentY = yInit;
        (*PlanetIt).second->CurrentZ = zInit;
        (*PlanetIt).second->CurrentvX = vXInit;
        (*PlanetIt).second->CurrentvY = vYInit;
        (*PlanetIt).second->CurrentvZ = vZInit;

        (*PlanetIt).second->Mass = mass;

        (*PlanetIt).second->PName = PlanetName;

        (*PlanetIt).second->OrbitalPeriod = PERIODNOTSET;
        (*PlanetIt).second->FirstSignFlip = false;
        (*PlanetIt).second->SecondSignFlip = false;
        (*PlanetIt).second->Revolution = 0;

        WriteCurrentCoords(PlanetID);

        return true;
    }
    return false;
}

/*
    Update the Coordinate List.
    Returns 0 if successful, 1 if not.
*/
int SolarSystem::UpdateCoordinates(std::vector<GraphInfo*>* MainCoordinates)
{
    // Clear Coordinates
    (*MainCoordinates).clear();

    if (this->IsEmpty()) return 0;

    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();

    // Assign Coordinates
    while (PlanetIt != PlanetList.end()) {
        (*MainCoordinates).push_back(&((*PlanetIt).second->PlanetInfo));
        PlanetIt++;
    }

    return 0;
}

/*
    Sets the trail length
*/
void SolarSystem::SetTrailLength(int length)
{
    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();
    if (PlanetIt == PlanetList.end()) {
        TrailLength = length;
        return;
    }

    int CurrentLength = (*PlanetIt).second->PlanetInfo.XCoordinate.size();

    while (PlanetIt != PlanetList.end()) {
        // If the new length is shorter, resize the vector.
        while (length < CurrentLength && CurrentLength > 0) {
            (*PlanetIt).second->PlanetInfo.XCoordinate.erase((*PlanetIt).second->PlanetInfo.XCoordinate.begin());
            (*PlanetIt).second->PlanetInfo.YCoordinate.erase((*PlanetIt).second->PlanetInfo.YCoordinate.begin());
            (*PlanetIt).second->PlanetInfo.ZCoordinate.erase((*PlanetIt).second->PlanetInfo.ZCoordinate.begin());

            CurrentLength--;
        }
        PlanetIt++;
    }


    TrailLength = length;
}

/*
    Returns the trail length
*/
int SolarSystem::GetTrailLength()
{
    return TrailLength;
}

/*
    Set step size in seconds
*/
void SolarSystem::SetStepSize(int StepS)
{
    if (StepS > 0) {
        StepLength = StepS;
    } else {
        StepLength = 1000;
    }

}

/*
    Check if SolarSystem is empty
    Returns true if empty, false if not.
*/
bool SolarSystem::IsEmpty()
{
    return PlanetList.empty();
}

/*
    Returns number of planets
*/
int SolarSystem::NumPlanets()
{
    return PlanetList.size();
}

/*
    Reset planets to intial coordinates
*/
void SolarSystem::ResetCoordinates()
{
    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();

    // Clear coordinates and reset to original
    while (PlanetIt != PlanetList.end()) {
        (*PlanetIt).second->PlanetInfo.XCoordinate.clear();
        (*PlanetIt).second->PlanetInfo.YCoordinate.clear();
        (*PlanetIt).second->PlanetInfo.ZCoordinate.clear();

        (*PlanetIt).second->CurrentX = (*PlanetIt).second->InitialX;
        (*PlanetIt).second->CurrentY = (*PlanetIt).second->InitialY;
        (*PlanetIt).second->CurrentZ = (*PlanetIt).second->InitialZ;
        (*PlanetIt).second->CurrentvX = (*PlanetIt).second->InitialvX;
        (*PlanetIt).second->CurrentvY = (*PlanetIt).second->InitialvY;
        (*PlanetIt).second->CurrentvZ = (*PlanetIt).second->InitialvZ;

        (*PlanetIt).second->OrbitalPeriod = PERIODNOTSET;
        (*PlanetIt).second->FirstSignFlip = false;
        (*PlanetIt).second->SecondSignFlip = false;
        (*PlanetIt).second->Revolution = 0;

        PlanetIt++;
    }

    // Reset Time
    ElapsedTime = 0;

    WriteCurrentCoords();

}

/*
    Delete all planets
    UpdateCoordinates should be called immediately after.
*/
void SolarSystem::ResetSystem()
{
    if (this->IsEmpty()) return;

    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();

    // Delete planet objects
    while (PlanetIt != PlanetList.end()) {
        delete (Planet*)((*PlanetIt).second);

        PlanetIt++;
    }

    // Clear PlanetList
    PlanetList.clear();

    // Clear COM
    MaxXCoord = 0;
    MaxYCoord = 0;

    // Reset Frame
    FrameChoice = COMORIGIN;
    CustomX = 0;
    CustomY = 0;
    CustomZ = 0;
    CustomPlanetOriginId = 0;

    TranslatingOrigin = false;
    OriginvX = 0;
    OriginvY = 0;
    OriginvZ = 0;


    // Reset Time
    ElapsedTime = 0;

    return;
}

/*
    Change frame of reference
    Overloaded version accepts custom origin
*/
void SolarSystem::ChangeReferenceFrame(FrameType Choice)
{
    // Clear Coordinates
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();
    while (PlanetIt != PlanetList.end()) {
        (*PlanetIt).second->PlanetInfo.XCoordinate.clear();
        (*PlanetIt).second->PlanetInfo.YCoordinate.clear();
        (*PlanetIt).second->PlanetInfo.ZCoordinate.clear();

        ++PlanetIt;
    }

    FrameChoice = Choice;
    WriteCurrentCoords();
}

void SolarSystem::ChangeReferenceFrame(FrameType Choice, double x, double y, double z)
{
    if (Choice == CUSTOMORIGIN) {
        CustomX = x;
        CustomY = y;
        CustomZ = z;
    }

    ChangeReferenceFrame(Choice);

}

void SolarSystem::ChangeReferenceFrame(FrameType Choice, int PlanetId)
{
    if (Choice == PLANETORIGIN) {
        CustomPlanetOriginId = PlanetId;
    }

    ChangeReferenceFrame(Choice);
}

/*
    Change origin speed
    Overloaded version accepts origin speed
*/
void SolarSystem::ChangeOriginSpeed(bool Moving)
{
    if (Moving) {
        ChangeOriginSpeed(Moving, OriginvX, OriginvY, OriginvZ);
    } else {
        TranslatingOrigin = false;
    }
}

void SolarSystem::ChangeOriginSpeed(bool Moving, double vX, double vY, double vZ)
{
    if (Moving) {
        TranslatingOrigin = true;
        OriginvX = vX;
        OriginvY = vY;
        OriginvZ = vZ;
    } else {
        TranslatingOrigin = false;
    }
}

/*
    Change rotation
    Overloaded version accepts new rotation angular frequency in radians per second
*/
void SolarSystem::ChangeRotation(bool Rotating)
{
    if (Rotating) {
        ChangeRotation(Rotating, RotationFrequency);
    } else {
        Rotation = false;
    }
}

void SolarSystem::ChangeRotation(bool Rotating, double Freq)
{
    if (Rotating) {
        Rotation = true;
        RotationFrequency = Freq;
    } else {
        Rotation = false;
    }
}

/*
    Gets the time elapsed
*/
double SolarSystem::GetTimeElapsed()
{
    return ElapsedTime;
}

/*
    Save System to file
    Returns true if successful
*/
bool SolarSystem::SaveSystemToFile(wxTextFile* SaveFile)
{
    wxString TempOutputString;
    wxString NumString;
    // Check if 0 planets
    if (this->IsEmpty()) return true;

    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();

    while (PlanetIt != PlanetList.end()) {
        // Header
        SaveFile->AddLine("<Planet>");

        // PlanetName
        TempOutputString = "PlanetName=";
        TempOutputString.Append((*PlanetIt).second->PName);
        SaveFile->AddLine(TempOutputString);

        // Colour
        TempOutputString = "Colour=";
        TempOutputString.Append((*PlanetIt).second->PlanetInfo.TrailColour.GetAsString());
        SaveFile->AddLine(TempOutputString);

        // Size
        TempOutputString = "Size=";
        NumString = wxString::Format("%d", (*PlanetIt).second->PlanetInfo.TermSize);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        // Initial X, Y, vX, vY
        TempOutputString = "X=";
        NumString = wxString::Format("%.15e", (*PlanetIt).second->InitialX);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        TempOutputString = "Y=";
        NumString = wxString::Format("%.15e", (*PlanetIt).second->InitialY);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        TempOutputString = "Z=";
        NumString = wxString::Format("%.15e", (*PlanetIt).second->InitialZ);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        TempOutputString = "vX=";
        NumString = wxString::Format("%.15e", (*PlanetIt).second->InitialvX);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        TempOutputString = "vY=";
        NumString = wxString::Format("%.15e", (*PlanetIt).second->InitialvY);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        TempOutputString = "vZ=";
        NumString = wxString::Format("%.15e", (*PlanetIt).second->InitialvZ);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        // Mass
        TempOutputString = "Mass=";
        NumString = wxString::Format("%.15e", (*PlanetIt).second->Mass);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        // PlanetID
        TempOutputString = "ID=";
        NumString = wxString::Format("%d", (*PlanetIt).second->PlanetId);
        TempOutputString.Append(NumString);
        SaveFile->AddLine(TempOutputString);

        // Closer
        SaveFile->AddLine("</Planet>");
        PlanetIt++;
    }

    return true;
}

void SolarSystem::NextStep()
{
    // Check if 0 planets
    if (this->IsEmpty()) return;

    int h = StepLength;

    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();
    std::map<int, Planet*>::const_iterator PlanetItInner = PlanetList.begin();
    int PlanetNum = PlanetList.size();

    // Counters are Count1, Count2
    int Count1, Count2;

    /*************************************************************************************/
    /**     Runge-Kutta 4th order method for solving 2nd order Differential Equations   **/
    /**     Constants k1, k2, k3, k4 refer to the slopes of the position function       **/
    /**     Constants j1, j2, j3, j4 refer to the slopes of the velocity function       **/
    /*************************************************************************************/

    // Initialize temporary container for the positions of each planet at a given time step
    std::vector<double> tempx(PlanetNum, 0);
    std::vector<double> tempy(PlanetNum, 0);
    std::vector<double> tempz(PlanetNum, 0);

    /**
        Step 1: Find k1 and j1 for all planets.

        k1x = Current vX
        k1y = Current vY
        k1z = Current vZ
        (k constants refer to the velocity)

        j1x = -GM * x / sqrt(x^2 + y^2 + z^2)
        j1y = -GM * y / sqrt(x^2 + y^2 + z^2)
        j1z = -GM * z / sqrt(x^2 + y^2 + z^2)
        (j constants refer to the acceleration)
    **/
    // Initialize vectors containing k1 and j1 for all planets.
    std::vector<double> k1x(PlanetNum, 0);
    std::vector<double> k1y(PlanetNum, 0);
    std::vector<double> k1z(PlanetNum, 0);
    std::vector<double> j1x(PlanetNum, 0);
    std::vector<double> j1y(PlanetNum, 0);
    std::vector<double> j1z(PlanetNum, 0);

    double masslessforceX, masslessforceY, masslessforceZ;
    double invDistance;
    double x, y, z;

    /*
        First loop:
            Grab the initial positions of each planet at the beginning of the time step.
            -- tempx = CurrentX
            -- tempy = CurrentY
            -- tempz = CurrentZ
            Calculate k1 for each planet, which is the initial velocity at the beginning of the time step.
            -- k1x = CurrentvX
            -- k1y = CurrentvY
            -- k1z = CurrentvZ
    */
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Positions
        tempx[Count1] = (*PlanetIt).second->CurrentX;
        tempy[Count1] = (*PlanetIt).second->CurrentY;
        tempz[Count1] = (*PlanetIt).second->CurrentZ;

        // Velocities
        k1x[Count1] = (*PlanetIt).second->CurrentvX;
        k1y[Count1] = (*PlanetIt).second->CurrentvY;
        k1z[Count1] = (*PlanetIt).second->CurrentvZ;

        ++PlanetIt;
    }

    /*
        Second loop:
            Calculate the distance between each planet at the beginning of the time step.
            -- distance = sqrt(x2 + y2)
            Find the product G/r^2, which is split into Gx/r^3 and Gy/r^3
            Add the interaction between these two objects to their total acceleration.
    */
    PlanetIt = PlanetList.begin();
    PlanetItInner = PlanetList.begin();
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Make sure each force interaction is only calculated once.
        PlanetItInner = PlanetIt;
        ++PlanetItInner;

        for (Count2 = Count1+1; Count2 < PlanetNum; Count2++) {
            // Find the distance
            x = tempx[Count1] - tempx[Count2];
            y = tempy[Count1] - tempy[Count2];
            z = tempz[Count1] - tempz[Count2];
            invDistance = 1 / sqrt(x*x + y*y + z*z);

            // Find massless forces
            masslessforceX = GConstant * x * invDistance * invDistance * invDistance;
            masslessforceY = GConstant * y *invDistance * invDistance * invDistance;
            masslessforceZ = GConstant * z *invDistance * invDistance * invDistance;

            // For the planet with lower index (Count1)
            j1x[Count1] += (masslessforceX * -(*PlanetItInner).second->Mass);
            j1y[Count1] += (masslessforceY * -(*PlanetItInner).second->Mass);
            j1z[Count1] += (masslessforceZ * -(*PlanetItInner).second->Mass);


            // For the planet with higher index (Count 2)
            j1x[Count2] += (masslessforceX * (*PlanetIt).second->Mass);
            j1y[Count2] += (masslessforceY * (*PlanetIt).second->Mass);
            j1z[Count2] += (masslessforceZ * (*PlanetIt).second->Mass);

            // Increment PlanetItInner
            ++PlanetItInner;
        }

        // Increment PlanetIt
        ++PlanetIt;
    }

    /**
        Step 2: Find k2 and j2 for all planets.

        k2x = Initial vX + j1x * h/2
        k2y = Initial vY + j1y * h/2
        k2z = Initial vZ + j1z * h/2
        (k constants refer to the velocity)

        j2x = -GM * x / sqrt(x^2 + y^2 + z^2)
        j2y = -GM * y / sqrt(x^2 + y^2 + z^2)
        j2z = -GM * z / sqrt(x^2 + y^2 + z^2)
        (j constants refer to the acceleration)

        The distances x, y and z have to be recalculated
    **/
    // Initialize vectors containing k2 and j2 for all planets.
    std::vector<double> k2x(PlanetNum, 0);
    std::vector<double> k2y(PlanetNum, 0);
    std::vector<double> k2z(PlanetNum, 0);
    std::vector<double> j2x(PlanetNum, 0);
    std::vector<double> j2y(PlanetNum, 0);
    std::vector<double> j2z(PlanetNum, 0);

    /*
        First loop:
            Calculate the positions of the planets at the midpoint of the timestep using k1 as the velocity.
            -- tempx += k1x * h/2
            -- tempy += k1y * h/2
            -- tempz += k1z * h/2
            Calculate k2 for each planet at the midpoint of the timestep using j1 as the acceleration.
            -- k2x += j1x * h/2
            -- k2y += j1y * h/2
            -- k2z += j1z * h/2
    */
    PlanetIt = PlanetList.begin();
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Positions
        tempx[Count1] = (*PlanetIt).second->CurrentX + k1x[Count1] * h/2;
        tempy[Count1] = (*PlanetIt).second->CurrentY + k1y[Count1] * h/2;
        tempz[Count1] = (*PlanetIt).second->CurrentZ + k1z[Count1] * h/2;

        // Velocities
        k2x[Count1]  = (*PlanetIt).second->CurrentvX + j1x[Count1] * h/2;
        k2y[Count1]  = (*PlanetIt).second->CurrentvY + j1y[Count1] * h/2;
        k2z[Count1]  = (*PlanetIt).second->CurrentvZ + j1z[Count1] * h/2;

        ++PlanetIt;
    }

    /*
        Second loop:
            Calculate the distance between each planet at the middle of the time step.
            -- distance = sqrt(x2 + y2 + z^2)
            Find the product G/r^2, which is Gx/r^3 and Gy/r^3 when split into components of force in perpendicular directions
            Add the interaction between these two objects to their total acceleration.
    */
    PlanetIt = PlanetList.begin();
    PlanetItInner = PlanetList.begin();
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Make sure each force interaction is only calculated once.
        PlanetItInner = PlanetIt;
        ++PlanetItInner;

        for (Count2 = Count1+1; Count2 < PlanetNum; Count2++) {
            // Find the distance
            x = tempx[Count1] - tempx[Count2];
            y = tempy[Count1] - tempy[Count2];
            z = tempz[Count1] - tempz[Count2];
            invDistance = 1 / sqrt(x*x + y*y + z*z);

            // Find massless forces
            masslessforceX = GConstant * x * invDistance * invDistance * invDistance;
            masslessforceY = GConstant * y *invDistance * invDistance * invDistance;
            masslessforceZ = GConstant * z *invDistance * invDistance * invDistance;

            // For the planet with lower index (Count1)
            j2x[Count1] += (masslessforceX * -(*PlanetItInner).second->Mass);
            j2y[Count1] += (masslessforceY * -(*PlanetItInner).second->Mass);
            j2z[Count1] += (masslessforceZ * -(*PlanetItInner).second->Mass);


            // For the planet with higher index (Count 2)
            j2x[Count2] += (masslessforceX * (*PlanetIt).second->Mass);
            j2y[Count2] += (masslessforceY * (*PlanetIt).second->Mass);
            j2z[Count2] += (masslessforceZ * (*PlanetIt).second->Mass);

            // Increment PlanetItInner
            ++PlanetItInner;
        }

        // Increment PlanetIt
        ++PlanetIt;
    }

    /**
        Step 3: Find k3 and j3 for all planets.

        k3x = Initial vX + j2x * h/2
        k3y = Initial vY + j2y * h/2
        k3z = Initial vZ + j2z * h/2
        (k constants refer to the velocity)

        j3x = -GM * x / sqrt(x^2 + y^2 + z^2)
        j3y = -GM * y / sqrt(x^2 + y^2 + z^2)
        j3z = -GM * z / sqrt(x^2 + y^2 + z^2)
        (j constants refer to the acceleration)

        The distances x and y have to be recalculated
    **/
    // Initialize vectors containing k3 and j3 for all planets.
    std::vector<double> k3x(PlanetNum, 0);
    std::vector<double> k3y(PlanetNum, 0);
    std::vector<double> k3z(PlanetNum, 0);
    std::vector<double> j3x(PlanetNum, 0);
    std::vector<double> j3y(PlanetNum, 0);
    std::vector<double> j3z(PlanetNum, 0);

    /*
        First loop:
            Calculate the positions of the planets at the midpoint of the timestep using k2 as the velocity.
            -- tempx = XInitial + k2x * h/2
            -- tempy = YInitial + k2y * h/2
            -- tempz = ZInitial + k2z * h/2
            Calculate k3 for each planet at the midpoint of the timestep using j2 as the acceleration.
            -- k3x = VXInitial + j2x * h/2
            -- k3y = VYinitial + j2y * h/2
            -- k3z = VZinitial + j2z * h/2
    */
    PlanetIt = PlanetList.begin();
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Positions
        tempx[Count1] = (*PlanetIt).second->CurrentX + k2x[Count1] * h/2;
        tempy[Count1] = (*PlanetIt).second->CurrentY + k2y[Count1] * h/2;
        tempz[Count1] = (*PlanetIt).second->CurrentZ + k2z[Count1] * h/2;

        // Velocities
        k3x[Count1] = (*PlanetIt).second->CurrentvX + j2x[Count1] * h/2;
        k3y[Count1] = (*PlanetIt).second->CurrentvY + j2y[Count1] * h/2;
        k3z[Count1] = (*PlanetIt).second->CurrentvZ + j2z[Count1] * h/2;

        ++PlanetIt;
    }

    /*
        Second loop:
            Calculate the distance between each planet at the middle of the time step.
            -- distance = sqrt(x2 + y2)
            Find the product G/r^2, which is Gx/r^3 and Gy/r^3 when split into components of force in perpendicular directions
            Add the interaction between these two objects to their total acceleration.
    */
    PlanetIt = PlanetList.begin();
    PlanetItInner = PlanetList.begin();
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Make sure each force interaction is only calculated once.
        PlanetItInner = PlanetIt;
        ++PlanetItInner;

        for (Count2 = Count1+1; Count2 < PlanetNum; Count2++) {
            // Find the distance
            x = tempx[Count1] - tempx[Count2];
            y = tempy[Count1] - tempy[Count2];
            z = tempz[Count1] - tempz[Count2];
            invDistance = 1 / sqrt(x*x + y*y + z*z);

            // Find massless forces
            masslessforceX = GConstant * x * invDistance * invDistance * invDistance;
            masslessforceY = GConstant * y *invDistance * invDistance * invDistance;
            masslessforceZ = GConstant * z *invDistance * invDistance * invDistance;

            // For the planet with lower index (Count1)
            j3x[Count1] += (masslessforceX * -(*PlanetItInner).second->Mass);
            j3y[Count1] += (masslessforceY * -(*PlanetItInner).second->Mass);
            j3z[Count1] += (masslessforceZ * -(*PlanetItInner).second->Mass);


            // For the planet with higher index (Count 2)
            j3x[Count2] += (masslessforceX * (*PlanetIt).second->Mass);
            j3y[Count2] += (masslessforceY * (*PlanetIt).second->Mass);
            j3z[Count2] += (masslessforceZ * (*PlanetIt).second->Mass);

            // Increment PlanetItInner
            ++PlanetItInner;
        }

        // Increment PlanetIt
        ++PlanetIt;
    }

    /**
        Step 4: Find k4 and j4 for all planets.

        k4x = Initial vX + j3x * h
        k4y = Initial vY + j3y * h
        k4z = Initial vZ + j3z * h
        (k constants refer to the velocity)

        j4x = -GM * x / sqrt(x^2 + y^2 + z^2)
        j4y = -GM * y / sqrt(x^2 + y^2 + z^2)
        j4z = -GM * z / sqrt(x^2 + y^2 + z^2)
        (j constants refer to the acceleration)

        The distances x and y have to be recalculated
    **/
    // Initialize vectors containing k4 and j4 for all planets.
    std::vector<double> k4x(PlanetNum, 0);
    std::vector<double> k4y(PlanetNum, 0);
    std::vector<double> k4z(PlanetNum, 0);
    std::vector<double> j4x(PlanetNum, 0);
    std::vector<double> j4y(PlanetNum, 0);
    std::vector<double> j4z(PlanetNum, 0);

    /*
        First loop:
            Calculate the positions of the planets at the end of the timestep using k3 as the velocity.
            -- tempx = XInitial + k3x * h
            -- tempy = YInitial + k3y * h
            -- tempz = ZInitial + k3z * h
            Calculate k4 for each planet at the midpoint of the timestep using j3 as the acceleration.
            -- k4x = VXInitial + j3x * h
            -- k4y = VYinitial + j3y * h
            -- k4z = VZinitial + j3z * h
    */
    PlanetIt = PlanetList.begin();
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Positions
        tempx[Count1] = (*PlanetIt).second->CurrentX + k3x[Count1] * h;
        tempy[Count1] = (*PlanetIt).second->CurrentY + k3y[Count1] * h;
        tempz[Count1] = (*PlanetIt).second->CurrentZ + k3z[Count1] * h;

        // Velocities
        k4x[Count1] = (*PlanetIt).second->CurrentvX + j3x[Count1] * h;
        k4y[Count1] = (*PlanetIt).second->CurrentvY + j3y[Count1] * h;
        k4z[Count1] = (*PlanetIt).second->CurrentvZ + j3z[Count1] * h;

        ++PlanetIt;
    }

    /*
        Second loop:
            Calculate the distance between each planet at the end of the time step.
            -- distance = sqrt(x2 + y2 + z^2)
            Find the product G/r^2, which is Gx/r^3 and Gy/r^3 when split into components of force in perpendicular directions
            Add the interaction between these two objects to their total acceleration.
    */
    PlanetIt = PlanetList.begin();
    PlanetItInner = PlanetList.begin();
    for (Count1 = 0; Count1 < PlanetNum; Count1++) {
        // Make sure each force interaction is only calculated once.
        PlanetItInner = PlanetIt;
        ++PlanetItInner;

        for (Count2 = Count1+1; Count2 < PlanetNum; Count2++) {
            // Find the distance
            x = tempx[Count1] - tempx[Count2];
            y = tempy[Count1] - tempy[Count2];
            z = tempz[Count1] - tempz[Count2];
            invDistance = 1 / sqrt(x*x + y*y + z*z);

            // Find massless forces
            masslessforceX = GConstant * x * invDistance * invDistance * invDistance;
            masslessforceY = GConstant * y *invDistance * invDistance * invDistance;
            masslessforceZ = GConstant * z *invDistance * invDistance * invDistance;

            // For the planet with lower index (Count1)
            j4x[Count1] += (masslessforceX * -(*PlanetItInner).second->Mass);
            j4y[Count1] += (masslessforceY * -(*PlanetItInner).second->Mass);
            j4z[Count1] += (masslessforceZ * -(*PlanetItInner).second->Mass);


            // For the planet with higher index (Count 2)
            j4x[Count2] += (masslessforceX * (*PlanetIt).second->Mass);
            j4y[Count2] += (masslessforceY * (*PlanetIt).second->Mass);
            j4z[Count2] += (masslessforceZ * (*PlanetIt).second->Mass);

            // Increment PlanetItInner
            ++PlanetItInner;
        }

        /**
                Step 5: Calculate the final positions and velocity for all planets based on the coefficients 1, 2, 2, 1
        **/
        // Update "Current" attributes of the planets
        (*PlanetIt).second->CurrentvX += (h/6)*(j1x[Count1] + 2*j2x[Count1] + 2*j3x[Count1] + j4x[Count1]);
        (*PlanetIt).second->CurrentvY += (h/6)*(j1y[Count1] + 2*j2y[Count1] + 2*j3y[Count1] + j4y[Count1]);
        (*PlanetIt).second->CurrentvZ += (h/6)*(j1z[Count1] + 2*j2z[Count1] + 2*j3z[Count1] + j4z[Count1]);
        (*PlanetIt).second->CurrentX += (h/6)*(k1x[Count1] + 2*k2x[Count1] + 2*k3x[Count1] + k4x[Count1]);
        (*PlanetIt).second->CurrentY += (h/6)*(k1y[Count1] + 2*k2y[Count1] + 2*k3y[Count1] + k4y[Count1]);
        (*PlanetIt).second->CurrentZ += (h/6)*(k1z[Count1] + 2*k2z[Count1] + 2*k3z[Count1] + k4z[Count1]);

        ++PlanetIt;

    }

    // Increment Time Counter
    ElapsedTime += h;

    // Update Coordinates
    PlanetIt = PlanetList.begin();

    double COMX, COMY, COMZ;
    CalcCOM(&COMX, &COMY, &COMZ);
    Count1 = 0;

    while (PlanetIt != PlanetList.end()) {
        if ((*PlanetIt).second->PlanetInfo.XCoordinate.size() >= TrailLength) {
            int excess = (*PlanetIt).second->PlanetInfo.XCoordinate.size() - TrailLength;
            (*PlanetIt).second->PlanetInfo.XCoordinate.erase((*PlanetIt).second->PlanetInfo.XCoordinate.begin(), (*PlanetIt).second->PlanetInfo.XCoordinate.begin()+excess);
            (*PlanetIt).second->PlanetInfo.YCoordinate.erase((*PlanetIt).second->PlanetInfo.YCoordinate.begin(), (*PlanetIt).second->PlanetInfo.YCoordinate.begin()+excess);
            (*PlanetIt).second->PlanetInfo.ZCoordinate.erase((*PlanetIt).second->PlanetInfo.ZCoordinate.begin(), (*PlanetIt).second->PlanetInfo.ZCoordinate.begin()+excess);
        }

        // Transform coordinates to appropriate frame
        if (FrameChoice == ORIGINAL) {
            (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX);
            (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY);
            (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ);
        } else if (FrameChoice == COMORIGIN) {
            (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX - COMX);
            (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY - COMY);
            (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ - COMZ);
        } else if (FrameChoice == PLANETORIGIN) {
            if (PlanetList.count(CustomPlanetOriginId) == 0) {
                // In case planet has not been created yet.
                (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX);
                (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY);
                (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ);
            } else {
                // Simply subtract
                (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX - PlanetList[CustomPlanetOriginId]->CurrentX);
                (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY - PlanetList[CustomPlanetOriginId]->CurrentY);
                (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ - PlanetList[CustomPlanetOriginId]->CurrentZ);
            }

        } else if (FrameChoice == CUSTOMORIGIN) {
            (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX - CustomX);
            (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY - CustomY);
            (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ - CustomZ);
        }

        if (TranslatingOrigin) {
            std::deque<double>::iterator CoordIt;

            CoordIt = (*PlanetIt).second->PlanetInfo.XCoordinate.end();
            --CoordIt;
            (*CoordIt) -= ElapsedTime * OriginvX;

            CoordIt = (*PlanetIt).second->PlanetInfo.YCoordinate.end();
            --CoordIt;
            (*CoordIt) -= ElapsedTime * OriginvY;

            CoordIt = (*PlanetIt).second->PlanetInfo.ZCoordinate.end();
            --CoordIt;
            (*CoordIt) -= ElapsedTime * OriginvZ;
        }

        if (Rotation) {
            std::deque<double>::iterator CoordIt;
            double TempX, TempY;

            TempX = (*PlanetIt).second->PlanetInfo.XCoordinate.back();
            TempY = (*PlanetIt).second->PlanetInfo.YCoordinate.back();

            CoordIt = (*PlanetIt).second->PlanetInfo.XCoordinate.end();
            --CoordIt;
            (*CoordIt) = TempX * std::cos(-RotationFrequency*ElapsedTime) - TempY*std::sin(-RotationFrequency*ElapsedTime);

            CoordIt = (*PlanetIt).second->PlanetInfo.YCoordinate.end();
            --CoordIt;
            (*CoordIt) = TempX * std::sin(-RotationFrequency*ElapsedTime) + TempY*std::cos(-RotationFrequency*ElapsedTime);
        }
        // End of Origin Transformation

        // Calculate Orbital Period
        double CurrentAngle = std::atan2((*PlanetIt).second->CurrentY - COMY, (*PlanetIt).second->CurrentX - COMX);
        // Set Initial Angle
        if ((*PlanetIt).second->Revolution > 0) {
            // For all subsequent revolutions
            if ((*PlanetIt).second->FirstSignFlip == false) {
                // Check if angle has flipped sign
                if ((*PlanetIt).second->InitialAngle >= 0) {
                    if (CurrentAngle < 0) (*PlanetIt).second->FirstSignFlip = true;
                } else {
                    if (CurrentAngle >= 0) (*PlanetIt).second->FirstSignFlip = true;
                }
            } else if ((*PlanetIt).second->SecondSignFlip == false) {
                // Check if 2nd sign flip has occured
                if ((*PlanetIt).second->InitialAngle >= 0) {
                    if (CurrentAngle >= 0) (*PlanetIt).second->SecondSignFlip = true;
                } else {
                    if (CurrentAngle < 0) (*PlanetIt).second->SecondSignFlip = true;
                }
            } else {
                // Check if orbit completed
                if ((*PlanetIt).second->Clockwise == false) {
                    if (CurrentAngle >= (*PlanetIt).second->InitialAngle) {
                        (*PlanetIt).second->OrbitalPeriod = ElapsedTime - (*PlanetIt).second->PreviousRevStart;
                        (*PlanetIt).second->PreviousRevStart = ElapsedTime;
                        (*PlanetIt).second->Revolution++;
                        (*PlanetIt).second->FirstSignFlip = false;
                        (*PlanetIt).second->SecondSignFlip = false;
                    }
                } else {
                    if (CurrentAngle <= (*PlanetIt).second->InitialAngle) {
                        (*PlanetIt).second->OrbitalPeriod = ElapsedTime - (*PlanetIt).second->PreviousRevStart;
                        (*PlanetIt).second->PreviousRevStart = ElapsedTime;
                        (*PlanetIt).second->Revolution++;
                        (*PlanetIt).second->FirstSignFlip = false;
                        (*PlanetIt).second->SecondSignFlip = false;
                    }
                }
            }
        } else {
            // For first revolution
            if ((*PlanetIt).second->OrbitalPeriod == PERIODNOTSET) {
                if (CurrentAngle != 0) {
                    (*PlanetIt).second->InitialAngle = CurrentAngle;
                    (*PlanetIt).second->OrbitalPeriod++;
                }
            } else if ((*PlanetIt).second->OrbitalPeriod <= -1) {
                (*PlanetIt).second->OrbitalPeriod++;
            } else if ((*PlanetIt).second->OrbitalPeriod == -1) {
                // Assume counterclockwise if current angle is greater than initial angle.
                if (CurrentAngle > (*PlanetIt).second->InitialAngle) {
                    (*PlanetIt).second->Clockwise = false;
                }
                // Assume clockwise if current angle is less than initial angle.
                else if (CurrentAngle < (*PlanetIt).second->InitialAngle && CurrentAngle) {
                    (*PlanetIt).second->Clockwise = true;
                }
                // In all other cases try calculating again
                else {
                    (*PlanetIt).second->OrbitalPeriod = PERIODNOTSET - 1;
                }
                (*PlanetIt).second->OrbitalPeriod++;
            } else if ((*PlanetIt).second->OrbitalPeriod == 0) {
                if ((*PlanetIt).second->FirstSignFlip == false) {
                    // Check if angle has flipped sign
                    if ((*PlanetIt).second->InitialAngle >= 0) {
                        if (CurrentAngle < 0) (*PlanetIt).second->FirstSignFlip = true;
                    } else {
                        if (CurrentAngle >= 0) (*PlanetIt).second->FirstSignFlip = true;
                    }
                } else if ((*PlanetIt).second->SecondSignFlip == false) {
                    // Check if 2nd sign flip has occured
                    if ((*PlanetIt).second->InitialAngle >= 0) {
                        if (CurrentAngle >= 0) (*PlanetIt).second->SecondSignFlip = true;
                    } else {
                        if (CurrentAngle < 0) (*PlanetIt).second->SecondSignFlip = true;
                    }
                } else {
                    // Check if orbit completed
                    if ((*PlanetIt).second->Clockwise == false) {
                        if (CurrentAngle >= (*PlanetIt).second->InitialAngle) {
                            (*PlanetIt).second->OrbitalPeriod = ElapsedTime;
                            (*PlanetIt).second->PreviousRevStart = ElapsedTime;
                            (*PlanetIt).second->Revolution = 1;
                            (*PlanetIt).second->FirstSignFlip = false;
                            (*PlanetIt).second->SecondSignFlip = false;
                        }
                    } else {
                        if (CurrentAngle <= (*PlanetIt).second->InitialAngle) {
                            (*PlanetIt).second->OrbitalPeriod = ElapsedTime;
                            (*PlanetIt).second->PreviousRevStart = ElapsedTime;
                            (*PlanetIt).second->Revolution = 1;
                            (*PlanetIt).second->FirstSignFlip = false;
                            (*PlanetIt).second->SecondSignFlip = false;
                        }
                    }
                }
            }
        }
        // End of Orbital Period Calculation

        // Calculate additional parameters for ViewInfo Dialog.
        if (!(*PlanetIt).second->ViewInfo) {
            // Don't Calculate
        } else {
            // Calculate distance from COM
            (*PlanetIt).second->DistanceCOM = std::sqrt(((*PlanetIt).second->CurrentX - COMX) * ((*PlanetIt).second->CurrentX - COMX)
                                                        + ((*PlanetIt).second->CurrentY - COMY) * ((*PlanetIt).second->CurrentY - COMY)
                                                        + ((*PlanetIt).second->CurrentZ - COMZ) * ((*PlanetIt).second->CurrentZ - COMZ));


            // Calculate Accelerations
            (*PlanetIt).second->AccelX = (j1x[Count1] + 2*j2x[Count1] + 2*j3x[Count1] + j4x[Count1]) / 6;
            (*PlanetIt).second->AccelY = (j1y[Count1] + 2*j2y[Count1] + 2*j3y[Count1] + j4y[Count1]) / 6;
            (*PlanetIt).second->AccelZ = (j1z[Count1] + 2*j2z[Count1] + 2*j3z[Count1] + j4z[Count1]) / 6;

            // Calculate GPE
            (*PlanetIt).second->GPE = 0;
            PlanetItInner = PlanetList.begin();
            while (PlanetItInner != PlanetList.end()) {
                if ((*PlanetItInner).second != (*PlanetIt).second) {
                    // Find the distance
                    x = (*PlanetIt).second->CurrentX - (*PlanetItInner).second->CurrentX;
                    y = (*PlanetIt).second->CurrentY - (*PlanetItInner).second->CurrentY;
                    z = (*PlanetIt).second->CurrentZ - (*PlanetItInner).second->CurrentZ;
                    invDistance = 1 / sqrt(x*x + y*y + z*z);

                    (*PlanetIt).second->GPE -= GConstant * (*PlanetItInner).second->Mass * (*PlanetIt).second->Mass * invDistance;

                }
                ++PlanetItInner;
            }

            // Calculate KE
            (*PlanetIt).second->KE = 0.5 * (*PlanetIt).second->Mass * ((*PlanetIt).second->CurrentvX * (*PlanetIt).second->CurrentvX +
                                                                       (*PlanetIt).second->CurrentvY * (*PlanetIt).second->CurrentvY +
                                                                       (*PlanetIt).second->CurrentvZ * (*PlanetIt).second->CurrentvZ);

            // Calculate TE
            (*PlanetIt).second->TE = (*PlanetIt).second->KE + (*PlanetIt).second->GPE;
        }


        ++PlanetIt;
        ++Count1;
    }
    return;
}

/*
    Get Max Elements
    Places the maximum X and Y coordinates in the addresses provided
*/
void SolarSystem::GetMaxElements(double* MaxX, double* MaxY)
{
    if (this->IsEmpty()) {
        // Do nothing if empty
        *MaxX = 0;
        *MaxY = 0;
    }

    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();

    std::vector<double> PlanetMaxX, PlanetMaxY;
    double TempMax;
    double TempMin;

    // Get maximum coordinate drawn from each trail
    while (PlanetIt != PlanetList.end()) {
        // X Coordinate
        TempMax = std::abs(*(std::max_element((*PlanetIt).second->PlanetInfo.XCoordinate.begin(), (*PlanetIt).second->PlanetInfo.XCoordinate.end())));
        TempMin = std::abs(*(std::min_element((*PlanetIt).second->PlanetInfo.XCoordinate.begin(), (*PlanetIt).second->PlanetInfo.XCoordinate.end())));
        PlanetMaxX.push_back((TempMax >= TempMin ? TempMax : TempMin));

        // Y Coordinate
        TempMax = std::abs(*(std::max_element((*PlanetIt).second->PlanetInfo.YCoordinate.begin(), (*PlanetIt).second->PlanetInfo.YCoordinate.end())));
        TempMin = std::abs(*(std::min_element((*PlanetIt).second->PlanetInfo.YCoordinate.begin(), (*PlanetIt).second->PlanetInfo.YCoordinate.end())));
        PlanetMaxY.push_back((TempMax >= TempMin ? TempMax : TempMin));

        ++PlanetIt;
    }

    // Find the system-wide maximum coordinate.
    MaxXCoord = *(std::max_element(PlanetMaxX.begin(), PlanetMaxX.end()));
    MaxYCoord = *(std::max_element(PlanetMaxY.begin(), PlanetMaxY.end()));

    /*
    if (TempX > SCALEMAXTOLERANCE * MaxXCoord || TempX < SCALEMINTOLERANCE * MaxXCoord) {
        MaxXCoord = TempX;
    }
    if (TempY > SCALEMAXTOLERANCE * MaxYCoord || TempY < SCALEMINTOLERANCE * MaxYCoord) {
        MaxYCoord = TempY;
    }
    */

    // Pass coordinates to main frame.
    *MaxX = MaxXCoord;
    *MaxY = MaxYCoord;
}




/////////////////////////////////////////
//          PRIVATE FUNCTIONS          //
/////////////////////////////////////////

/*
    Returns new planet ID.
*/
int SolarSystem::NewPlanetID(void)
{
    while (PlanetList.count(IDCounter) > 0) IDCounter++;
    return IDCounter;
}

/*
    Calculates the centre of mass of the system
    Returns in the three integers passed.
*/
void SolarSystem::CalcCOM(double* COMX, double* COMY, double* COMZ)
{
    // Declare iterator for PlanetList
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();

    double TempX = 0;
    double TempY = 0;
    double TempZ = 0;
    double TotalMass = 0;
    while (PlanetIt != PlanetList.end()) {
        TotalMass += (*PlanetIt).second->Mass;

        TempX += (*PlanetIt).second->CurrentX * (*PlanetIt).second->Mass;
        TempY += (*PlanetIt).second->CurrentY * (*PlanetIt).second->Mass;
        TempZ += (*PlanetIt).second->CurrentZ * (*PlanetIt).second->Mass;

        ++PlanetIt;
    }

    *COMX = TempX / TotalMass;
    *COMY = TempY / TotalMass;
    *COMZ = TempZ / TotalMass;
}

/*
    Writes the current coordinates of all planets according to the given frame.
*/
void SolarSystem::WriteCurrentCoords()
{
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.begin();

    while (PlanetIt != PlanetList.end()) {
        WriteCurrentCoords((*PlanetIt).second->PlanetId);
        ++PlanetIt;
    }
}

void SolarSystem::WriteCurrentCoords(int ID)
{
    std::map<int, Planet*>::const_iterator PlanetIt = PlanetList.find(ID);

    if (FrameChoice == ORIGINAL) {
        (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX);
        (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY);
        (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ);
    } else if (FrameChoice == COMORIGIN) {
        double COMX, COMY, COMZ;
        CalcCOM(&COMX, &COMY, &COMZ);

        (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX - COMX);
        (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY - COMY);
        (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ - COMZ);
    } else if (FrameChoice == PLANETORIGIN) {
        if (CustomPlanetOriginId == 0) {
            // Set default back to COM
            ChangeReferenceFrame(COMORIGIN);
            return;
        } else if (PlanetList.count(CustomPlanetOriginId) == 0) {
            // In case planet has not been created yet.
            (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX);
            (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY);
            (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ);
        } else {
            // Simply subtract
            (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX - PlanetList[CustomPlanetOriginId]->CurrentX);
            (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY - PlanetList[CustomPlanetOriginId]->CurrentY);
            (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ - PlanetList[CustomPlanetOriginId]->CurrentZ);
        }

    } else if (FrameChoice == CUSTOMORIGIN) {
        (*PlanetIt).second->PlanetInfo.XCoordinate.push_back((*PlanetIt).second->CurrentX - CustomX);
        (*PlanetIt).second->PlanetInfo.YCoordinate.push_back((*PlanetIt).second->CurrentY - CustomY);
        (*PlanetIt).second->PlanetInfo.ZCoordinate.push_back((*PlanetIt).second->CurrentZ - CustomZ);
    }

    if (TranslatingOrigin) {
        std::deque<double>::iterator CoordIt;

        CoordIt = (*PlanetIt).second->PlanetInfo.XCoordinate.end();
        --CoordIt;
        (*CoordIt) -= ElapsedTime * OriginvX;

        CoordIt = (*PlanetIt).second->PlanetInfo.YCoordinate.end();
        --CoordIt;
        (*CoordIt) -= ElapsedTime * OriginvY;

        CoordIt = (*PlanetIt).second->PlanetInfo.ZCoordinate.end();
        --CoordIt;
        (*CoordIt) -= ElapsedTime * OriginvZ;
    }

    if (Rotation) {
        std::deque<double>::iterator CoordIt;
        double TempX, TempY;

        TempX = (*PlanetIt).second->PlanetInfo.XCoordinate.back();
        TempY = (*PlanetIt).second->PlanetInfo.YCoordinate.back();

        CoordIt = (*PlanetIt).second->PlanetInfo.XCoordinate.end();
        --CoordIt;
        (*CoordIt) = TempX * std::cos(-RotationFrequency*ElapsedTime) - TempY*std::sin(-RotationFrequency*ElapsedTime);

        CoordIt = (*PlanetIt).second->PlanetInfo.YCoordinate.end();
        --CoordIt;
        (*CoordIt) = TempX * std::sin(-RotationFrequency*ElapsedTime) + TempY*std::cos(-RotationFrequency*ElapsedTime);
    }
}

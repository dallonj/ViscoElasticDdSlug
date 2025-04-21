//
//  cellclass.hpp
//  ErinSlug
//
//  Created by John Dallon on 8/9/23.
//

#ifndef cellclass_hpp
#define cellclass_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>


//slug dimension
const int ncx=3;
const int ncz=3;
const int ncy=5;// direction of motion and usually long direction of slug
//const int ncx=3;
//const int ncz=3;
//const int ncy=5;// direction of motion and usually long direction of slug
const int ncells=ncx*ncz*ncy;

struct Axis
{
    double vector[3];// must be unit vector
    double length;
    double length_old;
    double der_length;
    double force;
    double force_old;
    double der_force;
    double kmaxwell_spring;
    double mu;
    double kspring;
};
class Cell
{
private:

    
public:
    double center[3];
    Axis a;
    Axis b;
    Axis c;
    double motive_force;
    double boundary_force;
    double random_force;
    double direction[3];
    double area[ncells];
    int type; // 0 is PSP 1 is PST
    
    
    void initialize(int type, double xc, double yc, double zc, double k1a, double mua, double maxwellkspringa, double k1b, double mub, double maxwellkspringb, double k1c, double muc, double maxwellkspringc, double k2, double motive_force, double actb_force, double randforce, double dia, double randomdirxp, double randomdiryp, double randomdirzp,double randomdirxbp, double randomdirybp, double randomdirzbp);
    Cell();
    ~Cell();
    void orient();
    void initialize_axes(double x, double y, double z);

};
#endif /* cellclass_hpp */

//
//  cellclass.cpp
//  ErinSlug
//
//  Created by John Dallon on 8/9/23.
//

#include "cellclass.hpp"

// Constructor
Cell::Cell(){
}
// Destructor
Cell::~Cell(){
}

void Cell::initialize(int typep, double xc, double yc, double zc, double k1ap, double muap, double maxwellkspringap, double k1bp, double mubp, double maxwellkspringbp, double k1cp, double mucp, double maxwellkspringcp, double k2p, double motive_forcep, double actb_forcep, double randforcep, double diap, double randomdirxp,double randomdiryp, double randomdirzp,double randomdirxbp, double randomdirybp, double randomdirzbp){
    type=typep;
    center[0]=xc;
    center[1]=yc;
    center[2]=zc;
    motive_force=motive_forcep;
    boundary_force=actb_forcep;
    random_force=randforcep;
    // set axes variables
    a.force=0;
    a.length=diap;
    a.kmaxwell_spring=maxwellkspringap;
    a.kspring=k1ap;
    a.mu=mubp;
    b.force=0;
    b.length=diap;
    b.kmaxwell_spring=maxwellkspringbp;
    b.kspring=k1bp;
    b.mu=mubp;
    c.force=0;
    c.length=diap;
    c.kmaxwell_spring=maxwellkspringcp;
    c.kspring=k1cp;
    c.mu=mucp;
    b.vector[0]=randomdirxbp;
    b.vector[1]=randomdirybp;
    b.vector[2]=randomdirzbp;
    initialize_axes(randomdirxp,randomdiryp,randomdirzp);
    for (int k = 0;k <ncells; k++) {
        area[k]= 0;
    }
}

void Cell::initialize_axes(double x, double y, double z){// must be a unit vector
    a.vector[0]=x;
    a.vector[1]=y;
    a.vector[2]=z;
    double dot1 = 0;
    for (int k = 0;k <= 2; k++) {
        dot1 += a.vector[k] * b.vector[k];
    }
    double orth_b[3];
    for (int k = 0; k <= 2; k++) {
        orth_b[k] = b.vector[k] - dot1 * a.vector[k];
    }
    double stored_b = std::sqrt((orth_b[0]*orth_b[0]) + (orth_b[1]*orth_b[1]) + (orth_b[2]*orth_b[2]));
    for (int k = 0; k <= 2; k++) {
        b.vector[k] = orth_b[k] / stored_b;            //Normalise b
    }
    //Find a unit c vector orthogonal to a and b
    c.vector[0] = a.vector[1] * b.vector[2] - a.vector[2] * b.vector[1];
    c.vector[1] = a.vector[2] * b.vector[0] - a.vector[0] * b.vector[2];
    c.vector[2] = a.vector[0] * b.vector[1] - a.vector[1] * b.vector[0];
    double stored_c = std::sqrt((c.vector[0]*c.vector[0]) + (c.vector[1]*c.vector[1]) + (c.vector[2]*c.vector[2]));
    for (int k = 0; k <= 2; k++) 
        c.vector[k] = c.vector[k] / stored_c;            //Normalise b
    
    a.vector[0]=1;
    a.vector[1]=0;
    a.vector[2]=0;
    b.vector[0]=0;
    b.vector[1]=1;
    b.vector[2]=0;
    c.vector[0]=0;
    c.vector[1]=0;
    c.vector[2]=1;
    
}

//
// Created by Ankoor Bhagat on 7/11/18.
//

#include "Swarm.h"


namespace explosion {

    Swarm::Swarm() {
        m_pParticles = new Particle[nParticles];  // Allocate memory
    }

    Swarm::~Swarm() {
        delete [] m_pParticles;  // De-allocate memory
    }

}

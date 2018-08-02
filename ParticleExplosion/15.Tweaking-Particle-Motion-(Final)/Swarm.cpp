//
// Created by Ankoor Bhagat on 7/11/18.
//

#include "Swarm.h"


namespace explosion {

    Swarm::Swarm(): lastTime(0) {
        m_pParticles = new Particle[nParticles];  // Allocate memory
    }

    Swarm::~Swarm() {
        delete [] m_pParticles;  // De-allocate memory
    }

    void Swarm::update(int elapsed) {
        int interval = elapsed - lastTime;
        for(int i=0; i<Swarm::nParticles; i++) {
            m_pParticles[i].update(interval);
        }
        lastTime = elapsed;
    }

}
//
// Created by Ankoor Bhagat on 7/11/18.
//

#ifndef INC_9_CREATING_PARTICLES_SWARM_H
#define INC_9_CREATING_PARTICLES_SWARM_H

#include "Particle.h"

namespace explosion {

    class Swarm {
    private:
        Particle *m_pParticles;

    public:
        const static int nParticles = 5000;

    public:
        Swarm();
        virtual ~Swarm();

        // For getting particles from swarm
        const Particle * const getParticles() { return m_pParticles; }
    };

}


#endif //INC_9_CREATING_PARTICLES_SWARM_H

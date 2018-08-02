//
// Created by Ankoor Bhagat on 7/11/18.
//

#ifndef INC_10_ANIMATING_PARTICLES_SWARM_H
#define INC_10_ANIMATING_PARTICLES_SWARM_H

#include "Particle.h"

namespace explosion {

    class Swarm {
    private:
        Particle *m_pParticles;

    public:
        const static int nParticles = 1000;

    public:
        Swarm();
        virtual ~Swarm();

        // For getting particles from swarm
        const Particle * const getParticles() { return m_pParticles; }

        void update();
    };

}


#endif //INC_10_ANIMATING_PARTICLES_SWARM_H

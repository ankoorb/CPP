//
// Created by Ankoor Bhagat on 7/12/18.
//

#ifndef INC_11_CREATING_AN_EXPLOSION_SWARM_H
#define INC_11_CREATING_AN_EXPLOSION_SWARM_H


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

        void update();
    };

}


#endif //INC_11_CREATING_AN_EXPLOSION_SWARM_H

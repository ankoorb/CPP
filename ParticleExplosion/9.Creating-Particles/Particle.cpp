//
// Created by Ankoor Bhagat on 7/11/18.
//

#include "Particle.h"
#include <stdlib.h>  // For using rand


namespace explosion {

    Particle::Particle() {
        m_x = ((2.0 * rand())/RAND_MAX) - 1;  // Returns a number between -1 and 1
        m_y = ((2.0 * rand())/RAND_MAX) - 1;
    }

    Particle::~Particle() {}

}
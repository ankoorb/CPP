//
// Created by Ankoor Bhagat on 7/11/18.
//

#include "Particle.h"
#include <stdlib.h>  // For using rand


namespace explosion {

    Particle::Particle() {
        m_x = ((2.0 * rand())/RAND_MAX) - 1;  // Returns a number between -1 and 1
        m_y = ((2.0 * rand())/RAND_MAX) - 1;

        m_xspeed = 0.01 * (((2.0 * rand())/RAND_MAX) - 1);
        m_yspeed = 0.01 * (((2.0 * rand())/RAND_MAX) - 1);
    }

    Particle::~Particle() {}

    void Particle::update() {

        m_x += m_xspeed;
        m_y += m_yspeed;

        // Making particles off the edge
        if(m_x <= -1.0 || m_x >= 1.0) {
            m_xspeed = - m_xspeed;
        }

        if(m_y <= -1.0 || m_y >= 1.0) {
            m_yspeed = - m_yspeed;
        }
    }

}


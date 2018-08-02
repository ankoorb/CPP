//
// Created by Ankoor Bhagat on 7/11/18.
//

#include "Particle.h"
#include <math.h>
#include <stdlib.h>  // For using rand


namespace explosion {

    Particle::Particle(): m_x(0), m_y(0) {  // m_x(0), m_y(0) -> Particles will originate from center
        m_direction = (2 * M_PI * rand())/RAND_MAX;
        m_speed = (0.001 * rand())/RAND_MAX;
    }

    Particle::~Particle() {}

    void Particle::update() {
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);

        m_x += xspeed;
        m_y += yspeed;
    }

}


//
// Created by Ankoor Bhagat on 7/12/18.
//

#ifndef INC_11_CREATING_AN_EXPLOSION_PARTICLE_H
#define INC_11_CREATING_AN_EXPLOSION_PARTICLE_H

namespace explosion {

    struct Particle {
        double m_x;
        double m_y;

        double m_speed;
        double m_direction;

    public:
        Particle();
        virtual ~Particle();
        void update();  // Update the position of particle
    };

}


#endif //INC_11_CREATING_AN_EXPLOSION_PARTICLE_H

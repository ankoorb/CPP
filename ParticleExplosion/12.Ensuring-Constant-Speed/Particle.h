//
// Created by Ankoor Bhagat on 7/12/18.
//

#ifndef INC_12_ENSURING_CONSTANT_SPEED_PARTICLE_H
#define INC_12_ENSURING_CONSTANT_SPEED_PARTICLE_H

namespace explosion {

    struct Particle {
        double m_x;
        double m_y;

        double m_speed;
        double m_direction;

    public:
        Particle();
        virtual ~Particle();
        void update(int interval);  // Update the position of particle
    };

}


#endif //INC_12_ENSURING_CONSTANT_SPEED_PARTICLE_H

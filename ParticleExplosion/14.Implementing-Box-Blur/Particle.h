//
// Created by Ankoor Bhagat on 7/12/18.
//

#ifndef INC_14_IMPLEMENTING_BOX_BLUR_PARTICLE_H
#define INC_14_IMPLEMENTING_BOX_BLUR_PARTICLE_H

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


#endif //INC_14_IMPLEMENTING_BOX_BLUR_PARTICLE_H

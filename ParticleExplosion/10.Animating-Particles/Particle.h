//
// Created by Ankoor Bhagat on 7/11/18.
//

#ifndef INC_10_ANIMATING_PARTICLES_PARTICLE_H
#define INC_10_ANIMATING_PARTICLES_PARTICLE_H


namespace explosion {

    struct Particle {
        double m_x;
        double m_y;

        double m_xspeed;
        double m_yspeed;

    public:
        Particle();
        virtual ~Particle();
        void update();  // Update the position of particle
    };

}


#endif //INC_10_ANIMATING_PARTICLES_PARTICLE_H

//
// Created by Ankoor Bhagat on 7/11/18.
//

#ifndef INC_9_CREATING_PARTICLES_PARTICLE_H
#define INC_9_CREATING_PARTICLES_PARTICLE_H


namespace explosion {

//    class Particle {
//    private:
//        double m_x;  // double is used to change value gradually and round it off pixel position
//        double m_y;
//    public:
//        Particle();
//        virtual ~Particle();
//    };

    struct Particle {
        double m_x;
        double m_y;

    public:
        Particle();
        virtual ~Particle();
    };

}


#endif //INC_9_CREATING_PARTICLES_PARTICLE_H

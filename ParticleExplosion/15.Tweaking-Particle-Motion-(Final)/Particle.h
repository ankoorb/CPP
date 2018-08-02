//
// Created by Ankoor Bhagat on 7/12/18.
//

#ifndef INC_15_TWEAKING_PARTICLE_MOTION_FINAL_PARTICLE_H
#define INC_15_TWEAKING_PARTICLE_MOTION_FINAL_PARTICLE_H


namespace explosion {

    struct Particle {  // In struct public is default
        double m_x;
        double m_y;

    private:
        double m_speed;
        double m_direction;

    private:
        void init();

    public:
        Particle();
        virtual ~Particle();
        void update(int interval);  // Update the position of particle
    };

}


#endif //INC_15_TWEAKING_PARTICLE_MOTION_FINAL_PARTICLE_H

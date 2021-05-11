//
// Created by bily101 on 5/10/21.
//
#ifndef GAMETUT_PARTICLE_H
#define GAMETUT_PARTICLE_H

namespace GameTUT {
    class Particle {
    public:
        double m_x;
        double m_y;
        double m_speed;
        double m_direction;
    public:
        Particle();
        void update(int interval);
        virtual ~Particle();
    };
}

#endif //GAMETUT_PARTICAL_H

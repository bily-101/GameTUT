//
// Created by bily101 on 5/10/21.
//

#ifndef GAMETUT_SWARM_H
#define GAMETUT_SWARM_H
#include "Particle.h"

namespace GameTUT {
    class Swarm {
    public:
        const static int NPARTICLES = 5000;
    private:
        int lastTime;
        Particle * m_pParticles;
    public:
        Swarm();
        void update(int elapsed);
        virtual ~Swarm();
        const Particle * const getParticles() { return m_pParticles; };
    };
}

#endif //GAMETUT_SWARM_H

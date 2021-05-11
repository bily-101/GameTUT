//
// Created by bily101 on 5/10/21.
//

#include "Swarm.h"

namespace GameTUT {

    Swarm::Swarm(): lastTime(0) {

        m_pParticles = new Particle[NPARTICLES];
    }
    void Swarm::update(int elapsed) {
        int interval = elapsed - lastTime;
        for (int i = 0; i<Swarm::NPARTICLES; i++) {
            m_pParticles[i].update(interval);
        }

        lastTime = elapsed;
    }

    Swarm::~Swarm() {
        delete[] m_pParticles;
    }
}
/**
 * @file    sphinxsim_project.h
 * @brief   tbd.
 * @author  Xiangyu Hu
 */

#ifndef SPHINXSIM_PROJECT_H
#define SPHINXSIM_PROJECT_H

#include "composite_solid.h"
#include "simulation_scaling.h"

namespace SPH
{
class EntityManager;

bool addExtraMaterial(EntityManager &config_manager, SPHBody &sph_body, const json &config, const std::string &type);
} // namespace SPH

#endif // SPHINXSIM_PROJECT_H
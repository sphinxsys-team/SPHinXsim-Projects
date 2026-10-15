#include "sphinxsim_project.h"

namespace SPH
{
//=================================================================================================//
bool addExtraMaterial(EntityManager &config_manager, SPHBody &sph_body,
                      const json &config, const std::string &type)
{
    return false;
}
//=================================================================================================//
void addExtraEmitterFeatures(
    EntityManager &config_manager, MainMethods &main_methods,
    FluidBody &fluid_body, FluidSolverConfig &fluid_solver_config,
    StagePipeline<SimulationHookPoint> &simulation_pipeline,
    const json &config)
{

}
//=================================================================================================//
void addExtraInflowSpeed(
    EntityManager &config_manager, MainMethods &main_methods,
    FluidBody &fluid_body, OrientedBoxByParticle &emitter,
    ParticleDynamicsGroup &inflow_condition, const json &config)
{

}
//=================================================================================================//
} // namespace SPH

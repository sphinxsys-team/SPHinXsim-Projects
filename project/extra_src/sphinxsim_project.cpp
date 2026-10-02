#include "sphinxsim_project.h"
#include "riser_check.h"
#include "sphinxsys_entity.h"
#include "base_body.hpp"

#include <iostream>
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
    if (config.contains("riser_check"))
    {
        const json &riser_config = config.at("riser_check");
        auto &riser_fluid_height = addRiserCheck(config_manager, main_methods,fluid_body,config);
        auto &scaling_config = config_manager.getEntity<ScalingConfig>("ScalingConfig");
        Real target_height =scaling_config.jsonToReal(
                riser_config.at("target_height"),
                "Length");

        simulation_pipeline.insert_hook(
            SimulationHookPoint::AfterUpdateConfiguration,
            [&riser_fluid_height,
             &fluid_solver_config,
             target_height]()
            {
                if (fluid_solver_config.emitter_on_ &&
                    riser_fluid_height.exec() >= target_height)
                {
                    fluid_solver_config.emitter_on_ = false;

                    std::cerr << "Emitter stopped." << std::endl;
                }
            });
    }
}
//=================================================================================================//
} // namespace SPH
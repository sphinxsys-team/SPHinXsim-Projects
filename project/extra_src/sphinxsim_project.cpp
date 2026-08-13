#include "sphinxsim_project.h"

#include "base_body.hpp"
#include "sphinxsys_entity.h"

namespace SPH
{
//=================================================================================================//
bool addExtraMaterial(EntityManager &config_manager, SPHBody &sph_body, const json &config, const std::string &type)
{
    auto &scaling_config = config_manager.getEntity<ScalingConfig>("ScalingConfig");

    if (type == "composite_solid")
    {
        Real density = scaling_config.jsonToReal(config.at("density"), "Density");
        Real poisson_ratio = scaling_config.jsonToReal(config.at("poisson_ratio"), "Dimensionless");
        Real youngs_active = scaling_config.jsonToReal(config.at("youngs_modulus_active"), "Stress");
        Real youngs_1 = scaling_config.jsonToReal(config.at("youngs_modulus_1"), "Stress");
        Real youngs_2 = scaling_config.jsonToReal(config.at("youngs_modulus_2"), "Stress");
        auto &material = sph_body.defineMatterMaterial<CompositeSolidMaterial>(
            density, youngs_active, youngs_1, youngs_2, poisson_ratio);
        config_manager.addEntity(sph_body.Name() + "CompositeSolid", &material);
        return true;
    }
    return false;
}
//=================================================================================================//
} // namespace SPH
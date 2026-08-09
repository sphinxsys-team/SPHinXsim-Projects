# Instruction on developing SPHinXsim Projects

In this document, we wil provide the important information.

## What is a SPHinXsim Project?

We use the term **SPHinXsim Project** to describe a long term project aiming at simulating a complex multi-physics problem using SPHinXsim as the simulator. 

### Challenging ultimate objective

A essential characteristic of such project is that ultimate objective is so challenging that there is always something important to add for more realistic or scientifically more accurate simulation. Therefore, the problem to be simulated must be a scientific, typically multi-physics, problem currently under investigation but unsolved, and will be in such status for foreseeable future.

### Co-development with SPHinXsys and SPHinXsim

Another essential characteristic is that the project will be co-developed together with the other two projects, i.e. SPHinXsys and SPHinXsim. While the former provides the numerical solvers (as C++ library) of the physical problems involved and the latter provides the software by which the complex simulation can be built.
Therefore, the upward driving development, i.e. the new solvers and simulator functionalities leads to more physics included in the simulation, and downward one, i.e. the request for new physics push the development of new solvers or functionalities in the simulator.

## How to setup a SPHinXsim Project

The content of each project need be stored in the folder `project` with its specified project name as the branch name. Under `project`, there is a folder called  `extra_src` for saving C++ extra source code. There is also a `simulation` folder in which all simulation cases (including JSON config file and assets) are included in sub-folder with case name. There is also a `docs` saves documentation and some other files (such as skills) used for enhancing the AI assistance. 
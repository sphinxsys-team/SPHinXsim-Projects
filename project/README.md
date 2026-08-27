# Instructions for developing SPHinXsim Projects

This document explains the purpose of the repository, describes how to set up a project, and gives important guidance on branching, pull requests, and merges.

## What is a SPHinXsim Project?

A **SPHinXsim Project** to is a long‑term effort to simulate a complex, multi‑physics problem using SPHinXsim as the simulation environment.

### Ambitious, long‑term goal

A defining feature of such a project is that the ultimate objective is so challenging that there is always something meaningful left to add – more realistic physics, higher accuracy, or additional phenomena. The problem must therefore be an open scientific question (typically multi‑physics) that is under active investigation and will likely remain unsolved for the foreseeable future.

### Co-development with SPHinXsys and SPHinXsim

Another defining characteristic is that the project evolves together with two other projects:

- **SPHinXsys** – provides the numerical solvers as a C++ library.
- **SPHinXsim** – the software framework that lets you assemble and run complex simulations.

Development flows in both directions:

- **Bottom‑up**: new solvers and simulator features enable more physics to be included in the simulation.
- **Top‑down**: the need for new physics drives the creation of new solvers or simulator functionality.

## How to setup a SPHinXsim Project

Each project lives in its own branch, and the branch name must be the project name. All project‑specific files are stored in a directory called `project/` at the repository root. That directory has a fixed internal structure:

1. `extra_src/` – C++ source code that is needed to build the simulation but is not part of the core libraries.
   An umbrella header `sphinxsim_project.h` must be provided; it should include all extra classes and functions.

2. `simulation/` – contains all simulation cases. Each case resides in a sub‑folder named after the case. A case folder includes the JSON configuration file and any assets (e.g., geometry files, initial conditions).

3. `docs/` – documentation for the project and auxiliary files (for example, “skills” definitions that enhance AI‑assisted development).

To help you get started, the repository already includes an example project called `fish-swimming` on its own branch. You can check out that branch and explore its project/ directory to see a concrete, working layout that you can use as a reference when creating your own project (Please do NOT branch from it if working for your own project).

## Branching, Pull Requests, and Merging

Although this repository is a fork of SPHinXsim, we maintain it independently.
Project branches are never pushed back to the upstream SPHinXsim repository.

To keep the main history clean and to control how upstream changes enter the projects, we use two special branches:

- `main` – tracks the upstream SPHinXsim. No direct contributions from project branches are allowed.
- `project-template` – an intermediate, safeguarded branch. It is the only branch that is allowed to receive updates from upstream (by merging `main` into it).

All project branches must follow these rules:

- Create project branches exclusively from `project-template`.
- The only allowed merge from a shared branch is merging `project-template` into your project branch (to pick up template updates).
- Never merge a project branch directly into `main` or into `project-template`.

This workflow ensures that:

- Project branches remain isolated from each other and from the upstream history.
- Upstream changes flow only through `project-template`, where they can be reviewed and adapted before reaching the projects.

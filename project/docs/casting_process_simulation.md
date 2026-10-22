# Casting Process Simulation: A Technical Review of Defect Prediction and Commercial Platforms

**Abstract**

Casting simulation has evolved from a niche numerical exercise into an indispensable tool for foundry engineering, driven by the need to predict defects, reduce trial-and-error, and shorten development cycles. This review examines the current landscape of casting simulation with a focus on defect prediction and the four most prominent commercial platforms: FLOW-3D CAST, ProCAST, MAGMASoft, and ANSYS Fluent. It surveys the principal defect categories that simulation targets—porosity, filling-related defects, thermo-mechanical defects, and oxide inclusions—and then analyses how each software addresses these challenges through distinct numerical strategies and modelling philosophies. A comparative synthesis identifies the centre of gravity of each tool and the persistent gaps that remain between simulation and physical reality.

---

## 1. Introduction

Computer simulation of casting processes rests on the numerical solution of coupled equations for fluid flow, heat transfer, and solidification, with extensions into stress, microstructure, and defect kinetics. The theoretical foundations span finite difference, finite element, and finite volume methods, and modern packages increasingly incorporate multiphysics and data-driven approaches to improve predictive accuracy. A recent comparative analysis of commercial and research software—including ProCAST, MAGMASoft, FLOW-3D Cast, ANSYS, SolidCast, NovaFlow&Solid, and QuikCAST—highlights that tool selection depends on casting type, geometric complexity, and the required level of defect prediction accuracy, as well as on integration with CAD/CAE/CAM systems for digital-twin development.

The credibility of any simulation tool ultimately rests on validation against physical experiments. This review therefore privileges studies that report experimental corroboration alongside descriptions of modelling capability.

---

## 2. A Taxonomy of Casting Defects Targeted by Simulation

Casting defects can be grouped into four broad categories that correspond to distinct physical mechanisms and modelling requirements.

### 2.1 Porosity: Shrinkage and Gas

Porosity is a pervasive defect that degrades mechanical properties and pressure tightness. It arises from two principal mechanisms: volumetric shrinkage during solidification, where feeding is insufficient to compensate for contraction, and gas precipitation, where dissolved gases evolve as solubility drops. Simulation predicts porosity by coupling thermal fields with feeding-flow analysis and, in more advanced models, gas segregation kinetics. In MAGMASoft, for example, the Niyama criterion is used as an indicator of poor directional solidification, with values below a critical threshold (typically around 1) flagging microporosity risk, and a dedicated “Microporosity” result quantifies the defect for comparison across designs.

### 2.2 Filling-Related Defects

These defects form during mold filling and include air entrapment, oxide films, cold shuts, and misruns. Air entrapment produces gas porosity or surface defects; cold shuts occur when two melt streams meet but fail to fuse; misruns arise when metal solidifies before filling a thin section. Filling-related defects are strongly governed by free-surface dynamics, turbulence, and gating design, making them particularly sensitive to the fidelity of the flow solver.

### 2.3 Thermo-Mechanical Defects: Hot Tears and Residual Stress

Hot tears are intergranular cracks that form during the final stages of solidification, when thermal contraction is restrained by the mold or by already-solid regions while a coherent but weak mushy zone persists. Residual stress and distortion arise from differential cooling and phase transformations. Predicting these defects requires coupled thermo-mechanical analysis. ProCAST and MAGMASoft both contain thermo-mechanical modules capable of estimating stresses and hot tears, although a review of simulation systems notes that these modules are “rarely used” in routine foundry practice. A validation study specifically compared the hot-tearing indices of ProCAST and MagmaSoft against experimental results across multiple cases. ProCAST offers two built-in hot-tearing models, the Gurson and RDG models, and its predicted susceptibility has shown overall agreement with experimental observations in squeeze casting.

### 2.4 Oxide-Related Defects: Films, Bifilms, and Reoxidation Inclusions

Oxide-related defects deserve particular attention because they are frequently misunderstood. The term does not refer merely to the surface region of the melt. When molten metal—especially aluminium and high-alloy steels—is exposed to air during pouring, a thin, solid oxide skin forms almost instantly on the free surface. If the flow is disturbed, this brittle film can fold over, break up, and become entrained into the bulk as a **bifilm**: a double-layered oxide film that acts as a stress raiser and crack-initiation site, and that can trap air pockets responsible for scattered porosity. In steel castings, reoxidation inclusions are a dominant subset: one estimate attributes 83% of macro-inclusions in low-alloy steel castings and 48% in high-alloy steels to reoxidation. Oxide films in high-alloy steels have been measured at thicknesses of 10–100 μm and occur as both surface films and tenacious fold films.

The simulation challenge is therefore twofold: estimating the rate of oxide formation at the free surface, and tracking where the entrained material ultimately resides. The following sections examine how each platform addresses this and the other defect categories.

---

## 3. FLOW-3D CAST: Specialisation in Free-Surface Flow

FLOW-3D CAST is a dedicated casting tool built on the FLOW-3D solver, distinguished by two numerical methods that directly target the physics of mold filling.

### 3.1 TruVOF and FAVOR

The **TruVOF** (Volume of Fluid) method provides accurate tracking of sharp, fast-moving metal fronts by solving the volume-fraction equation with advanced interface-capturing techniques. The **FAVOR** (Fractional Area/Volume Obstacle Representation) method allows complex geometries to be represented on a Cartesian mesh without stair-stepping, by computing partial cell face areas and volumes at solid boundaries. Together, these methods give FLOW-3D CAST a strong claim to fidelity in filling simulations where turbulence, splashing, and air entrapment dominate. A comparative assessment notes that FLOW-3D “stands out for its exceptional modeling of fluid flow behavior, including turbulence, splashing, and air entrapment”.

### 3.2 Validation and Defect Prediction

FLOW-3D CAST has been validated against experimental castings for porosity defects. In one documented case, an aluminium casting with significant porosity—sufficient to cause rejection against functional specifications—was simulated, and the predicted porosity was compared with experimental findings. Japanese validation work reports that shrinkage porosity predicted by FLOW-3D CAST matched locations observed in real products, and that cavitation erosion zones correctly aligned with actual cases. Oxide film transport models have also been applied in FLOW-3D to casting experiments and an industry case study, as part of a programme developing validated oxide-defect modelling for high-alloy steels.

The principal trade-off of the Cartesian-mesh approach is that extremely complex geometries may require careful local refinement to achieve the highest surface detail, with attendant computational cost. The tool’s historical centre of gravity remains fluid flow and solidification rather than advanced thermo-mechanical fatigue of tooling.

---

## 4. ProCAST: Thermo-Mechanical Depth and Oxide Tracking

ProCAST, developed within the ESI group and now associated with Keysight, is a finite-element-based platform oriented toward comprehensive multiphysics across the full casting cycle.

### 4.1 Core Capabilities

ProCAST simulates filling, solidification, cooling, and defect prediction in an integrated workflow. It is recognised for accurate modelling of shrinkage phenomena and thermo-mechanical stresses, and its finite-element approach provides good approximation of complex boundaries for thermal and mechanical calculations. The software includes a two-phase VOF flow solver for filling dynamics and covers sand casting, die casting, investment casting, and low-pressure die casting. Its hot-tearing prediction capabilities rest on built-in Gurson and RDG models.

### 4.2 Oxide Defect Prediction

ProCAST’s approach to oxide defects is built around quantifying the exposure of the free surface to atmosphere, the precursor to oxide formation. The key metric is **Free Surface Time Exposure**, with units of cm²·s: at each point on the free surface, the surface area is multiplied by the time of exposure, and this value is cumulated over successive timesteps and transported with the flow field. This allows the software not only to identify where oxides are forming but also to predict **where they are most likely to end up** in the casting after entrainment. Experiments have been executed to validate these functions.

Beyond the built-in indicator, research has coupled more sophisticated models with ProCAST. The **Oxide Entrainment Number (OEN)** has been developed to predict the location and severity of bifilms and oxide-induced defects, tracking newly formed bifilms via free-surface tracking, and has been experimentally validated with aluminium A356 castings. The OEN model has been shown to predict both the location and severity of entrained oxide inclusions, with validation of its volume prediction demonstrating utility for final cast structures.

### 4.3 Limitations

ProCAST’s finite-element meshing can be a bottleneck: mesh generation for complex geometries is more involved than for Cartesian approaches, and computation times can be longer. It is a high-cost platform that rewards users with strong theoretical and practical expertise.

---

## 5. MAGMASoft: Process Optimisation and Inclusion Life-Cycle Modelling

MAGMASoft, developed by MAGMA GmbH, is a finite-difference-based platform with a pronounced emphasis on process optimisation and automated design.

### 5.1 Optimisation and Foundry Workflow

MAGMASoft is distinguished by powerful capabilities for optimising process parameters, including automated procedures for sizing castings and gating systems that reduce trial-and-error. It simulates filling from multiple inlets with different boundary conditions and has introduced an optimised surface-tension algorithm to improve accuracy in complex filling processes. The software covers filling, crystallisation, stress/strain, and microstructure across a wide range of alloys and processes.

### 5.2 Reoxidation Inclusion Model

MAGMASoft treats oxide defects as the life cycle of **reoxidation inclusions**. In an independent reoxidation model, the software simulates the **formation, growth, movement, and agglomeration** of inclusions throughout filling. The model has been described in detail for steel casting: a combined theoretical and experimental study at the University of Iowa developed a model predicting the growth, agglomeration, and motion of oxide inclusions, implemented in MAGMAsoft and validated against radiographically measured inclusion number densities and volume fractions in cast steel plates.

For interpretation, MAGMASoft provides two key outputs. The **Inclusion Diameter Tracer** visualises the formation, growth, movement, and agglomeration of inclusions; larger predicted diameters indicate a higher tendency for practical defects. The **Inclusion Area Fraction** is calculated on the casting surface from the predicted reoxidation inclusions, providing a quantitative measure of expected surface-defect severity. Oxide film transport models have been calibrated and applied in MAGMASoft to casting experiments and an industry case study, alongside parallel work in FLOW-3D.

### 5.3 Hot Tearing and Thermo-Mechanical Analysis

MAGMASoft’s hot-tearing indices have been validated against experimental results in a comparative study with ProCAST. Its stress simulation capabilities have found widespread use in automotive and general engineering castings for tackling distortion and cracking.

### 5.4 Limitations

A reviewer noted that MAGMASoft, as a macroscopic-based tool, has limitations compared with general-purpose CFD codes such as ANSYS Fluent in simulating complex two-phase flows, particularly regarding bubble sizes and splash formation. The interface is sometimes described as complex, and significant time is required for data input.

---

## 6. ANSYS: General-Purpose CFD and Multiphysics Coupling

ANSYS Fluent (and CFX) occupies a different position in the landscape: it is a general-purpose CFD and multiphysics platform that can be adapted for casting simulation rather than a dedicated foundry tool.

### 6.1 Fluid Flow Fidelity

Because it is a general-purpose solver, ANSYS Fluent is often considered capable of better recreating real conditions for complex fluid dynamics—including two-phase flows and bubble formation—than specialised macroscopic casting codes. This makes it valuable for fundamental studies of filling phenomena where detailed interfacial physics matters.

### 6.2 Validation for Casting Applications

ANSYS Fluent has been validated for porosity prediction in aluminium casting. A study using a CFD approach with Fluent created a simulation model for turbulent flow and solidification inside the mould cavity and validated it against existing experimental research, reporting quantitative porosity predictions. Further work has applied Fluent to thin-wall aluminium pump impeller structures and validated the predicted shrinkage and porosity distribution experimentally. In continuous casting of steel, a conjugate turbulent fluid-flow–heat-transfer model embodied in ANSYS Fluent V18.0 has been formulated via the enthalpy–porosity method and validated against plant temperature measurements.

### 6.3 Multiphysics Coupling

ANSYS offers integrated solvers for interactions among heat transfer, melt-pool evolution, residual stress, and structural deformation, and its strength lies in high-fidelity multiphysics coupling for applications such as continuous casting. Multiphysics models developed within the ANSYS Fluent environment have been used to quantify defect-formation mechanisms related to flow instability, particle transport and capture, and superheat transport in continuous steel casting.

### 6.4 Limitations

The principal limitation is the absence of foundry-specific workflows: gating-and-riser design, process-specific material databases, and automated optimisation routines are not native to the platform. Setting up a casting simulation requires more manual effort and expertise than with ProCAST or MAGMASoft. Specific casting phenomena may also require user implementation; one study noted that cavitation was not implemented in a continuous-casting model, leading to incorrect flow predictions. Reviews also highlight remaining gaps in material-model accuracy and unified simulation standards for multiphysics coupling.

---

## 7. Comparative Synthesis

The four platforms occupy distinct niches, and the choice among them should be governed by the dominant physics of the problem rather than by a search for a universally superior tool.

| Platform | Numerical Core | Centre of Gravity | Oxide-Defect Strategy | Principal Trade-off |
|---|---|---|---|---|
| **FLOW-3D CAST** | TruVOF + FAVOR (Cartesian) | Free-surface filling fidelity; turbulence, splashing, air entrapment | Oxide film transport models applied and calibrated | Cartesian mesh may need refinement for extreme geometric detail |
| **ProCAST** | Finite element | Thermo-mechanical integrity; shrinkage, stress, hot tears | Free Surface Time Exposure indicator; OEN model for bifilms | Complex meshing; high expertise and cost |
| **MAGMASoft** | Finite difference | Process optimisation; automated gating and riser design | Full reoxidation inclusion life cycle; Inclusion Area Fraction | Macroscopic two-phase flow limitations vs. general CFD |
| **ANSYS Fluent** | Finite volume (general CFD) | Fundamental flow physics; multiphysics coupling | Not a native casting-specific model | No foundry-specific workflows; manual setup |

A 2025 comparative analysis captures this differentiation succinctly: MAGMASoft is noted for powerful process-parameter optimisation, ProCAST for accurate modelling of shrinkage and thermo-mechanical stresses, and FLOW-3D Cast for its fluid-flow strengths. ProCAST is also described as offering a balanced approach between usability and technical depth, making it accessible to medium and large foundries.

On the specific question of oxide defects, both ProCAST and MAGMASoft move well beyond a naive treatment of the surface layer. ProCAST quantifies surface exposure and transports the resulting indicator with the flow to predict final oxide locations, while MAGMASoft models the complete life cycle of inclusions and provides surface-quality metrics. Independent validation exists for both approaches: the OEN model coupled with ProCAST has been validated on A356 aluminium, and MAGMASoft’s inclusion model has been tuned and validated against radiographic measurements in steel. Oxide film transport models have been calibrated in both FLOW-3D and MAGMASoft for high-alloy steel applications.

The persistent gap across all platforms is the validation base. While individual studies report good agreement for specific defects in specific alloys, comprehensive, cross-platform benchmarks remain scarce. The comparative analysis notes that results can show noticeable differences even when the same solidification models are solved, underscoring the importance of experimental validation against the user’s own process and alloy. The trend toward artificial intelligence and machine learning for parameter optimisation and defect prediction may help close this gap, but the fundamental need for physical ground truth remains.

---

## References

1. Dehula, A., Kharchenko, N., & Hryb, V. (2025). Analysis of software for modelling the casting technological process. *Mathematical and Computer Modelling. Series: Technical Sciences*. Kamianets-Podilskyi National Ivan Ohiienko University. http://mcm-tech.kpnu.edu.ua/article/view/342534 
2. Reoxidation Processes Prediction in Gating System by Numerical Simulation for Aluminium Alloys. (n.d.). *Biblioteka Nauki*. University of Žilina. https://bibliotekanauki.pl/articles/380662 
3. MAGMASoft. (n.d.). *Reoxidation Inclusion*. MAGMA Asia Pacific. https://www.magmasoft.com.sg/export/sites/MAGMA_AsiaPacific/.galleries/pdfs_publication/Defect-Articles/Top-7-most-common-casting-defects-in-Steel.pdf 
4. FLOW-3D. (2025). Metal Casting Archives. https://www.flow3d.com/tag/metal-casting/ 
5. FLOW-3D. (n.d.). FLOW-3D CAST 鋳造検証 [Casting validation]. https://www.flow3d.co.jp 
6. Ridgeway, C. D., Ripplinger, K., Detwiler, D., & Luo, A. A. (2020). Prediction of entrained oxide inclusions and oxide induced defects during directional flow in aluminum casting. *Transactions of the American Foundry Society*, 128, 59–70. 
7. Melendez, A. J., Carlson, K. D., & Beckermann, C. (2007). Simulation of reoxidation inclusion formation in steel casting. *Proceedings of the 61st SFSA Technical and Operating Conference*, Paper No. 3.8. Steel Founders’ Society of America. 
8. Hardin, R. (2026). *Modeling of Oxide Films in High Alloy Steel Castings*. University of Iowa, Emergent Metal Casting Technologies, AMC Technology Review. https://amc.ati.org/wp-content/uploads/2026/06/05-UI-2026.pdf 
9. An investigation on the solidification and porosity prediction in aluminium casting process. (2023). *Journal of Engineering and Applied Science*. Springer. https://link.springer.com 
10. Validation of hot tearing indices of ProCast and MagmaSoft. (n.d.). *Polytechnique Montréal*. https://publications.polymtl.ca 
11. Hot tearing behaviour and ProCAST models. (n.d.). *ScienceDirect*. https://www.sciencedirect.com 
12. Arul Mozhi Varman et al. (2025). CFD modeling and simulation of cold hearth continuous casting using FLOW-3D TruVOF and FAVOR techniques. *Light Metals 2025*, TMS 2025. https://dspace.lib.cranfield.ac.uk 
13. An Assessment of Physical and Mathematical Modelling approaches in the study of Flow and Solidification Phenomena in Continuous Casting of Steel. (2023). *Transactions of the Indian Institute of Metals*, 76(4), 1075–1084. https://doi.org/10.1007/s12666-022-02819-8 
14. Multiphysics models for defect formation in continuous steel casting. (n.d.). *University of Illinois*. https://ccc.illinois.edu
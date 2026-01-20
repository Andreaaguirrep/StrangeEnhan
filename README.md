# Enhanced Production of Multi-Strange Hadrons

This repository contains the analysis and results related to the study of the enhanced production of multi-strange hadrons using different Monte Carlo event generators.

---

## 📁 Repository Structure

### `finalGraphs/`
This directory contains the final plots produced in the analysis:

- **EPOSLHC_bCuts.pdf**  
  Optimal impact parameter ranges for each particle species using the **EPOS-LHC** Monte Carlo generator with **FUSION ON**.

- **ALL_ON.pdf**  
  Comparison between **EPOS-LHC**, **EPOS4**, and **PYTHIA** with all effects enabled (**ALL ON**)

- **ALL_separated_ON_and_OFF.pdf**  
Comparing separetly **EPOS-LHC**, **EPOS4**, and **PYTHIA**, with each model split into **ON** and **OFF** effects.

- **PYTHIA_ON_nMPI.png**  
  Average number of multiple parton interactions (**nMPI**) provided by **PYTHIA** for different impact parameter ranges (**FUSION ON**).

---

### `macros/`
This directory contains the **ROOT macros** used to generate all plots and perform the data analysis.

---

### `root_files/`
This directory contains the generated **Monte Carlo ROOT files** used as input for the analysis.

---

## 🛠️ Tools and Generators Used
- ROOT
- EPOS-LHC
- EPOS4
- PYTHIA

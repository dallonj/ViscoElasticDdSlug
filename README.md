# ViscoElasticDdSlug
Force based model of collective cell migration in Dictyostelium discoideum slug in 3D.  

This code requires Sundials code ARKODE and CVODE.  It also requires ceres solver with the associated google libraries, eigen3, and nlopt.

To compile on OSX Arm64
clang++ -O3 -stdlib=libc++ -std=c++17  main.cpp mersenne.cpp cellclass.cpp stoc1.cpp userintf.cpp -I/opt/homebrew/include/eigen3 -I/opt/homebrew/include -L/opt/homebrew/lib -lceres -lgflags -lglog -lsundials_arkode -lsundials_nvecserial -lsundials_kinsol -lsundials_cvode  -lsundials_core -lnlopt -lm -o Slug

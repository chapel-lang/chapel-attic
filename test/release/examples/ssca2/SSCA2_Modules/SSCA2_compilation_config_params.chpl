module SSCA2_compilation_config_params

// +==========================================================================+
// |  compilation time configuration parameters                               |
// |                                                                          |
// |  "FILTERING" turns edge filtering on and off (the value of the edge      |
// |  weight determines whether the edge is filtered or not).                 |
// |                                                                          |
// |  "VALIDATE_BC" causes the code to do additional work to demonstrate      |
// |  correct functioning.                                                    |
// |                                                                          |
// |  "REPRODUCIBLE_PROBLEMS" causes all random number streams to start from  |
// |  fixed (deterministic) seeds.                                            |
// |                                                                          |
// |  "PRINT_TIMING_STATISTICS" enables or disables timing measurement and    |
// |  documentation.  This mode is normally used with the preceding mode to   |
// |  create deterministic output for compiler regression testing.            |
// |                                                                          |
// |  "DISTRIBUTION_TYPE" selects among different distribution possiblities.  |
// |  At present, only "BLOCK" distributions is supported in the code.        |
// |  The alternative to "BLOCK" is "none" (undistributed).                   |
// +==========================================================================+

{
  config param FILTERING = false;

  config param VALIDATE_BC = false;

  config param DEBUG_GRAPH_GENERATOR = false;

  config param DEBUG_WEIGHT_GENERATOR = false;

  config param DEBUG_KERNEL2 = false;

  config param DEBUG_KERNEL3 = false;

  config param DEBUG_KERNEL4 = false;

  config param REPRODUCIBLE_PROBLEMS = true;

  config param PRINT_TIMING_STATISTICS = true;

  config param DISTRIBUTION_TYPE = "BLOCK";

  config param BUILD_TORUS_VERSIONS = false;
}



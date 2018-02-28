#pragma once

#include <vector>
#include <string>
#include <boost/dll.hpp>


std::vector<std::string>& all_generators() {
    static std::vector<std::string> generators = {"halton",
                                        "halton_large",
                                        "halton409",
                                        "halton409_large",
                                        "sobol",
                                        "sobol_large",
                                        "faure",
                                        "hammersley",
                                        "latin_random"
                                    };

    return generators;
}




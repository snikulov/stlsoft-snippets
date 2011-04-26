#include <algorithm>
#include <iostream>

#include <platformstl/platformstl.hpp>
#include <platformstl/filesystem/readdir_sequence.hpp>


using platformstl::readdir_sequence;

int main(int argc, char *argv[])
{
    readdir_sequence entries(argc > 1 ? argv[1] : ".",
			     readdir_sequence::files|readdir_sequence::directories);

    std::copy(entries.begin(), entries.end(),
	      std::ostream_iterator<char const*>(std::cout, "\n"));

    return EXIT_SUCCESS;
}





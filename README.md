# Version
Simple single-header Semantic Versioning in C++

```cpp
#include <iostream>

// Include Single Header
#include "SemanticVersion.h"

int main(int argc, char* argv[])
{
	SemanticVersion ver(1, 2, 3);
	SemanticVersion ver2("1.3.3");

	if (ver < ver2)
	{
		std::cout << "ver is less than ver2" << std::endl;
	}
	else
	{
		std::cout << "ver is greater than ver2" << std::endl;
	}

	return EXIT_SUCCESS;
}
```
`ver is less than ver2`

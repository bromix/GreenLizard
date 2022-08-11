# GreenLizard

Base package for GreenLizard.

## GreenLizard::String

The String class is like a wrapper/proxy for the native string of the platform. For example, on Windows, it is a wrapper
for the `std::basic_string<wchar_t>` (alias std::wstring) class.

```cpp
#include <GreenLizard/String.hpp>

using namespace GreenLizard;

void main()
{
    String str = "Hello World";
}
```
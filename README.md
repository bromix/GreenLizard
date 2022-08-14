# Green Lizard

# Motivation

For work, I needed recurring functions for an older project. The rather annoying problem was that we were working with
different encodings of text strings and that is sometimes very problematic under Windows.
The final nail in the coffin was when I asked a colleague at work under what he would look for date operations in C++.
The answer: "Date or DateTime". When I then explained that under C++ there is the chrono library, I had to realize that
for a new generation the language is simply not accessible. The names of the libraries and function names alone cause
too much confusion.

Inspiration is drawn primarily from .NET. Everything that the C++ standard already offers should also be used directly
as much as possible. GreenLizard is intended to be a very "thin" layer to simplify and accelerate development processes
with C++.

# Current status

| Library           | Description                                          |
|-------------------|------------------------------------------------------|
| GreenLizard       | Base library                                         |
| GreenLizard.IO    | library for IO Operations (in progress               |
| GreenLizard.Win32 | library for operations on MS Windows (e.g. Registry) |

# Examples

## String

```cpp
#include <GreenLizard/String.hpp>

using namespace GreenLizard;

void main()
{
	String s = "Hello World!";
}
```

## Registry

```cpp
#include <GreenLizard/Win32/Registry.hpp>

using namespace GreenLizard::Win32;

void main()
{
	auto currentUserKey = RegistryKey::OpenBaseKey(RegistryHive::LocalMachine, RegistryView::Default);
	auto softwareKey = currentUserKey->OpenSubKey(R"(SOFTWARE\Microsoft\Windows\CurrentVersion)");
	auto value = softwareKey->GetValue(R"(CommonFilesDir)");
	auto stringValue = value->Value<String>();
}
```

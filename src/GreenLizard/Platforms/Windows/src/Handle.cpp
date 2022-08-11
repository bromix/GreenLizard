#include <utility>
#include <GreenLizard/Platform/Handle.hpp>

namespace GreenLizard
{
	Platform::Handle::Handle() :
		handle(nullptr),
		ownsHandle(false)
	{
	}

	Platform::Handle::Handle(::HANDLE handle, bool ownsHandle) :
		handle(handle),
		ownsHandle(ownsHandle)
	{

	}

	Platform::Handle::~Handle()
	{
		if (ownsHandle && !IsNull())
		{
			::CloseHandle(handle);
			handle = nullptr;
			ownsHandle = false;
		}
	}

	Platform::Handle::operator ::HANDLE() const
	{
		return this->handle;
	}

	bool Platform::Handle::IsInvalid() const
	{
		return handle == INVALID_HANDLE_VALUE;
	}

	bool Platform::Handle::IsNull() const
	{
		return handle == nullptr;
	}

	bool Platform::Handle::IsNullOrInvalid() const
	{
		return IsNull() || IsInvalid();
	}

	bool Platform::Handle::OwnsHandle() const
	{
		return ownsHandle;
	}
}
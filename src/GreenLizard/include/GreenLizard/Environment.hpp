#pragma once

namespace GreenLizard {
    class Environment final {
    public:
        /**
         * @brief Default constructor.
         */
        Environment() = delete;

        /**
         * @brief Destructor.
         */
        ~Environment() = delete;

#if defined(_WIN32) || defined(_WINDOWS)
        using CharacterType = wchar_t;
#else
        using CharacterType = char;
#endif
    };
}
#pragma once

#include <memory>
#include <atomic>
#include <mutex>

#include <boost/dll/import.hpp>
#include <boost/make_shared.hpp>
#include <boost/utility/string_view.hpp>

namespace dll = boost::dll;


class dl_python final {
public:
    dl_python(const dl_python &) = delete;
    dl_python &operator=(const dl_python &) = delete;
    dl_python(dl_python &&) = delete;
    dl_python &operator=(dl_python &&) = delete;
    dl_python() = default;
    ~dl_python() = default;

    template<typename... Args>
    static void constructor(Args &&...args) {
        std::call_once(once_, [&]() {
            instance_ = std::make_unique<storage>(std::forward<Args>(args)...);
        });
    }

    static dll::shared_library &get_instance() {
        return instance_->lib_;
    }

    struct storage final {
        explicit storage(const std::string& path):lib_(path){}
        dll::shared_library lib_;
    };
private:
    static std::unique_ptr<storage> instance_;
    static std::once_flag once_;
};

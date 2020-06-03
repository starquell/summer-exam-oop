#pragma once

#include <string>
#include <string_view>

namespace exam::subject {

    class Worker {
    public:

        explicit Worker (std::string_view name)
            : _name{name.data()}
        {}

        [[nodiscard]]
        auto name() const noexcept -> const std::string&
        {
            return _name;
        }

    private:
        std::string _name;
    };

    class Department {
    public:

        Department (std::initializer_list<Worker> workers)
            : _workers {workers}
        {}

        [[nodiscard]]
        auto workers() const noexcept -> const std::vector<Worker>&
        {
            return _workers;
        }

    private:
        std::vector <Worker> _workers;
    };


    class Organization {
    public:

        Organization (std::initializer_list<Department> departments)
             : _departments {departments}
        {}

        [[nodiscard]]
        auto departments() const noexcept -> const std::vector<Department>&
        {
            return _departments;
        }

    private:
        std::vector <Department> _departments;
    };

    class Ministry {

    public:

        Ministry (std::initializer_list<Organization> organizations)
        : _organizations {organizations}
        {}

        [[nodiscard]]
        auto organizations() const noexcept -> const std::vector<Organization>&
        {
            return _organizations;
        }

    private:
        std::vector <Organization> _organizations;

    };
}
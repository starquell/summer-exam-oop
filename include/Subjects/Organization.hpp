#pragma once

#include <string>
#include <string_view>
#include <algorithm>

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
        auto name() const noexcept -> const std::string&
        {
            return _name;
        }

        [[nodiscard]]
        auto workers() const noexcept -> const std::vector<Worker>&
        {
            return _workers;
        }

        [[nodiscard]]
        auto workers_number() const noexcept -> std::size_t
        {
            return _workers.size();
        }

    private:
        std::vector <Worker> _workers;
        std::string _name;
    };


    class Organization {
    public:

        Organization (std::initializer_list<Department> departments)
             : _departments {departments}
        {}

        [[nodiscard]]
        auto name() const noexcept -> const std::string&
        {
            return _name;
        }

        [[nodiscard]]
        auto departments() const noexcept -> const std::vector<Department>&
        {
            return _departments;
        }

        [[nodiscard]]
        auto workers_number() const noexcept -> std::size_t
        {
            return std::accumulate(_departments.begin(), _departments.end(), 0,
                    [] (const auto sum, const auto department) {
                        return sum + department.workers_number();
            });
        }

    private:
        std::vector <Department> _departments;
        std::string _name;
    };

    class Ministry {

    public:

        Ministry (std::initializer_list<Organization> organizations)
        :  _organizations {organizations}
        {}

        [[nodiscard]]
        auto name() const noexcept -> const std::string&
        {
            return _name;
        }

        [[nodiscard]]
        auto organizations() const noexcept -> const std::vector<Organization>&
        {
            return _organizations;
        }

        [[nodiscard]]
        auto workers_number() const noexcept -> std::size_t
        {
            return std::accumulate(_organizations.begin(), _organizations.end(), 0,
                           [] (const auto sum, const auto organization) {
                               return sum + organization.workers_number();
                           });
        }

    private:
        std::vector <Organization> _organizations;
        std::string _name;
    };


    template <typename Comparable>
    auto name_less_compare (const Comparable& lhs, const Comparable& rhs) -> bool
    {
        return lhs.name() < rhs.name();
    }


    template <typename Comparable>
    auto name_greater_compare (const Comparable& lhs, const Comparable& rhs) -> bool
    {
        return lhs.name() > rhs.name();
    }

    auto operator< (const Department& lhs, const Department& rhs) -> bool
    {
        return lhs.workers_number() < rhs.workers_number();
    }

    auto operator< (const Organization& lhs, const Organization& rhs) -> bool
    {
        return lhs.workers_number() < rhs.workers_number();
    }

    auto operator< (const Ministry& lhs, const Ministry& rhs) -> bool
    {
        return lhs.workers_number() < rhs.workers_number();
    }

    auto operator> (const Department& lhs, const Department& rhs) -> bool
    {
        return lhs.workers_number() > rhs.workers_number();
    }

    auto operator> (const Organization& lhs, const Organization& rhs) -> bool
    {
        return lhs.workers_number() > rhs.workers_number();
    }

    auto operator> (const Ministry& lhs, const Ministry& rhs) -> bool
    {
        return lhs.workers_number() > rhs.workers_number();
    }

    auto operator== (const Department& lhs, const Department& rhs) -> bool
    {
        return lhs.workers_number() == rhs.workers_number()
             && lhs.name() == rhs.name();
    }

    auto operator== (const Organization& lhs, const Organization& rhs) -> bool
    {
        return lhs.workers_number() == rhs.workers_number()
               && lhs.name() == rhs.name();
    }

    auto operator== (const Ministry& lhs, const Ministry& rhs) -> bool
    {
        return lhs.workers_number() == rhs.workers_number()
               && lhs.name() == rhs.name();
    }
}

namespace std {
    template <> struct hash<exam::subject::Worker>
    {
        auto operator()(const exam::subject::Worker& worker) const -> size_t
        {
            return hash<string>{}(worker.name());
        }
    };

    template <> struct hash<exam::subject::Department>
    {
        auto operator()(const exam::subject::Department& department) const -> size_t
        {
            return std::accumulate(department.workers().begin(),
                                   department.workers().end(),
                                   size_t{},
                                   [] (const auto sum, const auto& worker) {
                return sum + hash<exam::subject::Worker>{}(worker);
            })
                +
                hash<string>{}(department.name());
        }
    };

    template <> struct hash<exam::subject::Organization>
    {
        auto operator()(const exam::subject::Organization& org) const -> size_t
        {
            return std::accumulate(org.departments().begin(),
                                   org.departments().end(),
                                   size_t{},
                                   [] (const auto sum, const auto& department) {
                return sum + hash<exam::subject::Department>{}(department);
            })
               +
               hash<string>{}(org.name());
        }
    };

    template <> struct hash<exam::subject::Ministry>
    {
        auto operator()(const exam::subject::Ministry& ministry) const -> size_t
        {
            return std::accumulate(ministry.organizations().begin(),
                                   ministry.organizations().end(),
                                   size_t{},
                                   [] (const auto sum, const auto& org) {
                                       return sum + hash<exam::subject::Organization>{}(org);
                                   })
                   +
                   hash<string>{}(ministry.name());
        }
    };

}
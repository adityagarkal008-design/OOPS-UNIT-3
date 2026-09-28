#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <utility>

class Employee {
protected:
    int employeeId;
    std::string name;

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    virtual double calculateSalary() const = 0;

    virtual double calculateTax() const { return 0.0; }

    double netSalary() const {
        return calculateSalary() - calculateTax();
    }

    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
    double basicSalary;
    double allowance;

public:
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}

    double calculateSalary() const override {
        return basicSalary + allowance;
    }

    double calculateTax() const override {
        return calculateSalary() * 0.10;
    }
};

class ContractEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

class FreelanceEmployee : public Employee {
    double projectAmount;

public:
    FreelanceEmployee(int id, std::string employeeName, double amount)
        : Employee(id, std::move(employeeName)), projectAmount(amount) {}

    double calculateSalary() const override {
        return projectAmount;
    }
};

void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    std::cout << "Gross Salary: Rs. " << employee.calculateSalary() << '\n';
    std::cout << "Tax: Rs. " << employee.calculateTax() << '\n';
    std::cout << "Net Salary: Rs. " << employee.netSalary() << "\n\n";
}

int main() {
    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<PermanentEmployee>(101, "Asha", 40000.0, 8000.0));
    employees.push_back(std::make_unique<ContractEmployee>(102, "Vikas", 500.0, 80));
    employees.push_back(std::make_unique<FreelanceEmployee>(103, "Riya", 30000.0));

    double totalPayroll = 0.0;

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& employee : employees) {
        printPaySlip(*employee);
        totalPayroll += employee->netSalary();
    }

    std::cout << "Total Net Payroll: Rs. " << totalPayroll << '\n';
    return 0;
}
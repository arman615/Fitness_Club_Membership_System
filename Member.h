#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <ctime>

class Member {
private:
    std::string name;
    std::string contactInfo;
    std::string membershipLevel;
    int remainingFitnessEntries;
    int remainingMassages;
    int remainingPoolEntries;
    time_t membershipStartDate;

public:
    Member(const std::string& name, const std::string& contactInfo, const std::string& membershipLevel);

    std::string getName() const;
    std::string getMembershipLevel() const;
    const std::string& getContactInfo() const;
    int getRemainingFitnessEntries() const;
    int getRemainingMassages() const;
    int getRemainingPoolEntries() const;
    void updateRemainingFitnessEntries(int count);
    void updateRemainingMassages(int count);
    void updateRemainingPoolEntries(int count);
    time_t getMembershipStartDate() const;
    time_t getMembershipEndDate() const;
};

#endif // MEMBER_H

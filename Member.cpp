#include "Member.h"

Member::Member(const std::string& name, const std::string& contactInfo, const std::string& membershipLevel)
    : name(name), contactInfo(contactInfo), membershipLevel(membershipLevel), membershipStartDate(time(nullptr)) {
    if (membershipLevel == "standard") {
        remainingFitnessEntries = 12;
        remainingMassages = 1;
        remainingPoolEntries = 6;
    } else if (membershipLevel == "premium") {
        remainingFitnessEntries = 24;
        remainingMassages = 2;
        remainingPoolEntries = 12;
    } else if (membershipLevel == "all included") {
        remainingFitnessEntries = -1;
        remainingMassages = -1;
        remainingPoolEntries = -1;
    }
}

std::string Member::getName() const {
    return name;
}

std::string Member::getMembershipLevel() const {
    return membershipLevel;
}

const std::string& Member::getContactInfo() const {
    return contactInfo;
}

int Member::getRemainingFitnessEntries() const {
    return remainingFitnessEntries;
}

int Member::getRemainingMassages() const {
    return remainingMassages;
}

int Member::getRemainingPoolEntries() const {
    return remainingPoolEntries;
}

void Member::updateRemainingFitnessEntries(int count) {
    remainingFitnessEntries -= count;
}

void Member::updateRemainingMassages(int count) {
    remainingMassages -= count;
}

void Member::updateRemainingPoolEntries(int count) {
    remainingPoolEntries -= count;
}

time_t Member::getMembershipStartDate() const {
    return membershipStartDate;
}

time_t Member::getMembershipEndDate() const {
    time_t endDate = membershipStartDate + 30 * 24 * 60 * 60;
    return endDate;
}

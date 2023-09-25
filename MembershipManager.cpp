#include "MembershipManager.h"
#include <iostream>
#include <fstream>

std::vector<Member> members;

void registerMember(const std::string& name, const std::string& contactInfo, const std::string& membershipLevel) {
    Member member(name, contactInfo, membershipLevel);
    members.push_back(member);

    std::cout << "Member registered successfully!\n";
}

void logUsage(const std::string& memberName, const std::string& area) {
    for (auto& member : members) {
        if (member.getName() == memberName) {
            time_t currentTime = time(nullptr);
            if (currentTime > member.getMembershipEndDate()) {
                std::cout << "Membership has expired! Please renew your membership.\n";
                return;
            }

            if (area == "fitness" && member.getRemainingFitnessEntries() == 0) {
                std::cout << "No remaining fitness entries for this member!\n";
                return;
            } else if (area == "massage" && member.getRemainingMassages() == 0) {
                std::cout << "No remaining massages for this member!\n";
                return;
            } else if (area == "pool" && member.getRemainingPoolEntries() == 0) {
                std::cout << "No remaining pool entries for this member!\n";
                return;
            }
            if (area == "fitness") {
                member.updateRemainingFitnessEntries(1);
            } else if (area == "massage") {
                member.updateRemainingMassages(1);
            } else if (area == "pool") {
                member.updateRemainingPoolEntries(1);
            }
            std::cout << "Usage logged successfully!\n";
            return;
        }
    }

    std::cout << "Member not found!\n";
}

void generateMonthlyStats(const Member& member) {
    std::cout << "Monthly statistics for " << member.getName() << ":\n";
    std::cout << "Membership level: " << member.getMembershipLevel() << std::endl;
    std::cout << "Fitness entries remaining: " << member.getRemainingFitnessEntries() << std::endl;
    std::cout << "Massages remaining: " << member.getRemainingMassages() << std::endl;
    std::cout << "Pool entries remaining: " << member.getRemainingPoolEntries() << std::endl;
}

void authorizeMembershipUpdate(const std::string& memberName, const std::string& newMembershipLevel) {
    for (auto& member : members) {
        if (member.getName() == memberName) {
            member.updateRemainingFitnessEntries(0);
            member.updateRemainingMassages(0);
            member.updateRemainingPoolEntries(0);
            member = Member(member.getName(), member.getContactInfo(), newMembershipLevel);

            std::cout << "Membership level updated successfully!\n";
            return;
        }
    }

    std::cout << "Member not found!\n";
}

void generateMonthlyBill(const Member& member) {
    std::ofstream file(member.getName() + ".txt");

    file << "Monthly bill for " << member.getName() << ":\n";
    file << "Membership level: " << member.getMembershipLevel() << std::endl;
    file << "Fitness entries remaining: " << member.getRemainingFitnessEntries() << std::endl;
    file << "Massages remaining: " << member.getRemainingMassages() << std::endl;
    file << "Pool entries remaining: " << member.getRemainingPoolEntries() << std::endl;

    file.close();

    std::cout << "Monthly bill generated and saved!\n";
}

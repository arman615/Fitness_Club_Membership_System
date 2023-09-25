#ifndef MEMBERSHIP_MANAGER_H
#define MEMBERSHIP_MANAGER_H

#include <string>
#include <vector>
#include "Member.h"

extern std::vector<Member> members;

void registerMember(const std::string& name, const std::string& contactInfo, const std::string& membershipLevel);
void logUsage(const std::string& memberName, const std::string& area);
void generateMonthlyStats(const Member& member);
void authorizeMembershipUpdate(const std::string& memberName, const std::string& newMembershipLevel);
void generateMonthlyBill(const Member& member);

#endif // MEMBERSHIP_MANAGER_H

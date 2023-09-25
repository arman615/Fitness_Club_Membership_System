#include "Member.h"
#include "MembershipManager.h"

int main() {
    registerMember("John Doe", "john.doe@example.com", "standard");
    registerMember("Jane Smith", "jane.smith@example.com", "premium");

    logUsage("John Doe", "fitness");
    logUsage("Jane Smith", "fitness");

    generateMonthlyStats(members[0]);
    generateMonthlyStats(members[1]);

    authorizeMembershipUpdate("John Doe", "premium");

    generateMonthlyStats(members[0]);
    generateMonthlyStats(members[1]);

    generateMonthlyBill(members[0]);
    generateMonthlyBill(members[1]);

    return 0;
}

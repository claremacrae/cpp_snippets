#define APPROVALS_CATCH
#include "integrations/catch/Catch2Approvals.h"
#include "Approvals.h"

using namespace ApprovalTests;

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

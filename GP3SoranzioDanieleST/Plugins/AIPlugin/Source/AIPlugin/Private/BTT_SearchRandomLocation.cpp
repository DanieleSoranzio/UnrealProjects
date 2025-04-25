#include "BTT_SearchRandomLocation.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UBTT_SearchRandomLocation::UBTT_SearchRandomLocation()
{
	NodeName = TEXT("Search Random Location");
}

EBTNodeResult::Type UBTT_SearchRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	APawn* Pawn = AICon ? AICon->GetPawn() : nullptr;
	if (!Pawn) return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	FNavLocation RandomLocation;

	if (NavSys && NavSys->GetRandomReachablePointInRadius(Pawn->GetActorLocation(), SearchRadius, RandomLocation))
	{
		AICon->MoveToLocation(RandomLocation.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
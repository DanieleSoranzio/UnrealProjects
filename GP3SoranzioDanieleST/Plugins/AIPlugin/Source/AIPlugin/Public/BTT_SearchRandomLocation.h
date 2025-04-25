#pragma once


#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_SearchRandomLocation.generated.h"


UCLASS()
class AIPLUGIN_API UBTT_SearchRandomLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_SearchRandomLocation();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	float SearchRadius = 1000.f;
};


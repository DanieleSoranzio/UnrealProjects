#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "AIC_BaseAI.generated.h"

class UAISenseConfig_Sight;
class USplineComponent;

UCLASS()
class AIPLUGIN_API AAIC_BaseAI : public AAIController
{
	GENERATED_BODY()

public:
	AAIC_BaseAI();


protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:

	UPROPERTY()
	UAISenseConfig_Sight* SightConfig;

	UPROPERTY()
	USplineComponent* PatrolSpline;

	// === CALLBACKS===
	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

public:
	
};

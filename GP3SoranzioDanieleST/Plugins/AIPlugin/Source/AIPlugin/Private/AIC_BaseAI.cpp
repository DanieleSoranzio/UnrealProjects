#include "AIC_BaseAI.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
#include "GameFramework/Character.h"
#include "Components/SplineComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIC_BaseAI::AAIC_BaseAI()
{

	// Recupero il PerceptionComponent esistente dal Controller
	if (GetPerceptionComponent() == nullptr)
	{
		// Se serve, crea manualmente un nuovo component (ma normalmente c'è già)
		UAIPerceptionComponent* NewPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent0"));
		SetPerceptionComponent(*NewPerception);
	}

	// Configura la vista
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1500.f;
	SightConfig->LoseSightRadius = 1600.f;
	SightConfig->PeripheralVisionAngleDegrees = 90.f;
	SightConfig->SetMaxAge(5.f);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->ConfigureSense(*SightConfig);
	GetPerceptionComponent()->SetDominantSense(SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AAIC_BaseAI::OnTargetPerceptionUpdated);
}

void AAIC_BaseAI::BeginPlay()
{
	Super::BeginPlay();
}

void AAIC_BaseAI::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (InPawn)
	{
		PatrolSpline = InPawn->FindComponentByClass<USplineComponent>();

		if (!PatrolSpline)
		{
			UE_LOG(LogTemp, Warning, TEXT("BaseAIController: No SplineComponent found on Pawn."));
		}
	}
}

void AAIC_BaseAI::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (!Actor) return;

	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(LogTemp, Log, TEXT("BaseAIController: Visto attore %s"), *Actor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("BaseAIController: Perso attore %s"), *Actor->GetName());
	}
}

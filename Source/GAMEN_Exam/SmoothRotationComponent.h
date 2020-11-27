#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SmoothRotationComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAMEN_EXAM_API USmoothRotationComponent : public UActorComponent {
	GENERATED_BODY()

public:
	USmoothRotationComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Toogle();

};

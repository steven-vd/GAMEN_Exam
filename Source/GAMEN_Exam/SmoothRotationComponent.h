#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SmoothRotationComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAMEN_EXAM_API USmoothRotationComponent : public UActorComponent {
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float rotationMin;
	UPROPERTY(EditAnywhere)
		float rotationMax;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;

protected:
	virtual void BeginPlay() override;

public:
	USmoothRotationComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Toggle();

};

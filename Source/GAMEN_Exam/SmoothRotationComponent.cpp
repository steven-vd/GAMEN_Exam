#include "SmoothRotationComponent.h"
#include <assert.h>


USmoothRotationComponent::USmoothRotationComponent() {
	PrimaryComponentTick.bCanEverTick = true;
	rotationSpeed = -5.f;
	rotationMin = 0.f;
	rotationMax = 90.f;
}

void USmoothRotationComponent::BeginPlay() {
	Super::BeginPlay();
	assert(rotationSpeed != 0);
	assert(rotationMin < rotationMax);
}

void USmoothRotationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FTransform t = GetOwner()->GetActorTransform();
	if (rotationSpeed > 0) {
		if (t.GetRotation().Euler().Z < rotationMax) {
			GetOwner()->AddActorLocalRotation(FRotator(0, rotationSpeed, 0));
		}
	} else {
		if (t.GetRotation().Euler().Z > rotationMin) {
			GetOwner()->AddActorLocalRotation(FRotator(0, rotationSpeed, 0));
		}
	}
}

void USmoothRotationComponent::Toggle() {
	rotationSpeed *= -1;
}

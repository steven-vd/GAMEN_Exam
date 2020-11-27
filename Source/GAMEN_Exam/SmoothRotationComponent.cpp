#include "SmoothRotationComponent.h"

USmoothRotationComponent::USmoothRotationComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void USmoothRotationComponent::BeginPlay() {
	Super::BeginPlay();

}

void USmoothRotationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USmoothRotationComponent::Toogle() {
	
}

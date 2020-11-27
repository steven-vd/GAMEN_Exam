#include "SmoothRotationComponent.h"

#include "CppFpsCharacter.h"

ACppFpsCharacter::ACppFpsCharacter() {
	PrimaryActorTick.bCanEverTick = true;
}

void ACppFpsCharacter::BeginPlay() {
	Super::BeginPlay();
	firstPersonCamera = FindComponentByClass<UCameraComponent>();
}

void ACppFpsCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ACppFpsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ACppFpsCharacter::Interact);
}

void ACppFpsCharacter::Interact() {
	//DEBUG
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Interact"));

	if (!firstPersonCamera) {
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Shit's fucked m8"));
		return;
	}

	FHitResult hit;
	FVector start = firstPersonCamera->GetComponentLocation();
	FVector end = start + firstPersonCamera->GetForwardVector() * 500.f; //Change 500 to set length
	FCollisionQueryParams queryParams;

	if (GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_GameTraceChannel2, queryParams)) {
		hit.GetActor()->FindComponentByClass<USmoothRotationComponent>()->Toggle();
	}
}

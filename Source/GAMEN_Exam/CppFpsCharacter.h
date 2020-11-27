// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "CppFpsCharacter.generated.h"

UCLASS()
class GAMEN_EXAM_API ACppFpsCharacter : public ACharacter {
	GENERATED_BODY()

private:
	UCameraComponent* firstPersonCamera;

public:
	ACppFpsCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Interact();

};

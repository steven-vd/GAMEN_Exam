// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GAMEN_Exam\VectorSolver.h>
#include "InteractiveBlackboard.generated.h"

UCLASS()
class GAMEN_EXAM_API AInteractiveBlackboard : public AActor {
	GENERATED_BODY()

private:
	VectorSolver vectorSolver;

public:
	// Sets default values for this actor's properties
	AInteractiveBlackboard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void EnterDigit(int digit);


};

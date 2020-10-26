// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GAMEN_Exam\VectorSolver.h>
#include "VectorSolver.h"
#include "Components/TextRenderComponent.h"
#include "InteractiveBlackboard.generated.h"

	UCLASS()
		class GAMEN_EXAM_API AInteractiveBlackboard : public AActor {
		GENERATED_BODY()

		private:
			VectorSolver vectorSolver;

			UTextRenderComponent* vecAxTRC;
			UTextRenderComponent* vecAyTRC;
			UTextRenderComponent* vecBxTRC;
			UTextRenderComponent* vecByTRC;

			UTextRenderComponent* magATRC;
			UTextRenderComponent* normAxTRC;
			UTextRenderComponent* normAyTRC;

			UTextRenderComponent* magBTRC;
			UTextRenderComponent* normBxTRC;
			UTextRenderComponent* normByTRC;

			UTextRenderComponent* determinantTRC;

		public:
			UPROPERTY(EditAnywhere)
				FVector vectorsStartPos;
			UPROPERTY(EditAnywhere)
				float vectorsMaxLength;

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
			UFUNCTION(BlueprintCallable)
				void DotLeftVector();
			UFUNCTION(BlueprintCallable)
				void DotRightVector();
			UFUNCTION(BlueprintCallable)
				void ClearVector();
			UFUNCTION(BluePrintCallable)
				void SetSelected(Selectable selected);

		private:
			void UpdateUI();
	};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GAMEN_Exam\VectorSolver.h>
#include "VectorSolver.h"
#include "Components/TextRenderComponent.h"
#include "Components/LineBatchComponent.h"
#include "InteractiveBlackboard.generated.h"

	UCLASS()
		class GAMEN_EXAM_API AInteractiveBlackboard : public AActor {
		GENERATED_BODY()

		private:
			VectorSolver vectorSolver;

			UTextRenderComponent* vecAxTRC;
			UTextRenderComponent* vecAyTRC;
			UTextRenderComponent* vecAzTRC;
			UTextRenderComponent* vecBxTRC;
			UTextRenderComponent* vecByTRC;
			UTextRenderComponent* vecBzTRC;
			UTextRenderComponent* vecCxTRC;
			UTextRenderComponent* vecCyTRC;
			UTextRenderComponent* vecCzTRC;

			UTextRenderComponent* magATRC;
			UTextRenderComponent* normAxTRC;
			UTextRenderComponent* normAyTRC;
			UTextRenderComponent* normAzTRC;

			UTextRenderComponent* magBTRC;
			UTextRenderComponent* normBxTRC;
			UTextRenderComponent* normByTRC;
			UTextRenderComponent* normBzTRC;

			UTextRenderComponent* magCTRC;
			UTextRenderComponent* normCxTRC;
			UTextRenderComponent* normCyTRC;
			UTextRenderComponent* normCzTRC;

			UTextRenderComponent* determinantTRC;

			UTextRenderComponent* xyBasisTRC;
			UTextRenderComponent* xyzBasisTRC;

			ULineBatchComponent* lineBatchComponent;

		public:
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
				void InvertVector();
			UFUNCTION(BlueprintCallable)
				void ClearVector();
			UFUNCTION(BluePrintCallable)
				void SetSelected(Selectable selected);

		private:
			void UpdateUI();
	};

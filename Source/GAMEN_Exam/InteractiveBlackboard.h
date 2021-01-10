// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GAMEN_Exam\VectorSolver.h>
#include "VectorSolver.h"
#include "MatrixSolver.h"
#include "Components/TextRenderComponent.h"
#include "Components/LineBatchComponent.h"
#include "InteractiveBlackboard.generated.h"

enum Operand {
	PLUS,
	MINUS,
	MULTIPLY,
};

	UCLASS()
		class GAMEN_EXAM_API AInteractiveBlackboard : public AActor {
		GENERATED_BODY()

		private:
			/* --- Vector Stuff --- */
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

			/* --- Matrix Stuff --- */
			MatrixSolver matrixSolver;

			UTextRenderComponent* matA11TRC;
			UTextRenderComponent* matA12TRC;
			UTextRenderComponent* matA13TRC;
			UTextRenderComponent* matA21TRC;
			UTextRenderComponent* matA22TRC;
			UTextRenderComponent* matA23TRC;
			UTextRenderComponent* matA31TRC;
			UTextRenderComponent* matA32TRC;
			UTextRenderComponent* matA33TRC;

			UTextRenderComponent* matB11TRC;
			UTextRenderComponent* matB12TRC;
			UTextRenderComponent* matB13TRC;
			UTextRenderComponent* matB21TRC;
			UTextRenderComponent* matB22TRC;
			UTextRenderComponent* matB23TRC;
			UTextRenderComponent* matB31TRC;
			UTextRenderComponent* matB32TRC;
			UTextRenderComponent* matB33TRC;

			UTextRenderComponent* matABR11TRC;
			UTextRenderComponent* matABR12TRC;
			UTextRenderComponent* matABR13TRC;
			UTextRenderComponent* matABR21TRC;
			UTextRenderComponent* matABR22TRC;
			UTextRenderComponent* matABR23TRC;
			UTextRenderComponent* matABR31TRC;
			UTextRenderComponent* matABR32TRC;
			UTextRenderComponent* matABR33TRC;

			UTextRenderComponent* matC11TRC;
			UTextRenderComponent* matC12TRC;
			UTextRenderComponent* matC21TRC;
			UTextRenderComponent* matC22TRC;

			UTextRenderComponent* matD11TRC;
			UTextRenderComponent* matD12TRC;
			UTextRenderComponent* matD21TRC;
			UTextRenderComponent* matD22TRC;

			UTextRenderComponent* matCDR11TRC;
			UTextRenderComponent* matCDR12TRC;
			UTextRenderComponent* matCDR21TRC;
			UTextRenderComponent* matCDR22TRC;

			UTextRenderComponent* matABOperandTRC;
			UTextRenderComponent* matCDOperandTRC;

			UTextRenderComponent* detMatA;
			UTextRenderComponent* detMatB;
			UTextRenderComponent* detMatC;
			UTextRenderComponent* detMatD;

			Operand matABOperand = Operand::PLUS;
			Operand matCDOperand = Operand::PLUS;

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
			UFUNCTION(BluePrintCallable)
				void ToggleABOperand();
			UFUNCTION(BluePrintCallable)
				void ToggleCDOperand();

		private:
			void UpdateUI();
	};

// GAS Example project

#include "Characters/GASE_BaseCharacter.h"
#include "EnhancedInputSubsystems.h"

AGASE_BaseCharacter::AGASE_BaseCharacter() { PrimaryActorTick.bCanEverTick = true; }

void AGASE_BaseCharacter::BeginPlay() { Super::BeginPlay(); }

void AGASE_BaseCharacter::MoveAction(const FInputActionValue &Value)
{
    // Potential C++ logic for moving action calls
}

void AGASE_BaseCharacter::LookAction(const FInputActionValue &Value)
{
    // Potential C++ logic for looking action calls
}
void AGASE_BaseCharacter::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void AGASE_BaseCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

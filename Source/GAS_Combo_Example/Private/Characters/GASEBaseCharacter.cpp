// GAS Example project

#include "Characters/GASEBaseCharacter.h"
#include "EnhancedInputSubsystems.h"

AGASEBaseCharacter::AGASEBaseCharacter() { PrimaryActorTick.bCanEverTick = true; }

void AGASEBaseCharacter::BeginPlay() { Super::BeginPlay(); }

void AGASEBaseCharacter::MoveAction(const FInputActionValue &Value)
{
    // Potential C++ logic for moving action calls
}

void AGASEBaseCharacter::LookAction(const FInputActionValue &Value)
{
    // Potential C++ logic for looking action calls
}
void AGASEBaseCharacter::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void AGASEBaseCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

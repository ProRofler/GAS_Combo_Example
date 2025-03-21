// GAS Example project

#include "Characters/GASEBaseCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "GAS/GASEAbilitySystemComponent.h"
#include "GAS/GASEMainAttributeSet.h"

AGASEBaseCharacter::AGASEBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    AbilitySystemComponent = CreateDefaultSubobject<UGASEAbilitySystemComponent>("Ability system component");
}

void AGASEBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (IsValid(AbilitySystemComponent))
    {
        AttributeSetMain = CastChecked<UGASEMainAttributeSet>(AbilitySystemComponent->GetSet<UGASEMainAttributeSet>());

        AbilitySystemComponent->InitAbilities();
    }
}

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

UAbilitySystemComponent *AGASEBaseCharacter::GetAbilitySystemComponent() const
{
    return Cast<UAbilitySystemComponent>(AbilitySystemComponent.Get());
}

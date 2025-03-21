// GAS Example project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GASE_BaseCharacter.generated.h"

UCLASS()
class GAS_COMBO_EXAMPLE_API AGASE_BaseCharacter : public ACharacter
{
    GENERATED_BODY()

  public:
    AGASE_BaseCharacter();

  protected:
    virtual void BeginPlay() override;

  public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
};

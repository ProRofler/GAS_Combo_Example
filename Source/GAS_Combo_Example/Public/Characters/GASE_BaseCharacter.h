// GAS Example project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GASE_BaseCharacter.generated.h"

class AGASE_PlayerController;

UCLASS()
class GAS_COMBO_EXAMPLE_API AGASE_BaseCharacter : public ACharacter
{
    GENERATED_BODY()

  public:
    friend AGASE_PlayerController;

    AGASE_BaseCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

  protected:
    virtual void BeginPlay() override;

  private:
    UFUNCTION()
    void MoveAction(const FInputActionValue &Value);
    UFUNCTION()
    void LookAction(const FInputActionValue &Value);
};


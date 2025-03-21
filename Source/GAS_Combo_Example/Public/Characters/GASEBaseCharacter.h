// GAS Example project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GASEBaseCharacter.generated.h"

class AGASEPlayerController;

UCLASS()
class GAS_COMBO_EXAMPLE_API AGASEBaseCharacter : public ACharacter
{
    GENERATED_BODY()

  public:
    friend AGASEPlayerController;

    AGASEBaseCharacter();

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


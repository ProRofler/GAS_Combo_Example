// GAS Example project

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "DataAssets/GASEAbilitiesListDataAsset.h"
#include "GameFramework/Character.h"

#include "GASEBaseCharacter.generated.h"

class AGASEPlayerController;
class UGASEAbilitySystemComponent;
class UGASEMainAttributeSet;

UCLASS()
class GAS_COMBO_EXAMPLE_API AGASEBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

  public:
    friend AGASEPlayerController;

    AGASEBaseCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    virtual UAbilitySystemComponent *GetAbilitySystemComponent() const override;

    UFUNCTION(BlueprintPure, Category = "GASE Abilities")
    UGASEAbilitiesListDataAsset *GetGrantedAbilitiesDataAsset() { return GrantedAbilitiesDataAsset; }

  protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "GASE Character|GAS",
              meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UGASEAbilitySystemComponent> AbilitySystemComponent;
    TObjectPtr<const UGASEMainAttributeSet> AttributeSetMain;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GASE Abilities")
    TObjectPtr<UGASEAbilitiesListDataAsset> GrantedAbilitiesDataAsset;

  private:
    UFUNCTION()
    void MoveAction(const FInputActionValue &Value);
    UFUNCTION()
    void LookAction(const FInputActionValue &Value);
};
